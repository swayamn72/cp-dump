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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll left = -1, right = -1;
        for(ll i=1; i<n; i++){
            if(arr[i]==arr[i-1]){
                left = i;
                break;
            }
        }
        for(ll i=n-2; i>=0; i--){
            if(arr[i]==arr[i+1]){
                right = i;
                break;
            }
        }
        if(left==-1){
            cout << 0;
            continue;
        }
        ll res = right-left+1;
        if(arr[left]==arr[right]) res++;
        cout << res;
    }
} 