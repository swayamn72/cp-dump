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
        ll n,s,l; cin >> n >> s >> l;
        s--;
        ll curr = 0;
        vi v = {0};
        for(ll i=0; i<n-1; i++){
            ll x; cin >> x;
            curr += x;
            v.push_back(curr);
        }
        // for(auto a : v) cout << a << " ";
        // cout << "\n";
        ll res = 0;
        for(ll i=s; i<n; i++){
            ll temp = 0;
            ll ans = 1;
            if(v[i]-v[s]<=l){
                ans = (i-s+1);
            }
            temp += (2*(v[i]-v[s]));
            res = max(res,ans);
            if(temp>l) continue;
            for(ll j=s-1; j>=0; j--){
                temp += (v[j+1]-v[j]);
                if(temp>l) break;
                ans++;
            }
            res = max(res,ans);
        }
        for(ll i=s; i>=0; i--){
            ll temp = 0;
            ll ans = 1;
            if(v[s]-v[i]<=l){
                ans = (s-i+1);
            }
            temp += (2*(v[s]-v[i]));
            res = max(res,ans);
            if(temp>l) continue;
            for(ll j=s+1; j<n; j++){
                temp += (v[j]-v[j-1]);
                if(temp>l) break;
                ans++;
            }
            res = max(res,ans);
        }
        cout << res << "\n";
    }
} 