#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        ll minv = min(k-1,n-k);
        ll maxv = max(k-1,n-k);

        ll res = 0;
        ll l = 0, r = n-1;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if(mid==0){
                res = max(res,0LL);
                l = mid+1;
                continue;
            }
            ll ymax = min(minv,mid/2);
            ll cost = 2*mid-ymax-1;
            if(cost<=m){
                res = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        cout << res+1 << "\n";
    }
}