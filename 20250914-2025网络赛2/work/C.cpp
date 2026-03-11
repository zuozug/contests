#include "bits/stdc++.h"
using namespace std;
#define int long long
int f[7];
bool check(int mid) {
    int sum = 0;
    int a = min(mid, f[0]), b = min(mid, f[1]), c = min(mid, f[3]);
    sum += a + b + c;
    if(a + b + f[2] < 2 * mid)
        sum += f[2];
    else
        sum += 2 * mid - a - b;
    if(a + c + f[4] < 2 * mid)
        sum += f[4];
    else
        sum += 2 * mid - a - c;
    if(b + c + f[5] < 2 * mid)
        sum += f[5];
    else
        sum += 2 * mid - c - b;
    sum += f[6];
    if(sum >= 3 * mid)
        return true;
    return false;
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int s;
        cin >> s;
        for(int i = 0; i < 7; i++)
            cin >> f[i];
        int l = 0, r = s;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}