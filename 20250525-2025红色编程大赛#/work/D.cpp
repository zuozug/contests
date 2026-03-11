#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<int> fa;
int find(int x) {
    if(fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    fa.resize(n + 1);
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    vector<int> u(m), v(m);
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        fa[find(u[i])] = find(v[i]);
    }
    map<int, int> cnt1, cnt2;
    for(int i = 1; i <= n; i++)
        cnt1[find(i)]++;
    for(int i = 0; i < m; i++)
        cnt2[find(u[i])]++;
    if(cnt1 == cnt2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

/*
 3 2
 2 3
 2 3

 5 5
 1 2
 2 3
 3 4
 3 5
 1 5
 */