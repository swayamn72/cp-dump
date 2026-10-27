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
        ll n,m; cin >> n >> m;
        vi a(n), b(m);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        multiset<ll> s; for(auto x : a) s.insert(x);

        vi res(m);
        for(ll i=0; i<m; i++){
            ll curr = b[i];
            auto it = s.upper_bound(curr);
            if(it==s.begin()){
                res[i] = -1;
                continue;
            }
            it--;
            res[i] = *it;
            s.erase(it);
        }
        for(auto a : res) cout << a << "\n";
    }
}