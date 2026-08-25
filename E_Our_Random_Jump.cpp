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
    cin >> t;
    while(t--){
        ll n,a,b; cin >> n >> a >> b;

        // 0-normal  1-tp(lose)  2-tm(win)
        vi type(n+1,0);
        while(a--){
            ll x; cin >> x;
            type[x] = 1;
        }
        while(b--){
            ll x; cin >> x;
            type[x] = 2;
        }
        // cx + d
        vector<double> c(n+1,0.0);
        vector<double> d(n+1,0.0);
        c[n] = 1.0; d[n] = 0.0;
        double sumc = 1.0, sumd = 0.0;
        for(ll i=n-1; i>=1; i--){
            if(type[i]==2){
                c[i] = 0.0;
                d[i] = 1.0;
            }else if(type[i]==1){
                c[i] = 0.0;
                d[i] = 0.0;
            }else{
                double ways = n-i;
                c[i] = sumc/ways;
                d[i] = sumd/ways;
            }
            sumc += c[i];
            sumd += d[i];
        }
        double res = d[1]/(1.0-c[1]);
        cout << fixed << setprecision(6) << res << "\n";
    }
} 