#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll maxn = 32000;
    vi primes;
    vector<bool> isprime(maxn+1,true);
    isprime[0] = isprime[1] = false;
    for(ll i=2; i*i<=maxn; i++){
        if(isprime[i]){
            for(int j=i*i; j<=maxn; j+=i){
                isprime[j] = false;

            }
        }
    }
    for(ll i=2; i<=maxn; i++){
        if(isprime[i]) primes.push_back(i);
    }

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        
        vi factors;
        for(auto &a : arr){
            for(auto p : primes){
                if(p*p>a) break;
                if(a%p==0){
                    factors.push_back(p);
                    while(a%p==0) a/=p;
                } 
            }
            if(a>1) factors.push_back(a);
        }
        sort(factors.begin(),factors.end());
        bool flag = false;
        for(ll i=1; i<factors.size(); i++){
            if(factors[i]==factors[i-1]){
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}