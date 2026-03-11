#include "bits/stdc++.h"
using namespace std;
#define int long long
int Mod = 998244353;
int trans(string s) {
    if(s == "A")
        return 1;
    if(s == "J")
        return 11;
    if(s == "Q")
        return 12;
    if(s == "K")
        return 13;
    if(s == "10")
        return 10;
    return s[0] - '0';
}
int qpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b % 2 == 1)
            ans = (ans * a) % Mod;
        b /= 2;
        a = (a * a) % Mod;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> ini;
    map<int, int> cnt;
    for(int i = 1; i <= 13; i++)
        cnt.insert({i, 4});
    for(int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        int num = trans(s);
        ini.push_back(num);
        cnt[num]--;
    }
    vector<vector<vector<vector<int>>>> dp(6, vector<vector<vector<int>>>(65, vector<vector<int>>(6, vector<int>(65, 0))));
    for(auto i : cnt) {
        dp[1][i.first][0][0] = i.second;
        dp[0][0][1][i.first] = i.second;
    }
    sort(ini.begin(), ini.end());
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            for (int x = 0; x <= 64; x++) {
                for (int y = 0; y <= 64; y++) {
                    for (int num = 1; num <= 13; num++) {
                        for (int times = 0; times < cnt[num]; times++) {
                            int num1 = 0, num2 = 0;
                            if (i > 0 && x >= num)
                                num1 = dp[i - 1][x - num][j][y];
                            if (j > 0 && y >= num)
                                num2 = dp[i][x][j - 1][y - num];
                            dp[i][x][j][y] += (num1 + num2) % Mod;
                            if (num1 + num2 == 0)
                                continue;
//                            cout << num << endl;
//                            cout << i << " " << x << " " << j << " " << y << endl;
//                            cout << dp[i][x][j][y] << endl;
//                            system("pause");
                        }
                    }
                }
            }
        }
    }
//    for (int x = 0; x <= 20; x++) {
//        for (int y = 0; y <= 20; y++) {
//            cout << "x:" << x << " y:" << y << endl;
//            for (int i = 0; i <= 5; i++) {
//                for (int j = 0; j <= 5; j++) {
//                    cout << i << " " << j << " " << dp[i][x][j][y] << endl;
//                }
//            }
//        }
//    }

    for(int i = 1; i <= 5; i++) {
        int sum = 0;
        for(int j = i; j < 5; j++)
            sum += ini[j];
        int cnt1 = 0, cnt2 = 0, cnt12 = 0;
        for(int x = 0; x <= 64; x++) {
            for(int y = 0; y <= 64; y++) {
                cnt12 = (cnt12 + dp[i][x][5][y]) % Mod;
                if(x + sum > y)
                    cnt1 = (cnt1 + dp[i][x][5][y]) % Mod;
                if(x + sum < y)
                    cnt2 = (cnt2 + dp[i][x][5][y]) % Mod;
            }
        }
        int ans;
        ans = i * cnt1 % Mod * qpow(cnt12, Mod - 2) % Mod;
        ans = ((ans - i * cnt2 % Mod * qpow(cnt12, Mod - 2) % Mod) % Mod + Mod) % Mod;
        cout << ans << endl;
    }
}

/*
 A A A A Q

 8 6 8 10 J
 */