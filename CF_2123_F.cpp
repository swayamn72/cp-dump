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
        vi res(n+1);
        res[1] = 1;
        map<ll,ll> mp,mp2;
        ll primes = 0;

        vi spf(n+1);
        for(ll i=0; i<=n; i++) spf[i] = i;
        for(ll i=2; i<=n; i++){
            if(spf[i]==i){
                mp[i] = primes;
                mp2[primes] = i;
                primes++;
                for(ll j=i*i; j<=n; j+=i){
                    if(spf[j]==j){
                        spf[j] = i;
                    }
                }
            }
        }
        // cout << primes << "\n";
        // for(auto a : spf) cout << a << " "; cout << "\n";
        vector<vector<ll>> adj(primes);
        
        for(ll i=2; i<=n; i++){
            ll temp = i;
            ll maxv = spf[temp];
            while(temp>1){
                maxv = max(maxv,spf[temp]);
                temp /= spf[temp];
            }
            adj[mp[maxv]].push_back(i);
        }

        for(ll i=0; i<primes; i++){
            ll num = mp2[i];
            if(adj[i].size()==1){
                res[num] = num;
                continue;
            }
            vi &v = adj[i];
            ll prev = v[0];
            for(ll j=1; j<v.size(); j++){
                res[v[j]] = prev;
                prev = v[j];
            }
            res[v[0]] = prev;
        }

        for(ll i=1; i<=n; i++) cout << res[i] << " ";
        cout << "\n";
    }
} 