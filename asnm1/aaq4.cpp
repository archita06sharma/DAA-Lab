// You are given a sequence A of length n and a number k. A number A[l]  is special if there 
// exists a contiguous subarray that contains exactly k numbers that are strictly greater than 
// A[l]. The specialty of a sequence is the sum of special numbers that are available in the 
// sequence. Your task is to determine the specialty of the provided sequence

#include<bits/stdc++.h>
using namespace std;

int speciality(int arr[],int n,int k){
    int speciality=0;
    vector<int> b(arr, arr + n);   
    sort(b.begin(), b.end());
    for(int i=0;i<n;i++){
        int greater=n-i-1;
        if(greater>=k) {
            speciality+=arr[i];
        }
    }
    return speciality;
}

int main(){
    int arr[]={7,1,6,2,5,3,4};
    int n=sizeof(arr)/sizeof(int);
    int k=4;
    int spec = speciality(arr,n,k);
    cout<<"Spec="<<spec<<"\n";
    return 0;
}