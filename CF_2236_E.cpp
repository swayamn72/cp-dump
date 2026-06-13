#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        vector<vector<bool>> v(n+1, vector<bool>(n+1,false));
        for(ll i=0; i<n; i++){
            ll minv = arr[i];
            ll maxv = arr[i];
            vector<bool> seen(n+1,false);
            for(ll j=i; j<n; j++){
                if(seen[arr[j]]) break;
                seen[arr[j]] = true;
                minv = min(arr[j],minv);
                maxv = max(arr[j],maxv);
                ll len = j-i+1;
                if(maxv-minv+1 == len){
                    v[minv][maxv] = true;
                }
            }
        }        
        ll res = 0;
        for(ll len = n/2; len>=1; len--){
            for(ll start = 1; start<= n+1-2*len; start++){
                ll firstend = start + len - 1;
                ll secondstart = firstend + 1;
                ll secondend = secondstart + len - 1;
                if(v[start][firstend] && v[secondstart][secondend]){
                    res = len;
                    break;
                }
            }
            if(res!=0) break;
        }
        cout << res << "\n";
    }
}