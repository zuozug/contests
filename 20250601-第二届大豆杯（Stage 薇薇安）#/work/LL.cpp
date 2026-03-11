#include "bits/stdc++.h"
using namespace std;
#define int long long
int Mod = 998244353;
int solve(char a) {
    if(a == '?')
        return -1;
    if(a >= '0' && a <= '9') {
        if(a == '1')
            return 5;
        return 2;
    }
    if(a >= 'a' && a <= 'z') {
        if(a == 'l')
            return 4;
        else
            return 0;
    }
    if(a == 'I')
        return 3;
    else
        return 1;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<vector<int>> dp(s.size(), vector<int>(6, 0));
        //a, A, 0, I, l, 1
        if(solve(s[0]) == -1) {
            dp[0][0] = 25;
            dp[0][1] = 25;
            dp[0][2] = 9;
        }
        else if(solve(s[0]) <= 2)
            dp[0][solve(s[0])] = 1;
        for(int i = 1; i < s.size(); i++) {
            int sum = 0;
            for(int j = 0; j < 6; j++)
                sum = (sum + dp[i - 1][j]) % Mod;
            if(solve(s[i]) == -1) {
                dp[i][0] = ((sum - dp[i - 1][3] - dp[i - 1][5]) % Mod + Mod) * 25 % Mod;
                dp[i][1] = ((sum - dp[i - 1][4] - dp[i - 1][5]) % Mod + Mod) * 25 % Mod;
                dp[i][2] = ((sum - dp[i - 1][4] - dp[i - 1][3]) % Mod + Mod) * 9 % Mod;
                dp[i][3] = (dp[i - 1][1] + dp[i - 1][3]) % Mod;
                dp[i][4] = (dp[i - 1][0] + dp[i - 1][4]) % Mod;
                dp[i][5] = (dp[i - 1][2] + dp[i - 1][5]) % Mod;
            }
            else {
                if(solve(s[i]) == 0)
                    dp[i][0] = ((sum - dp[i - 1][3] - dp[i - 1][5]) % Mod + Mod) % Mod;
                else if(solve(s[i]) == 1)
                    dp[i][1] = ((sum - dp[i - 1][4] - dp[i - 1][5]) % Mod + Mod) % Mod;
                else if(solve(s[i]) == 2)
                    dp[i][2] = ((sum - dp[i - 1][4] - dp[i - 1][3]) % Mod + Mod) % Mod;
                else if(solve(s[i]) == 3)
                    dp[i][3] = (dp[i - 1][1] + dp[i - 1][3]) % Mod;
                else if(solve(s[i]) == 4)
                    dp[i][4] = (dp[i - 1][0] + dp[i - 1][4]) % Mod;
                else
                    dp[i][5] = (dp[i - 1][2] + dp[i - 1][5]) % Mod;
            }
        }
        int ans = 0;
        for(int i = 0; i < 3; i++)
            ans = (ans + dp[s.size() - 1][i]) % Mod;
        cout << ans << endl;
    }
    return 0;
}