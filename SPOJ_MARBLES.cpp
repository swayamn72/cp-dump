#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        n--; k--;
        if(k>n/2) k = n-k;
        ll res = 1;
        for(ll i=1; i<=k; i++){
            res = res * (n-i+1)/i;
        }
        cout << res << "\n";
    }
}