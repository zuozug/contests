#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int gold = 0, silver = 0, bronze = 0;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 3 < m && a[i][j] == 'g' && a[i][j + 1] == 'o' && a[i][j + 2] == 'l' && a[i][j + 3] == 'd')
                gold++;
            if (j + 3 < m && a[i][j] == 'd' && a[i][j + 1] == 'l' && a[i][j + 2] == 'o' && a[i][j + 3] == 'g')
                gold++;
            if (i + 3 < n && a[i][j] == 'g' && a[i + 1][j] == 'o' && a[i + 2][j] == 'l' && a[i + 3][j] == 'd')
                gold++;
            if (i + 3 < n && a[i][j] == 'd' && a[i + 1][j] == 'l' && a[i + 2][j] == 'o' && a[i + 3][j] == 'g')
                gold++;

            if (j + 5 < m && a[i][j] == 's' && a[i][j + 1] == 'i' && a[i][j + 2] == 'l' && a[i][j + 3] == 'v' && a[i][j + 4] == 'e' && a[i][j + 5] == 'r')
                silver++;
            if (j + 5 < m && a[i][j] == 'r' && a[i][j + 1] == 'e' && a[i][j + 2] == 'v' && a[i][j + 3] == 'l' && a[i][j + 4] == 'i' && a[i][j + 5] == 's')
                silver++;
            if (i + 5 < n && a[i][j] == 's' && a[i + 1][j] == 'i' && a[i + 2][j] == 'l' && a[i + 3][j] == 'v' && a[i + 4][j] == 'e' && a[i + 5][j] == 'r')
                silver++;
            if (i + 5 < n && a[i][j] == 'r' && a[i + 1][j] == 'e' && a[i + 2][j] == 'v' && a[i + 3][j] == 'l' && a[i + 4][j] == 'i' && a[i + 5][j] == 's')
                silver++;

            if (j + 5 < m && a[i][j] == 'b' && a[i][j + 1] == 'r' && a[i][j + 2] == 'o' && a[i][j + 3] == 'n' && a[i][j + 4] == 'z' && a[i][j + 5] == 'e')
                bronze++;
            if (j + 5 < m && a[i][j] == 'e' && a[i][j + 1] == 'z' && a[i][j + 2] == 'n' && a[i][j + 3] == 'o' && a[i][j + 4] == 'r' && a[i][j + 5] == 'b')
                bronze++;
            if (i + 5 < n && a[i][j] == 'b' && a[i + 1][j] == 'r' && a[i + 2][j] == 'o' && a[i + 3][j] == 'n' && a[i + 4][j] == 'z' && a[i + 5][j] == 'e')
                bronze++;
            if (i + 5 < n && a[i][j] == 'e' && a[i + 1][j] == 'z' && a[i + 2][j] == 'n' && a[i + 3][j] == 'o' && a[i + 4][j] == 'r' && a[i + 5][j] == 'b')
                bronze++;
        }
    }
    cout << bronze << " " << silver << " " << gold << endl;
    return 0;
}

/*
1 4
gold
 */

/*
 2 6
 silver
 revlis
 */

/*
 6 10
 baeaaaaaaa
 razaaaaaaa
 oanaaaaaaa
 naoaeznorb
 zaraaaaaaa
 eababronze
 */