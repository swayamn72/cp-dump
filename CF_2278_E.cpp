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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << arr[0] << "\n";
            continue;
        }        
        vi even,odd; 
        for(ll i=0; i<n; i++){
            if(i%2) odd.push_back(arr[i]);
            else even.push_back(arr[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        ll res = sum;
        ll i = 0;
        ll m = min(even.size(),odd.size());
        for(ll i=0; i<m; i++){
            ll diff = (-even[i]-odd[i])-(even[i]+odd[i]);
            if(diff>0) sum += diff;
        }
        cout << sum << "\n";
    }
}