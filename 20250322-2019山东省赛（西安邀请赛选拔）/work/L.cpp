#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;

void solve(){
    int n,m;cin>>n>>m;
    vector<int> in(n+1,0);
    vector<vector<int>> e(n+1,vector<int>());

    vector<int> in2(n+1,0);
    vector<vector<int>> e2(n+1,vector<int>());
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        e[x].push_back(y);
        in[y]++;
        e2[y].push_back(x);
        in2[x]++;
    }

    queue<int> q;
    vector<bool> vis1(n+1,0);
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            vis1[i]=1;
        }
    }
    int cnt = 0;
    int tag = (n+1)/2;
    vector<bool> st(n+1,0);
    bool ok=0;
    while(q.size()){
        queue<int> nq;
        vector<int> temp;
        bool f=0;
        while(q.size()){
            auto t=q.front();
            q.pop();
            cnt++;
            temp.push_back(t);
            if(cnt>=tag)f=1;

            for(auto v:e[t]){
                in[v]--;
                if(in[v]==0){
                    nq.push(v);
                    vis1[v]=1;
                }
            }

        }
        if(f==1 && !ok){
            for(auto ti:temp){
                st[ti]=1;
            }
            ok=1;
        }
        q=nq;
    }

    for(int i=1;i<=n;i++){
        if(vis1[i]==0){
            ok=0;
        }
    }

    queue<int> q2;
    vector<bool> vis2(n+1,0);
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            vis2[i]=1;
        }
    }
    int cnt2 = 0;
    int tag2 = (n+1)/2;
    while(q2.size()){
        queue<int> nq;
        vector<int> temp;
        bool f=0;
        while(q2.size()){
            auto t=q2.front();
            q2.pop();
            cnt++;
            temp.push_back(t);
            if(cnt>=tag)f=1;

            for(auto v:e2[t]){
                in2[v]--;
                if(in2[v]==0){
                    nq.push(v);
                    vis2[v]=1;
                }
            }

        }
        if(f==1 && !ok){
            for(auto ti:temp){
                st[ti]=1;
            }
            ok=1;
        }
        q=nq;
    }

    for(int i=1;i<=n;i++){
        if(vis2[i]==0){
            ok=0;
        }
    }


    if(ok){
        for(int i=1;i<=n;i++){
            if(st[i]){
                cout<<1;
            }
            else cout<<0;
        }
        cout<<'\n';
    }
    else {
        for(int i=1;i<=n;i++){
            cout<<0;
        }
        cout<<'\n';
    }
}

int main()
{
    int T = 1;
    cin>>T;

    while(T--)
    {
        solve();
    }
}
/*

 2
 5 4
 1 2
 3 2
 2 4
 2 5
 3 2
 1 1
 2 3

 1
 7 7
 1 3
 2 3
 3 4
 3 6
 4 5
 5 7
 6 7

 1
 5 3
 1 2
 1 3
 4 5
 */