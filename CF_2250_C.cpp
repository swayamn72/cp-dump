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
        ll n; cin >> n;
        vi l(n), r(n), u(n), v(n);
        for(ll i=0; i<n; i++){
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        }        
        ll res = 0;
        for(ll i=n; i>0; i--){
            ll ptr = 1;
            for(ll j=0; j<n; j++){
                if(ptr>i) break;
                bool flag1 = false;
                if(ptr<l[j] || ptr>r[j]) flag1 = true;

                bool flag2 = false;
                ll val = i-ptr+1;
                if(val<u[j]||val>v[j]) flag2 = true;

                if(flag1 && flag2) ptr++;
            }
            if(ptr>i){
                res = i;
                break;
            }
        }
        cout << res << "\n";
    }
}