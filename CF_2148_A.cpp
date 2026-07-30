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
        ll x,n; cin >> x >> n;
        if(n%2) cout << x << "\n";
        else cout << 0 << "\n";        
    }
}