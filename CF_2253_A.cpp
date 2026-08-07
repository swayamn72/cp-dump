#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll maxn = 3e5+1;
    vector<bool> isprime(maxn,true);
    isprime[1] = isprime[0] = false;
    for(ll i=2; i<maxn; i++){
        if(isprime[i]){
            for(ll j=i*i; j<maxn; j+=i){
                isprime[j] = false;
            }
        }
    }
    // for(ll i=0; i<10; i++) cout << isprime[i] << " ";
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        n++;
        cout << (isprime[n] ? "YES" : "NO") << "\n";
    }
}