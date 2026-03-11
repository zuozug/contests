#include "bits/stdc++.h"
using namespace std;
#define int long long
queue<set<int>> q;
struct Node {
    map<set<int>, int> l;
};
struct Cmp {
    bool operator()(const pair<int, set<int>>& a, const pair<int, set<int>>& b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};
Node nullnode;
set<int> nullset;
map<set<int>, Node> node;

void fun(set<int> temp, int num, int cost) {
    set<int> ans;
    for(auto i : temp) {
        int n = i ^ num;
        if(n != 15)
            ans.insert(n);
    }
    if(node.count(ans) == 0) {
        node[ans] = nullnode;
    }
    node[temp].l[ans] = cost;
    node[ans].l[temp] = cost;
}

signed main() {
    int t;
    cin >> t;
    int a[4];
    for(int i = 0; i < 4; i++)
        cin >> a[i];

    string s = "0000000000000000";
    while(true) {
        set<int> temp;
        for(int i = 0; i < 16; i++) {
            if (s[i] == '1')
                temp.insert(i);
        }
        fun(temp, 1, a[0]);
        fun(temp, 2, a[0]);
        fun(temp, 4, a[0]);
        fun(temp, 8, a[0]);
        fun(temp, 12, a[1]);
        fun(temp, 3, a[1]);
        fun(temp, 10, a[2]);
        fun(temp, 5, a[2]);
        fun(temp, 15, a[3]);
        for(int i = 0; i < 16; i++) {
            if(s[i] == '1')
                s[i] = '0';
            else {
                s[i] = '1';
                break;
            }
        }
        if(s == "0000000000000000")
            break;
    }

    cout << 114514 << endl;

    vector<set<int>> vvvvvvv;
    for(int i = 0; i < t; i++) {
        set<int> temp;
        int m;
        cin >> m;
        while(m--) {
            string s1, s2;
            cin >> s1 >> s2;
            int num = (s1[0] - '0') * 8 + (s1[1] - '0') * 4 + (s2[0] - '0') * 2 + (s2[1] - '0');
            temp.insert(num);
        }
        vvvvvvv.push_back(temp);
        if(node.count(temp) == 0) {
            node[temp] = nullnode;
        }
    }



//    for(auto i : node) {
//        for(auto j : i.first)
//            cout << j << " ";
//        cout << "|" << endl;
//        for(auto j : i.second.l) {
//            for(auto k : j.first)
//                cout << k << " ";
//            cout << ":";
//            cout << j.second << endl;
//        }
//    }


    priority_queue<pair<int, set<int>>, vector<pair<int, set<int>>>, Cmp> pq;
    map<set<int>, int> ans;
    set<set<int>> rannode;
    rannode.insert(nullset);
    ans[nullset] = 0;
    for(auto i : node[nullset].l)
        pq.push({i.second, i.first});
    while(!pq.empty()) {
        pair<int, set<int>> temp = pq.top();
        if(rannode.count(temp.second) == 0) {
            rannode.insert(temp.second);
            ans[temp.second] = temp.first;
            for(auto i : node[temp.second].l)
                pq.push({i.second + temp.first, i.first});
        }
        pq.pop();
    }

    for(auto i : vvvvvvv) {
//        for(auto j : i)
//            cout << j << " ";
//        cout << endl;
        cout << ans[i] << endl;
    }
    return 0;
}


/*
2 1000 100 10 1
4
10
00

01
00

00
10

00
01
1
11
11


1 1 1 1 1
16
00
00
00
01
00
10
00
11
01
00
01
01
01
10
01
11
10
00
10
01
10
10
10
11
11
00
11
01
11
10
11
11
 */