#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s[8];
    int a[8];
    for(int i = 0; i < 8; i++) {
        cin >> s[i] >> a[i];
    }
    for(int i = 0; i < 4; i++) {
        int l = i * 2;
        int r = l + 1;
        if(a[l] < a[r]) {
            s[l] = s[r];
            a[l] = a[r];
        }
    }
    for(int i = 0; i < 2; i++) {
        int l = i * 4;
        int r = l + 2;
        if(a[l] < a[r]) {
            s[l] = s[r];
            a[l] = a[r];
        }
    }
    if(a[0] > a[4])
        cout << s[0] << " beats " << s[4] << endl;
    else
        cout << s[4] << " beats " << s[0] << endl;
}
signed main(){
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}


/*
LNG 55
WBG 65
HLE 70
BLG 81
TES 48
T1 80
GEN 60
FLY 50
 */