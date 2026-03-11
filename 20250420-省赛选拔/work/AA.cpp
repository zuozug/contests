#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int fa[100010];
int find(int u)
{
    if(u == fa[u])return u;
    return find(fa[u]);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        fa[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        if (find(a[i]) != find(i))
        {
            fa[a[i]] = i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout<<find(i)<<" ";
    }
    cout<<endl;
    set<int> s;
    for(int i = 1; i <= n; i++)
    {
        s.insert(find(i));
    }
    cout<<s.size() - 1<<endl;
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

/*
 5
 1
 1
 2
 1 2
 3
 1 3 2
 4
 1 3 2 4
 5
 3 4 5 2 1
 */