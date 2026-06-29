#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    string s; cin >> s;
    ll east = 0, west = 0;
    for(auto a : s){
        if(a=='E') east++;
        else west++;
    }
    if(east>west) cout << "East";
    else cout << "West";
}