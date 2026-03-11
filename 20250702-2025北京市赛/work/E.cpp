#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<double> x(n), y(n);
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        if(bb == 0) {
            double xx = (double)cc / aa * -1;
            double a = aa, b = bb, c = cc;
            double l = -1e9, r = 1e9;
            while(r - l > 1e-8) {
                double y1 = l + (r - l) / 3, y2 = r - (r - l) / 3;
                double mi1 = 0, mi2 = 0;
                for(int i = 0; i < n; i++) {
                    mi1 = max(mi1, sqrt((x[i] - xx) * (x[i] - xx) + (y[i] - y1) * (y[i] - y1)));
                    mi2 = max(mi2, sqrt((x[i] - xx) * (x[i] - xx) + (y[i] - y2) * (y[i] - y2)));
                }
                if(mi1 > mi2)
                    l = y1;
                else
                    r = y2;
            }
            double mi = 0;
            for(int i = 0; i < n; i++)
                mi = max(mi, sqrt((x[i] - xx) * (x[i] - xx) + (y[i] - l) * (y[i] - l)));
            cout << fixed << setprecision(9) << mi << endl;
            continue;
        }
        double a = aa, b = bb, c = cc;
        double l = -1e9, r = 1e9;
        while(r - l > 1e-8) {
            double x1 = l + (r - l) / 3, x2 = r - (r - l) / 3;
            double y1 = (a * x1 + c) / b * -1, y2 = (a * x2 + c) / b * -1;
            double mi1 = 0, mi2 = 0;
            for(int i = 0; i < n; i++) {
                mi1 = max(mi1, sqrt((x[i] - x1) * (x[i] - x1) + (y[i] - y1) * (y[i] - y1)));
                mi2 = max(mi2, sqrt((x[i] - x2) * (x[i] - x2) + (y[i] - y2) * (y[i] - y2)));
            }
            if(mi1 > mi2)
                l = x1;
            else
                r = x2;
        }
        r = (a * l + c) / b * -1;
        double mi = 0;
        for(int i = 0; i < n; i++)
            mi = max(mi, sqrt((x[i] - l) * (x[i] - l) + (y[i] - r) * (y[i] - r)));
        cout << fixed << setprecision(9) << mi << endl;
    }
    return 0;
}


/*
 3
 4
 0 0
 0 1
 1 0
 1 1
 1 -1 0
 3
 0 1
 0 2
 0 3
 1 0 0
 3
 -1 1
 0 1
 1 1
 0 1 1
 */