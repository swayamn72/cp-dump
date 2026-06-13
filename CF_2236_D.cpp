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
        vi v(n+1,0);
        for(ll i=0; i<n; i++){
            ll val; cin >> val;
            v[val]++;
        }
        bool flag = false;
        ll closest = LLONG_MAX;
        for(ll i=n; i>=1; i--){
            if(v[i]==0) continue;
            bool temp = false;
            if(closest <= i+k){
                temp = true;
            }else{
                if(v[i]%2==0){
                    temp = true;
                }else{
                    closest = i;
                }
            }
            if(temp){
                flag = true; break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}