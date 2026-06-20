#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll maxn = 1e7+5;
vi mu(maxn,0);
vi primes;
vector<bool> isprime(maxn,true);

void mobius(){
    isprime[0] = isprime[1] = false;
    mu[1] = 1;
    for(ll i=2; i<maxn; i++){
        if(isprime[i]){
            primes.push_back(i);
            mu[i] = -1;
        }
        for(auto p : primes){
            if(i*p >= maxn) break;
            isprime[i*p] = false;
            if(i%p==0){
                mu[i*p] = 0;
                break;
            }else{
                mu[i*p] = -mu[i];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    mobius();
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll res = 0;
        for(ll i=1; i*i<=n; i++){
            if(mu[i]==0) continue;
            ll multiples = n/(i*i);
            res += mu[i]*multiples;
        }
        cout << res << "\n";
    }
}