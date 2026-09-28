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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll minv = *min_element(arr.begin(),arr.end());
        if(arr[0]==minv || arr[n-1]==minv){
            cout << minv+1;
        }else{
            cout << minv+2;
        }
    }
}