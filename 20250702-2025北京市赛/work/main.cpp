#include "bits/stdc++.h"
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int mod = 998244353;
#define all(x) x.begin(),x.end()

void solve(){
    int n;cin>>n;
    vector<int> w(n),c(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<int> lans(n, 0), rans(n, 0);
    vector<int> cnt;
    vector<pair<int, int>> ans;
    for(int i=0;i<n;i++){
        int flag = 0;
        for(int j = 0; j < ans.size(); j++) {
            if(ans[j].second == c[i])
                continue;
            if(__gcd(ans[j].first, w[i]) == 1)
                continue;
            cnt[j]++;
            ans[j] = {w[i], c[i]};
            flag = 1;
            lans[i] = max(lans[i], cnt[j]);
        }
        if(flag == 0) {
            cnt.push_back(1);
            ans.push_back({w[i], c[i]});
            lans[i] = max(lans[i], (int)1);
        }
    }
    cnt.resize(0);
    ans.resize(0);
    for(int i=n - 1;i >= 0;i--){
        int flag = 0;
        for(int j = 0; j < ans.size(); j++) {
            if(ans[j].second == c[i])
                continue;
            if(__gcd(ans[j].first, w[i]) == 1)
                continue;
            cnt[j]++;
            ans[j] = {w[i], c[i]};
            flag = 1;
            rans[i] = max(rans[i], cnt[j]);
        }
        if(flag == 0) {
            cnt.push_back(1);
            ans.push_back({w[i], c[i]});
            rans[i] = max(rans[i], (int)1);
        }
    }
//    for(auto i : lans)
//        cout << i << " ";
//    cout << endl;
//    for(auto i : rans)
//        cout << i << " ";
//    cout << endl;
    int ma = 0;
    for(int i = 0; i < n; i++)
        ma = max(ma, lans[i] + rans[i] - 1);
    cout << ma << endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

/*
 6
 6 6 6 6 6 6
 1 1 2 2 3 3

 10
 2 3 6 10 8 9 6 3 2 10
 1 2 3 2 3 2 4 5 2 1
 */