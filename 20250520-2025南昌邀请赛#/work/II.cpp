#include "bits/stdc++.h"
using namespace std;
#define int long long
int Mod = 998244353;
vector<int> fact, inf;
int qpow(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b % 2 == 1)
            ans = (ans * a) % Mod;
        b /= 2;
        a = (a * a) % Mod;
    }
    return ans;
}
void build(int n) {
    fact.resize(n + 1);
    inf.resize(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % Mod;
    inf[n] = qpow(fact[n], Mod - 2);
    for(int i = n - 1; i >= 1; i--)
        inf[i] = (inf[i + 1] * (i + 1)) % Mod;
    inf[0] = 1;
}
int C(int a, int b) {
    if(a <= 0 || b < 0)
        return 0;
    int res = fact[a];
    res = (res * inf[b]) % Mod;
    res = (res * inf[a - b]) % Mod;
    return res;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        build(n);
        string s;
        cin >> s;
        int cnt = 0, l = 0;
        for(auto i : s)
            cnt += i - '0';
        if(cnt < k) {
            cout << 0 << endl;
            continue;
        }
        cnt = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1')
                cnt++;
            while(cnt > k) {
                if(s[l] == '1')
                    cnt--;
                l++;
            }
//            cout << l << " " << i << " " << cnt << endl;
            dp[i + 1] = (dp[i + 1] + dp[i]) % Mod;
            if(s[i] == '1') {
                if(cnt < i - l + 1)
                    dp[i + 1] = (dp[i + 1] + C(i - l, cnt)) % Mod;
            }
            else {
                if(cnt > 0)
                    dp[i + 1] = (dp[i + 1] + C(i - l, cnt - 1)) % Mod;
            }
//            cout << dp[i + 1] << endl;
        }
        cout << dp[n] + 1 << endl;
    }
    return 0;
}

/*
 3
 6 2
 101011
 7 4
 1100111
 4 2
 0010
 */