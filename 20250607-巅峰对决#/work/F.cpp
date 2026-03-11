#include <bits/stdc++.h>
using namespace  std;
#define int long long
typedef long long LL;
#define all(x) x.begin(),x.end()
map<int,int> m;
void solve(){
    int n;cin>>n;
    if(n&1){
        int t=(n+1)/2;
        cout<<t<<'\n';
        for(int i=1;i<=t;i++){
            cout<<i<<" ";
        }
        cout<<'\n';
    }
    else {
        int id=m[n];
        bool f=0;
        if(id==0){
            n-=2;
            id=m[n];
            if(id==0){
                cout<<-1<<'\n';
                return ;
            }
            f=1;
        }

        set<int> st;
//        cout<<id<<'\n';
        if(!f){
            for(int i=1,cnt=1;cnt<=id && i<=5e5;i<<=1,cnt++){
                st.insert(i);
            }
            if(st.size()!=id){
                cout<<-1<<'\n';
            }
            else {
                cout<<id<<'\n';
                for(auto i:st){
                    cout<<i<<" ";
                }
                cout<<'\n';
            }
        }
        else {
            st.insert(0);
            for(int i=1,cnt=1;cnt<=id && i<=5e5;i<<=1,cnt++){
                st.insert(i);
            }
            if(st.size()!=id+1){
                cout<<-1<<'\n';
            }
            else {
                cout<<id+1<<'\n';
                for(auto i:st){
                    cout<<i<<" ";
                }
                cout<<'\n';
            }
        }

    }
}

signed main() {
    int T=1;
//    cin>>T;
    int tt=0;
    for(int i=1;i<=5e5;i++){
        tt+=i;
        m[tt]=i;
    }
    while(T--){
        solve();
    }
    return 0;
}
