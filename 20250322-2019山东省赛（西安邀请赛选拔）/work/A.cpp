#include<bits/stdc++.h>

using namespace std;

#define int long long
signed main()
{
    int t;
    cin >> t;
    while(t--) {
        int y, m, d;
        cin >> y >> m >> d;
        string s;
        cin >> s;
        int yy, mm, dd;
        cin >> yy >> mm >> dd;
        d %= 10;
        dd %= 10;
        int tt = dd - d;
        if(tt < 0)
            tt += 10;
        tt %= 5;
        int day;
        if(s[0] == 'M')
            day = 0;
        else if(s == "Tuesday")
            day = 1;
        else if(s[0] == 'W')
            day = 2;
        else if(s[0] == 'T')
            day = 3;
        else
            day = 4;
        day += tt;
        day %= 5;
        string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        cout << days[day] << endl;
    }
    return 0;
}