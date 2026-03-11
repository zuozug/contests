#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << 1 + (m - (n + 1) / 2) * 2 << endl;
    }
    return 0;
}