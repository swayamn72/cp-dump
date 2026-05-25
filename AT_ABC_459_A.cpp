#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll x; cin >> x;
    string res = "HelloWorld";
    string ans = "";
    for(ll i=0; i<10; i++){
        if(i==x-1) continue;
        ans += res[i];
    }
    cout << ans;
}