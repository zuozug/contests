#include "bits/stdc++.h"
using namespace std;
#define int long long
int cnt = 0;
set<int> x[4], y[4];
int n, m;
void dfs(int p) {
//    cout << p << endl;
    if(p == n * m) {
        cnt++;
        return;
    }
    for(int i = 1; i <= 4; i++) {
        if(x[p / m].count(i))
            continue;
        if(y[p % m].count(i))
            continue;
        x[p / m].insert(i);
        y[p % m].insert(i);
        dfs(p + 1);
        x[p / m].erase(i);
        y[p % m].erase(i);
    }
}
signed main() {
    cin >> n >> m;
    if(n > 4)
        n = 4;
    if(m > 4)
        m = 4;
//    cout << n << " " << m << endl;
    dfs(0);
    cout << cnt << endl;
    return 0;
}