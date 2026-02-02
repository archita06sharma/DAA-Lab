// Find inversions

#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];
    int invCount = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= high){
        temp[k++] = arr[j++];
    }

    for (int x = low, y = 0; x <= high; x++, y++){
        arr[x] = temp[y];
    }

    return invCount;
}

int mergeSortAndCount(int arr[], int low, int high) {
    if (low >= high) return 0;

    int mid = low + (high - low) / 2;
    int invCount = 0;

    invCount += mergeSortAndCount(arr, low, mid);
    invCount += mergeSortAndCount(arr, mid + 1, high);
    invCount += mergeAndCount(arr, low, mid, high);

    return invCount;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << mergeSortAndCount(arr, 0, n - 1);
    return 0;
}
