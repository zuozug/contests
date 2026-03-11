#include "bits/stdc++.h"
using namespace std;
#define int long long
queue<int> ans;
int sum = 0;
struct Node {
    int l, r;
    int id;
};
bool cmpr(Node a, Node b) {
    return a.r < b.r;
}
void solve(int f, vector<Node> node) {
    cout << "------------" << f << endl;
    vector<Node> down, mid, up;
    stack<int> st;
    int ff = f;
    int upl = 1000000000000;
    for(auto i : node) {
        cout << i.id << " ";
        if(i.r < f) {
            down.push_back(i);
            sum += i.r - i.l;
        }
        else if(i.l > f) {
            up.push_back(i);
            upl = min(upl, i.l);
        }
        else {
            ff = max(ff, i.r);
            mid.push_back(i);
            sum += i.r - i.l;
        }
        cout << sum << endl;
    }
    sort(mid.begin(), mid.end(), cmpr);
    sort(down.begin(), down.end(), cmpr);
//    for(auto i : mid)
//        cout << i.id << " ";
//    cout << endl;
    for(auto i : mid)
        ans.push(i.id);
    if(upl != 1000000000000) {
        sum += upl - ff;
        solve(max(ff, upl), up);
    }
    for(auto i : down)
        ans.push(i.id);
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, f;
        cin >> n >> f;
        vector<Node> node(n);
        for(int i = 0; i < n; i++) {
            cin >> node[i].l >> node[i].r;
            node[i].id = i + 1;
        }
        solve(f, node);
        cout << sum << endl;
        while(!ans.empty()) {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}

/*
v
 */