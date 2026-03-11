#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;
const LL inf=0x3f3f3f3f3f3f3f3f;
vector<PII> e[510];
LL g[510][510];
LL dis[510];
bool st[510];
LL w[510];
int n,m;

void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    memset(st,0,sizeof st);
    memset(w,0,sizeof w);
    int tag;cin>>tag;
    for(int i=1;i<n;i++){
        cin>>w[i];
    }
    priority_queue<array<LL,3>,vector<array<LL,3>>,greater<array<LL,3>>> q;
    q.push({0,1,1});
    dis[1]=0;
    while(q.size()){
        auto [d,u,step]=q.top();
        q.pop();

        if(st[u])continue;
        st[u]=1;
        for(auto [v,ww]:e[u]){
            if(dis[v]>d+ww+w[step]){
                dis[v]=d+ww+w[step];
                q.push({dis[v],v,step+1});
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<'\n';
//    cout<<dis[tag]<<'\n';
}

void solve()
{
    memset(g,0x3f,sizeof g);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        LL u,v,ww;cin>>u>>v>>ww;
        g[u][v]=min(g[u][v],ww);
        g[v][u]=min(g[v][u],ww);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(g[i][j]!=inf)e[i].push_back({j,g[i][j]});
                if(g[j][i]!=inf)e[j].push_back({i,g[j][i]});
            }

        }
    }

    int q;cin>>q;
    while(q--){
        dijkstra();
    }
}

int main()
{
    int t = 1;
//    cin>>t;
    while(t--)
    {
        solve();
    }
}

/*
 4 5
 1 2 1
 2 3 1
 2 4 1
 3 4 1
 1 4 3
 2
 4 0 0 0
 4 0 2 0
 */