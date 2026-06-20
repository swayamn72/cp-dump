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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll maxv = *max_element(arr.begin(),arr.end());
        if(is_sorted(arr.begin(),arr.end())){
            cout << maxv << "\n";
            continue;
        }
        ll index = -1;
        for(ll i=1; i<n; i++){
            if(arr[i]<arr[i-1]){
                index = i-1;
                break;
            }
        }
        ll res = arr[index];
        ll temp = 0;
        for(ll i=index+1; i<n; i++){
            if(arr[i]<res){
                res += arr[i];
                // res += temp;
                // temp = 0;
            }else{
                res = arr[i];
            } 
            
        }
        cout << max(maxv,res) << "\n";
    }
}