#include <iostream>
using namespace std;

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int max3(int a, int b, int c) {
    return max2(max2(a, b), c);
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int left_sum = -1000000000;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = -1000000000;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = low + (high - low) / 2;

    int left = maxSubArraySum(arr, low, mid);
    int right = maxSubArraySum(arr, mid + 1, high);
    int cross = maxCrossingSum(arr, low, mid, high);

    return max3(left, right, cross);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSubArraySum(arr, 0, n - 1);
    return 0;
}
