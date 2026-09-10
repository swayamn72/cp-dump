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
        ll x,y,k; cin >> x >> y >> k;
        if(x==y){
            cout << 0 << "\n";
            continue;
        }
        ll res = 0;
        for(ll i=0; i<k; i++){
            ll half = (y+1)/2;
            if(x>half){
                ll rem = k-i;
                res += (rem*(y%x));
                break;
            }
            ll ans = y%x;
            res += ans;
            y++; x++;
        }        
        cout << res << "\n";
    }
} 