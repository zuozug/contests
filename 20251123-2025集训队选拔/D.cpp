#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m;
    cin >> m;
    int num = 2;
    for (int i = 1; i < 60; i++) {
        if (num > m) {
            cout << i << endl;
            break;
        }
        num *= 2;
    }
    return 0;
}