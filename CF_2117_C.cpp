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
        vi arr(n); for(auto &x : arr) cin >> x;
        set<ll> a, b;
        ll res = 0;
        for(ll i=0; i<n; i++){
            a.insert(arr[i]);
            b.insert(arr[i]);
            if(a.size()==b.size()){
                res++;
                b.clear();
            }
        }
        cout << res << "\n";
        // map<ll,ll> mp; 
        // for(auto a : arr) mp[a]++;
        // vi v(n);
        // for(ll i=0; i<n; i++){
        //     v[i] = mp[arr[i]];
        //     mp[arr[i]]--;
        // }       
        // vi pref(n); pref[0] = v[0];
        // for(ll i=1; i<n; i++) pref[i] = min(pref[i-1],v[i]);
        // // for(auto a : v) cout << a << " ";
        // // cout << "\n";
        // // for(auto a : pref) cout << a << " ";
        // // cout << "\n";
        // if(v[0]==1){
        //     cout << 1 << "\n";
        //     continue;
        // }
        // ll curr = 1;
        // for(ll i=1; i<n; i++){
        //     if(pref[i]>1 && arr[i]==arr[0]){
        //         curr++;
        //     }else if(arr[i]==arr[0]){
        //         if(pref[i-1]!=1) curr++;
        //         break;
        //     }
        // }
        // cout << curr << "\n";
    }
} 