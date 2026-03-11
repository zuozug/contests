#include "bits/stdc++.h"
using namespace std;
#define int long long
bool cmp(int a, int b){
    return a > b;
}
signed main() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = x - y;
    }
    sort(a.begin(), a.end(), cmp);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(h <= 0)
            break;
        h += a[i];
        if(h <= 0)
            break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}