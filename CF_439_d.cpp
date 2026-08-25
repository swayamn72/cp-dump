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
        ll n,m; cin >> n >> m;
        vi arr1(n); for(auto &x : arr1) cin >> x;
        vi arr2(m); for(auto &x : arr2) cin >> x;
        sort(arr1.begin(),arr1.end());
        sort(arr2.rbegin(),arr2.rend());
        auto func = [&](ll x)->ll{
            ll ans = 0;
            for(auto a : arr1){
                if(a<x) ans += (x-a);
                else break;
            }
            for(auto a : arr2){
                if(a>x) ans += (a-x);
                else break;
            }
            return ans;
        };
        ll res = LLONG_MAX;
        ll l = 0, r = 1e9;
        while(r-l>2){
            ll m1 = l + (r-l)/3;
            ll m2 = r - (r-l)/3;
            if(func(m1)>func(m2)){
                l = m1+1;
            }else{
                r = m2-1;
            }
            
        }
        for(ll i=l; i<=r; i++){
            res = min(res,func(i));
        }
        cout << res;
    }
} 