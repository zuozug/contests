#include "bits/stdc++.h"
using namespace std;
#define int long long
bool cmpid(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> a(n - 2, vector<pair<int, int>>(3));
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> a[i][j].first;
                a[i][j].second = j;
            }
            sort(a[i].begin(), a[i].end());
        }
        int flag = 1;
        map<int, int> cnt;
        map<int, int> ans;
        if(n % 2 == 0) {
            for(int i = 0; i < n - 2; i++) {
                if(a[i][0].first != 1) {
                    flag = 0;
                    break;
                }
                if(a[i][2].first - a[i][1].first != 1) {
                    flag = 0;
                    break;
                }
                cnt[a[i][2].first]++;
                if(cnt[a[i][2].first] > 2) {
                    flag = 0;
                    break;
                }
                if(cnt[a[i][2].first] == 1)
                    ans[i] = a[i][2].first;
                else
                    ans[i] = n - a[i][2].first + 1;
            }
        }
        else {
            for(int i = 0; i < n - 2; i++) {
                if(a[i][0].first != 1) {
                    flag = 0;
                    break;
                }
                if(a[i][1].first == a[i][2].first) {
                    if(a[i][1].first != n / 2) {
                        flag = 0;
                        break;
                    }
                    cnt[a[i][1].first + 1]++;
                    if(cnt[a[i][1].first + 1] > 1) {
                        flag = 0;
                        break;
                    }
                    else
                        ans[i] = 1 + a[i][1].first;
                }
                else {
                    if(a[i][2].first - a[i][1].first != 1) {
                        flag = 0;
                        break;
                    }
                    cnt[a[i][2].first]++;
                    if(cnt[a[i][2].first] > 2) {
                        flag = 0;
                        break;
                    }
                    if(cnt[a[i][2].first] == 1)
                        ans[i] = a[i][2].first;
                    else
                        ans[i] = n - a[i][2].first + 1;
                }
            }

        }
        if(flag == 0)
            cout << "No" << endl;
        else {
            vector<array<int,3>> res;
            for(int i = 0; i < n - 2; i++) {
                sort(a[i].begin(),a[i].end(),cmpid);
                vector<int> temp(3);
                temp[0] = 1;
                temp[1] = ans[i];
                temp[2] = temp[i] + 1;

                do{
                    int flagg = 1;
                    for(int j = 0; j < 3; j++) {
                        if(a[i][j].first != min(abs(temp[j] - temp[(j + 1) % 3]), n - abs(temp[j] - temp[(j + 1) % 3]))) {
                            flagg = 0;
                            break;
                        }
                    }
                    if(flagg == 1) {
                        res.push_back({temp[0],temp[1],temp[2]});
                        break;
                    }
                }
                while(next_permutation(temp.begin(),temp.end()));
            }

            if(res.size()==n-2){
                cout << "Yes" << endl;
                for(auto i:res)
                    cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
            }
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
/*
 3
 3
 1 1 1
 4
 1 1 1
 1 2 1
 6
 3 1 2
 1 2 1
 1 3 2
 1 2 1
 */