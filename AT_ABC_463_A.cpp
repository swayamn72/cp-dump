#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll x,y; cin >> x >> y;
    if((x/16==y/9) && (x%16==0 && y%9==0)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}