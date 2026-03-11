#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    string s;
    cin >> s;
    map<int, int> p;
    for(int i = 1; i <= 9; i++)
        p[i] = i - 1;
    p[0] = 10;
    int sum = 0;
    for(int i = 1; i < s.size(); i++) {
        sum += abs(p[s[i] - '0'] / 3 - p[s[i - 1] - '0'] / 3) + abs(p[s[i] - '0'] % 3 - p[s[i - 1] - '0'] % 3);
    }
    cout << sum << endl;
    return 0;
}