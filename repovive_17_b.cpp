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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll res = n*n*n;
        ll count = 0;
        for(auto a : arr){
            if(a==5 || a==0) continue;
            count ++;
        }
        res -= (count*count*count);
        cout << res << "\n";
    }
}