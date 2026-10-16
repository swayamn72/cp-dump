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
        ll n; cin >> n;
        vi dp(n+1,0);
        vi start(n+1,0);
        set<pair<ll,ll>> edges;
        ll k = 2;
        vi prevpath = {1};
        start[1] = 1;
        while(true){
            cout << "? " << k << endl;
            ll q; cin >> q;
            if(!q) break;
            vi curr(q);
            for(auto &x : curr) cin >> x;
            for(ll i=0; i<q-1; i++){
                edges.insert({curr[i],curr[i+1]});
            }
            ll lcplen = 0;
            while(lcplen<prevpath.size() && lcplen<curr.size() && prevpath[lcplen] == curr[lcplen]){
                lcplen++;
            } 
            for(ll i=lcplen; i<prevpath.size(); i++){
                ll v = prevpath[i];
                dp[v] = k - start[v];
            }
            for(ll i=lcplen; i<curr.size(); i++){
                ll v = curr[i];
                start[v] = k;
            }
            ll lastv = curr.back();
            if(dp[lastv]>0){
                k+=dp[lastv];
            }else{
                k++;
            }
            prevpath = curr;
        }        
        cout << "! " << edges.size() << endl;
        for(auto [a,b] : edges) cout << a << " " << b << endl;
    }
}