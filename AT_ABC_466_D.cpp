#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> v(m, vector<ll>(2));
    for(ll i=0; i<m; i++){
        cin >> v[i][0] >> v[i][1];
    }
    ll res = 0;
    set<ll> su, sv;
    for(ll i=m-1; i>=0; i--){
        ll x = v[i][0], y = v[i][1];
        if(!su.count(x) && !sv.count(y)){
            res++;
        }
        su.insert(x); sv.insert(y);
    }
    cout << res;
}