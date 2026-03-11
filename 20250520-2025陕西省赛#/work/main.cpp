#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    string s;
    cin >> s;
    vector<vector<int>> cost(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> dp(1 << n, vector<int>(n, 1e9));
    for(int i = 0; i < n; i++)
        dp[1 << i][i] = t + cost[s[i] - 'a'][0];
    for(int sta = 0; sta < 1 << n; sta++) {
        vector<int> num(n, 0);
        if(sta & 1)
            num[0]++;
        for(int i = 1; i < n; i++) {
            num[i] = num[i - 1] + (sta >> i & 1);
        }
        for(int i = 0; i < n; i++) {
            if((sta >> i & 1) == 0)
                continue;
            for(int j = 0; j < n; j++) {
                dp[sta | (1 << j)][j] =min(dp[sta | (1 << j)][j],
                                           dp[sta][i] + cost[s[i] - 'a'][s[j] - 'a']
                                           +abs(num[i] - num[j]) * t + t);
            }
        }
    }
//    for(auto i : dp) {
//        for(auto j : i)
//            cout << j << " ";
//        cout << endl;
//    }
    int ans = dp[(1 << n) - 1][0];
    for(int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i]);
    cout << ans << endl;
    return 0;
}
/*
5 2 1
 aabaa
 0 10
 10 0

 5 2 1
 abaaa
 0 1
 1 0
 */