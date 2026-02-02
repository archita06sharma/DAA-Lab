#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxSum = arr[0];
    int currSum = arr[0];

    for (int i = 1; i < n; i++) {
        currSum = (arr[i] > currSum + arr[i]) ? arr[i] : currSum + arr[i];
        maxSum = (maxSum > currSum) ? maxSum : currSum;
    }

    cout << maxSum;
    return 0;
}
