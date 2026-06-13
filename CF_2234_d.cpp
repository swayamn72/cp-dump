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
        ll n,k; cin >> n >> k;
        string a, b; cin >> a >> b;
        ll aones = 0, azeros = 0, bones = 0, bzeros = 0;
        for(auto x : a){
            if(x=='1') aones++; else azeros++;
        }
        for(auto x : b){
            if(x=='1') bones++; else bzeros++;
        }
        ll cones = 0, czeros = 0;
        for(ll i=0; i<n; i++){
            if(a[i]==b[i]) czeros++; else cones++;
        }      
        ll power = 1;
        while(k>0){
            power*=2;
            k--;
        } 
        power++;
        bool flag = (power%3==2);
        ll div = power/3;
        ll res = 0;
        res += (aones*azeros)*(div);
        if(flag) res += (aones*azeros);
        res += (bones*bzeros)*(div);
        if(flag) res += (bones*bzeros);
        res += (cones*czeros)*div;
        cout << res << "\n";
    }
}