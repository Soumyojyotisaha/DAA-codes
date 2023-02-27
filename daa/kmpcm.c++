#include<bits/stdc++.h>
using namespace std;

int main()
{
    string p;
    cout << "Enter a string: ";
    cin >> p;

    int n = p.length();
    int lps[n];
    lps[0] = 0;

    int i = 1, j = 0;
    while (i < n)
    {
        if (p[i] == p[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    cout << "The longest prefix-suffix array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;

    return 0;
}
