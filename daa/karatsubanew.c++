#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

string intToString(int x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

int karat(int a, int b) {
    string as = intToString(a);
    string bs = intToString(b);
    int alen = as.length();
    int blen = bs.length();
    if (alen == 1 && blen == 1) {
        return a * b;
    } else {
        int n = max(alen, blen);
        while (alen != n) {
            as = "0" + as;
            alen = as.length();
        }
        while (blen != n) {
            bs = "0" + bs;
            blen = bs.length();
        }
        int aL = strtol(as.substr(0, n / 2).c_str(), nullptr, 10);
        int aR = strtol(as.substr(n / 2, n - (n / 2)).c_str(), nullptr, 10);
        int bL = strtol(bs.substr(0, n / 2).c_str(), nullptr, 10);
        int bR = strtol(bs.substr(n / 2, n - (n / 2)).c_str(), nullptr, 10);
        int x1 = karat(aL, bL);
        int x2 = karat(aL + aR, bL + bR);
        int x3 = karat(aR, bR);
        int m = n / 2 + n % 2;
        return x1 * pow(10, 2 * m) + (x2 - x1 - x3) * pow(10, m) + x3;
    }
}

int main() {
    cout << karat(5678, 1234);
    return 0;
}
