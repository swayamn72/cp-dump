#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll res1 = *max_element(arr.begin(),arr.end());
        ll res2 = res1;

        ll sum = arr[0];
        for(ll i=1; i<n; i++){
            res1 = max({res1,arr[i]-sum,arr[i]+sum});
            sum = min({sum+arr[i]-sum,sum+arr[i]+sum,sum+arr[i]});
        }

        sum = arr[0];
        for(ll i=1; i<n; i++){
            res2 = max({res2,arr[i]-sum,arr[i]+sum});
            sum = max({sum+arr[i]-sum,sum+arr[i]+sum,sum+arr[i]});
        }

        cout << max(res1,res2) << "\n";
    }
}