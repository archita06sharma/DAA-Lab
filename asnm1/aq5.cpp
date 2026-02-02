#include <iostream>
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


int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int minMedian=100000000;
    for(int k=0;k<n-2;k++){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int size = j-i+1;
                if(size>1 && size%2==1){
                    int temp[j-i+1];
                    for(int z=i,a=0;z<=j;z++,a++){
                        temp[a]=arr[z];
                    }
                    mergeSort(temp,0,size);
                    int median = temp[size/2];
                    if (median < minMedian){
                        minMedian=median;
                    }
                }
            }
    }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int size = j-i+1;
            if(size>1 && size%2==1){
                mergeSort(arr,i,j);
                int median = arr[(size-1)/2];
                if (median < minMedian){
                    minMedian=median;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]==minMedian){
            for(int k=i;k<=n;i++){
                
            }
        }
    }

    return 0;
}