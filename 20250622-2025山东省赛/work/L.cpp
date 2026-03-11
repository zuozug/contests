#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<char, int> ma;
    ma['O'] = 0;
    ma['B'] = 1;
    ma['A'] = 2;
    ma['F'] = 3;
    ma['G'] = 4;
    ma['K'] = 5;
    ma['M'] = 6;
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int aa = ma[a[0]] * 10 + a[1] - '0', bb = ma[b[0]] * 10 + b[1] - '0';
        if(aa < bb)
            cout << "hotter" << endl;
        else if(aa == bb)
            cout << "same" << endl;
        else
            cout << "cooler" << endl;
    }
    return 0;
}

/*
 5
 O2 O7
 M9 M2
 G2 G2
 A0 B9
 F8 K1
 */