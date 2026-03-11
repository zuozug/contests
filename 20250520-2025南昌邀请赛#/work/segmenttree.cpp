#include<bits/stdc++.h>

using namespace std;

void build(int u, int l, int r)
{
    if(l == r)
    {
        w[u] = a[l];
        return ;
    }

    int mid = l + r >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);

    pushup(u);
}

void update(int u, int l, int r, int L, int R, int cnt)
{
    if(L <= l && r <= R)
    {
        return;
    }
    else if(!(l > R || r < L))
    {

    }

}

void solve(){
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }

    build(1, 1, n);
}
int main()
{
    int t = 1;
    cin>>t;

    while(t--)
    {
        solve();
    }
}