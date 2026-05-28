#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<ll>> dp(n, vector<ll>(m, 0LL));
    for (auto &a : grid)
        for (auto &b : a)
            cin >> b;
    for (ll i = 0; i < n; i++)
    {
        if (grid[i][0] == '#')
            break;
        dp[i][0] = 1;
    }
    for (ll i = 0; i < m; i++)
    {
        if (grid[0][i] == '#')
            break;
        dp[0][i] = 1;
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j < m; j++)
        {
            if (grid[i][j] == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n - 1][m - 1];
}