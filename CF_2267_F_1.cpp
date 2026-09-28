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
        ll n,q; cin >> n >> q;
        vi arr(n); for(auto &x : arr) cin >> x;
        // sort(arr.begin(),arr.end());
        ll ans0 = *max_element(arr.begin(),arr.end()) - *min_element(arr.begin(),arr.end());
        // for(auto a : arr) cout << a << " ";
        // cout << "\n";
        vi v;
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                ll val = arr[i]^arr[j];
                v.push_back(val);
            }
        }
        sort(v.begin(),v.end());
        v.resize(n);
        ll ans1 = v[n-1] - v[0];
        vi res; res.push_back(ans0); res.push_back(ans1);
        ll idx = 2;
        ll even = -1, odd = -1;
        while(true){
            vi v2;
            for(ll i=0; i<n; i++){
                for(ll j=i+1; j<n; j++){
                    ll val = v[i]^v[j];
                    v2.push_back(val);
                }
            }
            sort(v2.begin(),v2.end());
            v2.resize(n);
            ll ans = v2[n-1] - v2[0];
            res.push_back(ans);
            if(v2==arr){
                if(idx%2){
                    odd = ans;
                    even = res[idx-1];
                }else{
                    even = ans;
                    odd = res[idx-1];
                }
                break;
            }
            arr = v;
            v = v2;
            idx++;
        }
        while(q--){
            ll x; cin >> x;
            if(x<res.size()){
                cout << res[x] << "\n";
            }else{
                if(x%2) cout << odd << "\n";
                else cout << even << "\n";
            }
        }
    }
}