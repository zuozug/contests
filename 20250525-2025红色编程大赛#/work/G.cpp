#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt += a[i];
    }
    if(cnt < s) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> pre(n + 1, 0), inp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        inp[i] = inp[i - 1] + a[n - i + 1];
    }
//    for(auto i : pre)
//        cout << i << " ";
//    cout << endl;
//    for(auto i : inp)
//        cout << i << " ";
//    cout << endl;
    int ans = 1e9;
    for(int i = 0; i <= n; i++) {
        if(pre[i] > cnt - s)
            break;
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r)/ 2;
            if(inp[mid] < cnt - s - pre[i])
                l = mid + 1;
            else
                r = mid;
        }
        ans = min(ans, i + l);
    }
    cout << ans << endl;
    return 0;
}

/*
 3 1
1 1 0

 9 3
 0 1 0 1 1 1 0 0 1
 */