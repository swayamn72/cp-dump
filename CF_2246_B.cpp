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
        if(n==1){
            cout << 1 << "\n";
            continue;
        }        
        if(n==2){
            cout << -1 << "\n";
            continue;
        }
        vi res(n);
        res[0] = 1;
        res[1] = 2;
        res[2] = 3;
        for(ll i=3; i<n; i++) res[i] = 2*res[i-1];
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}