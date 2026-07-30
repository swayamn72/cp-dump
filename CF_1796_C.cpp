#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll l,r; cin >> l >> r;
        ll temp = l;
        ll k = 1;
        while(temp*2<=r){
            temp*=2; k++;
        }    
        ll pow2 = (1LL<<(k-1));
        ll ways2 = max(0LL,(r/pow2)-l+1);
        ll res = ways2;
        if(k>1){
            ll pow3 = 3LL*(1LL<<(k-2));
            ll ways3 = max(0LL,(r/pow3)-l+1);
            ways3 = (ways3*(k-1))%mod;
            res = (res + ways3) %mod;
        }
        
        cout << k << " " << res << "\n";
    }
}