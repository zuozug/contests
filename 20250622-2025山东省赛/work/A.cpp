#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, vector<pair<int, int>>> node;
        for(int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            node[a].push_back({b, i});
        }
        queue<int> q;
        for(auto it = node.rbegin(); it != node.rend(); it++) {
            auto temp = it->second;
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());
//            cout << it->first << endl;
//            for(auto i : temp)
//                cout << i.first << " ";
//            cout << endl;
            int ma = q.size();
            int id = -1;
            for(int i = 0; i < temp.size(); i++) {
                if(min((int)q.size(), temp[i].first) + i + 1 > ma) {
                    ma = min((int)q.size(), temp[i].first) + i + 1;
                    id = i;
                }
            }
//            cout << ma << endl;
            if(id != -1) {
                while (q.size() > temp[id].first)
                    q.pop();
                for (int i = 0; i <= id; i++)
                    q.push(temp[i].second);
            }
        }
        cout << q.size() << endl;
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}

/*
 2
 6
 3 0
 4 0
 3 1
 5 3
 1 2
 3 1
 2
 1 1
 1 0


 1
 9
 5 4
 5 3
 5 0
 4 0
 3 4
 3 2
 3 1
 1 4
 1 2
 */