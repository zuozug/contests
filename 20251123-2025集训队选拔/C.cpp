#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    if (b % 2 == 0)
        cout << a << 0 << b / 2 << endl;
    else {
        cout << a << 0 << b * 5 << endl;
    }
    return 0;
}