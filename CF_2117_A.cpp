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
    cin >> t;
    while(t--){
        ll n,x; cin >> n >> x;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll idx = -1;
        for(ll i=0; i<n; i++){
            if(arr[i]){
                idx = i;
                break;
            }
        }        
        if(idx==-1){
            cout << -1 << "\n";
            continue;
        }
        ll right = idx+x-1;
        bool flag = true;
        for(ll i=right+1; i<n; i++){
            if(arr[i]){
                flag = false; break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
} 