#include<iostream>
using namespace std;
int binSearchIterative(int arr[],int low,int high,int key){
    while(low<=high){
        int mid = high-(high-low)/2;
        if (arr[mid] == key){
            return mid;
        }else if(arr[mid]>key){
            high = mid-1;
        }else {
            low = mid+1;
        }
    }

    return -1;
}

int main(){
    int arr[]={2,4,8,13,56,77,99,130};
    int size = sizeof(arr)/sizeof(int);
    int key = 4;
    int index = binSearchIterative(arr,0,size-1,key);
    cout<<"The required index is :"<<index;
    return 0;
}