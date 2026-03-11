#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    map<pair<int, int>, int> ans;
    cin >> n >> q;
    vector<int> num(n);
    map<int, int> numcnt;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        if(numcnt.count(num[i]))
            continue;
        numcnt[num[i]] = numcnt.size();
    }
    vector<vector<int>> m(numcnt.size());
    for(int i = 0; i < n; i++)
        m[numcnt[num[i]]].push_back(i);
    while(q--) {
        int x, y;
        cin >> x >> y;

        if((!numcnt.count(x) )|| (!numcnt.count(y))) {
            cout << 0 << endl;
            continue;
        }
        x = numcnt[x];
        y = numcnt[y];
        if(x == y) {
            cout << (int)m[x].size() * (m[x].size() - 1) / 2 << endl;
            continue;
        }
        if(ans.count({x, y})) {
            cout << ans[{x, y}] << endl;
            continue;
        }
        if(m[x].size() <= m[y].size()) {
            int cnt = 0;
            for(auto i : m[x]) {
                int p = m[y].end()-upper_bound(m[y].begin(),m[y].end(), i);
//                cout<<p<<endl;
                cnt += p;
            }
            ans[{x, y}] = cnt;
            cout << cnt << endl;
        }
        else {
            int cnt = 0;
            for(auto i : m[y]) {
                int p = upper_bound(m[x].begin(), m[x].end(),i,less<>())-m[x].begin();
//                cout<<p<<endl;
                cnt+=p;
            }
            ans[{x, y}] = cnt;
            cout << cnt << endl;
        }
    }
    return 0;
}