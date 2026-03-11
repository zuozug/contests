#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> ans(n + 1, 0);
        for(int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            if(a >= n) {
                ans[0] += a / n;
                ans[n] -= a / n;
                a %= n;
            }
            if(a - 1 + b < n) {
                ans[b]++;
                ans[a + b]--;
            }
            else {
                ans[b]++;
                ans[n]--;
                ans[0]++;
                ans[(a + b - 1) % n + 1]--;
            }
        }
        cout << ans[0] << " ";
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + ans[i];
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
 2
 7 3
 10 0
 4 2
 21 1
 1 2
 200 0
 100 0
 */