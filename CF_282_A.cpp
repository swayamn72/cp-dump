#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    ll x = 0;
    string s;
    while(n--){
        cin >> s;
        if(s[0]=='+' || s[1]=='+') x++;
        else x--;
    }
    cout << x;
}