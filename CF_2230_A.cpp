#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,a,b; cin >> n >> a >> b;
        if(b>=3*a){
            cout << n*a << "\n";
            continue;
        }
        ll div = n/3;
        ll rem = n%3;
        ll res = b*div;
        res += min(b,rem*a);
        cout << res << "\n";
    }
}