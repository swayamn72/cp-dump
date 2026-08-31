#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll c; cin >> c;
        ll a = c * (1LL << 24);
        ll b = a + c;
        cout << a << " " << b << "\n";     
    }
} 