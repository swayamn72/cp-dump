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
        ll n,k; cin >> n >> k;
        if(n==k && ((n*(n+1))/2)%2==0){
            cout << "No" << "\n";
        }else{
            cout << "Yes" << "\n";
        }
    }
}