#include <iostream>
#include <string>
using namespace std;

const int d = 256; // number of characters in the alphabet
const int q = 1; // prime number for hash function

void rabin_karp(string pat, string txt)
{
    int m = pat.length();
    int n = txt.length();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // calculate h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // calculate hash value for pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++) {
        // check if hash values of current window of text and pattern match
        if (p == t) {
            // check if all characters of pattern match the current window of text
            int j;
            for (j = 0; j < m; j++) {
                if (txt[i+j] != pat[j]) {
                    break;
                }
            }
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        // calculate hash value for next window of text
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i+m]) % q;
            if (t < 0) {
                t += q;
            }
        }
    }
}

int main()
{
    string txt, pat;
    cout << "Enter the text string: ";
    getline(cin, txt);
    cout << "Enter the pattern string: ";
    getline(cin, pat);
    rabin_karp(pat, txt);
    return 0;
}
