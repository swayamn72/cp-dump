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
        string s; cin >> s;
        vi res;
        for(ll i=0; i<n; i++){
            if(s[i]=='0') res.push_back(i+1);
        }
        cout << res.size() << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";       
    }
}