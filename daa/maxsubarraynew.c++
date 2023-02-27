#include<iostream>
#include<climits>
using namespace std;

struct MaxSubarray {
    int sum;
    int start;
    int end;
};

int max(int a, int b) {
    return a > b ? a : b;
}

MaxSubarray crosssum(int a[], int l, int mid, int h) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = mid;
    for (int i = mid; i >= l; i--) {
        sum += a[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right = mid+1;
    for (int i = mid+1; i <= h; i++) {
        sum += a[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
          }

    MaxSubarray res = { left_sum + right_sum, max_left, max_right };
    return res;
}

MaxSubarray maxsum(int a[], int l, int h) {
    if (l == h) {
        MaxSubarray res = { a[l], l, h };
        return res;
    }
    else {
        int mid = (l + h) / 2;
        MaxSubarray left = maxsum(a, l, mid);
        MaxSubarray right = maxsum(a, mid + 1, h);
        MaxSubarray cross = crosssum(a, l, mid, h);

        if (left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        }
        else if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        }
        else {
            return cross;
        }
    }
}

void printMaxSubarray(int a[], int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = { -2, -5, 6, -2, -3, 1, 5, -6 };
    MaxSubarray max_subarray = maxsum(a, 0, 7);
    cout << "Maximum sum: " << max_subarray.sum << endl;
    cout << "Max subarray: ";
    printMaxSubarray(a, max_subarray.start, max_subarray.end);
    return 0;
}