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
        ll res = LLONG_MAX;
        ll a = 1;
        while(a<n) a*=2;
        res = min(res,a);
        
        while(a%2==0){
            a/=2;
            if(a<n) a*=3;
            res = min(res,a);
        }

        cout << res << "\n";
    }
}