#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double m,n; cin >> m >> n;
    double res = m;
    for(ll i=1; i<m; i++){
        res -= (pow(i/m,n));
    }
    cout << fixed << setprecision(6) << res;
}