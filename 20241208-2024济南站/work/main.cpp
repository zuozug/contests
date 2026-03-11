#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
int ans1 = 0, ans2 = 0;
map<pair<int, int>, pair<int, int>> mmr;
pair<int, int> solve(int l, int r) {
    if(l == r)
        return {0, a[l]};
    if(mmr.count({l, r}) != 0)
        return mmr[{l, r}];
    if(r - l == 1)
        return mmr[{l, r}] = {min(a[l], a[r]), max(a[l], a[r])};
    pair<int, int> ansl, ansr;
    if(a[l + 1] >= a[r]) {
        pair<int, int> temp = solve(l + 2, r);
        ansl = {temp.first + a[l + 1], temp.second + a[l]};
    }
    else {
        pair<int, int> temp = solve(l + 1, r - 1);
        ansl = {temp.first + a[r], temp.second + a[l]};
    }
    if(a[l] >= a[r - 1]) {
        pair<int, int> temp = solve(l + 1, r - 1);
        ansr = {temp.first + a[l], temp.second + a[r]};
    }
    else {
        pair<int, int> temp = solve(l, r - 2);
        ansr = {temp.first + a[r - 1], temp.second + a[r]};
    }
//    cout << l << " " << r << ":" << endl;
//    cout << ansl.first << " " << ansl.second << " " << ansr.first << " " << ansr.second << endl;
    if(ansl.second >= ansr.second)
        return mmr[{l, r}] = ansl;
    else
        return mmr[{l, r}] = ansr;
}
signed main(){
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n - 1;
    if(a[l] >= a[r]) {
        ans1 += a[l];
        l++;
    }
    else {
        ans1 += a[r];
        r--;
    }
    cout << ans1 + solve(l, r).first << " " << ans2 + solve(l, r).second << endl;
    return 0;

}
