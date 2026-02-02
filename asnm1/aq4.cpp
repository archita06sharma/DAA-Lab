#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    for(int j = left; j < right; j++) {
        if(arr[j] <= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;
    return i;
}

int quickSelect(int arr[], int left, int right, int k) {
    if(left == right) return arr[left];
    
    int pivotIndex = partition(arr, left, right);
    
    if(k == pivotIndex) return arr[k];
    else if(k < pivotIndex) return quickSelect(arr, left, pivotIndex - 1, k);
    else return quickSelect(arr, pivotIndex + 1, right, k);
}

int findMedian(int arr[], int start, int len) {
    int temp[len];
    for(int i = 0; i < len; i++) {
        temp[i] = arr[start + i];
    }
    return quickSelect(temp, 0, len - 1, len / 2);
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int currentSize = n;
        
        for(int op = 0; op < n - 2; op++) {
            int minMedian = 2000000000;
            
            for(int len = 3; len <= currentSize; len += 2) {
                for(int start = 0; start <= currentSize - len; start++) {
                    int median = findMedian(arr, start, len);
                    if(median < minMedian) {
                        minMedian = median;
                    }
                }
            }
            
           
            for(int i = 0; i < currentSize; i++) {
                if(arr[i] == minMedian) {
                    for(int j = i; j < currentSize - 1; j++) {
                        arr[j] = arr[j + 1];
                    }
                    currentSize--;
                    break;
                }
            }
        }
        
        long long sum = 0;
        for(int i = 0; i < currentSize; i++) {
            sum += arr[i];
        }
        
        cout << sum << "\n";
    }
    
    return 0;
}