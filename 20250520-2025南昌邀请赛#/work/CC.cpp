@陕西师范大学 左祖光
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

const int mod = 998244353;

struct Comb
{
    vector<ll> fact, infact;

    Comb(int n)
    {
        fact.resize(n + 1);
        infact.resize(n + 1);
        init(n);
    }

    ll qmi(ll a, ll k, ll p = mod)
    {
        ll res = 1;
        a %= p;
        while (k)
        {
            if (k & 1)
                res = res * a % p;
            a = a * a % p;
            k >>= 1;
        }
        return res;
    }

    void init(int n)
    {
        fact[0] = infact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i % mod;
            infact[i] = infact[i - 1] * qmi(i, mod - 2) % mod;
        }
    }

    ll A(int a, int b)
    {
        if (a < b)
            return 0;
        return fact[a] * infact[a - b] % mod;
    }

    ll C(int a, int b)
    {
        if (a < b)
            return 0;
        return fact[a] * infact[b] % mod * infact[a - b] % mod;
    }
};

Comb comb(60);

map<string, int> mp = {
        {"A", 1},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"10", 10},
        {"J", 11},
        {"Q", 12},
        {"K", 13}};

void solve()
{
    vector<int> hand(5);
    vi cnt(14, 4);
    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        hand[i] = mp[s];
        cnt[hand[i]]--;
    }
    vector<vvvl> f(6, vvvl(66, vvl(6, vl(66, 0))));
    f[0][0][0][0] = 1;
    for (int r = 1; r <= 13; r++)
    {
        int c = cnt[r];
        vector<vvvl> g(6, vvvl(66, vvl(6, vl(66, 0))));
        for (int i = 0; i <= 5; i++)
        {
            for (int x = 0; x <= i * r; x++)
            {
                for (int j = 0; j <= 5; j++)
                {
                    for (int y = 0; y <= j * r; y++)
                    {
                        ll v0 = f[i][x][j][y];
                        if (!v0)
                            continue;
                        for (int u = 0; u <= c && i + u <= 5; u++)
                        {
                            for (int v = 0; v <= c - u && j + v <= 5; v++)
                            {
                                ll w = comb.C(c, u) * comb.C(c - u, v) % mod;
                                g[i + u][x + u * r][j + v][y + v * r] = (g[i + u][x + u * r][j + v][y + v * r] + v0 * w) % mod;
                            }
                        }
                    }
                }
            }
        }
        f.swap(g);
    }
    sort(hand.begin(), hand.end());
    for (int k = 1; k <= 5; k++)
    {
        ll sum = 0;
        for (int t = k; t < 5; t++)
            sum += hand[t];
        ll W = 0, L = 0, T = 0;
        for (int x = 0; x <= k * 13; x++)
        {
            for (int y = 0; y <= 5 * 13; y++)
            {
                ll cnt = f[k][x][5][y];
                if (!cnt)
                    continue;
                T = (T + cnt) % mod;
                if (x + sum > y)
                    W = (W + cnt) % mod;
                else if (x + sum < y)
                    L = (L + cnt) % mod;
            }
        }
        ll num = (W - L + mod) % mod;
        ll ans = (ll)k * num % mod * comb.qmi(T, mod - 2) % mod;
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    // std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
