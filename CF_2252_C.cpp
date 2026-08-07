#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi v(n); for(auto &x : v) cin >> x;
        vector<vector<ll>> grid(n, vector<ll>(m));
        ll res = m;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin >> grid[i][j];
            }
        } 
        
        vector<ll> temp;
        for(ll i=n-1; i>=0; i--){
            for(ll j=0; j<m; j++){
                temp.push_back(grid[i][j]);
            }
            sort(temp.rbegin(),temp.rend());
            while(temp.size()>m) temp.pop_back();

            ll sum = 0;
            for(ll j=0; j<m; j++){
                sum += temp[j];
                if(sum>=v[i]){
                    ll len = j+1;
                    res = min(res,len);
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}