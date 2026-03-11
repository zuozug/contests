#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    cin >> x;
    if (x >= 0) {
        vector<int> ans;
        while (x) {
            ans.push_back(x % 2);
            x /= 2;
        }
        while (ans.size() < 64)
            ans.push_back(0);
        reverse(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i;
        cout << endl;
    }
    else {
        if (x == -9223372036854775808) {
            cout << 1;
            for (int i = 0; i < 63; i++)
                cout << 0;
            cout << endl;
        }
        else {
            x = abs(x);
            vector<int> ans;
            while (x) {
                ans.push_back(x % 2);
                x /= 2;
            }
            while (ans.size() < 63)
                ans.push_back(0);
            ans.push_back(1);
            for (int i = 0; i < 63; i++) {
                if (ans[i] == 0)
                    ans[i] = 1;
                else
                    ans[i] = 0;
            }
            ans[0]++;
            for (int i = 0; i < 63; i++) {
                if (ans[i] == 2) {
                    ans[i] = 0;
                    ans[i + 1]++;
                }
            }
            if (ans[63] == 2)
                ans[63] = 1;
            reverse(ans.begin(), ans.end());
            for (auto i : ans)
                cout << i;
            cout << endl;
        }
    }
    return 0;
}