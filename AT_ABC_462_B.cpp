#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<vector<ll>> res(n);
    for(ll i=0; i<n; i++){
        ll k; cin >> k;
        for(ll j=0; j<k; j++){
            ll a; cin >> a;
            res[a-1].push_back(i+1);
        }
    }

    for(auto a : res){
        cout << a.size() << " ";
        for(auto b : a) cout << b << " ";
        cout << "\n";
    }
}