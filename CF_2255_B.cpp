#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 998244353;
ll binexp(ll a, ll b) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll maxn = 1e6+10;
void factandinv(vector<ll> &fact, vector<ll> &invFact){
    fact[0] = 1;
    for(ll i=1; i<maxn; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    invFact[maxn-1] = binexp(fact[maxn-1],mod-2);
    for(int i=maxn-2; i>=0; i--){
        invFact[i] = (invFact[i+1]*(i+1))%mod;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> fact(maxn), invfact(maxn);
    factandinv(fact,invfact);
    auto ncr = [&](ll n, ll r)->ll{
        if(r < 0 || r > n) return 0;
        return (((fact[n] * invfact[r]) % mod)
            * invfact[n-r]) % mod;
    }; 
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll one = 0, zero = 0, block0 = 0, block1 = 0;
        for(ll i=0; i<n; i++){
            if(s[i]=='0') zero++;
            else one++;
            if(i>0 && s[i]!=s[i-1]){
                if(s[i]=='0') block0++;
                else block1++;
            }
        }
        if(s[0]=='0') block0++;
        else block1++;
        if(!one || !zero){
            cout << 1 << "\n";
            continue;
        }
        ll res = (ncr(one-1,block1-1)*ncr(zero-1,block0-1))%mod;
        cout << res << "\n";
    }
}