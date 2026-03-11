#include <bits/stdc++.h>
using namespace  std;
#define int long long
typedef long long LL;
#define all(x) x.begin(),x.end()
void solve(){
    int n;cin>>n;
    vector<int> f(n+1),in(n+1,0);
    vector<vector<int>> e1(n+1,vector<int>());
    vector<vector<int>> e2(n+1,vector<int>());
    map<int,array<int,2>> m;
    for(int i=1;i<=n;i++){
        cin>>f[i];
        e1[i].push_back(f[i]);
        e2[f[i]].push_back(i);
        in[f[i]]++;
    }
    queue<int> q;
    vector<int> st1(n+1,0);
    vector<int> st2(n+1,0);
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            st1[i]=1;
            st2[i]=1;
        }
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto v:e1[t]){
            in[v]--;
            if(in[v]==0){
                q.push(v);
                st1[v]=1;
                st2[v]=1;
            }
        }
    }
    queue<array<int,3>> q1;
    vector<int> st(n+1,0);
    set<pair<int,int>> s;
    for(int i=1;i<=n;i++){
        if(st2[i]==0) {

            set<int> huan;
            q.push(i);
            st1[i] = 1;
            st[i] = 1;
            huan.insert(i);
            int cnt = 1;
            while (q.size()) {
                auto t = q.front();
                q.pop();
                for (auto v: e1[t]) {
                    if (st1[v] == 0) {
                        huan.insert(v);
                        cnt++;
                        q.push(v);
                        st1[v] = 1;
                        st[v] = 1;
                    }
                }
            }
            for (auto hi: huan) {
                m[hi] = {0, cnt};
            }

            for (auto v: e2[i]) {
                if (st2[i] == 1) {
                    s.insert({i, cnt});
                }
            }
        }
    }

    for(auto si:s){
        q1.push({si.first,1,si.second});
        st[si.first]=1;
    }

    while(q1.size()){
        auto [id,step,d]=q1.front();
        q1.pop();
        m[id]={step,d};
        for(auto v:e2[id]){
            if(st[v]==0){
                q1.push({v,step+1,d});
                st[v]=1;
            }
        }
    }

    for(auto [x,y]:m){
        cout<<x<<" "<<y[0]<<" "<<y[1]<<'\n';
    }
    map<int,int> ccnt;
    for(auto [x,y]:m){
        ccnt[y[1]]=0;
        if(y[0]>0){
            ccnt[y[1]]++;
        }
    }


    int query;cin>>query;
//    map<int,array<int,2>> ans;

    for(auto [x,y]:ccnt){
        cout<<x<<" "<<y<<'\n';
    }
    while(query--){
        int a,b;cin>>a>>b;
        if(a==b){
            cout<<n<<'\n';
            return ;
        }
        int ans=0;
        int T=abs(a-b);
        for(auto [x,y]:ccnt){
            if(T%x==0)ans+=min({a,b,y});
        }
        cout<<ans<<'\n';
    }

}
signed main() {
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
6
1 1 4 5 1 4
5
1 919810
19 19810
191 9810
1919 810
19198 10

 */