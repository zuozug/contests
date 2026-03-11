#include<bits/stdc++.h.>
#define int long long
#define all(x) x.begin(),x.end()
#define INF 3e18
#define pii pair<int,int>
using namespace std;

struct node {
    int t,u;
    bool operator <(const node& a) const {
        return t>a.t;
    }
};

vector<int>mp[101010];
map<pii,int>e;

void solve() {
    int n,m,k;cin>>n>>m>>k;
    vector<int>a(n+1);
    vector<int>K(n+1,INF);
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=k;i++) {
        int t,sc;cin>>t>>sc;
        for (int j=1,id;j<=sc;j++) {
            cin>>id;
            K[id]=min(K[id],t);
        }
    }
    for (int i=1,u,v,w;i<=m;i++) {
        cin>>u>>v>>w;
        mp[u].push_back(v);
        e[{u,v}]=w;
    }
    priority_queue<node>p;
    for (int i=1;i<=n;i++) {
        if (a[i]==0)p.push({0,i});
        if (K[i]!=INF)p.push({K[i],i});
    }

    vector<int>ans(n+1,0);
    while (!p.empty()) {
        auto [t,u]=p.top();p.pop();

        for (auto v:mp[u]) {

        }
    }








}

signed main() {
    int t=1;
    // cin>>t;
    while (t--) {
        solve();
    }
}
/*

 */
