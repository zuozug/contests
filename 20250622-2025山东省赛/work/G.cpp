#include "bits/stdc++.h"
using namespace std;
#define int long long
bool cmp(int a, int b) {
    return a > b;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            int w, tt;
            cin >> w >> tt;
            a[i] = tt - w;
        }
        sort(a.begin(), a.end(), cmp);
        int ans = a[0];
        for(int i = 1; i < n; i++) {
            if(a[i] >= ans)
                ans--;
            else
                ans = a[i];
        }
        cout << 0 - ans + n << endl;
    }
    return 0;
}