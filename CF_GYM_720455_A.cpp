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
        ll n,l,d; cin >> n >> l >> d;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll div = d/l;
        ll res = div*n;
        ll remt = d%l;
        if(div%2==0){
            sort(arr.begin(),arr.end());
            auto it = upper_bound(arr.begin(),arr.end(),remt);
            if(it!=arr.begin()){
                it--;
                res += (it-arr.begin()+1);
            }
        }else{
            sort(arr.rbegin(),arr.rend());
            ll val = l-remt;
            ll left = 0, right = n-1;
            if(arr[0]>=val){
                ll ans = left;
                while(left<=right){
                    ll m = left+(right-left)/2;
                    if(arr[m]>=val){
                        ans = m;
                        left = m+1;
                    }else{
                        right=m-1;
                    }
                }
                res += (ans+1);
            }
        }
        cout << res << "\n";
    }
}