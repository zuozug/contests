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
    return a.r > b.r;
}
bool cmpl(Node a, Node b) {
    return a.l < b.l;
}
void solve(int f, vector<Node> &node) {
    vector<Node> down, mid, up;
    int upl = 1e18;
    for(auto i : node) {
        if(i.r < f)
            down.push_back(i);
        else if(i.l > f)
            up.push_back(i);
        else
            mid.push_back(i);
    }
    for(auto i : mid)
        sum += i.r - i.l;
    for(auto i : down)
        sum += i.r - i.l;
    for(int i = 1; i < mid.size(); i++)
        ans.push(mid[i].id);
    if(!mid.empty())
        ans.push(mid[0].id);
    for(auto i : up)
        upl = min(upl, i.l);

    if(!up.empty()) {
        int ff = f;
        if(!mid.empty())
            ff = mid[0].r;
        if(ff > upl)
            ff = upl;
        queue<int> temp;
        for(int i = 0; i < up.size(); i++) {
            if(up[i].l <= ff) {
                if(up[i].r <= ff) {
                    sum += up[i].r - up[i].l;
                    temp.push(up[i].id);
                }
                else {
                    sum += up[i].r - up[i].l;
                    ff = up[i].r;
                    ans.push(up[i].id);
                }
            }
            else {
                sum += up[i].l - ff;
                sum += up[i].r - up[i].l;
                ff = up[i].r;
                ans.push(up[i].id);
            }
        }
        while(!temp.empty()) {
            ans.push(temp.front());
            temp.pop();
        }
    }

    for(auto i : down)
        ans.push(i.id);
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        sum = 0;
        int n, f;
        cin >> n >> f;
        vector<Node> node(n);
        for(int i = 0; i < n; i++) {
            cin >> node[i].l >> node[i].r;
            node[i].id = i + 1;
        }
        sort(node.begin(), node.end(), cmpr);
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