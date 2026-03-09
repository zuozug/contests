#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        if (n - k <= 0) {
            if (a == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        if (2 * (n - k) >= n) {
            map<char, int> aa, bb;
            for (auto i : a)
                aa[i]++;
            for (auto i : b)
                bb[i]++;
            if (aa == bb)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else {
            int flag = 1;
            for (int i = n - k; i < k; i++) {
                if (a[i] != b[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                cout << "NO" << endl;
                continue;
            }
            map<char, int> aa, bb;
            for (int i = 0; i < n - k; i++) {
                aa[a[i]]++;
                bb[b[i]]++;
            }
            for (int i = k; i < n; i++) {
                aa[a[i]]++;
                bb[b[i]]++;
            }
            if (aa == bb)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

/*
7
16 1
tommarvoloriddle
iamlordvoldemort
13 3
LightofShadow
ShadowofLight
12 6
abracadabraa
avadakedavra
5 3
accio
cicao
5 4
lumos
molus
4 3
uwjt
twju
4 3
kvpx
vxpk
*/