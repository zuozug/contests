#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[4];
    int res = 1;
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a, a + 4);
    if(a[3] == 0)
        cout << 0 << endl;
    else {
        for(int i = 0; i < 4; i++) {
            if(a[i] != 0)
                res *= a[i];
        }
        cout << res << endl;
    }
    return 0;
}