#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n), b(n);
        for(ll i=0; i<n; i++) cin >> a[i] >> b[i];
        set<ll> s; for(auto x : a) s.insert(x); 
        for(auto x : b) s.insert(x);

        vi freq(s.size()+2);
    }
}