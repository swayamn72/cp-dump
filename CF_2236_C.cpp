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
        ll a,b,x; cin >> a >> b >> x;
        if(b<a) swap(a,b);
        ll res = b-a;
        ll ans = 0;
        while(a!=b){
            b/=x;
            ans++;
            res = min(ans+abs(b-a),res);
            if(a==b) break;
            if(a>b) swap(a,b);
        }        
        
        cout << min(ans,res) << "\n";
    }
}