#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a;
            for (int j = 0; j < m; j++) {
                if (a[j] == '1') {
                    cnt[j]++;
                    break;
                }
            }
        }
        int flag = 0;
        for (auto i : cnt) {
            if (i.second > 1) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

/*
1
2 10
0010100001
0100110000


3
6 7
1001011
0010101
0010110
0101010
1000010
1101000
2 9
001100011
001110011
8 5
00110
10001
00100
00110
11111
11001
00011
11000

*/