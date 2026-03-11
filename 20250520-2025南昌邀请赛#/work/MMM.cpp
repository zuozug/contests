#include "bits/stdc++.h"
using namespace std;
#define int long long
int n = 4;
vector<int> path;
set<vector<int>> opset,coinset,op[10];

void build(int p, int l, int r, int op) {
    if(p == n) {
        if(op == 1)
            opset.insert(path);
        else
            coinset.insert(path);
        return;
    }
    for(int i = l; i <= r; i++) {
        path.push_back(i);
        build(p + 1, l, r, op);
        path.pop_back();
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    build(0, 1, 4, 1);
    build(0, 0, 1, 2);
//    for(auto i : opset) {
//        for(auto j : i)
//            cout << j;
//        cout << endl;
//    }
//
//    for(auto i : coinset) {
//        for(auto j : i)
//            cout << j;
//        cout << endl;
//    }

    for(auto i:coinset){
        int k=0;
        for(auto j:i){
            if(j==1)k++;
        }
        op[k].insert(i);
    }


    for(auto a : opset) {
        map<vector<int>, int> cnt;
//        for(int id=0;id<5;id++){
//            cout<<id<<'\n';
        int ttt=0;
        for(auto tt : op[1]) {
            ttt++;
            int cnt1 = 0, cnt2 = 0;
            for(int i = 0; i < 4; i++) {
//                    cout<<tt[i];
                if(a[i]==1){
                    if(tt[i]==0)cnt1++;
                }
                else if(a[i]==2){
                    if(tt[i]==1)cnt1++;
                }
                else if(a[i]==3){
                    if(tt[i]==0)cnt2++;
                }
                else{
                    if(tt[i]==1)cnt2++;
                }
            }
//            cout<<cnt1 <<" "<<cnt2<<'\n';
//                cout<<endl;
            if(cnt1 == cnt2) {
                cnt[a]++;
            }
        }
//            cout<<endl;
        if(cnt[a]==ttt){
            for(auto ai:a){
                cout<<ai;
            }
            cout<<endl;
        }
//        }
//        for(auto [x,y]:cnt){
//            for(auto i:x){
//                cout<<i;
//            }
//            cout<<" "<<y<<endl;
//        }
    }
}