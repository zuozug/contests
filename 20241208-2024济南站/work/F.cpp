#include "bits/stdc++.h"
using namespace std;
#define int long long
int Mod = 998244353;
vector<vector<int>> f(30, vector<int>(100100, 0));

int fact[100010], infact[100010];

int qpow(int a, int b) {
    int ans = 1;
    while(b != 0) {
        if(b % 2 == 1) {
            ans *= a;
            ans %= Mod;
        }
        b /= 2;
        a *= a;
        a %= Mod;
    }
    return ans;
}

void init() {
    fact[0] = 1;
    for(int i = 1; i <= 100000; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= Mod;
    }
    infact[100000] = qpow(fact[100000], Mod - 2);
    for(int i = 99999; i >= 0; i--) {
        infact[i] = infact[i + 1] * (i + 1);
        infact[i] %= Mod;
    }
}

int C(int n, int m) {
    int ans = fact[n];
    ans *= infact[m];
    ans %= Mod;
    ans *= infact[n - m];
    ans %= Mod;
    return ans;
}

signed main() {
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        f[1][i] = 1;
    for(int c = 1; c < 29; c++) {
        for(int i = 1; i <= m; i++) {
            for(int j = 2; ; j++) {
                if(i * j > m)
                    break;
                f[c + 1][i * j] += f[c][i];
                f[c + 1][i * j] %= Mod;
            }
        }
    }

    init();
    int ans=0;

    for(int i = 1; i <= min(n, (int)29); i++) {
        for(int j = 1; j <= m; j++) {
            if(m / j - 1 < n - i || n - i < 0)
                continue;
            ans += C(m / j - 1, n - i) * f[i][j];
            ans %= Mod;
        }
    }

    int aans = C(m, n) * n % Mod;
    aans -= ans;
    aans = (aans % Mod + Mod) % Mod;

    cout << aans << endl;
    return 0;
}