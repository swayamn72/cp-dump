#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> isprime(1e5+1,true);
    for(ll i=2; i<=1e5; i++){
        if(isprime[i]){
            for(ll j=i*i; j<=1e5; j+=i){
                isprime[j] = false;
            }
        }
    }
    vi primes; for(ll i=2; i<=1e5; i++) if(isprime[i]) primes.push_back(i);
    // cout << primes.size() << "\n";
    // for(auto a : primes) cout << a << " ";

    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        auto it = lower_bound(primes.begin(),primes.end(),n);
        // cout << (it-primes.begin()) << "\n";
        ll idx = (it-primes.begin())/2;
        ll left = primes[idx]-1, right = primes[idx]+1;
        vi res = {primes[idx]};
        while(left>0 && right<=n){
            res.push_back(left--);
            res.push_back(right++);
        }
        while(left>0) res.push_back(left--);
        while(right<=n) res.push_back(right++);
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}