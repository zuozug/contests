#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N=1e5+10;
const int mod = 998244353;
int fact[N],inf[N];
int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
void init(){
    fact[0]=1;
    for(int i=1;i<=N-10;i++){
        fact[i]=fact[i-1]*i%mod;
    }
    inf[N-10]=qpow(fact[N-10],mod-2)%mod;
    for(int i=N-11;i>=0;i--){
        inf[i]=inf[i+1]*(i+1)%mod;
    }
}
int C(int n,int m){
    return fact[n]*inf[m]%mod*inf[n-m]%mod;
}
void solve(){
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    int j = 0;
    int cnt0 = 0, cnt1 = 0;

    int f = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(!f)
        {
            if(s[i] == '1')cnt1++;
            else cnt0++;
            if(cnt1 == k)f = 1;
            ans += C(cnt1 + cnt0, k);
            ans %= mod;
        }
        else
        {
            if(s[i] == '0')
            {
                int num = 0;
                while(s[i] == '0'){
                    num++;
                    i++;
                }
                i--;
                for(int kk = 1; kk <= num; kk++)
                {
                    ans += C(cnt1 + cnt0, k - kk) * C(num, k) % mod;
                    ans %= mod;
                }
                cnt0 += num;
            }
            else
            {
                while(s[j] == '0')
                {
                    j++;
                    cnt0--;
                }
                ans += C(j - i, k);
                ans %= mod;
            }
        }

        cout<<ans<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T=1;
    cin>>T;
    init();
    while(T--){
        solve();
    }
    return 0;
}
/*
 3
 6 2
 101011
 7 4
 1100111
 4 2
 0010

 */