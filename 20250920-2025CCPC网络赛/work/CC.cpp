#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<int> a;
int bsearch(int l, int r, int num) {
    while(l < r) {
        int mid = (l + r) / 2;
        if(a[mid] < num)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int ans = 0;
        int n, k;
        cin >> n >> k;
        a.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= k;
        }
        int p = a[0];
        sort(a.begin(), a.end());
        int lp, rp;
        for(int i = 0; i < n; i++) {
            if(a[i] == p) {
                p = i;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            if(a[i] >= (k + 1) / 2) {
                lp = i;
                rp = i;
                break;
            }
        }
        map<int, int> lcnt, rcnt;
        if(p <= lp) {
            while(rp < n && a[rp] <= k - a[p]) {
                rcnt[a[rp]]++;
                rp++;
            }
            rp--;

        }
        else {
            while(lp >= 0 && a[lp] >= k - a[p]) {
                lp--;
            }
            lp++;
        }

    }
    return 0;
}