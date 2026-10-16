#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

ll dp[5001][5001][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,b; cin >> n >> b;
        vi c(n), d(n), x(n);
        x[0] = -1;
        vector<vi> adj(n);
        for(ll i=0; i<n; i++){
            cin >> c[i] >> d[i];
            if(i>0){
                cin >> x[i]; x[i]--;
                adj[x[i]].push_back(i);
            } 
        }
        // dp[i][j][k]  i-current node  j-no. of nodes  
        // k : 0-no coupon  1-coupon
        for(ll i=0; i<=n; i++){
            for(ll j=0; j<=n; j++){
                for(ll k=0; k<2; k++) dp[i][j][k] = 1e18;
            }
        }
        auto dfs = [&](auto &&self, ll u, ll p)->ll{
            ll sz = 1;
            dp[u][0][0] = 0;
            dp[u][1][0] = c[u];
            dp[u][1][1] = c[u]-d[u];

            for(auto v : adj[u]){
                if(v==p) continue;
                ll childsz = self(self,v,u);
                
                // merge u and v
                vector<vi> temp(sz+childsz+1,vi(2,1e18));
                for(ll j=0; j<=sz; j++){
                    for(ll k=0; k<=childsz; k++){

                        // u coupon not used -> v coupon not used
                        if(dp[u][j][0]!=1e18 && dp[v][k][0]!=1e18){
                            temp[j+k][0] = min(temp[j+k][0],dp[u][j][0]+dp[v][k][0]);
                        }

                        // u coupon used -> v can or cannot
                        if(dp[u][j][1]!=1e18){
                            ll minv = min(dp[v][k][0],dp[v][k][1]);
                            if(minv!=1e18){
                                temp[j+k][1] = min(temp[j+k][1],dp[u][j][1]+minv);
                            }
                        }
                    }
                }
                sz += childsz;
                for(ll j=0; j<=sz; j++){
                    dp[u][j][0] = temp[j][0];
                    dp[u][j][1] = temp[j][1];
                }
            }
            return sz;
        };
        dfs(dfs,0,-1);
        ll res = 0;
        for(ll i=n; i>=0; i--){
            if(dp[0][i][0] <= b || dp[0][i][1] <= b) {
                res = i;
                break;
            }
        }
        cout << res << "\n";
    }
}