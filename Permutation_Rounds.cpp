#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr){
        cin >> x; x--;
    } 
    vector<bool> vis(n,false);
    auto dfs = [&](auto &&self, ll u, ll &d)->void{
        if(vis[u]) return;
        vis[u] = true;
        d++;
        ll v = arr[u];
        self(self,v,d);
    };
    vi v;
    for(ll i=0; i<n; i++){
        if(vis[i]) continue;
        ll d = 0;
        dfs(dfs,i,d);
        v.push_back(d);
    }
    // for(auto a : v) cout << a << " ";
    map<ll,ll> primes;
    for(auto a : v){
        for(ll i=2; i*i<=a; i++){
            ll count = 0;
            while(a%i==0){
                a/=i;
                count++;
            }
            if(count>0) primes[i] = max(primes[i],count);
        }
        if(a>1) primes[a] = max(primes[a],1LL);
    }
    ll res = 1;
    for(auto a : primes){
        ll val = a.first;
        for(ll i=0; i<a.second; i++){
            res = (res*val)%mod;
        }
    }
    cout << res;
}