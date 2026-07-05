#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x,y,l,r,a,b; cin >> x >> y >> l >> r >> a >> b;
    ll res = 0;
    for(ll i=a+1; i<=b; i++){
        if(i>l && i<=r) res += x;
        else res += y;
    }
    cout << res;
}