#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        int cnt = 0;
        for(int i = 0; i < 31; i++) {
            int num;
            cin >> num;
            if(num < a)
                cnt++;
        }
        if(cnt == 0)
            cout << 32 << endl;
        else if(cnt < 3)
            cout << 16 << endl;
        else if(cnt < 7)
            cout << 8 << endl;
        else if(cnt < 15)
            cout << 4 << endl;
        else if(cnt < 31)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}