#include "bits/stdc++.h"
using namespace std;
#define int long long
struct Node {
    int s = 0;
    vector<int> p;
    int l = 0, r = 0;
    int need;
    int id = -1;
};
Node newnode;

bool cmps(Node a, Node b) {
    return a.s < b.s;
}
bool cmpid(Node a, Node b) {
    return a.id < b.id;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<Node> node(n);
        for(int i = 0; i < n; i++) {
            cin >> node[i].s;
            int temp;
            int cnt = 0;
            int sum = 0;
            for(int j = 0; j < m; j++) {
                cin >> temp;
                if(temp == -1)
                    cnt++;
                else
                    sum += temp;
                node[i].p.push_back(temp);
            }
            node[i].l = sum;
            node[i].r = sum + cnt * k;
            node[i].id = i;
        }
        node.push_back(newnode);
        sort(node.begin(), node.end(), cmps);

        int flag = 0;
        int down = -1;
        for(int i = 1; i <= n; i++) {
            int up = 0;
            while(true) {
                if(node[i].r <= down) {
                    flag = 1;
                    break;
                }
                if(node[i].l > down) {
                    node[i].need = 0;
                    up = max(node[i].l, up);
                }
                else {
                    node[i].need = down + 1 - node[i].l;
                    up = max(down + 1, up);
                }
                if(i + 1 <= n && node[i + 1].s == node[i].s)
                    i++;
                else
                    break;
            }
            if(flag == 1)
                break;
            down = up;
        }
        if(flag == 1)
            cout << "No" << endl;
        else {
            cout << "Yes" << endl;
            sort(node.begin(), node.end(), cmpid);
            for(int i = 1; i <= n; i++) {
                for(auto j : node[i].p) {
                    if(j != -1)
                        cout << j << " ";
                    else {
                        if(node[i].need > k) {
                            cout << k << " ";
                            node[i].need -= k;
                        }
                        else {
                            cout << node[i].need << " ";
                            node[i].need = 0;
                        }
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}