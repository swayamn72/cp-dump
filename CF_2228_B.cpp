#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,x1,x2,k; cin >> n >> x1 >> x2 >> k;
        if(n<=3){
            cout << 1 << "\n";
            continue;
        }
        if(x2<x1) swap(x2,x1);
        ll dist = min(x2-x1, x1+n-x2);
        cout << k+dist << "\n";

    }
}