#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll a,b,c; cin >> a >> b >> c;
    vi v = {a,b,c}; sort(v.begin(),v.end());
    if(v[2]-v[0]>=10){
        cout << "check again";
    }else{
        cout << "final " << v[1];
    }
}