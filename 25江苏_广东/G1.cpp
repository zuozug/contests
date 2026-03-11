#include<bits/stdc++.h.>
#define int long long
#define all(x) x.begin(),x.end()
const int INF = 1e18;
#define pii pair<int,int>
using namespace std;

struct node {
    int t,u;
    bool operator <(const node& a) const {
        return t>a.t;
    }
};

// vector<int>mp[101010];
// map<pii,int>e;

void solve() {
    int n, m, k; cin >> n>> m >> k;
    vector<vector<pii>> edge(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> t(k + 1), sc(k + 1);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<> > p;
    for (int i = 1; i <= k; i++) {
        cin >> t[i] >> sc[i];
        for (int j = 1; j <= sc[i]; j++) {
            int x; cin >> x;
            p.push({t[i], x});
        }
    }

    vector<array<int, 3>> E(m);
    for (int i = 0; i < m; i++) {
        auto &[u, v, w] = E[i];
        cin >> u >> v >> w;
    }
    sort(E.begin(), E.end());

    for (int i = 0; i < m; i++) {
        if (i == 0) {
            auto [u, v, w] = E[i];
            edge[u].push_back({v, w});
            continue;
        }
        auto [u1, v1, w1] = E[i - 1];
        auto [u2, v2, w2] = E[i];

        if (u1 == u2 && v1 == v2) continue;
        edge[u2].push_back({v2, w2});

    }



    for (int i = 1; i <= n; i++){
        if (a[i] == 0) p.push({0, i});
    }
    vector<int> vis(n + 1);

    vector<int> ans(n + 1, INF);

    while (!p.empty()) {
        auto [tim, u] = p.top();
        p.pop();
        if (ans[u] < tim) continue;
        ans[u] = tim;
        if (vis[u] == 1) continue;
        vis[u] = 1;

        for (auto &[v, w] : edge[u]) {
            if (--a[v] <= 0) {
                p.push({tim + w, v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == INF) ans[i] = -1;
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    int t=1;
    // cin>>t;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (t--) {
        solve();
    }
}
