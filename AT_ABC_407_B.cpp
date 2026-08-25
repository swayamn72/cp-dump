#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;

    vector<pair<ll,ll>> v;
    for(ll i=1; i<=6; i++){
        for(ll j=1; j<=6; j++) v.push_back({i+j,abs(i-j)});
    }

    while(t--){
        ll x,y; cin >> x >> y;
        ll res = 0;
        for(auto a : v){
            if(a.first>=x || a.second>=y) res++;
        }
        cout << fixed << setprecision(9) << (double)res/36.0;
    }
} 