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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        ll val = arr[n/2];
        double x = val/2.0;
        double res = 0.0;
        for(auto a : arr){
            double comp = min((double)a,2*x);
            res += (a-comp);
        }
        res /= n; res += x;
        cout << fixed << setprecision(6) << res;
    }
} 