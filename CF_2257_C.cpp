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
        vi parent(n-1);
        for(auto &x : parent) cin >> x;

        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u = parent[i]-1, v = i+1;
            adj[u].push_back(v);
        }
        ll m; cin >> m;
        vi dams(m); for(auto &x : dams) cin >> x;
        set<ll> s; for(auto a : dams) s.insert(a-1);
        vi res;
        auto dfs = [&](auto &&self, ll u)->ll{
            vi temp;
            for(auto v : adj[u]){
                auto num = self(self,v);
                if(num==1) temp.push_back(v);
            }
            if(s.count(u)&&temp.size()>0){
                for(auto a : temp) res.push_back(a);
            }else if(temp.size()>1){
                for(ll i=0; i<temp.size()-1; i++) res.push_back(temp[i]);
            }
            if(s.count(u)) return 1;
            if(temp.size()==0) return 0;
            return 1;
        };
        dfs(dfs,0);
        cout << res.size() << " ";
        for(auto a : res) cout << a+1 << " ";
        cout << "\n";
    }
} 