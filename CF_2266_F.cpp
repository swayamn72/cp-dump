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
        ll maxm = n+65;
        vi count(maxm+1,0);
        ll total = 0;
        ll maxv = 0;
        for(ll i=0; i<n; i++){
            ll x,y; cin >> x >> y;
            if(x<=maxm){
                count[x]+=y;
            }
            total += y;
            maxv = max(maxv,x);
        }
        auto check = [&](ll target)->bool{
            if(!target) return true;
            ll requirement = 1, used = 0;
            for(ll i=target-1; i>=1; i--){
                ll owned = count[i];
                ll taken = min(requirement,owned);
                used += taken;
                if(used>total) return false;
                ll deficit = requirement-taken;
                requirement += deficit;
                if(requirement>total+1){
                    requirement = total+1;
                }
            }
            used += requirement;
            return used <= total;
        };
        ll l = maxv, r = maxm;
        ll res = maxv;
        while(l<=r){
            ll m = l+(r-l)/2;
            if(check(m)){
                res = m;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        cout << res << "\n";
    }
}