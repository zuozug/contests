#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, dn, dfn[5010], mi[20][5010];
int dep[5010];
vector<int> e[5010];
int frac[5010];
const int mod = 998244353;

void dfs2(int p, int depth, int fa)
{
    dep[p] = depth;
    for(int x: e[p])
    {
        if(x == fa) continue;
        dfs2(x, depth + 1, p);
    }
}

int get(int x, int y)
{
    return dfn[x] < dfn[y] ? x : y;
}

void dfs(int id, int f)
{
    mi[0][dfn[id] = ++dn] = f;
    for(int it: e[id]) if(it != f) dfs(it, id);
}

int lca(int u, int v)
{
    if(u == v) return u;
    if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
    int d = __lg(v - u++);
    return get(mi[d][u], mi[d][v - (1 << d) + 1]);
}

void init()
{
    frac[0] = 1;
    for(int i = 1; i < 5000; i++)
    {
        frac[i] = frac[i - 1] * i % mod;
    }
}

void solve()
{
    cin >> n;
    dn=0;
    memset(dfn,0,sizeof dfn);
    memset(mi,0,sizeof mi);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0);
    for(int i = 1; i <= __lg(n); i++)
    {
        for(int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << (i - 1))]);
        }
    }
    dfs2(1, 0, 0);
//    cout<<lca(2,6)<<'\n';
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int p = lca(i, j);
            int l = dep[i] + dep[j] - 2 * dep[p] + 1;
            int temp=ans;
            if(l==1)continue;
            if(l == 2)
            {
                ans = (ans + 1) % mod;
            }
            else
            {
                ans = (ans + (frac[l] - frac[l - 1] * 2 %mod + frac[l - 2])%mod+mod) % mod;
            }
//            cout<<i<<" "<<j<<" "<<ans-temp<<'\n';
        }
    }
    for(int i = 1; i <= n; i++)
    {
        e[i].resize(0);
    }
    cout << ans << endl;
}

signed main()
{
    int _;
    cin >> _;
    init();
    while(_--)
    {
        solve();
    }
}