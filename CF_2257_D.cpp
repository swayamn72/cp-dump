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
    cin >> t;
    while(t--){
        ll s,q; cin >> s >> q;
        set<ll> divisors;
        for(ll i=1; i*i<=s; i++){
            if(s%i==0){
                divisors.insert(i);
                divisors.insert(s/i);
            }
        }
        for(auto a : divisors) cout << a << " ";
        cout << "\n";
        while(q--){
            ll x,y; cin >> x >> y;
            
        }
    }
}