#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll w,h,d; cin >> w >> h >> d;
    ll n; cin >> n;
    ll res1, res2, res3;
    res1 = gcd(n,w);
    n /= gcd(n,w);
    res2 = gcd(n,h);
    n /= gcd(n,h);
    res3 = gcd(n,d);
    n /= gcd(n,d);
    if(n!=1){
        cout << -1 << "\n";
        return 0;
    }
    cout << res1-1 << " " << res2-1 << " " << res3-1;
}