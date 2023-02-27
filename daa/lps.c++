#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    string p = "bcdabcd";
    int LPS[p.length()];
    int i = 0;
    int j = 0;
    
    while (j < p.length())
    {
        if (p[i] == p[j])
        {
            LPS[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i == 0)
            {
                LPS[j] = 0;
                j++;
            }
            else
            {
                i = LPS[i - 1];
            }
        }
    }

    return 0;
}
