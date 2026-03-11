#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, m;
int Mod = 998244353;
set<int> pre;
int qpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b % 2 == 1)
            res = res * a % Mod;
        a = a * a % Mod;
        b>>=1;
    }
    return res;
}
signed main() {
    int T=1;
    cin>>T;

    for(int i=1;i<=1e6;i*=2){
        pre.insert(i);
    }
    while(T--){
        cin >> n >> m;

        if(n&1){
            int t=qpow((qpow(2,m)-1),n-1);
            cout<<t<<'\n';
        }
        else {
            if(n==2){
                cout<<0<<'\n';
            }
            else {
                if(!pre.count(n))
                    cout<<(qpow((qpow(2,m)-1),n/2)*qpow(2,m)%Mod*n%Mod)%Mod<<endl;
                else {
                    cout<<(qpow((qpow(2,m)-1),n-1)+qpow((qpow(2,m)-1),n-2))%Mod<<endl;
                }
            }
        }
    }

    return 0;
}