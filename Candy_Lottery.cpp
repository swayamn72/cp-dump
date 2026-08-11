#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double n,k; cin >> n >> k;
    double res = k;
    for(ll i=1; i<k; i++){
        res -= pow(i/k,n);
    }
    cout << fixed << setprecision(6) << res;
}