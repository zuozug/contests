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
        cout << "? 1 " << n << endl;
        int flag;
        cin >> flag;
        if(flag == 1) {
            cout << "! 1 1" << endl;
            continue;
        }
        int l = 1, r = n;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            cout << "? " << mid << " " << n << endl;
            int flag0;
            cin >> flag0;
            if(flag0 == flag)
                l = mid;
            else
                r = mid - 1;
        }
        cout << "! " << l << " 3" << endl;
    }
    return 0;
}