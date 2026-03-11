#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N=1e5+10;
const int mod = 998244353;
int fact[N];
int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
int n;
vector<vector<int>> st;
vector<vector<int>> g(N,vector<int>());
set<vector<vector<int>>> vis;
int ans=0;
void dfs(int p){
    if(p==n){
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(g[i][j]==0)cnt++;
            }
            if(cnt==n)return;
        }
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(g[j][i]==0)cnt++;
            }
            if(cnt==n)return;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(g[i][i]==0)cnt++;
        }
        if(cnt==n)return ;
        cnt=0;
        for(int i=0;i<n;i++){
            if(g[i][n-i-1]==0)cnt++;
        }
        if(cnt==n)return ;

        if(!vis.count(g)){
            vis.insert(g);
            ans++;
        }
        return ;
    }
    for(int i=0;i<n;i++){
        g[p]=st[i];
        dfs(p+1);
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=114;i++){
        fact[i]=fact[i-1]*i%mod;
    }
    cout<<fact[114]<<endl;
    cin>>n;
    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        temp[i]=1;
        st.push_back(temp);
        temp[i]=0;
    }
    for(auto i:st){
        for(int j:i){
            cout<<j;
        }
        cout<<endl;
    }
    dfs(0);
    cout<<ans<<'\n';
//    for(auto i:vis){
//
//        for(int j=0;j<n;j++){
//            for(int k=0;k<n;k++){
//                cout<<i[j][k];
//            }
//            cout<<endl;
//        }
//        cout<<endl<<endl;
//    }
}