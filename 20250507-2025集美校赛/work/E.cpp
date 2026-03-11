#include "bits/stdc++.h"
using namespace std;
#define int long long
int fact[10];
vector<int> transform(int num) {
    vector<int> temp(10);
    for(int i = 9; i >= 1; i--) {
        temp[i] = num / fact[i];
        num %= fact[i];
    }
    return temp;
}
signed main() {
    fact[1] = 1;
    for(int i = 2; i <= 9; i++)
        fact[i] = fact[i - 1] * i;
    int n, q;
    cin >> n >> q;
    for(auto i : transform(100))
        cout << i << " ";
    return 0;
}