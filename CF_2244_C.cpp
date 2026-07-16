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
        ll n,x,y; cin >> n >> x >> y;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll gcdv = gcd(x,y);
        bool flag = true;
        for(ll i=1; i<=n; i++){
            ll val = arr[i-1];
            ll diff = abs(val-i);
            if(diff==0) continue;
            if(diff%gcdv!=0){
                flag = false;
                break;
            } 
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}