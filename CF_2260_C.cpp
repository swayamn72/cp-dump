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
        ll x,y; cin >> x >> y;
        ll total = x + y;
        ll count = x;
        ll temp = 0;
        for(ll i=35; i>=0; i--){
            if(((1LL<<i)&total)!=0){
                if(temp+(1LL<<i)<=x) temp += (1LL<<i);
            } 
        }
        ll ans = x-temp;
        if(x>=temp) ans = min(ans,x-temp);
        if(y<=temp) ans = min(ans,temp-y);
        // cout << temp << "\n";
        cout << total << " " << ans << "\n";
    }
} 