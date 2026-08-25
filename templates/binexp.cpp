#include<bits/stdc++.h>
using ll = long long;
ll mod = 1e9+7;
ll mulmod(ll a, ll b) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = mulmod(res,a);
        a = mulmod(a,a);
        b>>=1;
    }
    return res;
}
ll modinv(ll a){
    return binexp(a,mod-2);
}
