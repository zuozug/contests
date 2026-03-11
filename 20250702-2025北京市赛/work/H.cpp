#include "bits/stdc++.h"
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int mod = 998244353;
#define all(x) x.begin(),x.end()

int a[1010][1010], c[1010][1010], b[1010][1010];

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            b[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            int t = c[i][j];
            if(t == 0)
            {
                for(int k = 0; k < m; k++)
                {
                    if(a[i][k] == 1)
                    {
                        b[k][j] = 0;
                    }
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

/*
3 2 3
1 0
1 1
1 0
0 0 0
0 1 0
0 0 0


3 2 3
 1 0
 1 1
 1 0
 1 0 0
 0 1 0
 0 0 1
 */