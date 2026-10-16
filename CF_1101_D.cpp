#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll maxn = 2e5;
    vector<ll> spf(maxn+1);
    for(ll i=0; i<=maxn; i++) spf[i] = i;
    for(ll i=2; i<=maxn; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<=maxn; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    // for(ll i=0; i<=20; i++) cout << spf[i] << " ";
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll res = 0;
        auto dfs = [&](auto &&self, ll u, ll p)->vector<pair<ll,ll>>{
            if(arr[u]>1) res = max(res,1LL);
            
            vector<pair<ll,ll>> primes;
            ll temp = arr[u];
            while(temp>1){
                primes.push_back({spf[temp],1LL});
                ll val = spf[temp];
                while(temp%val==0) temp/=val;
            }
            if(primes.empty()) return {};
            vi first(primes.size(),0);
            vi second(primes.size(),0);
            for(auto v : adj[u]){
                if(v==p) continue;
                vector<pair<ll,ll>> vv = self(self,v,u);
                for(auto [a,b] : vv){
                    for(ll i=0; i<primes.size(); i++){
                        if(a==primes[i].first){
                            if(b>first[i]){
                                second[i] = first[i];
                                first[i] = b;
                            }else if(b>second[i]){
                                second[i] = b;
                            }
                        }
                    }
                }
            }
            for(ll i=0; i<primes.size(); i++){
                res = max(res,1+first[i]+second[i]);
                primes[i].second += first[i];
            } 
            return primes;
        };
        dfs(dfs,0,-1);
        cout << res << "\n";
    }
}