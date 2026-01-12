#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int temp[high+1];
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(int x = low;x<=high;x++){
        arr[x]=temp[x];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);

    }
    
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={2,5,7,234,654,546,55,90,59,130,120};
    int size = sizeof(arr)/sizeof(int);

    mergeSort(arr,0,size-1);
    print(arr,size);

    return 0;
}