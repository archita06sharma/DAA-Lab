// You are given an array A consisting of N integers. A subsequence of the array is called 
// good if every pair of elements in the subsequence have an absolute difference of at most 
// 10. Determine the maximum possible length of a good subsequence


#include<bits/stdc++.h>
using namespace std;

int find(int arr[],int n){
    sort(arr,arr+n);
    int count=0,maxCount=0;
    for(int i=0;i<n;i++){
        count=1;
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i]<=10){
                count ++;
            }
        }
        if(maxCount<count){
            maxCount=count;
        }
    }
    return maxCount;

}


int findLength(int arr[], int n){
    sort(arr,arr+n);
    int i=0,j=0,length=0,maxLength=0;
    while(j<n){
        if(arr[j]-arr[i]<=10){
            length=j-i+1;
            maxLength=max(maxLength,length);
            j++;
        } 
        else i++;

    }
    return maxLength;
}

int main(){
    int arr[]={5,3,7,9,12,34,56,2,1,22,21};
    int n = sizeof(arr)/sizeof(int);
    int maxLength=findLength(arr,n);
    cout<<"Max Length of Subsequence within 10 range is : "<<maxLength<<"\n";
    return 0;
}

