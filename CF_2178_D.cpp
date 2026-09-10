#include <bits/stdc++.h>
#include <numeric>
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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(k>(n/2)){
            cout << -1 << "\n";
            continue;
        }
        vector<pair<ll,ll>> v;
        for(ll i=1; i<=n; i++) v.push_back({arr[i-1],i});
        sort(v.begin(),v.end());
        if(k==0){
            // cout << "ZERO" << "\n";
            // vi pref(n), suff(n);
            // pref[0] = v[0].first;
            // for(ll i=1; i<n; i++) pref[i] = pref[i-1] + v[i].first;
            // suff[n-1] = v[n-1].first;
            // for(ll i=n-2; i>=0; i--) suff[i] = suff[i+1] + v[i].first;
            // for(auto a : pref) cout << a << " ";
            // cout << "\n";
            // for(auto a : suff) cout << a << " ";
            // cout << "\n";
            // cout << "END" << "\n";
            ll sum = accumulate(arr.begin(),arr.end(),0LL);
            sum -= v[n-1].first;
            if(sum<v[n-1].first){
                cout << -1 << "\n";
                continue;
            }
            vector<pair<ll,ll>> res;
            ll curr = v[n-1].first;
            ll maxv = v[n-1].second;
            ll idx = -1;
            for(ll i=n-2; i>=0; i--){
                curr -= v[i].first;
                if(curr<=0){
                    idx = i;
                    break;
                }
            }
            
            for(ll i=0; i<idx; i++){
                res.push_back({v[i].second,v[i+1].second});
            }
            for(ll i=idx; i<=n-2; i++){
                res.push_back({v[i].second, maxv});
            }
            cout << res.size() << "\n";
        for(auto [a,b] : res) cout << a << " " << b << "\n";
            continue;
        }
        ll toremove = n-k*2;
        vector<pair<ll,ll>> res;
        for(ll i=0; i<toremove; i++){
            res.push_back({v[i+1].second,v[i].second});
        }
        ll ptr1 = toremove, ptr2 = n-1;
        while(ptr1<ptr2){
            res.push_back({v[ptr2--].second,v[ptr1++].second});
        }
        cout << res.size() << "\n";
        for(auto [a,b] : res) cout << a << " " << b << "\n";
    }
} 