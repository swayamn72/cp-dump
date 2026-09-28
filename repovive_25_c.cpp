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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> v;
        for(ll i=0; i<n; i++){
            ll a,b; cin >> a >> b;
            v.push_back({b,a});
        }
        sort(v.begin(),v.end());
        ll l = 0, r = 2e15;
        ll res = r;
        while(l<=r){
            ll m = l + (r-l)/2;
            ll free = m;
            bool flag = true;
            for(auto [b,a] : v){
                if(b>free){
                    flag = false;
                    break;
                }
                free -= b;
                free += a;
            }
            if(flag){
                res = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        cout << res;
    }
}