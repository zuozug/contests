#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL mod = 1e9+7;
const int N=5e6+10;
LL qpow(LL a,LL b){
    LL ans =1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
LL fact[N],infact[N];
void init(){
    fact[0]=1;
    for(int i=1;i<=N-10;i++){
        fact[i]=fact[i-1]*i%mod;
    }
    infact[N-10]=qpow(fact[N-10],mod-2)%mod;
    for(int i=N-11;i>=0;i--){
        infact[i]=infact[i+1]*(i+1)%mod;
//        cout<<infact[i]<<'\n';
    }


}
LL C(LL n,LL m){
    return fact[n]*infact[m]%mod*infact[n-m]%mod;
}
void solve()
{
    init();
    LL n,R1,R2,r,a,h;cin>>n>>R1>>R2>>r>>a>>h;
    LL k=(h-1)/a+1;
    if(n<k){
        cout<<0<<'\n';
        return ;
    }

    if(R1+r<=R2){
        LL p=(R1+r)*(R1+r)%mod*qpow(R2,mod-2)%mod*qpow(R2,mod-2)%mod;
        LL p1=((1-p)%mod+mod)%mod;
        LL ans=0;
        for(int i=k;i<=n;i++){
            LL temp=C(n,i)*qpow(p,i)%mod*qpow(p1,n-i)%mod;
            ans=(ans+temp)%mod;
        }
        cout<<ans<<'\n';
    }
    else{
        cout<<1<<'\n';
    }
}

int main()
{
    int t = 1;
//    cin>>t;
    while(t--)
    {
        solve();
    }
}

/*
 5
 1
 1
 2
 1 2
 3
 1 3 2
 4
 1 3 2 4
 5
 3 4 5 2 1
 */