#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> grid(n, vector<ll>(m));
        ll ones = 0, rsize=0, dsize=0;
        for(auto &a : grid) for(auto &b : a){
            cin >> b;
            if(b==1) ones++;
        } 
        ll target = ones/2;
        vector<vector<ll>> pref(n, vector<ll>(m,0));
        for(ll i=0; i<m; i++){
            for(ll j=n-1; j>=0; j--){
                if(j!=n-1) pref[j][i] = pref[j+1][i];
                if(grid[j][i]==1) pref[j][i]++;
            }
        }
        // for(auto a : pref){
        //     for(auto b : a) cout << b << " ";
        //     cout << "\n";
        // }
        string res = "";
        ll curcol = 0;
        ll curones = 0;
        while(curcol<m && curones+pref[0][curcol]<=target){
            curones += pref[0][curcol++];
            res += 'R'; rsize++;
        }
        if(curcol==m){
            for(ll i=0; i<n; i++){
                res += 'D'; dsize++;
            } 
            for(ll i=0; i<(m-rsize); i++) res += 'R';
            for(ll i=0; i<(n-dsize); i++) res += 'D';
            cout << 0 << "\n";
            cout << res << "\n";
            continue;
        }
        ll currow = 0;
        while(currow<n && curones + pref[currow][curcol] != target){
            currow++;
            res += 'D'; dsize++;
        }
        if(currow == n){
            for(ll i=0; i<(m-rsize); i++) res += 'R';
            for(ll i=0; i<(n-dsize); i++) res += 'D';
            cout << (target)*(ones-target) << "\n";
            cout << res << "\n";
            continue;
        }
        res += 'R'; rsize++;
        for(ll i=0; i<(n-currow); i++){
           res += 'D'; dsize++;
        } 
        for(ll i=0; i<(m-rsize); i++) res += 'R';
        for(ll i=0; i<(n-dsize); i++) res += 'D';

        cout << (target)*(ones-target) << "\n";
        cout << res << "\n";
    }
}