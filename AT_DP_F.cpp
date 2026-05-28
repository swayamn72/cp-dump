#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0LL));
    vector<vector<ll>> direction(n + 1, vector<ll>(m + 1, 0LL));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                direction[i][j] = 2;
            }
            else if (dp[i - 1][j] < dp[i][j - 1])
            {
                dp[i][j] = dp[i][j - 1];
                direction[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                direction[i][j] = 0;
            }
        }
    }
    string res = "";
    ll currx = n, curry = m;
    while (currx != 0 && curry != 0)
    {
        if (s[currx] == t[curry])
            res += s[currx];
        if (direction[currx][curry] == 2)
        {
            currx--;
            curry--;
        }
        else if (direction[currx][curry] == 1)
        {
            curry--;
        }
        else
        {
            currx--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res;
}
// 2-topleft 0-top 1-left