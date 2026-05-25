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
        ll n; cin >> n;
        set<ll> s;
        vi res;
        for(ll i=1; i<=2*n; i++){
            if(s.find(i)==s.end()){
                res.push_back(i);
                s.insert(i);
            }
            if(res.size()>1) s.insert(res[res.size()-1]+res[res.size()-2]);
        }
        for(ll i=0; i<n; i++) cout << res[i] << " ";
        cout << "\n";
    }
}