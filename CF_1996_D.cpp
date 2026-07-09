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
        ll n,x; cin >> n >> x;
        ll res = 0;
        for(ll a=1; a<=n; a++){
            for(ll b=1; b<=n; b++){
                if(a*b>=n || a+b>x) break;
                ll val1 = x - a - b;
                ll val2 = n - a*b;
                val2 /= (a+b);
                ll val = max(0LL,min(val1,val2));
                res += val;
            }
        }        
        cout << res << "\n";
    }
}