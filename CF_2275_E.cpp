#include <bits/stdc++.h>
#include <vector>
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
        vi a(n), b(n); 
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        if(n==1){
            cout << (a[0]==b[0] ? 2 : 1) << "\n";
            continue;
        }
        vector<vi> dpall(n,vi(2,0));
        // vertical include
        dpall[0][0] = dpall[0][1] = (a[0]==b[0] ? 2 : 1);
        for(ll i=1; i<n; i++){
            dpall[i][0] = dpall[i-1][0] + (a[i-1]==b[i] ? 2 : 1) + (a[i]==b[i] ? 2 : 1);
            dpall[i][1] = dpall[i-1][1] + (b[i-1]==a[i] ? 2 : 1) + (a[i]==b[i] ? 2 : 1);
        }

        ll res = dpall[n-1][1];
        // ll res = max(dpall[n-1][0],dpall[n-1][1]);

        vi dpzig(n);
        dpzig[n-1] = (a[n-1]==b[n-1] ? 2 : 1);
        for(ll i=n-2; i>=0; i--){
            dpzig[i] = dpzig[i+1] + (a[i]==b[i+1] ? 2 : 1) + (b[i]==a[i+1] ? 2 : 1);
        }
        for(ll i=0; i<n; i++){
            // res = max(res,dpall[i][0]+dpzig[i]- (a[i]==b[i] ? 2 : 1) );
            res = max(res,dpall[i][1]+dpzig[i]- (a[i]==b[i] ? 2 : 1) );
        }
        res = max(res,dpzig[0]);
        cout << res << "\n";
    }
}