#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vi c(n), s(n);
    for(ll i=0; i<n; i++){
        cin >> c[i] >> s[i];
    }
    vi res(m,-1);
    for(ll i=0; i<n; i++){
        res[c[i]-1] = max(res[c[i]-1],s[i]);
    }
    for(auto a : res) cout << a << " ";
}