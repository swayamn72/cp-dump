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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi freq(n+2,0);
        ll curr = 0;
        for(ll i=0; i<n; i++){
            freq[arr[i]]++;
            curr += (i*arr[i]);
        }
        vi count(n+2,0);
        ll currcount = 0;
        for(ll i=n; i>=1; i--){
            currcount += freq[i];
            count[i] = currcount;
        }
        ll sum = 0;
        for(ll i=1; i<=n; i++){
            ll val = count[i];
            if(val>0){
                ll first = n-val;
                ll last = n-1;
                sum += val*(first+last)/2;
            }
        }
        ll dist = sum - curr;
        ll res = 0;
        for(ll i=0; i<n; i++){
            ll idx = arr[i];
            ll val = count[idx];
            ll ans = i-n+val;
            res = max(res,ans);
        }
        cout << dist + res << "\n";
    }
}