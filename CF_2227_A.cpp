#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll x,y; cin >> x >> y;
        if(x%2==1 && y%2==1){
            cout << "NO" << "\n";
        }else{
            cout << "YES" << "\n";
        }
    }
}