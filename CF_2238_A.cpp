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
        ll n,c; cin >> n >> c;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        bool needed = false;
        ll res = 0;
        for(ll i=0; i<n; i++){
            if(b[i]>a[i]){
                needed = true;
                break;
            }
            res += (a[i]-b[i]);
        }
        bool flag = true;
        ll ans = c;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(ll i=0; i<n; i++){
            if(b[i]>a[i]){
                flag = false;
                break;
            }
            ans += (a[i]-b[i]);
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        if(!needed) ans = min(ans,res);
        cout << ans << "\n";
    }
}