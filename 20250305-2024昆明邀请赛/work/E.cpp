#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N=3e5+10;

LL stgcd[N][21];
LL aa[N];
LL Log2[N];
LL n,k;
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
void init(){
    for(int i=1;i<=n;i++){
        stgcd[i][0]=aa[i]+k;
//        cout<<stgcd[i][0]<<" ";
    }

    for(int j=1;j<=20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            stgcd[i][j]=gcd(stgcd[i][j-1],stgcd[i+(1<<(j-1))][j-1]);
//            cout<<stgcd[i][j-1]<<" "<<stgcd[i+(1<<(j-1))][j-1]<<"\n";
//            cout<<stgcd[i][j]<<" ";
        }
//        cout<<'\n';
    }
}
LL query(LL l,LL r){
    if(l>r){
//        cerr<<l<<" "<<r<<'\n';
        return 0;
    }
    LL len=r-l+1;
    LL s=Log2[len];
    return gcd(stgcd[l][s],stgcd[r-(1<<s)+1][s]);
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>aa[i];
    init();

    vector<LL> pre(n+1,0),suf(n+2,0);
    pre[1]=suf[n]=gcd(aa[1],aa[n]);
    for(int i=2;i<=n;i++){
        pre[i]=gcd(pre[i-1],aa[i]);
    }
    for(int i=n-1;i>=1;i--){
        suf[i]=gcd(suf[i+1],aa[i]);
    }

    LL ans=1;
    for(int i=1;i<=n;i++){
        LL l = pre[i];
        auto r = lower_bound(suf.begin(),suf.end(),l)-suf.begin();
//        cout<<l<<" "<<r<<'\n';
        LL tt=gcd(l,suf[r]);
        LL temp=query(i+1,r-1);
        ans=max(ans,gcd(tt,temp));
        ans=max(ans,gcd(l,query(i+1,n)));
    }

    for(int i=n;i>=1;i--){
        LL r = suf[i];
        auto l = lower_bound(pre.begin(),pre.end(),r,greater<>())-pre.begin();
//        cout<<l<<" "<<r<<'\n';
        LL tt=gcd(r,pre[l]);
        LL temp=query(l+1,i-1);
        ans=max(ans,gcd(tt,temp));
        ans=max(ans,gcd(r,query(1,i-1)));
    }
    ans=max(ans,query(1,n));
    cout<<ans<<'\n';
}

int main() {
    int t = 1;
    cin>>t;

    for(int i=2;i<=N-10;i++){
        Log2[i]=Log2[i/2]+1;
    }
    while(t--)
    {
        solve();
    }
}
/*
2
6 2
5 3 13 8 10 555
3 0
3 6 9



 */
