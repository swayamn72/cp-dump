#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;

        vi prefa(n); prefa[0] = a[0];
        for(ll i=1; i<n; i++) prefa[i] = prefa[i-1] + a[i];

        vi prefb(n); prefb[0] = b[0];
        for(ll i=1; i<n; i++) prefb[i] = prefb[i-1] + b[i];

        if(prefa[n-1]!=prefb[n-1]){
            cout << -1 << "\n";
            continue;
        }
        set<ll> s;
        for(ll i=0; i<n; i++) s.insert(prefa[i]);
        
        ll res = 0;
        for(ll i=0; i<n; i++){
            if(s.count(prefb[i])) res++;
        }
        cout << res << "\n";
    }
}