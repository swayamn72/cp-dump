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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        if(arr[0]==arr[n-1]){
            cout << arr[0] << "\n";
            continue;
        }        
        ll maxv = arr[n-1];
        vi bits(64,0);
        for(auto &a : arr){
            ll i = 0;
            while(a>0){
                if(a&1){
                    bits[i]++;
                }
                i++;
                a/=2;
            }
        }
        ll res = 0;
        ll idx = -1;
        for(ll i=63; i>=0; i--){
            bool on = false;
            if(maxv&(1LL<<i)) on = true;
            if(on && bits[i]!=n){
                idx = i; break;
            }else if(!on && bits[i]!=0){
                idx = i;
                break;
            }
        }
        for(ll i=0; i<=idx; i++) res += (1LL<<i);
        for(ll i=idx+1; i<64; i++){
            if(maxv&(1LL<<i)) res += (1LL<<i);
        }
        cout << res << "\n";
    }
}