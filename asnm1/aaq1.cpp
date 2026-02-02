// You have an array A of length N. You have to divide the array into at-most M consecutive 
// segments such that the maximum bitwise OR of these segments is minimum. Find the 
// minimum possible maximum Bitwise OR of these segments if you divide optimally


#include<bits/stdc++.h>
using namespace std;

bool possible(int arr[],int n,int x,int maxSeg){
    int current_or=0,segment_count=1;
    for(int i=0;i<n;i++){
        if(arr[i] > x) return false;

        if( (current_or | arr[i]) <=x){
            current_or|=arr[i];
        }else{
            current_or=arr[i];
            segment_count++;
        }
    }
    return segment_count<=maxSeg;
}

int maxEle(int arr[],int n){
    int maxEle=INT_MIN;
    for(int i=0;i<n;i++){
        if(maxEle<arr[i]){
            maxEle=arr[i];
        }
    }
    return maxEle;
}

int maxOr(int arr[],int n){
    int orMax=0;
    for(int i=0;i<n;i++){
        orMax|=arr[i];
    }
    return orMax;
}

int main(){
    int arr[]={3,6,1,8,9,2,45,32};
    int n = sizeof(arr)/sizeof(int);
    int maxSeg=6;
    int high,low,mid;
    low=maxEle(arr,n);
    high = maxOr(arr,n);
    while(low<=high){
        mid = low+(high-low)/2;
        if(possible(arr,n,mid,maxSeg)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<low<<"\n";
    return 0;
}