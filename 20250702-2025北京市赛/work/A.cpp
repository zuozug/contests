#include <bits/stdc++.h>

using namespace std;

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s[0] != s[s.length() - 1])
        {
            cout << "empty" << endl;
        }
        else {
            int mi = INT_MAX;
            int cur = 1;
            bool f = false;
            for (int i = 1; i < s.length(); i++)
            {
                if(s[i] == s[i - 1])
                {
                    cur++;
                }
                else
                {
                    if(s[i - 1] == s[0])
                    {
                        mi = min(mi, cur);
                    }
                    else if(cur > 1)
                    {
                        f = true;
                    }
                    cur = 1;
                }
            }
            if(cur)
            {
                mi = min(mi, cur);
            }
            if(f)
            {
                cout << "empty";
            }
            else
            {
                for(int i = 0; i < mi; i++)
                {
                    cout << s[0];
                }
            }
            cout << endl;
        }
    }
    return 0;
}

/*
4
2
01
4
0010
5
10011
5
11011
 * */