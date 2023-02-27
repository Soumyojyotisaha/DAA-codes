#include <iostream>
using namespace std;

int a[] = {3,2,1,7,8,4};
int n = 6, tar =18;
bool found = false;

void print(int subset[], int len)
{
    for (int i = 0; i < len; i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void solve(int subset[], int len, int curr, int ind)
{
    if (curr > tar) {
        return;
    }
    if (curr == tar) {
        found = true;
        print(subset, len);
        return;
    }
    for (int i = ind; i < n; i++) {
        subset[len] = a[i];
        solve(subset, len + 1, curr + a[i], i + 1);
    }
}

int main()
{
    int subset[n];
    solve(subset, 0, 0, 0);
    if (found == false) {
        cout << "no solution";
    }
    return 0;
}
