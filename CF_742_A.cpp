#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    if(n==0){
        cout << 1 << "\n";
        return 0;
    } 
    if(n%4==0) cout << 6 << "\n";
    else if(n%4==1) cout << 8 << "\n";
    else if(n%4==2) cout << 4 << "\n";
    else cout << 2 << "\n";
}