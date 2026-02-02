// You have been given an array A consisting of N integers. All the elements in this array A are unique. You have to answer some queries based on the elements of this array. Each query will consist of a single integer x. You need to print the rank based position of this element in this array considering that the array is 1 indexed. The rank based position of an element in an array is its position in the array when the array has been sorted in ascending order.

// Note: It is guaranteed that all the elements in this array are unique and for each x belonging to a query, value x shall exist in the array

// Input Format

// The first line consists of a single integer N denoting the size of array A. The next line contains N unique integers, denoting the content of array A. The next line contains a single integer q denoting the number of queries. Each of the next q lines contains a single integer x denoting the element whose rank based position needs to be printed.




#include <iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
	int left = low;
	int right = mid+1;
	int k=0;
	int temp[high-low+1];

	while(left<=mid && right<=high){
		if(arr[left]<=arr[right]){
			temp[k++] = arr[left++];
		}else{
			temp[k++] = arr[right++];
		}
	}

    while(left<=mid){
			temp[k++]=arr[left++];
	}

	while(right<=high){
			temp[k++]=arr[right++];
	}

	for(int i=low,k=0;i<=high;i++,k++){
			arr[i]=temp[k];
	}
}

void mergeSort(int arr[],int low,int high){
	if(low>=high) return;
	int mid = low + (high-low)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}

int binarySearch(int arr[],int low,int high,int key){
	while(low<=high){
		int mid = low + (high-low)/2;
		if(arr[mid]==key) return mid+1;
		else if (arr[mid]>key) high = mid-1;
		else low = mid+1;
	}
	return -1;
}

void printArray(int arr[],int size){
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main() {
	int n;
	cout<<"Enter number of elements in array : ";
	cin>>n;

	int arr[n];
	for(int i =0;i<n;i++){
		cout<<"Enter "<<i+1<<"th element : ";
		cin>>arr[i];
	}

	mergeSort(arr,0,n-1);
    printArray(arr,n);

	int q,x;
	cout<<"Enter how many queries : ";
	cin>>q;

	while(q--){
		cout<<"Enter query : ";
		cin>>x;
		int index = binarySearch(arr,0,n-1,x);
		cout<<"Index of the element is : "<<index<<"\n";
	}
	return 0;
}