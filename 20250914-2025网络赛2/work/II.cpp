#include "bits/stdc++.h"
using namespace std;
#define int long long
int Mod = 998244353;
int qpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b % 2 == 1)
            res = res * a % Mod;
        a = a * a % Mod;
        b>>=1;
    }
    return res;
}
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
    vector<vector<int>> func(node[n - 1].route.size(), vector<int>(node[n - 1].route.size() + 1, 0));
    for(int i = 0; i < node[n - 1].route.size(); i++) {
        int temp = i + 1;
        for(int j = 0; j < node[n - 1].route.size(); j++) {
            func[i][j] = temp;
            temp = temp * (i + 1) % Mod;
        }
    }
    for(int i = 0; i < node[n - 1].route.size(); i++) {
        cout << "? 1 " << n << " " << i + 1 << endl;
        int num;
        cin >> num;
        func[i][node[n - 1].route.size()] = num;
    }
    vector<int> ans(node[n - 1].route.size(), 0);

    for(int i = 0; i < node[n - 1].route.size() - 1; i++) {
        for(int j = node[n - 1].route.size() - 2; j >= i; j--) {
            int mult = __gcd(func[j + 1][i], func[j][i]);
            int numa = func[j][i] / mult, numb = func[j + 1][i] / mult;
            for(int k = i; k <= node[n - 1].route.size(); k++) {
                func[j + 1][k] = func[j + 1][k] * numa - func[j][k] * numb;
                func[j + 1][k] = ((func[j + 1][k] % Mod) + Mod) % Mod;
            }
        }
    }
    for(int i = node[n - 1].route.size() - 1; i >= 0; i--) {
        for(int j = node[n - 1].route.size() - 1; j > i; j--) {
            func[i][node[n - 1].route.size()] -= ans[j] % Mod * func[i][j] % Mod;
            func[i][node[n - 1].route.size()] = ((func[i][node[n - 1].route.size()] % Mod) + Mod) % Mod;
        }
        ans[i] = func[i][node[n - 1].route.size()] % Mod * qpow(func[i][i], Mod - 2) % Mod;
    }
    cout << '!' << endl;
    int num;
    cin >> num;
    int sum = 0;
    int p = 0;
    for(auto i : node[n - 1].route) {
        sum += qpow(num, i.first) % Mod * ans[p];
        sum %= Mod;
        p++;
    }
    cout << sum << endl;
    return 0;
}