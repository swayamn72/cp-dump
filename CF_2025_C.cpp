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
        sort(arr.begin(),arr.end());
        ll res = 1, left = 0;
        for(ll i=1; i<n; i++){
            if(arr[i]-arr[i-1]>1){
                left = i;
                continue;
            }
            while(arr[i]-arr[left]>=k){
                left++;
            }
            res = max(res,i-left+1);
        }        
        cout << res << "\n";
    }
}