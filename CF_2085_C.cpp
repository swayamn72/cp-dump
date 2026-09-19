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
        ll x,y; cin >> x >> y;
        if(x==y){
            cout << -1 << "\n";
            continue;
        }        
        if(x<y) swap(x,y);
        ll b = 64 - __builtin_clzll(x);
        ll k = (1LL<<(b+1)) - x;
        cout << k << "\n";
    }
}