#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll maxn = 1e6+2;
    vi phi(maxn);
    for(ll i=0; i<maxn; i++) phi[i] = i;
    for(ll i=2; i<maxn; i++){
        if(phi[i]==i){
            for(ll j=i; j<maxn; j+=i){
                phi[j] -= (phi[j]/i);
            }
        }
    }
    vi f(maxn,0);
    for(ll i=1; i<maxn; i++){
        for(ll j=i; j<maxn; j+=i){
            f[j] += i * phi[j/i];
        }
    }
    for(ll i=2; i<maxn; i++){
        f[i] += f[i-1];
    }
    ll n;
    while(cin>>n){
        if(n==0) break;
        ll tominus = (n*(n+1))/2;
        cout << f[n] - tominus << "\n";
    }
}