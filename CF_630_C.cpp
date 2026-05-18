#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll res = 0;
    ll val = 2;
    for(ll i=1; i<=n; i++){
        res += val;
        val <<= 1;
    } 
    cout << res;
}