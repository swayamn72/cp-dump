#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    auto func = [](auto &&self, ll n)->ll{
        // f(0) = 0, f(1) = 1, f(2) = 3, f(3) = 2
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 3;
        if(n==3) return 2;

        ll k = 63 - __builtin_clzll(n);
        ll op1 = self(self,n-(1LL<<k)+2)+k+1;
        ll op2 = (1LL<<(k+1))-n+k;
        return min(op1,op2);
    };
    while(t--){
        ll l,r; cin >> l >> r;
        ll res = 0;
        for(ll i=l; i<=r; i++){
            res = (res+func(func,i))%mod;
        }
        cout << res << "\n";
    }
}