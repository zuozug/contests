#include "bits/stdc++.h"
using namespace std;
#define int long long
int Mod = 998244353;
int qpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b % 2 == 1)
            ans = ans * a % Mod;
        b /= 2;
        a = a * a % Mod;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        int xx = x, yy = y;
        int flag = 1;
        while(yy--) {
            if(xx == 0) {
                flag = 0;
                break;
            }
            xx /= 2;
        }
        if(flag == 1)
            flag = xx % 2;
        int ans = y;
        for(int i = y + 1; i < n; i++) {
            xx = x, yy = i;
            int flagg = 1;
            while(yy--) {
                if(xx == 0) {
                    flagg = 0;
                    break;
                }
                xx /= 2;
            }
            if(flagg == 1)
                flagg = xx % 2;
            if(flagg != flag) {
                ans = i - 1;
                break;
            }
            else
                ans = i;
            if(i >= 70) {
                ans = n - 1;
                break;
            }
        }
        cout << ((qpow(2, ans + 1) - 1) % Mod + Mod) % Mod << endl;
    }
    return 0;
}

/*
 2 2
 1 1
 2 0

 3 1
 2 2
 */