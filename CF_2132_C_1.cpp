#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll res = 0;
        while(n>0){
            ll temp = 1; ll val = 0; ll prev=0;
            while(temp*3<=n){
                prev = temp;
                temp*=3; val++;
            } 
            ll next = temp*3;
            ll ans = next + (val*prev);
            res += (n/temp)*ans;
            n %= temp;
        }
        cout << res << "\n";
    }
}