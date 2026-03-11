#include<bits/stdc++.h>

using namespace std;
#define all(x) x.begin(),x.end()
#define int long long
const int N=1e5+10;

int tree[N][3];
int n;
int lowbit(int x){return x&-x;}
int add(int x,int k,int id){
    for(int i=x;i<=n;i+= lowbit(i))tree[i][id]+=k;
}
int query(int x,int id){
    int ans=0;
    for(int i=x;i;i-= lowbit(i))ans+=tree[i][id];
    return ans;
}
struct node{
    int a1,b1,c1;
    int a2,b2,c2;
}p[N];
int newa[N];
void solve(){
    cin>>n;
    int a,b,c;cin>>a>>b>>c;
    vector<PII> temp;
    for(int i=1;i<=n;i++){
        cin>>p[i].a1>>p[i].b1>>p[i].c1>>p[i].a2>>p[i].b2>>p[i].c2;
        temp.push_back(p[i].a1);
        temp.push_back(p[i].b1);
        temp.push_back(p[i].c1);
        temp.push_back(p[i].a2);
        temp.push_back(p[i].b2);
        temp.push_back(p[i].c2);
    }
    sort(all(temp));
    temp.erase(unique(all(temp)),temp.end());

    for(auto i:temp){

    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin>>t;

    while(t--) {
        solve();
    }
}
