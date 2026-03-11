#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int x = 0, y = 0;
        int ans = 0;
        for(auto i : s) {
            if(i == 'U')
                y++;
            else if(i == 'D')
                y--;
            else if(i == 'L')
                x--;
            else
                x++;
            ans = max(ans, abs(x) + abs(y));

        }
        x *= k - 1;
        y *= k - 1;
        for(auto i : s) {
            if(i == 'U')
                y++;
            else if(i == 'D')
                y--;
            else if(i == 'L')
                x--;
            else
                x++;
            ans = max(ans, abs(x) + abs(y));
        }
        cout << ans << endl;
    }
    return 0;
}