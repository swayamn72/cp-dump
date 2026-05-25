#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi arr(n);
        for (auto &x : arr)
            cin >> x;
        sort(arr.begin(), arr.end());
        ll res = LLONG_MAX;
        ll minv = arr[0], maxv = arr[n - 1];
        // for(ll i=0; i<n; i++){
        //     ll val = max(abs(arr[i]-minv),abs(arr[i]-maxv));
        //     res = min(res,val);
        // }
        ll mid = (minv+maxv)/2;
        res = min(res,max(abs(maxv-mid),abs(minv-mid)));
        mid++;
        res = min(res,max(abs(maxv-mid),abs(minv-mid)));
        mid-=2;
        res = min(res,max(abs(maxv-mid),abs(minv-mid)));
        cout << res << "\n";
    }
}