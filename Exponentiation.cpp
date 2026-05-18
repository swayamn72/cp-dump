#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
ll binexp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        b >>= 1;
        a = (a*a)%mod;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll a,b; cin >> a >> b;
        cout << binexp(a,b) << "\n";        
    }
}