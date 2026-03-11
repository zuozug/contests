#include "bits/stdc++.h"
using namespace std;
#define int long long

bool check(int d, int c, int h, int s, map<char, int> cnt, vector<int> sp) {
    if(cnt['D'] < d) {
        int num = d - cnt['D'];
        if(sp[0] == 1) {
            if(num <= 3)
                sp[0] = 0;
            else if(num == 4) {
                if(sp[4] == 1) {
                    sp[0] = 0;
                    sp[4] = 0;
                }
                else if(sp[5] == 1) {
                    sp[0] = 0;
                    sp[5] = 0;
                }
                else
                    return false;
            }
            else if(num == 5) {
                if(sp[4] == 1 && sp[5] == 1) {
                    sp[0] = 0;
                    sp[4] = 0;
                    sp[5] = 0;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if(num == 1) {
            if(sp[4] == 1)
                sp[4] = 0;
            else if(sp[5] == 1)
                sp[5] = 0;
            else
                return false;
        }
        else if(num == 2) {
            if(sp[4] == 1 && sp[5] == 1) {
                sp[4] = 0;
                sp[5] = 0;
            }
            else
                return false;
        }
        else
            return false;
    }


    if(cnt['C'] < c) {
        int num = c - cnt['C'];
        if(sp[1] == 1) {
            if(num <= 3)
                sp[1] = 0;
            else if(num == 4) {
                if(sp[4] == 1) {
                    sp[1] = 0;
                    sp[4] = 0;
                }
                else if(sp[5] == 1) {
                    sp[1] = 0;
                    sp[5] = 0;
                }
                else
                    return false;
            }
            else if(num == 5) {
                if(sp[4] == 1 && sp[5] == 1) {
                    sp[1] = 0;
                    sp[4] = 0;
                    sp[5] = 0;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if(num == 1) {
            if(sp[4] == 1)
                sp[4] = 0;
            else if(sp[5] == 1)
                sp[5] = 0;
            else
                return false;
        }
        else if(num == 2) {
            if(sp[4] == 1 && sp[5] == 1) {
                sp[4] = 0;
                sp[5] = 0;
            }
            else
                return false;
        }
        else
            return false;
    }


    if(cnt['H'] < h) {
        int num = h - cnt['H'];
        if(sp[2] == 1) {
            if(num <= 3)
                sp[2] = 0;
            else if(num == 4) {
                if(sp[4] == 1) {
                    sp[2] = 0;
                    sp[4] = 0;
                }
                else if(sp[5] == 1) {
                    sp[2] = 0;
                    sp[5] = 0;
                }
                else
                    return false;
            }
            else if(num == 5) {
                if(sp[4] == 1 && sp[5] == 1) {
                    sp[2] = 0;
                    sp[4] = 0;
                    sp[5] = 0;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if(num == 1) {
            if(sp[4] == 1)
                sp[4] = 0;
            else if(sp[5] == 1)
                sp[5] = 0;
            else
                return false;
        }
        else if(num == 2) {
            if(sp[4] == 1 && sp[5] == 1) {
                sp[4] = 0;
                sp[5] = 0;
            }
            else
                return false;
        }
        else
            return false;
    }


    if(cnt['S'] < s) {
        int num = s - cnt['S'];
        if(sp[3] == 1) {
            if(num <= 3)
                sp[3] = 0;
            else if(num == 4) {
                if(sp[4] == 1) {
                    sp[3] = 0;
                    sp[4] = 0;
                }
                else if(sp[5] == 1) {
                    sp[3] = 0;
                    sp[5] = 0;
                }
                else
                    return false;
            }
            else if(num == 5) {
                if(sp[4] == 1 && sp[5] == 1) {
                    sp[3] = 0;
                    sp[4] = 0;
                    sp[5] = 0;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if(num == 1) {
            if(sp[4] == 1)
                sp[4] = 0;
            else if(sp[5] == 1)
                sp[5] = 0;
            else
                return false;
        }
        else if(num == 2) {
            if(sp[4] == 1 && sp[5] == 1) {
                sp[4] = 0;
                sp[5] = 0;
            }
            else
                return false;
        }
        else
            return false;
    }

//    cout << d << " " << c << " " << h << " " << s << endl;
    return true;
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        map<char, int> cnt;
        vector<int> sp(6);
        cin >> n;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            cnt[s[1]]++;
        }
//        for(auto i : cnt)
//            cout << i.first << i.second << endl;
        for(int i = 0; i < 6; i++)
            cin >> sp[i];

        int ans = 0;
        for(int d = 0; d <= 20; d += 5) {
            if(d > n)
                continue;
            for(int c = 0; c <= 20; c += 5) {
                if(d + c > n)
                    continue;
                for(int h = 0; h <= 20; h += 5) {
                    if(d + c + h > n)
                        continue;
                    for(int s = 0; s <= 20; s += 5) {
                        if(d + c + h + s > n)
                            continue;

                        if(check(d, c, h, s, cnt, sp))
                            ans = max(ans, d + c + h + s);
                    }
                }
            }
        }
        cout << ans / 5 << endl;
    }
    return 0;
}


/*
4
5
2H 3H 4H 5H 6D
1 1 1 1 0 0
5
2S 3S 4D 5C 6D
0 0 1 0 1 1
5
2S 3S 4D 5C 6D
0 0 1 0 1 0
13
AS 2S 3S 4S 5H 6H 7H 8H 9H TH JH QH KH
0 0 0 0 0 1

1
10
AH 2D 3D 4D 5D 6D 7D 8D 9D TD
0 0 1 0 0 0
 */