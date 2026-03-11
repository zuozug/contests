#include "bits/stdc++.h"
using namespace std;
#define int long long
int cnt[4];
vector<int> m[4] = {{0, 1, 2, 3}, {1, 2, 3, 0}, {2, 3, 0, 1}, {3, 0, 1, 2}};
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        cnt[num]++;
    }
    int ans = 1e18;
    for(int i = 0; i < 4; i++) {
        int sum = 0;
        for(int j = 0; j < 4; j++)
            sum += m[i][j] * cnt[j];
//        cout << sum << endl;
        while(sum % 4 != i)
            sum++;
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}