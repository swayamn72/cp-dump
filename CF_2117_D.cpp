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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll y = 2*arr[0]-arr[1];
        if(y%(n+1)!=0){
            cout << "NO" << "\n";
            continue;
        }
        y/=n+1;
        ll x = y-arr[0]+arr[1];
        if(x<0 || y<0){
            cout << "NO" << "\n";
            continue;
        }
        bool flag = true;

        for(ll i=0; i<n; i++){
            ll val = x*(i+1) + (n-i)*y;
            if(val!=arr[i]) flag = false;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
} 