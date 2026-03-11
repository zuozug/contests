#include "bits/stdc++.h"
using namespace std;
#define int long long
struct Node {
    vector<pair<int, int>> next;
    int a;
    int ans = -1;
    multiset<int> in;
};
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<Node> node(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        cin >> node[i].a;
        if (node[i].a == 0)
            pq.push({0, i});
    }
    while (k--) {
        int t, sc;
        cin >> t >> sc;
        while (sc--) {
            int id;
            cin >> id;
            pq.push({t, id - 1});
        }
    }
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        node[u - 1].next.push_back({v - 1, w});
    }
    while (!pq.empty()) {
        int t = pq.top().first;
        int id = pq.top().second;
        cout << t << " " << id + 1 << endl;
        pq.pop();
        if (node[id].ans == -1)
            node[id].ans = t;
        else
            continue;
        for (auto i : node[id].next) {
            node[i.first].in.insert(-1 * (t + i.second));
            while (node[i.first].in.size() > node[i.first].a)
                node[i.first].in.erase(node[i.first].in.begin());
            cout << i.first + 1 << ": ";
            for (auto iiii : node[i.first].in)
                cout << iiii * -1 << " ";
            cout << endl;
            if (node[i.first].a>0 && node[i.first].in.size() == node[i.first].a && node[i.first].ans == -1)
                pq.push({*node[i.first].in.begin() * -1, i.first});
        }
    }
    for (auto i : node)
        cout << i.ans << " ";
    cout << endl;
    return 0;
}