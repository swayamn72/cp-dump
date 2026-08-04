#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<pair<ll,ll>> seg;
        while(m--){
            ll l,r; cin >> l >> r;
            l--; r--;
            seg.push_back({l,r});
        }    
        ll q; cin >> q;
        vi v(q);
        for(auto &x : v){
            cin >> x;
            x--;
        } 
        ll res = LLONG_MAX;
        ll left = 1, right = q;
        while(left<=right){
            ll mid = left + (right-left)/2;

            vi arr(n,0);
            for(ll i=0; i<mid; i++){
                arr[v[i]] = 1;
            }
            vi pref(n,0);
            pref[0] = arr[0];
            for(ll i=1; i<n; i++) pref[i] = arr[i] + pref[i-1];

            bool flag = false;
            for(auto [l,r] : seg){
                ll len = r-l+1;
                ll ones = pref[r];
                if(l!=0) ones -= pref[l-1];

                if(ones*2>len){
                    flag = true;
                    break;
                }
            }
            if(flag){
                res = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        cout << (res==LLONG_MAX ? -1 : res) << "\n";
    }
}