#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<double> mult;
vector<double> plu;
double ans;
double sum;
int n;
double v;
int pp = 0, pm = 0;
bool cmp(double a, double b) {
    return a > b;
}
void dfs(int p) {
    if(p == n) {
        ans = max(sum / n, ans);
        return;
    }
    if(pp < plu.size()) {
        double temp = v;
        double tempsum = sum;
        v += plu[pp];
        sum += v;
        pp++;
        dfs(p + 1);
        pp--;
        sum = tempsum;
        v = temp;
    }
    if(pm < mult.size()) {
        double temp = v;
        double tempsum = sum;
        v *= mult[pm];
        sum += v;
        pm++;
        dfs(p + 1);
        pm--;
        sum = tempsum;
        v = temp;
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> v;
    for(int i = 0; i < n; i++) {
        char op;
        double x;
        cin >> op >> x;
        if (op == '+')
            plu.push_back(x);
        else
            mult.push_back(x);
    }
    sort(plu.begin(), plu.end(), cmp);
    sort(mult.begin(), mult.end(), cmp);
    ans = v;
    dfs(0);
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}

/*
3 1.000000
+ 1.000000
* 1.100000
+ 0.100000

5 1.000000
+ 1.000000
* 1.050000
* 1.100000
+ 0.100000
+ 0.500000

 */