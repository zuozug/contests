#include "bits/stdc++.h"
using namespace std;
#define int long long
struct Node {
    vector<int> up, down;
    int inup = 0, indown = 0;
    set<int> cntup, cntdown;
};

int fa[110];

int find(int u)
{
    return u==fa[u]?u:fa[u] = find(fa[u]);
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<Node> a(n);
        for(int i = 0; i < n; i++)
            fa[i] = i;
        while(m--) {
            int l, r;
            cin >> l >> r;
            int x1 = find(l - 1), x2 = find(r - 1);

            if(x1 != x2)
            {
//                cout<<x1<<" "<<x2<<endl;
                fa[x1] = x2;
            }
            a[l - 1].down.push_back(r - 1);
            a[r - 1].indown++;
            a[r - 1].up.push_back(l - 1);
            a[l - 1].inup++;
        }
        for(int i = 0; i < n; i++)
            find(i);
        set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(fa[i]);

        int flag1 = 0;
        vector<int> flag(n, 0);

        for(auto ii : s) {
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (a[i].indown == 0 && find(i) == ii) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                auto temp = q.front();
                flag[temp]++;
                q.pop();
                for (auto i: a[temp].down) {
                    a[i].indown--;
                    a[i].cntdown.insert(temp);
                    for(auto ss : a[temp].cntdown)
                        a[i].cntdown.insert(ss);

                    if (a[i].indown == 0 && find(i) == ii) {
                        q.push(i);
                    }
                }
            }


            for (int i = 0; i < n; i++) {
                if (a[i].inup == 0 && find(i) == ii) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                auto temp = q.front();
                q.pop();
                for (auto i: a[temp].up) {
                    a[i].inup--;
                    a[i].cntup.insert(temp);
                    for(auto ss : a[temp].cntup)
                        a[i].cntup.insert(ss);

                    if (a[i].inup == 0 && find(i) == ii) {
                        q.push(i);
                    }
                }
            }
        }
        for (auto i : flag) {
            if (i == 0)
                flag1 = 1;
        }
        if (flag1 == 1) {
            for (int i = 0; i < n; i++)
                cout << 0;
            cout << endl;
            continue;
        }
//        for(int i = 0; i < n; i++)
//            cout << a[i].cntdown.size() << " ";
//        cout << endl;
//        for(int i = 0; i < n; i++)
//            cout << a[i].cntup.size() << " ";
//        cout << endl;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(a[i].cntup.size() <= (n + 1) / 2 - 1 && a[i].cntdown.size() <= (n + 1) / 2 - 1)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        for(auto i : ans)
            cout << i;
        cout << endl;
    }
    return 0;
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