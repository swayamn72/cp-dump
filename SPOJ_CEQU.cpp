#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll a,b,c; cin >> a >> b >> c;
        if(b>a) swap(a, b);
        ll gcdv = __gcd(a, b);
        if(c%gcdv==0){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
}