#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll a,b,c; cin >> a >> b >> c;
        bool flag = true;
        cout << (((a&b)&(c))==0 ? "NO" : "YES")  << "\n";
        // if(((a&b)==0) || ((b&c)==0) || ((a&c)==0)) flag = false;
        // cout << (flag ? "YES" : "NO") << "\n";
    }
}