#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        double a,b,c,d; cin >> a >> b >> c >> d;
        double p1 = a/b, p2 = c/d;
        double bothmiss = (1-p1)*(1-p2);
        double cur = p1;
        double res = 0.0;
        for(ll i=1; i<1e5; i++){
            res += cur;
            cur *= bothmiss;
        }
        cout << fixed << setprecision(6) << res;
    }
} 