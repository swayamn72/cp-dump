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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll size = k-1;
        ll toremove = n-size;    
        ll idx1 = k-1, idx2 = n-k;
        
        if(k==1){
            cout << accumulate(arr.begin(),arr.end(),0LL) << "\n";
            continue;
        }
        ll res = 0;
        bool flag = true;
        if(idx1>idx2) flag = false;
        if(flag){
            for(ll i=idx1; i<=idx2; i++) res += arr[i];
            idx2++; idx1--;
            while(idx1>=0 && idx2<n){
                res += max(arr[idx1],arr[idx2]);
                idx2++; idx1--;
            }
            cout << res << "\n";
        }else{
            while(idx1<n && idx2>=0){
                res += max(arr[idx1],arr[idx2]);
                idx2--; idx1++;
            }
            cout << res << "\n";
        }
        
    }
}