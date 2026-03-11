#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<vector<int>> dp(40, vector<int>(n + 1, 1));
    vector<int> u(m), v(m), d(m);
    for(int i = 0; i < m; i++)
        cin >> u[i] >> v[i] >> d[i];
    for(int i = 1; i < 40; i++) {
        for(int j = 0; j < m; j++)
            dp[i][v[j]] = max(dp[i][v[j]], min((int)1e9, dp[i - 1][u[j]] * d[j]));
    }
    while(Q--) {
        int p, x;
        cin >> p >> x;
        for(int i = 1; i < 40; i++) {
            if(dp[i][p] >= x) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}