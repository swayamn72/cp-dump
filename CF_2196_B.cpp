#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll b = ceil(sqrt(n));
        ll res = 0;
        for(ll i=0; i<n; i++){
            if(arr[i]>=b){
                for(ll j=i+arr[i]; j<n; j+=arr[i]){
                    if((j-i)==(arr[i]*arr[j])) res++;
                }
                for(ll j=i-arr[i]; j>=0; j-=arr[i]){
                    if((i-j)==(arr[i]*arr[j])) res++;
                }
            }else{
                ll num1 = arr[i];
                ll index = i;
                for(ll k=0; k<b; k++){
                    index += num1;
                    if(index>=n) break;
                    if(arr[index]<b && (arr[index]*num1) == (index-i)) res++;
                }
            }
        }
        cout << res << "\n";
    }
}