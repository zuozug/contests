#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n * m);
        vector<int> cnt(n, 0);
        int mx=0;
        for(int i = 0; i < n * m; i++)
            cin >> a[i];
        for(int i = 0; i < n * m; i++) {
            int r = (a[i] - 1) / m;
            cnt[r]++;
            mx=max(cnt[r],mx);
//            cout << i - cnt[r] + 1 << " " << n - cnt[r] << endl;
            if(i - mx + 1 >= m - mx && k >= m - mx) {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}

/*
3
 3 5 2
 1 4 13 6 8 11 14 2 7 10 3 15 9 5 12
 2 3 0
 1 6 4 3 5 2
 2 3 1000000000
 1 2 3 4 5 6
 */