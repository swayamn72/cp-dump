#include <bits/stdc++.h>
#include <climits>
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
        vi a(n), b(n), c(n);
        for(ll i=0; i<n; i++) cin >> a[i] >> b[i] >> c[i];

        
        // a<b<c : no change
        // b>a>c : can change
        ll l = -2e18;
        ll r = 2e18;
        ll res = r;
        while(l<=r){
            ll m = l + (r-l)/2;
            ll ops = 0;
            bool flag = true;
            for(ll i=0; i<n; i++){
                ll val = a[i]+b[i]+c[i];
                bool check = false;
                if(a[i]-b[i]>0 || a[i]-c[i]>0 || b[i]-c[i]>0) check = true;
                if(!check){
                    if(val<m){
                        if(a[i]==b[i] && b[i]==c[i]){
                            flag = false;
                            break;
                        }
                        ll extra = min(c[i]-b[i]+1,b[i]-a[i]+1);
                        extra *=2;
                        extra += m-val;
                        ops += extra;
                        if(ops>k){
                            flag = false;
                            break;
                        }
                    }
                }else{
                    if(val>=m){
                        continue;
                    }else{
                        ll diff = m-val;
                        ops += diff;
                        if(ops>k){
                            flag = false;
                            break;
                        }
                    }
                }
            }

            if(!flag || ops>k){
                r=m-1;
            }else{
                res = m;
                l=m+1;
            }
        }
        cout << res << "\n";
    }
}