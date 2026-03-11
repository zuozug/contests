#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod= 998244353;
const int N=2e5+10;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        if(a[0]==b[0])puts("YES");
        else puts("NO");
    }
    return 0;
}