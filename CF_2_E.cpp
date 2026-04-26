#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double left = 0, right = 1e5;
    double c;
    cin >> c;
    for (ll i = 0; i < 100; i++)
    {
        double m = left + (right - left) / 2;
        if ((m * m + sqrt(m)) < c)
        {
            left = m;
        }
        else
        {
            right = m;
        }
    }
    cout << fixed << setprecision(7) << left << "\n";
}