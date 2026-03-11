#include <bits/stdc++.h>
using namespace  std;
#define int long long
typedef long long LL;
#define all(x) x.begin(),x.end()
const int N=1e6+10;
int f[N],siz[N],dp[N],w[N];
map<int,int> m;
vector<int> e[N];

void dfs(int u,int fa){
    siz[u]=1;
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int dfs1(int u,int fa){
    if(e[u].size()== 1){
        if(w[u]==0)dp[u]=2;
        else dp[u]=1;
        return w[u];
    }
    int mx=0;
    for(auto v:e[u]){
        if(v==fa)continue;
        mx=min(mx,dfs1(v,u));
        if(dp[v]==2 && w[u]==w[v]+1)dp[u]=2;
        else if(w[u]<mx)dp[u]=0;
        else dp[u]=1;
    }
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        m[w[i]]=i;
    }
    for(int i=2;i<=n;i++){
        cin>>f[i];
        e[i].push_back(f[i]);
        e[f[i]].push_back(i);
    }
    dfs(1,0);
    for(int i=0;i<n;i++){
        if(dp[m[i]]==0){
            cout<<n-siz[m[i]]<<" ";
        }
        else if(dp[m[i]]==1){
            cout<<0<<' ';
        }
        else cout<<n-1<<' ';
    }
    cout<<n<<'\n';
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
