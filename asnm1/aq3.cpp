#include<iostream>
using namespace std;
int main(){
    long long T;
    cin>>T;
    
    while(T--){
        long long n,h,w;
        cin>>n>>h>>w;

        long long low = max(h,w);
        long long high = max(h,w)*n;
        long long ans = high;

        while(low<=high){
            long long mid = low + (high-low)/2;
            long long rows = mid /h;
            long long cols = mid/w;
            if(rows*cols >=n){
                ans = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}