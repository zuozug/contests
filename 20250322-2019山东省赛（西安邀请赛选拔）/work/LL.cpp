#include "bits/stdc++.h"
using namespace std;

int fa[110];

int find(int u)
{
    return u==fa[u]?u:fa[u]=find(fa[u]);
}
int dp[110], dp1[110];
int cnt
void dfs(int u)
{

}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int> > e(n + 1), e1(n + 1);
    vector<int> in(n + 1, 0), st(n + 1, 0), in1(n + 1, 0);
    vector<int> sum(n + 1);

    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sum[i] = 1;
        dp[i] = 0;
        dp1[i] = 0;
    }
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        in[v]++;
        e[u].push_back(v);
        in1[u]++;
        e1[v].push_back(u);
        int x1 = find(u), x2 = find(v);
        if (x1 != x2) {
            sum[x1] = sum[x1] + sum[x2];
            fa[x2] = x1;
        }
    }

    cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        dfs(i);
    }



    string s = "";
    for(int i = 1; i <= n; i++)
    {
        if(st[i])s += '1';
        else s += '0';
    }
    cout<<s<<endl;

}



int main() {
    int t = 1;
    cin>>t;

    while(t--)
    {
        solve();
    }
}
/*

 2
 5 4
 1 2
 3 2
 2 4
 2 5
 3 2
 1 1
 2 3

 1
 7 7
 1 3
 2 3
 3 4
 3 6
 4 5
 5 7
 6 7

 1
 5 3
 1 2
 1 3
 4 5
 */
