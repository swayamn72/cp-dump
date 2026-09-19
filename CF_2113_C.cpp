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
        ll n,m,k; cin >> n >> m >> k;
        k--; ll side = 2*k+1;
        vector<vector<char>> grid(n+1,vector<char>(m+1));
        vector<vi> pref(n+1,vi(m+1,0LL));
        ll total = 0;
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                cin >> grid[i][j];
                char ch = grid[i][j];
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
                if(ch=='g'){
                    pref[i][j]++; total++;
                } 
            }
        }
        // for(auto &a : pref){
        //     for(auto b : a) cout << b << " ";
        //     cout << "\n";
        // }   
        ll minv = LLONG_MAX;
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                if(grid[i][j]!='.') continue;
                ll x = i+(side/2);
                ll y = j+(side/2);
                if(x>n) x=n;
                if(y>m) y=m;

                ll x2 = i-(side/2)-1;
                ll y2 = j-(side/2)-1;
                if(x2<0) x2=0;
                if(y2<0) y2=0;

                ll val = pref[x][y] + pref[x2][y2];
                val -= (pref[x][y2] + pref[x2][y]);
                minv = min(minv,val);
            }
        }
        cout << total-minv << "\n";
    }
}