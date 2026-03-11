#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    map<int, int> x, y, z;
    for(int i = 0; i < n; i++) {
        int xx, yy, zz, xxx, yyy, zzz;
        cin >> xx >> yy >> zz >> xxx >> yyy >> zzz;
        if(xx > xxx)
            swap(xx, xxx);
        if(yy > yyy)
            swap(yy, yyy);
        if(zz > zzz)
            swap(zz, zzz);
        x[xx]++;
        y[yy]++;
        z[zz]++;
        x[xxx + 1]--;
        y[yyy + 1]--;
        z[zzz + 1]--;
    }
    int ans = 0;
    int num = 0;
    for(auto i : x) {
        num += i.second;
        ans = max(ans, num);
    }
    for(auto i : y) {
        num += i.second;
        ans = max(ans, num);
    }
    for(auto i : z) {
        num += i.second;
        ans = max(ans, num);
    }
    cout << ans << endl;
    return 0;
}

/*
 3 2 2 2
 1 1 0 1 1 2
 1 0 1 1 2 1
 0 1 1 2 1 1
 */