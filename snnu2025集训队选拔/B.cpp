#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    vector<string> ss = {"Cam", "Ord", "Sil", "Dev", "Car", "Per"};
    while (t--) {
        string s;
        int n;
        cin >> s >> n;
        for (int i = 0; i < 6; i++) {
            if (ss[i] == s) {
                cout << ss[(i + n) % 6] << endl;
                break;
            }
        }
    }
    return 0;
}