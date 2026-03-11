#include <bits/stdc++.h>

using namespace std;

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        int cnt[30] = {0};
        set<string> acc[30];
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string t, v;
            char p;
            cin >> t >> p >> v;
            //cout << t << " " << p << " " << v << endl;
            if(v == "accepted")
            {
                if(!acc[p - 'A'].count(t))
                {
                    cnt[p - 'A']++;
                    acc[p - 'A'].insert(t);
                }
            }
        }
        int mx = 0;
        char mxp = 0;
        for(int i = 0; i < 26; i++)
        {
            if(mx < cnt[i])
            {
                mx = cnt[i];
                mxp = ('A' + i);
            }
        }
        cout << mxp << endl;
    }
    return 0;
}