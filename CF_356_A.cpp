#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    set<ll> s; for(ll i=1; i<=n; i++) s.insert(i);
    vector<ll> res(n,0);
    while(m--){
        ll l,r,x; cin >> l >> r >> x;
        auto it = s.lower_bound(l);
        while(it!=s.end() && *it<=r){
            if(*it==x){
                it++;
                continue;
            }
            res[*it-1] = x;
            it = s.erase(it);
        }
    }
    for(auto a : res) cout << a << " ";
}
