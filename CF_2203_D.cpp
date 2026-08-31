#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1; 
    cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi a(n), b(m);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;

        ll maxn = n+m;
        vi count(n+m+1,0);
        for(auto x : a) count[x]++;

        vi c(maxn+1,0);
        for(ll i=1; i<=maxn; i++){
            if(!count[i]) continue;
            for(ll j=i; j<=maxn; j+=i){
                c[j] += count[i];
            }
        }
        ll alice = 0, bob = 0, both = 0;
        for(auto y : b){
            if(c[y]==n) alice++;
            else if(c[y]==0) bob++;
            else both++;
        }
        alice += (both+1)/2;
        bob += both/2;
        if(bob>=alice) cout << "Bob" << "\n";
        else cout << "Alice" << "\n";
    }
} 