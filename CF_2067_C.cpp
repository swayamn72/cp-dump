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
        ll n; cin >> n;    
        ll res = -1;  
        for(ll i=0; i<=9; i++){
            string s = to_string(n-i);
            ll val = 0;
            for(auto a : s){
                if(a<='7'){
                    val = max(val,(ll)a-'0');
                }
            }
            if(i>=7-val){
                res = i;
                break;
            }
        }
        cout << res << "\n";
    }
}