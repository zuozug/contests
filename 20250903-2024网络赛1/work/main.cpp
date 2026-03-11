#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> cc;
    for(int len = 1; len <= n; len++) {
        vector<int> c;
        for (int l = 0; l < n - len + 1; l++) {
            int r = l + len - 1;
//            cout << l << " " << r << endl;
            vector<int> b;
            for (int i = l; i <= r; i++) {
                for (int j = i; j <= r; j++) {
//                    cout << i << " " << j << endl;
                    vector<int> aa;
                    for (int ii = i; ii <= j; ii++)
                        aa.push_back(a[ii]);
                    sort(aa.begin(), aa.end());
                    b.push_back(aa[(aa.size() + 1) / 2 - 1]);
                }
            }
            for (auto i: b)
                cout << i << " ";
            cout << endl;
            sort(b.begin(), b.end());

            c.push_back(b[(b.size() + 1) / 2 - 1]);
        }

        cout << endl;
        for (auto i: c) {
            cout << i << " ";
            cc.push_back(i);
        }
        sort(c.begin(), c.end());
        cout << endl;
    }
    sort(cc.begin(), cc.end());
    sort(a.begin(), a.end());
    cout << a[(a.size() + 1) / 2 - 1] << " ";
    cout << cc[(cc.size() + 1) / 2 - 1] << endl;
    return 0;
}