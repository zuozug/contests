#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        map<int, int> aa, bb, cc;
        for(int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            aa[a[i]]++;
            bb[b[i]]++;
            cc[c[i]]++;
        }
//        for(auto i : aa)
//            cout << i.first << " " << i.second << endl;
//        cout << "___________________" << endl;
//        for(auto i : bb)
//            cout << i.first << " " << i.second << endl;
//        cout << "___________________" << endl;
//        for(auto i : cc)
//            cout << i.first << " " << i.second << endl;
//        cout << "___________________" << endl;

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
//            cout << aa[a[i]] << " " << bb[b[i]] << " " << cc[c[i]] << endl;
            ans[max({aa[a[i]], bb[b[i]], cc[c[i]]}) - 1]++;
        }
//        for(auto i : ans)
//            cout << i << " ";
//        cout << endl;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cout << sum << " ";
            sum += ans[i];
        }
        cout << endl;
    }
    return 0;
}

/*
2
5
1 1 1
1 1 2
1 1 3
2 3 5
2 2 4
3
1 1 1
2 2 2
3 3 3
 */