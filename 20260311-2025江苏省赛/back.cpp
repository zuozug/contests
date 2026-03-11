#include<bits/stdc++.h.>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int kmi(int a,int b) {
    int res=1;
    while (b) {
        if (b&1) {
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}

void solve() {

}

signed main() {
    int t=1;
    cin>>t;
    while (t--) {
        solve();
    }
}
/*

5
23
61
62
114514
1919810
 */
