#include "bits/stdc++.h"
using namespace std;
#define int long long
int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(gcd(n, m) != 1)
            cout << "No" << endl;
        else {
            cout << "Yes" << endl;
            for(int i = 0; i < n; i++)
                cout << (1 + i * m) % (n * m) << " ";
            cout << endl;
            for(int i = 0; i < m; i++)
                cout << (1 + i * n) % (n * m) << " ";
            cout << endl;
        }
    }
    return 0;
}