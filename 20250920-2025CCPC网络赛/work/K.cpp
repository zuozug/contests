#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << n * (n + 1) / 2 << endl;
    for(int i = n; i >= 1; i--)
        cout << i << " ";
    cout << endl;
    return 0;
}