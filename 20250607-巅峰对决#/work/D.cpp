#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
double pi = acos(-1.0);
signed main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int xc, yc;
    cin >> xc >> yc;
    double l1, l2;
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    l1 = ((double)(xc - xa) * (yb - ya) - (yc - ya) * (xb - xa)) / sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    cin >> xa >> ya >> xb >> yb;
    l2 = ((double)(xc - xa) * (yb - ya) - (yc - ya) * (xb - xa)) / sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    l1 = abs(l1);
    l2 = abs(l2);
    vector<vector<pair<double, double>>> seg(n);
    for(int i = 0; i < n; i++) {
        x[i] -= xc;
        y[i] -= yc;
        double r = sqrt(x[i] * x[i] + y[i] * y[i]);
        double a;
        if(x[i] > 0)
            a = atan((double)y[i] / x[i]);
        else if(x[i] < 0)
            a = pi + atan((double)y[i] / x[i]);
        else {
            if(y[i] >= 0)
                a = pi / 2;
            else
                a = pi * 3 / 2;
        }
        if(r <= l1)
            seg[i].push_back({pi * -1 / 2 - a, pi / 2 - a});
        else {
            seg[i].push_back({acos(l1 / r) - a, pi / 2 - 1});
            seg[i].push_back({pi * -1 / 2 - a, acos(l1 / r) * -1 - a});
        }
        if(r <= l2)
            seg[i].push_back({pi / 2 - a, pi * 3 / 2 - a});
        else {
            seg[i].push_back({pi / 2 - a, acos(l2 * -1 / r) - a});
            seg[i].push_back({pi + acos(l2 / r) - a, pi * 3 / 2 - a});
        }
        for(auto j : seg[i])
            cout << j.first / pi * 180 << " " << j.second / pi * 180 << endl;
        cout << endl;
        vector<pair<double, double>> temp;
        for(auto j : seg[i]) {
            if(j.first < 0) {
                if(j.second < 0)
                    temp.push_back({j.first + pi * 2, j.second + pi * 2});
                else {
                    temp.push_back({j.first + pi * 2,  pi * 2});
                    temp.push_back({0, j.second});
                }
            }
            else if(j.second >= pi * 2) {
                if(j.first >= pi * 2)
                    temp.push_back({j.first - pi * 2, j.second - pi * 2});
                else {
                    temp.push_back({j.first, pi * 2});
                    temp.push_back({0, j.second - pi * 2});
                }
            }
            else
                temp.push_back(j);
        }
        swap(seg[i], temp);
        for(auto j : seg[i])
            cout << j.first / pi * 180 << " " << j.second / pi * 180 << endl;
        cout << endl;
    }
    vector<pair<double, double>> ans;
    ans.push_back({0, pi * 2});
    for(int i = 0; i < n; i++) {
        sort(seg[i].begin(), seg[i].end());
        vector<pair<double, double>> temp;
        for(auto j : seg[i]) {
            for(auto k : ans) {
                double tl = max(j.first, k.first);
                double tr = min(j.second, k.second);
                if(tl >= tr)
                    continue;
                temp.push_back({tl, tr});
            }
        }
        swap(ans, temp);
    }
    double sum = 0;
    for(auto i : ans) {
//        cout<<i.first<<" "<<i.second<<endl;
        sum += i.second - i.first;
    }
    cout << fixed << setprecision(9) << sum / pi * 180 << endl;
    return 0;
}

/*
 4
0 0
4 0
4 4
0 4
2 2
-1 0 -1 1
5 0 5 1

 4
0 0
2 0
2 2
0 2
1 1
2 0 2 1
0 0 0 1

 3
0 0
-3 -2
3 -2
0 -1
1 0 1 -1
-2 0 -2 -1
 */