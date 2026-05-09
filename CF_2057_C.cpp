#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ll a = 96, b = 95, c = 94;
    // ll a = 7, b = 16, c = 11;
    // ll res = a^b; res += (b^c); res += (a^c);
    // cout << res;
    ll t; cin >> t;
    while(t--){
        ll l,r; cin >> l >> r;
        ll val = 1, sum = 0;
        ll ans = -1;
        for(ll i=0; i<32; i++){
            if((l&val) != (r&val)){
                ans = val;
                sum = 0;
            }else{
                if((l&val) != 0) sum += val;
            }
            val*=2;
        }
        ll res1 = sum+ans;
        ll res2 = res1-1;
        ll res3;
        for(ll i=l; i<=r; i++){
            if(i!=res1 && i!=res2){
                res3=i;
                break;
            }
        }
        cout << res1 << " " << res2 << " " << res3 << endl;
    }
}
// 1 0 1 1 0 
// 0 0 1 1 0