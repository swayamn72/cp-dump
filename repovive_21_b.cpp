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
        vi arr(n-1); for(auto &x : arr) cin >> x;
        vector<bool> vis(n+1,false);
        for(ll i=0; i<n-2; i++){
            vis[max(arr[i],arr[i+1])] = true;
        }
        bool flag = true;
        for(ll i=3; i<=n; i++) if(!vis[i]) flag = false;
        if(flag) cout << 2;
        else cout << 0;
    }
} 