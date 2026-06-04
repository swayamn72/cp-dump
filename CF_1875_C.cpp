#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        n%=m; ll res = 0, i = 0;
        while(i<35 && n>0){
            res += n;
            n = (n*2)%m;
            i++;
        }
        if(n==0) cout << res << "\n";
        else cout << -1 << "\n";
    }
}