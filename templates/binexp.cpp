#include<bits/stdc++.h>
using ll = long long;
ll mulmod(ll a, ll b, ll mod) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b, ll mod) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = mulmod(res,a,mod);
        a = mulmod(a,a,mod);
        b>>=1;
    }
    return res;
}
