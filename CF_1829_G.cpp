#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<ll>> v(2023);
    vector<vector<ll>> pref(2023);
    ll temp = 1;
    for(ll i=0; i<2023; i++){
        for(ll j=0; j<i+1; j++){
            v[i].push_back(temp*temp);
            pref[i].push_back(temp*temp);
            if(j!=0) pref[i][j] += pref[i][j-1];
            temp++;
        }
    }
    

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;    
        ll temp = 1;
        ll total = 0;
        while(total + temp < n){
            total += temp;
            temp++;
        }
        ll left = n-total-1;
        ll right = left;
        // cout << temp << " " << total << " " << left << "\n";
        temp--;
        ll res = 0;
        for(ll i=temp; i>=0; i--){

            
            right = min(right,(ll)pref[i].size()-1);
            ll ans = pref[i][right];
            if(left!=0) ans -= pref[i][left-1];
            res += ans;
            left = max(0LL,left-1);
        }
        cout << res << "\n";
    }
}