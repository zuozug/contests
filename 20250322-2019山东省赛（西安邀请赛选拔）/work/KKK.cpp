#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;
LL qpow(LL a,LL b){
    LL ans=1;
    for(;b;b>>=1,a=a*a)if(b&1)ans=ans*a;
    return ans;
}
LL qpow(LL a,LL b,LL p){
    LL ans=1;
    for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;
    return ans;
}
void solve(LL a,LL p){
//    LL a,p;cin>>a>>p;
    if(a&1){
        cout<<1<<'\n';
        return ;
    }
    LL t=qpow(2,p);
    vector<LL> temp;
    for(LL x=2;x<p;x+=2) {
        if(qpow(a,x,t) == qpow(x,a,t)){
            temp.push_back(x);
        }
    }
    if(a<p){
        LL cnt=0;
        for(LL x=1;x<=t;x++){
            if(qpow(a,x,t) == qpow(x,a,t)){
                cnt++;
            }
        }
        cout<<cnt<<'\n';
        return ;
    }
    else {
        LL ans=qpow(2,p-1);
        for(auto x:temp){
            if(qpow(a,x,t) != qpow(x,a,t)){
                ans--;
            }
        }
        cout<<ans<<'\n';
    }
}

int main()
{
    int T = 1;
//    cin>>T;

//    while(T--)
//    {
//        solve();
//    }

    for(int i = 1; i <= 20; i++) {
        cout << "_________________________" << endl;
        for(int a = 1; a <= 100; a++)
            solve(a, i);
    }
}