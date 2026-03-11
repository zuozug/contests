#include "bits/stdc++.h"
using namespace std;
#define int long long
struct Node {
    vector<int> next;
    int incnt = 0;
    map<int, int> route;
};
signed main() {
    int n, m;
    cin >> n >> m;
    vector<Node> node(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        node[x - 1].next.push_back(y - 1);
        node[y - 1].incnt++;
    }
    set<int> canreach;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        if(canreach.count(temp))
            continue;
        canreach.insert(temp);
        for(auto i : node[temp].next) {
            if(canreach.count(i))
                continue;
            q.push(i);
        }
    }
    for(int i = 0; i < n; i++) {
        if(canreach.count(i))
            continue;
        for(auto j : node[i].next)
            node[j].incnt--;
        node[i].next.clear();
    }
    q.push(0);
    node[0].route[0] = 1;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for(auto i : node[temp].next) {
            for(auto j : node[temp].route)
                node[i].route[j.first + 1] += j.second;
            node[i].incnt--;
            if(node[i].incnt == 0)
                q.push(i);
        }
    }
    for(auto i : node[n - 1].route)
        cout << i.first << " " << i.second << endl;
    return 0;
}