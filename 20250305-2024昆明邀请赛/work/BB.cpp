#include<bits/stdc++.h>

using namespace std;

#define int long long
int n, k;
bool cmp(int a, int b) {
    if(a % k == 0)
        return a > b;
    if(b % k == 0)
        return b > a;
    return (a / k + 1) * k - a < (b / k + 1) * k - b;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int m;
        cin >> m;
        sort(a.begin(), a.end(), cmp);
        for(int i = 0; i < n; i++) {
            int temp = (a[i] / k + 1) * k - a[i];
            if(m >= temp) {
                m -= temp;
                a[i] += temp;
            }
            else
                break;
        }
        a[0] += m;
        int ans = 0;
        for(auto i : a)
            ans += i / k;
        cout << ans << endl;
    }
}
/*
2
3 10
239 141 524
6
2 1
300 100
1000
 */