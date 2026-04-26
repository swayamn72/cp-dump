#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll val = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return val;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    while (cin >> a >> b)
    {
        ll x, y;
        ll gcdv = gcd(a, b, x, y);
        cout << x << " " << y << " " << gcdv << "\n";
    }
}