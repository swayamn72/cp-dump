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
        ll n,m; cin >> n >> m;
        vector<vector<ll>> v;
        vi res(n,LLONG_MAX);
        ll inf = LLONG_MAX;
        bool flag = true;
        for(ll k=0; k<m; k++){
            ll a,b,c; cin >> a >> b >> c;
            b--; c--;
            v.push_back({a,b,c});
        }
        
    }
}