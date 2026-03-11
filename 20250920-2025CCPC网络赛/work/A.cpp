#include "bits/stdc++.h"
using namespace std;
#define int long long
typedef pair<int,int> PII;
int n, m;
bool check(PII a){
    if(a.first>=0 && a.first<=n && a.second>=0 && a.second<= m){
        return true;
    }
    return false;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) {
        cin >> n >> m;
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= m; y++) {
                int cnt = 0;
                for (int dx = -n; dx <= n; dx++) {
                    for (int dy = -m; dy <= m; dy++) {
                        PII a, b, c, d;
                        a = {x, y};
                        b = {x + dx, y + dy};
                        c = {x + dx - dy, y + dy + dx};
                        d = {x - dy, y + dx};
                        if (check(a) == 0 || check(b) == 0 || check(c) == 0 || check(d) == 0)continue;
                        if (b != c && c != d && b != d) {
                            if (a != b && a != c && a != d) {
                                cnt++;
                            }
                        }
                    }
                }
                cout << cnt << " ";
            }
            cout << endl;
        }
    }
    return 0;
}