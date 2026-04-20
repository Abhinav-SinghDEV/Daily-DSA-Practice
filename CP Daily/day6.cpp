By AbhinavSingh07, contest: Codeforces Round 1029 (Div. 3), problem: (B) Shrink, Accepted, #, Copy
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=2;i<=n;i+=2){
             cout<<i<<" ";
}
for(int i=n;i>0;i--){
   if(i%2!=0) cout<<i<<" ";
}
cout<<endl;
    }return 0;
}
