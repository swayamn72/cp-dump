#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<vector<ll>> arr(n);
    for(ll i=0; i<n; i++){
        ll num; cin >> num; 
        arr[i].resize(num);
        for(ll j=0; j<num; j++){
            ll x; cin >> x;
            arr[i][j] = x;
        }
    }
    ll x,y; cin >> x >> y;
    cout << arr[x-1][y-1];
}