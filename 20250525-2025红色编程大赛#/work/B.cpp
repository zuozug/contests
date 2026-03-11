#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n == 2) {
        cout << 2 << endl;
        return 0;
    }
    if(n >= 3)
        ans = n * (n - 1) / (n - 2);
    int temp = n - 3;
    if(temp > 5)
        temp -= ((temp - 5 - 1) / 4 + 1) * 4;
    if(temp == 1)
        ans += 1;
    if(temp == 2)
        ans += 1;
    if(temp == 3)
        ans += 1;
    if(temp == 4)
        ans -= 2;
    cout << ans << endl;
    return 0;
}