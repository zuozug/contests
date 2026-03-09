#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dis(n, vector<int>(n, 1e16));
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u - 1][v - 1] = min(dis[u - 1][v - 1], w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    // for (auto i : dis) {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dis[a - 1][b - 1] < 1e15)
            cout << dis[a - 1][b - 1] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}

/*
 2 1 1
 1 2 3
 1 2


 3 1 1
 1 2 3
 1 3
 */