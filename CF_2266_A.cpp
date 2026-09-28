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
    cin >> t;
    while(t--){
        ll n,a,b,c; cin >> n >> a >> b >> c;
        ll res = max({n-a,n-b,n-c});
        cout << res << "\n";        
    }
}