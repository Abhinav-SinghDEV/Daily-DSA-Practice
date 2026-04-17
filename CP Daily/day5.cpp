#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tt;cin>>tt;
    while(tt--){
        int max_val = INT_MIN;
        int n;cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>max_val)max_val = arr[i];
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==max_val)count++;
        }
        cout<<count<<"\n";
    }
 
    return 0;
}
