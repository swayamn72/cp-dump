#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k; cin >> n >> k;
    vi arr(n); for(auto &x : arr) cin >> x;
    
    ll left = *min_element(arr.begin(),arr.end());
    ll right = LLONG_MAX; 
    ll res = left;
    while(left<=right){
        ll mid = left + (right-left)/2;
        ll operations = 0;
        for(ll i=0; i<n; i++){
            ll a = arr[i];
            if(a<mid){
                ll diff = mid-a;
                operations += (diff+i)/(i+1);
            }
            if(operations>k) break;
        }
        if(operations<=k){
            res = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << res;
}