#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,h; cin >> n >> h;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi count(n);
        for(ll i=0; i<n; i++){
            ll curr = arr[i];
            count[i] = h - curr;
            for(int j=i+1; j<n; j++){
                curr = max(curr,arr[j]);
                count[i] += (h-curr);
            }
            curr = arr[i];
            for(int j=i-1; j>=0; j--){
                curr = max(curr,arr[j]);
                count[i] += (h-curr);
            }
        }

        ll res = 0;
        for(ll i=0; i<n; i++){
            ll peak = arr[i], peakindex = i;
            for(ll j=i; j<n; j++){
                if(arr[j]>peak){
                    peak = arr[j];
                    peakindex = j;
                }
                res = max(res,count[i]+count[j]-count[peakindex]);
            }
        }
        cout << res << "\n";
    }
}