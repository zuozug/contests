#include "bits/stdc++.h"
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int mod = 998244353;
#define all(x) x.begin(),x.end()

bitset<1010> a[1010], ra[1010], b[1010], rb[1010], c[1010], rc[1010];

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            a[i][j] = t;
            ra[j][i] = t;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            int t;
            cin >> t;
            c[i][j] = t;
            rc[i][j] = t;
        }
    }
    for(int i = 0; i < m; i++)
    {
        b[i] = ~b[i];
    }
    for(int i = 0; i < p; i++)
    {
        rb[i] = ~rb[i];
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