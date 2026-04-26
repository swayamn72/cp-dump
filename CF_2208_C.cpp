#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi c(n); vi p(n);
        for(ll i=0; i<n; i++){
            cin >> c[i] >> p[i];
        }
        vi rightmax(n, 0);
        ll temp = c[n-1];
        for(ll i=n-2; i>=0; i--){
            rightmax[i] = temp;
            temp = max(temp, c[i]);
        }
        double res = c[n-1]; double curloss = p[n-1];
        double s = 1;
        for(ll i=n-2; i>=0; i--){
            double val = c[i] + (double)res*((double)s*((double)1-((double)p[i]/(double)100)));
            if(val > res){
                res = val; 
            }
        }
        cout << fixed << setprecision(10) << res << "\n";
    }
}