#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, m;
int cnt = 0;
vector<int> path;
void dfs(int p) {
    if(p == n) {
        int flag = 1;
        for(int i = 0; i < path.size() - 1; i++) {
            if(path[i] == path[i + 1]) {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            return;
        int temp = path[0];
        for(int i = 1; i < path.size(); i++)
            temp = temp ^ path[i];
        if(temp == 0) {
            cnt++;
//            for(auto i : path)
//                cout << i << " ";
//            cout << endl;
        }
        return;
    }
    for(int i = 0; i < (1 << m); i++) {
        path.push_back(i);
        dfs(p + 1);
        path.pop_back();
    }
}
signed main() {
    int T=1;
    cin>>T;
    while(T--){
        path.clear();
        cnt=0;
        cin >> n >> m;
        dfs(0);
        cout << cnt << endl;
    }

    return 0;
}