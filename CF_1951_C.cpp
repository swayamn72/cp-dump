#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi sortedarr; sortedarr = arr;
        sort(sortedarr.begin(), sortedarr.end());
        map<ll,ll> mp;
        for(ll i=0; i<n; i++){
            if(k==0) break;
            mp[sortedarr[i]] += min(k, m);
            k -= min(k, m);
        }
        vi suffcount(n,0); map<ll,ll> temp;
        for(ll i=n-1; i>=0; i--){
            if(temp.find(arr[i])==temp.end()){
                temp[arr[i]]++; continue;
            } 
            suffcount[i] = temp[arr[i]];
            temp[arr[i]]++;
        }
        ll res = 0; ll buffer = 0;
        for(ll i=0; i<n; i++){
            if(mp.find(arr[i])==mp.end()) continue;
            ll numcount = mp[arr[i]] - (suffcount[i] * m);
            if(numcount < 1) continue;
            res += (arr[i]+buffer)*numcount;
            mp[arr[i]] -= numcount;
            buffer += numcount;
        }
        cout << res << "\n";
    }
}