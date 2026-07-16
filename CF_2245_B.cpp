#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        sum -= (k*n);
        ll buffer = n/2;
        sort(arr.begin(),arr.end());
        for(ll i=0; i<n; i++){
            if(arr[i]<k && buffer>0){
                sum += k; buffer--;
                sum -= arr[i];
            }
        }     
        cout << sum << "\n";   
    }
}