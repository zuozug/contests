#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
set<int> pre;
void solve()
{
    int n;cin>>n;
    if(pre.count(n)){
        puts("impossible");
        return ;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i]=i;
    }
    swap(ans[0],ans[1]);
    for(int i=2;i<n;i++){
        if(pre.count(i)){
            swap(ans[i],ans[i-1]);
        }
    }
//    int re=0;
//    for(auto i:ans){
//        re^=i;
//        if(re==0){
//            cerr<<i;return;
//        }
//    }

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<'\n';
}

int main() {
    int t = 1;
    cin>>t;
    pre.insert(1);
    for(int i=4;i<=1e6;i+=4){
        pre.insert(i);
    }
    while(t--)
    {
        solve();
    }
}

