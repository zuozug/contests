#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 n, m, t;
int a[21], b[26][26];

int f[21][1 << 20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'a';
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    for (int i = 0; i <= n; i++)
        f[i][(1 << n) - 1] = 0;
    for (int mask = (1 << n) - 2; mask >= 0; mask--)
        for (int i = 0; i <= n; i++) {
            if ((i == n && mask == 0) || (mask >> i & 1)) {
                int bef = __builtin_popcount(mask & ((1 << (i + 1)) - 1));
                int c = 0;
                i64 ans = 1e18;
                for (int j = 0; j < n; j++) {
                    if (mask >> j & 1) c++;
                    else {
                        i64 cost = b[a[i]][a[j]];
                        ans = min(ans, f[j][mask | (1 << j)] + cost + t * abs(c - bef));
                    }
                }
                f[i][mask] = ans;
            }
        }

    cout << f[n][0] + t * n;
}