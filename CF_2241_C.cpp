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
        ll changes = 0;
        for(ll i=1; i<n; i++){
            if(s[i]!=s[i-1]) changes++;
        }        
        if(changes==1){
            cout << 2 << "\n";
        }else{
            cout << 1 << "\n";
        }
    }
}