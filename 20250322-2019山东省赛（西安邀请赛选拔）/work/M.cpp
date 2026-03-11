#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;

void solve(){
    LL n,k;cin>>n>>k;
    while(n>1 && k>0){
        n=(n-1)/2+1;
        k--;
    }
    cout<<n<<'\n';
}

int main()
{
    int T = 1;
    cin>>T;

    while(T--)
    {
        solve();
    }
}