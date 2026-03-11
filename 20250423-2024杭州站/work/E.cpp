#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

struct node{
    int id;
    int l,r;
};
int n,f;
bool cmp(const node& a,const node& b){
//    LL cnt1=max(b.l-a.r,0)+(b.r-b.l);
//    LL cnt2=max(a.l-b.r,0)+(a.r-a.l);
//    if(cnt1<cnt2){
//        return true;
//    }
//    else return false;
}
void solve()
{
    cin>>n>>f;
    vector<node> a(n+1);
    a[0]={0,0,f};
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }
    sort(a.begin()+1,a.end(),cmp);
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans+=max(a[i].l-a[i-1].r,0)+(a[i].r-a[i].l);
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        cout<<a[i].id<<" ";
    }
    cout<<'\n';
}


int main() {
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
/*
 2
 4 2
 3 6
 1 3
 2 7
 5 6
 2 5
 2 4
 6 8

 1
 2 5
 2 6
 6 8

 1
 3 3
 1 5
 2 3
 10 12
 */