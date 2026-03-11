#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const int M = N * 33;
int a[N];

struct node
{
    int si;
    ll l,r;
    ll cnt;
} e[M];

void up(int u)
{
    e[u].si = e[u * 2].si + e[u * 2 + 1].si;
    e[u].l = e[u * 2 + 1].l ^ (e[u * 2].cnt * (e[u * 2 + 1].si % 2)) ^ e[u * 2].l;
    e[u].r = e[u * 2 + 1].r ^ (e[u * 2 + 1].cnt * (e[u * 2].si % 2)) ^ e[u * 2].r;
    e[u].cnt = (e[u * 2].r * (e[u * 2 + 1].si % 2)) ^
               (e[u * 2 + 1].l * (e[u * 2].si % 2))
               ^ e[u * 2].cnt ^ e[u * 2 + 1].cnt;
    return ;
}

void build(int u, int l, int r)
{
    if(l == r)
    {
        e[u].cnt = a[l];
        e[u].l = e[u].r = a[l];
        e[u].si = 1;
        return ;
    }
    int mid = l + r >>1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    up(u);

}

void update(int u, int l, int r, int L, int R, ll cnt)
{
    if(l == r)
    {
        e[u].cnt = cnt;
        e[u].l = e[u].r = cnt;
        return ;
    }
    int mid = l + r >>1;

    if(mid >= L)update(u * 2, l, mid, L, R, cnt);
    else update(u * 2 + 1, mid + 1, r, L, R, cnt);
    up(u);
}

node query(int u, int l, int r, int L ,int R)
{
    if(L <= l && r <= R)
    {
        return e[u];
    }
    else if(!(l > R || r < L))
    {
        int mid = l + r>>1;
        node a = query(u * 2, l, mid, L, R);
        node b = query(u * 2 + 1, mid + 1, r, L, R);

        node now;
        now.si = a.si + b.si;
        now.l = b.l ^ (a.cnt * (b.si % 2)) ^ a.l;
        now.r = b.r ^ (b.cnt * (a.si % 2)) ^ a.r;
        now.cnt = (a.r * (b.si % 2)) ^ (b.l * (a.si % 2)) ^ a.cnt ^ b.cnt;
        return now;
    }
    else
    {
        return node({0,0,0,0});
    }
}


void solve()
{
    int n,q;
    cin>>n>>q;

    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    build(1, 1, n);
    while(q--)
    {
        ll op, x, y;
        cin>>op>>x>>y;

        if(op == 1)
        {
            update(1, 1, n, x, x, y);
        }
        else
        {
            node ans = query(1, 1, n, x, y);
//            cout<<ans.cnt<<endl;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            node ans = query(1 , 1, n, i, j);
            cout<<i<<" "<<j<<" "<<ans.cnt<<endl;
        }
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
3 3
 1 2 3
 2 1 3
 1 1 3
 2 1 3

 5 0
 1 2 3 4 5

 1 1 1
1 2 0
1 3 2
1 4 0
1 5 7
2 1 0
2 2 2
2 3 0
2 4 6
2 5 0
3 1 0
3 2 0
3 3 3
3 4 0
3 5 6
4 1 0
4 2 0
4 3 0
4 4 4
4 5 0
5 1 0
5 2 0
5 3 0
5 4 0
5 5 5
 */