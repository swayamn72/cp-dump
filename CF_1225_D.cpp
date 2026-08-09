#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll maxn = 1e5+1;
    vi spf(maxn);
    for(ll i=0; i<maxn; i++) spf[i] = i;
    for(ll i=2; i<maxn; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<maxn; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    // for(ll i=0; i<20; i++) cout << spf[i] << " ";
    ll n,k; cin >> n >> k;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll res = 0;
    map<vector<pair<ll,ll>>,ll> mp2;
    for(auto a : arr){
        map<ll,ll> mp;
        while(a>1){
            mp[spf[a]]++;
            a/=spf[a];
        }
        vector<pair<ll,ll>> v, need;
        for(auto a : mp){
            if(a.second%k==0){
                continue;
            }else{
                ll rem = a.second%k;
                ll comp = k-rem;
                v.push_back({a.first,rem});
                need.push_back({a.first,comp});
            }
        }
        res += mp2[need];
        mp2[v]++;
    }
    cout << res << "\n";
}