#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
struct node{
    int l,r,len;
};
bool cmp(const node&a,const node &b){
    return a.len>b.len;
}
void solve()
{
    int n,k;cin>>n>>k;
    vector<node> a(k);
    for(int i=0;i<k;i++){
        cin>>a[i].l>>a[i].r;
        a[i].len=a[i].r-a[i].l+1;
//        cout<<a[i].l<<" "<<a[i].r<<'\n';
    }
    int root=0;
    vector<int> ans(n+1);
    sort(a.begin(),a.end(),cmp);
    int mx=a[0].len;
    for(int i=1;i<k;i++){
        if(a[i].len==mx){
            puts("IMPOSSIBLE");
            return ;
        }
    }
    root = a[0].l;

    for(int i=0;i<k;i++){
        if(a[i].l==root){
            ans[root]=0;
        }
        else ans[a[i].l]=root;

        for(int j=a[i].l+1,fa=a[i].l;j<=a[i].r;fa=j,j++){
            ans[j]=fa;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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
 3
 12 5
 1 5
 9 11
 7 8
 6 6
 12 12
 4 3
 1 1
 4 4
 2 3
 2 2
 1 1
 2 2
 */
