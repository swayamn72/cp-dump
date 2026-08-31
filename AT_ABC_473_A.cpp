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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n+1);
        for(ll i=1; i<=n; i++) cin >> arr[i];
        ll sum = 0;
        for(ll i=n/2+1; i<=n; i++) sum+=arr[i];
        cout << sum;        
    }
} 