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
        ll n,m; cin >> n >> m;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(m); for(auto &x : b) cin >> x;
        ll turn1 = 0, turn2 = 0;
        for(ll i=0; i<n-1; i++){
            ll next = a[i+1];
            ll curr = a[i];
            turn1 += curr-next+1;
        } 
        turn1 += a[n-1];
        for(ll i=0; i<m-1; i++){
            ll next = b[i+1];
            ll curr = b[i];
            turn2 += curr-next+1;
        }
        turn2 += b[m-1];

        if(turn1>=turn2) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
} 