#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        ll segments = n-k+1;
        
        ll res = k;
        for(ll i=segments; i>=1; i--){
            res = (res*i)%mod;
        }
        cout << res << "\n";
    }
}