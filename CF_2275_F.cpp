#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi spf(1e6+1);
    for(ll i=0; i<=1e6; i++) spf[i] = i;
    for(ll i=2; i<=1e6; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<=1e6; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vi> v(n);
        for(ll i=0; i<n; i++){
            ll x = arr[i];
            while(x>1){
                ll s = spf[x];
                ll e = 0;
                while(x%s==0){
                    x /= s; e++;
                }
                if(e%2) v[i].push_back(s);
            }
        }
        map<vi,ll> mp;
        set<ll> s;
        for(ll i=0; i<n; i++){
            for(auto &a : v[i]){
                if(s.count(a)) s.erase(a);
                else s.insert(a);
            }
            if(s.size()<=7) mp[vector<ll>(s.begin(),s.end())]++;
        }
        ll res = 0;
        for(ll i=0; i<n; i++){
            if(mp.count(v[i])) res += mp[v[i]];
        }
        cout << res << "\n";
    }
}