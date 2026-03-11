#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        double p, L, R;
        double rr, cc;
        cin >> rr >> cc >> p >> L >> R;
        vector<double> c(n + 1), r(n + 1, L);
        c[0] = cc;
        r[0] = rr;
        for(int i = 0; i < k; i++) {
            int pp;
            double vv;
            cin >> pp >> vv;
            r[pp] = vv;
        }
        double ans = 0;
        for(int i = 1; i <= n; i++) {
            c[i] = p * c[i - 1] + ((double)1.0 - p) * r[i - 1];
            ans += c[i] - r[i];
        }
        cout << fixed << setprecision(9) << ans << endl;
    }
    return 0;
}

/*
 2
 3 2
 5 6 0.5 1 10
 1 4
 2 5
 5 2
 10 5 0.5 3 12
 1 4
 3 6
 */