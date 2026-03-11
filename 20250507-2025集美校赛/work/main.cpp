#include "bits/stdc++.h"
using namespace std;
#define int long long
int fact[10];
int Mod = 1000000007;
int n;
vector<int> solve(int num) {
    vector<int> temp(n + 1);
    for(int i = 1; i < n; i++) {
        int sum = 0;
        sum += (((num + 1) / fact[i + 1] * fact[i]) % Mod) * i * (i + 1) / 2;
        sum %= Mod;
        int left = (num + 1) % fact[i + 1];
        int lefttemp = left / fact[i];
        sum += (((lefttemp - 1) * lefttemp / 2) % Mod) * fact[i];
        sum %= Mod;
        sum += left % fact[i] * lefttemp;
        sum %= Mod;
        temp[i] = sum;
    }
    int sum = 0;
    int left = num + 1;
    int lefttemp = left / fact[n];
    sum += ((((lefttemp - 1) % Mod) * (lefttemp % Mod)) % Mod) / 2 * fact[n];
    sum %= Mod;
    sum += (left % fact[n]) * (lefttemp % Mod);
    sum %= Mod;
    temp[n] = sum;
//    for(auto i : temp)
//        cout << i << " ";
//    cout << endl;
    return temp;
}
signed main() {
    fact[1] = 1;
    for(int i = 2; i <= 9; i++)
        fact[i] = fact[i - 1] * i % Mod;
    int q;
    cin >> n >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        vector<int> ll = solve(l - 1);
        vector<int> rr = solve(r);
        for(int i = 1; i <= n; i++) {
            int temp = rr[i] - ll[i];
            temp = ((temp % Mod) + Mod) % Mod;
            cout << temp;
            if(i < n)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}