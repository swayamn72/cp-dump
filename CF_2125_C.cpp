#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(ll x) {
    if (x <= 0) return 0;
    ll res = x;
    res -= (x/2 + x/3 + x/5 + x/7);
    res += (x/6 + x/10 + x/14 + x/15 + x/21 + x/35);
    res -= (x/30 + x/42 + x/70 + x/105);
    res += (x/210);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;  cin >> t;
    while(t--){
        ll l, r; cin >> l >> r;
        cout << solve(r)-solve(l-1) << "\n";
    }
    return 0;
}