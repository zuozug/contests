#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(m <=30 && (1LL << m) - 1 < n)
            cout << -1 << endl;
        else {
            int ans = 1e18;
            for(int i = 1; i <= min(m, (int)30); i++) {
                int range = (1LL << i) - 1;
                int left = 0;
                if(i < m)
                    left = (n - range - 1) / (m - i) + 1;
                if(left > range + 1)
                    continue;
                ans = min(ans, max(left, (int)(1LL << (i - 1))));
            }
            cout << ans << endl;
        }
    }
    return 0;
}

/*
 2
 40 6
 16 4
 */