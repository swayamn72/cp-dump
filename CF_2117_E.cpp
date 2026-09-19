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
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        map<ll,ll> mp;
        ll res = 0;
        for(ll i=0; i<n; i++){
            if(a[i]==b[i]){
                res = i+1;
            }
        }        
        mp[a[n-1]] = n-1; mp[b[n-1]] = n-1;
        for(ll i=n-2; i>=0; i--){
            if(a[i]==a[i+1] || b[i]==b[i+1]){
                res = max(res,i+1);
            }
            
            if(mp.count(a[i]) && mp[a[i]]>i+1){
                res = max(res,i+1);
            }else if(!mp.count(a[i])){
                mp[a[i]] = i;
            }
            if(mp.count(b[i]) && mp[b[i]]>i+1){
                res = max(res,i+1);
            }else if(!mp.count(b[i])){
                mp[b[i]] = i;
            }
        }
        cout << res << "\n";
    }
} 