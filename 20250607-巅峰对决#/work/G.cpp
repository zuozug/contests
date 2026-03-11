#include <bits/stdc++.h>
using namespace  std;
#define int long long
typedef long long LL;
#define all(x) x.begin(),x.end()
const int mod = 998244353;
int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
void solve(){
    int n,m;cin>>n>>m;
    vector<string> s(n+1);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int q;cin>>q;
    while(q--){
        int x,y,l,r,p;cin>>x>>y>>l>>r>>p;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        int t=1;
        for(int j=1;j<=n;j++){
            int tt=s[j][i]-'0';
            t&=tt;
        }
        ans+=t;
    }
    cout<<ans<<'\n';
}
signed main() {
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
