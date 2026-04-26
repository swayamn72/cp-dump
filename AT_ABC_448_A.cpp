#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    vi arr(n);
    for (auto &x : arr)
        cin >> x;
    ll val = x;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] < val)
        {
            cout << 1 << "\n";
            val = arr[i];
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}