#include<iostream>
using namespace std;

int binSearchRec(int arr[],int low,int high,int key){

    if(low>high) return -1;

    int mid = high-(high-low)/2;

    if(arr[mid]==key) return mid;
    else if(arr[mid]>key) return binSearchRec(arr,low,mid-1,key);
    else return binSearchRec(arr,mid+1,high,key);
}

int main(){
    int arr[]={1,3,5,7,9,22,58,99,120};
    int size = sizeof(arr)/sizeof(int);

    int key = 130;
    int index = binSearchRec(arr,0,size-1,key);

    if(index != -1){
        cout<<"Element found at index : "<<index;
    }else cout<<"Element not found.";

    return 0;
}
