#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 110;
int n, k;
int a[N];

bool cmp(int a, int b) {
    return (a / k + 1) * k - a < (b / k + 1) * k - b;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int m;
        cin >> m;
        sort(a, a + n, cmp);
        for(int i = 0; i < n; i++) {
            int temp = (a[i] / k + 1) * k - a[i];
            if(m >= temp) {
                if(a[i] % k != 0) {
                    m -= temp;
                    a[i] += temp;
                }
            }
            else
                break;
        }
        a[0] += m;
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += a[i] / k;
        cout << ans << endl;
    }
}

/*
2
3 10
239 141 526
6
2 1
300 100
1000
 */