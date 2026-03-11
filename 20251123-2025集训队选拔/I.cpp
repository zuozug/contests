#include "bits/stdc++.h"
using namespace std;
#define int long long
int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    cin >> x;
    vector<int> num;
    set<int> ans;
    ans.insert(0);
    int cnt = 0;
    while (x) {
        if (x % 2 == 1)
            num.push_back(cnt);
        x /= 2;
        cnt++;
    }
    cout << qpow(2, num.size()) << endl;
    for (auto i : num) {
        queue<int> q;
        int temp = qpow(2, i);
        for (auto j : ans)
            q.push(j + temp);
        while (!q.empty()) {
            ans.insert(q.front());
            q.pop();
        }
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}