#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 998244353;
int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
int fact[10010],inv[10010];
void init(){
    fact[0]=1;
    for(int i=1;i<=10000;i++){
        fact[i]=fact[i-1]*i%mod;
    }
    inv[10000]=qpow(fact[10000],mod-2)%mod;
    for(int i=9999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
int C(int a,int b){
    if(a<b)return 0;
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
signed main() {
    int T=1;
    cin>>T;
    init();
    while(T--){
        int n;cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
//        cout<<qpow(2,1)<<'\n';
        sort(a.begin()+1,a.end());
//        for(auto i:a){
//            cout<<i<<'\n';
//        }
//        cout<<C(2,1)<<'\n';
        int ans=0;
//        for(int i=1;i<=n;i++){
//            int sum=1;
//            for(int j=1;j<=i;j++){
//                sum+=C(i,j)*qpow(2,j-1);
//            }
//            cout<<sum<<'\n';
//        }
        int sum=1;
        for(int i=2;i<=n;i++){
            sum=(sum*3-1+mod)%mod;
            ans=(ans+sum*a[i]%mod*qpow(2,n-i)%mod)%mod;
        }
        ans=(ans+qpow(2,n-1)*a[1]%mod)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}