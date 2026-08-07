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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll toremove = 0;
        for(ll i=1; i<n; i++){
            if(arr[i]==arr[i-1]) toremove++;
        }        
        ll buffer = 0;
        for(ll i=1; i<n-1; i++){
            if(arr[i]==arr[i-1] && arr[i]!=arr[i+1] && (i>=n-2 || arr[i]!=arr[i+2])){
                buffer = 1;
                break;
            }
        }
        // if(n>=3){
        //     ll a = arr[0], b = arr[1], c = arr[2];
        //     if(b==c && a!=b) buffer = 1;

        //     a = arr[n-1], b = arr[n-2], c = arr[n-3];
        //     if(a==b && c!=b) buffer = 1;
        // }
        for(ll i=1; i<n-1; i++){
            if(arr[i]==arr[i+1] && arr[i]!=arr[i-1] && (i<2 || arr[i]!=arr[i-2])){
                buffer = 1;
                break;
            }
        }
        for(ll i=1; i<n-2; i++){
            if(arr[i]==arr[i+1]) continue;
            if(arr[i]==arr[i-1] && arr[i+1]==arr[i+2]){
                buffer = 2;
                break;
            }
        }
        toremove = max(0LL, toremove-buffer);
        cout << n-toremove << "\n";
    }
}