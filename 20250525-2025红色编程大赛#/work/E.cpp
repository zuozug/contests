#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            s.insert(i * j);
    }
    for(auto i : s)
        cout << i <<  " ";
    return 0;
}