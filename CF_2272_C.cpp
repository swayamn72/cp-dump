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
        ll n,x; cin >> n >> x;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        ll l=1, r=arr[n-1]-arr[0];
        ll res = r;
        auto check = [&](ll m)->bool{
            ll buffer = x;
            vi flag(n,true);
            for(ll i=1; i<n-1; i++){
                if(arr[i]-arr[i-1]>m && arr[i+1]-arr[i]>m){
                    flag[i] = false;
                }
            }
            if(arr[1]-arr[0]>m) flag[0] = false;
            if(arr[n-1]-arr[n-2]>m) flag[n-1] = false;
            for(ll i=0; i<n; i++){
                if(flag[i]) continue;
                buffer--;
                if(i+1<n && !flag[i+1] && arr[i+1]-arr[i]<=2*m) i++;
            }
            return buffer>=0;
        };
        while(l<=r){
            ll m = l + (r-l)/2;
            if(check(m)){
                res = m;
                r=m-1;
            }else{
                l=m+1;
            }
        }        
        cout << res << "\n";
    }
}