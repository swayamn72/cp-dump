#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m,q; cin >> n >> m >> q;
        vi p(n+1); for(ll i=1; i<=n; i++) cin >> p[i];
        vi arr(m+1); for(ll i=1; i<=m; i++) cin >> arr[i];
        vi prev(n+1);
        for(int i=1; i<=n; i++){
            if(i==1) prev[p[i]] = p[n];
            else prev[p[i]] = p[i-1];
        }
        
        vi last(n+1,0);
        vector<vi> up(2e5+5,vi(20));
        for(ll i=1; i<=m; i++){
            up[i][0] = last[prev[arr[i]]];
            last[arr[i]] = i;
        }
        for(ll j=1; j<20; j++){
            for(ll i=1; i<=m; i++){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
        vi maxleft(m+1);
        for(ll i=1; i<=m; i++){
            ll curr = i;
            ll jumps = n-1;
            for(ll j=0; j<20; j++){
                if((jumps>>j)&1){
                    curr = up[curr][j];
                }
            }
            maxleft[i] = max(maxleft[i-1],curr);
        }
        string res = "";
        for(ll i=0; i<q; i++){
            ll l,r; cin >> l >> r;
            if(maxleft[r]>=l) res += '1';
            else res += '0';
        }
        cout << res << "\n";
    }
}