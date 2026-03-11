#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        cout << 1;
    for(int i = 0; i < n - k; i++)
        cout << 4;
    cout << endl;
    return 0;
}