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
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp;
        for(auto a : arr) mp[a]++;
        bool flag = false;  
        ll res = 0; ll sum = 0;     
        for(auto a : mp){
            if(a.second>=3){
                res += (a.second*(a.second-1)*(a.second-2))/6;
            }
            if(a.second>=2){
                res += (a.second*(a.second-1))/2 * sum;
            }
            sum += a.second;
        }
        cout << res << "\n";
    }
}