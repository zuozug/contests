#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b;

    for(int i = 0;i < n; i++){
        vector<int> temp;
        for(int j = i;j < n;j++){
            int len=j-i+1;
            temp.push_back(a[j]);
            sort(temp.begin(),temp.end());
            b.push_back(temp[(len+1)/2-1]);
        }
    }
    map<int,int> cnt;
    for(auto i :b){
        cnt[i]++;
    }
    int k=n*(n+1)/2;
    k=(k-1)/2+1;
    cout<<k<<'\n';
    for(auto [x,y]:cnt){
        cout<<x<<" "<<y<<' '<<k<<endl;
        if(k-y>0){
            k-=y;
            continue;
        }
        else {
            cout<<x<<endl;
            break;
        }
    }
    return 0;
}
//1 1 1 1 3 1 3 1 1 7