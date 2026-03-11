#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        int n, m, i, j;
        cin >> n >> m >> i >> j;
        int mx[8] = {-1, 1, -1, 1, k, k, -1 * k, -1 * k};
        int my[8] = {k, k, -1 * k, -1 * k, -1, 1, 1, -1};
        set<pair<int, int>> s;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            if (s.count(temp))
                continue;
            s.insert(temp);
            for (int ii = 0; ii < 8; ii++) {
                int xx = temp.first + mx[ii];
                int yy = temp.second + my[ii];
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                    if (s.count({xx, yy}))
                        continue;
                    q.push({xx, yy});
                }
            }
        }
        cout << s.size() << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.count({i, j}))
                    cout << 1;
                else
                    cout << 0;
            }
            cout << endl;
        }
    }
    return 0;
}
