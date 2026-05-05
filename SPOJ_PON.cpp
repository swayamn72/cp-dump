#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u128 = __uint128_t;
using i128 = __int128_t;

ll mulmod(ll a, ll b, ll mod) {
    return (ll)((i128)a * b % mod);
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

bool checkcomposite(ll n, ll a, ll d, int s){
    ll x = binexp(a, d, n);
    if(x==1 || x==n-1) return false;
    for(int r=1; r<s; r++){
        x = mulmod(x, x, n);
        if(x==n-1) return false;
    }
    return true;
}
bool isPrime(ll n) {
    if(n<2) return false;
    for(ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}){
        if(n%p==0) return n==p;
    }
    int s = 0;
    ll d = n-1;
    while((d&1)==0){
        d>>=1;
        s++;
    }
    for(ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
        if(a%n==0) return true;
        if(checkcomposite(n,a,d,s)) return false;
    }
    return true;
}
int main() {
	ll t; cin >> t;
	while(t--){
	    ll n; cin >> n;
	    if(isPrime(n)) cout << "YES" << "\n";
	    else cout << "NO" << "\n";
	}
}
