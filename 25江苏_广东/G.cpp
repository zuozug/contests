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
        if (e.find({u,v})==e.end()) {
            e[{u,v}]=w;
        }
        else {
            e[{u,v}]=min(e[{u,v}],w);
        }
    }
    priority_queue<node>p,st;
    for (int i=1;i<=n;i++) {
        if (a[i]==0)p.push({0,i});
        if (K[i]!=INF)st.push({K[i],i});
    }
    vector<int>ans(n+1,INF);
    int T=0;
    while (1) {
        if (p.empty() && st.empty())break;
        if (p.empty()) {
            int pre=-1;
            while (!st.empty()) {
                auto [t,u]=st.top();
                if (pre==-1) {
                    pre=t;
                    p.push({t,u});
                    st.pop();
                }
                else {
                    if (pre==t) {
                        p.push({t,u});
                        st.pop();
                    }
                    else break;
                }
            }
            T=pre;
        }
        auto [t,u]=p.top();p.pop();
        if (t>=ans[u])continue;
        ans[u]=t;
        for (auto v:mp[u]) {
            a[v]--;
            if (a[v]<=0) {
                p.push({t+e[{u,v}],v});
            }
        }
    }
    for (int i=1;i<=n;i++) {
        cout<<(ans[i]==INF?-1:ans[i])<<' ';
    }
}

signed main() {
    int t=1;
    // cin>>t;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (t--) {
        solve();
    }
}
/*



 */