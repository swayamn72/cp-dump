#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,k,l,r; cin >> n >> k >> l >> r;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp1, mp2;
        ll res = 0;
        ll x=0, y=0;
        for(ll i=0; i<n; i++){
            while(x<n && mp1.size()<k){
                mp1[arr[x++]]++;
            }
            while(y<n){
                if(mp2.size()+(mp2.count(arr[y])==0) > k) break;
                mp2[arr[y++]]++;
            }
            if(mp1.size()==k){
                ll left = max(x-1,i+l-1);
                ll right = min(y-1,i+r-1);
                res += max(0LL,right-left+1);
            }
            mp1[arr[i]]--;
            if(mp1[arr[i]]==0) mp1.erase(arr[i]);

            mp2[arr[i]]--;
            if(mp2[arr[i]]==0) mp2.erase(arr[i]);
        }
        cout << res << "\n";
    }
}