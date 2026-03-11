#include<bist/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
const int M = N * 32;

struct node
{

}e[N];

void build(int u, int l, int r)
{
    if(l == r)
    {
        return;
    }
    int mid = l + r >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    up(u);
}

int update(int u,int l, int r, int L, int R, int cnt)
{
    if(L <= l && r <= R)
    {
        return;
    }
    else if(!(l > R || r < L)) {
        int mid = l + r >> 1;
        update(u * 2, l, mid, L, R, cnt);
        update(u * 2 + 1, mid + 1, r, L, R, cnt);
        up(u);
    }
}


int query(int u, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
    {
        return;
    }
    else if(!(l > R || r < L)) {
        int mid = l + r >> 1;
        update(u * 2, l, mid, L, R, cnt);
        update(u * 2 + 1, mid + 1, r, L, R, cnt);
        up(u);
    }
    else
    {

    }
}

void solve()
{

}


int main() {
    int t = 1;
//    cin>>t;
    while(t--)
    {
        solve();
    }
}
