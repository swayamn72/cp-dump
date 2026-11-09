#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n+1,0);
        ll orsum = 0; for(ll i=1; i<=n; i++) orsum |= i;
        vi bits(30,0);
        ll xorsum = 0;
        for(ll i=n; i>=1; i--){
            ll two = 2*i;
            ll newxor = xorsum^two;
            ll oldxor = xorsum^i;
            if(newxor>=oldxor){
                xorsum = newxor;
                arr[i] = 1;
            }else{
                xorsum ^= i;
            }
        }
        // cout << orsum << " " << xorsum << "\n";
        // if(xorsum>=2*orsum){
        //     cout << "YES" << "\n";
        // }
        for(ll i=1; i<=n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
}