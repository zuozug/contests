int kmi(int a,int b) {
    int res=1;
    while (b) {
        if (b&1) {
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}

void solve() {
    int x;cin>>x;
    string s=to_string(x);
    int n=s.size();n--;
    int ans=0;
    // reverse(all(s));
    for (int i=0;s[i];i++,n--) {
        int num=s[i]-'0';
        int val=kmi(2,n);
        ans+=num*val;
    }
    cout<<ans<<endl;
}