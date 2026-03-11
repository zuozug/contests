#include "bits/stdc++.h"
using namespace std;
#define int long long
struct Node {
    vector<pair<int, int>> edge;
    int dis;
};
signed main() {
    int n, m;
    cin >> n >> m;
    vector<Node> node(n);
    for(int i = 0; i < m; i++) {
        int u, v, len;
        cin >> u >> v >> len;
        if(u == v)
            continue;
        node[u - 1].edge.push_back({v - 1, len});
        node[v - 1].edge.push_back({u - 1, len});
    }
    int q;
    cin >> q;
    while(q--) {
        for(int i = 0; i < n; i++)
            node[i].dis = 1000000000000000;
        node[0].dis = 0;
        int t;
        cin >> t;
        vector<int> c(n - 1);
        for(int i = 0; i < n - 1; i++)
            cin >> c[i];
        for(int i = 0; i < 10000; i++)
            c.push_back(0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();
            if(temp.first >= node[temp.second.first].dis)
                continue;
            node[temp.second.first].dis = temp.first;
            for(auto i : node[temp.second.first].edge) {
                pq.push({node[temp.second.first].dis + i.first + c[temp.second.second], {i.second, temp.second.second + 1}});
            }
        }
        cout << node[t - 1].dis << endl;
    }
    return 0;
}