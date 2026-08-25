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
    // cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vector<vi> grid(n, vi(m));
        for(auto &a : grid) for(auto &b : a) cin >> b;
        
        if(n==1 && m==1){
            cout << (grid[0][0] == k ? 1 : 0);
            continue;
        }
        ll total = n+m-2;
        ll half = total/2;
        vector<vi> diag(n);

        auto dfs1 = [&](auto &&self, ll r, ll c, ll v, ll steps)->void{
            if(steps==half){
                diag[r].push_back(v);
                return;
            }
            if(r+1<n) self(self,r+1,c,v^grid[r+1][c],steps+1);
            if(c+1<m) self(self,r,c+1,v^grid[r][c+1],steps+1);
        };
        dfs1(dfs1,0,0,grid[0][0],0);
        for(ll i=0; i<n; i++){
            sort(diag[i].begin(), diag[i].end());
        }
        ll res = 0;
        ll rem = total-half;
        auto dfs2 = [&](auto &&self, ll r, ll c, ll v, ll steps)->void{
            if(steps==rem){
                ll target = k^v^grid[r][c];
                auto it1 = lower_bound(diag[r].begin(),diag[r].end(),target);
                auto it2 = upper_bound(diag[r].begin(),diag[r].end(),target);
                res += (it2-it1);
                return;
            }
            if(r-1>=0) self(self,r-1,c,v^grid[r-1][c],steps+1);
            if(c-1>=0) self(self,r,c-1,v^grid[r][c-1],steps+1);
        };
        dfs2(dfs2,n-1,m-1,grid[n-1][m-1],0);
        cout << res;
    }
} 