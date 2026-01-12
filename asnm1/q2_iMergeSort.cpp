#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (int x = low; x <= high; x++)
        arr[x] = temp[x - low];
}

void iterMergeSort(int arr[], int n)
{
    for (int size = 1; size < n; size *= 2)
    {
        for (int start = 0; start < n - 1; start += 2 * size)
        {
            int mid = start + size - 1;
            int end = start + 2 * size - 1;

            if (mid >= n - 1) continue;
            if (end >= n) end = n - 1;

            merge(arr, start, mid, end);
        }
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {2,5,7,234,654,546,55,90,59,130,120};
    int size = sizeof(arr) / sizeof(int);

    iterMergeSort(arr, size);
    print(arr, size);

    return 0;
}
