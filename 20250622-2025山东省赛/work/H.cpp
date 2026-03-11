
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define all(x) x.begin(),x.end()
typedef pair<LL,LL> PII;

//vector<int>mp[202020];

struct node{
    int u,v,w;
    int id;
}a[202020];

bool cmp(const node &aa,const node &b){
    return aa.w<b.w;
}
bool cmpda(const node &aa,const node &b){
    return aa.w>b.w;
}
int fa[202020]={0};

void init(int n){
    for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}

void solve(){
    int n,m,k;cin>>n>>m>>k;
    init(n);
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
        a[i].id=i;
    }
    sort(a+1,a+m+1,cmp);
    int cnt=0,ii=1;
    int id=m+1;
    vector<node>t;
    while(cnt<n-1){
        int u=a[ii].u,v=a[ii].v;
        if(find(u)==find(v)){
            ii++;continue;
        }
        t.push_back(a[ii]);
        merge(a[ii].u,a[ii].v);
        cnt++;ii++;
    }
    sort(all(t),cmpda);
    vector<array<int,4>> ans;
    int st=0;
    int ti=0;
    vector<bool> vis(n+1,0);
    for(;ti<t.size() && st<min(k,n-1);ti++){
        int u=min(t[ti].u,t[ti].v);
        int v=max(t[ti].u,t[ti].v);
        if(t[ti].w<=1)break;
        if(vis[u]==0){
            ans.push_back({u,u+1,1,id++});
            vis[u]=1;
            st++;
        }
        else if(vis[v-1]==0){
            ans.push_back({v-1,v,1,id++});
            vis[v-1]=1;
            st++;
        }
        else {
            int temp=u;
            bool f=0;
            while(temp>0){
                if(vis[temp]==0){
                    ans.push_back({temp,temp+1,1,id++});
                    vis[temp]=1;
                    st++;
                    f=1;
                    break;
                }
                temp++;
            }
            if(f)continue;
            temp=u+1;
            while(temp<n){
                if(vis[temp]==0){
                    ans.push_back({temp,temp+1,1,id++});
                    vis[temp]=1;
                    st++;
                    f=1;
                    break;
                }
                temp++;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    for(;ti<t.size();ti++){
        int u=min(t[ti].u,t[ti].v);
        int v=max(t[ti].u,t[ti].v);
        ans.push_back({u,v,t[ti].w,t[ti].id});
    }
    LL sum=0;
    for(auto i:ans){
        sum+=i[2];
    }
    cout<<sum<<endl;
    for(auto i:ans){
        cout<<i[3]<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}

/*
 3
 5 6 2
 1 2 3
 2 3 5
 1 4 7
 4 2 4
 5 4 8
 3 5 1
 4 5 100
 1 2 2
 2 3 0
 2 4 0
 4 1 1
 3 4 3
 3 2 0
 1 2 100
 2 3 100

 */

