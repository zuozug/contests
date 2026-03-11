#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<int> a;
int n, c;
double solve(int mid) {
    double res = 0;
    double num = 1;
    for(int i = n; i > n - mid; i++) {
        num *= i;
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> c;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = n;
    while(l + 2 <= r) {
        int mid = (r - l) / 3;
        int mid1 = l + mid, mid2 = r - mid;
        if(solve(mid1 <= mid2))
            r = mid2 - 1;
        else
            l = mid2 + 1;
    }
    cout << max(solve(l), solve(r)) << endl;
    return 0;
}