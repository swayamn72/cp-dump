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
        vi arr(n); for(auto &x : arr){cin >> x; x--;}  
        
        vector<bool> vis(n,false); vis[0] = true;       
        vector<bool> canreach0(n,false); canreach0[0] = true;
        for(ll i=1; i<n; i++){
            if(vis[i]) continue;
            ll temp = i;
            vi v;
            while(!vis[temp]){
                v.push_back(temp);
                vis[temp] = true;
                temp = arr[temp];
            }
            sort(v.begin(),v.end());
            bool one = false;
            if(v[0]==0) one = true;
            if(canreach0[temp]) one = true;
            if(one) for(auto a : v) canreach0[a] = true;
        }
        // for(auto a : canreach0) cout << a << " "; cout << "\n";
        vis.assign(n,false);
        for(ll i=0; i<n; i++) if(canreach0[i]) vis[i] = true;

        vi index(n,-1);
        vector<vi> vv;
        auto dfs = [&](auto &&self, ll u, ll &temp, vi &v)->void{
            if(vis[u]){
                temp = index[u];
                return;
            }
            vis[u] = true;
            v.push_back(u);
            self(self,arr[u],temp,v);
        };
        ll group = 0;
        for(ll i=0; i<n; i++){
            if(vis[i]) continue;
            ll temp = -1;
            vi v;
            dfs(dfs,i,temp,v);
            if(temp==-1){
                temp = group++;
                for(auto a : v) index[a] = temp;
                vv.push_back(v);
            }else{
                for(auto a : v){
                    vv[temp].push_back(a);
                    index[a] = temp;
                } 
            }
        }
        vi sizes;
        ll res = 0;
        for(ll i=0; i<n; i++){
            if(canreach0[i]){
                res++;
            }
        }
        if(vv.empty()){
            cout << res << "\n";
            continue;
        }
        for(auto &a : vv) sizes.push_back(a.size());
        sort(sizes.rbegin(),sizes.rend());
        for(ll i=0; i<k; i++){
            if(i==sizes.size()) break;
            res += sizes[i];
        }
        cout << res << "\n";
    }
}