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
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        
        ll m = n/2+1;
        vector<vi> adj(m);
        vi parent(m,-1);
        ll idx = 1;

        ll curr = 0;
        for(ll i=0; i<n; i++){
            if(s[i]=='('){
                adj[curr].push_back(idx);
                parent[idx] = curr;
                curr = idx;
                idx++;
            }else{
                curr = parent[curr];
            }
        }
        map<ll,ll> mp;
        auto dfs = [&](auto &&self, ll u, ll d)->void{
            mp[d]++;
            for(auto v : adj[u]) self(self,v,d+1);
        };
        dfs(dfs,0,0);
        ll extra = 0;
        ll maxv = 0;
        for(auto a : mp){
            maxv = max(maxv,a.first);
            extra += (a.second-1);
        }
        cout << maxv + min(k,extra) << "\n";
    }
}