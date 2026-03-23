int main()
{
    int t ;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string v;
        cin>>v;
        int count=0;
        int stop=0;
        for(int i=0;i<n;i++){
            if(v[i]=='1') stop=k;
            else{
                if(stop==0)count++;
                else stop-=1;
            }
        }
        cout<<count<<endl;
        
    }
    return 0;
}
