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
        ll ones = 0;
        for(auto a : arr) if(a==1) ones++;
        if(ones==n){
            cout << -1 << "\n";
            continue;
        }
        if(ones==n-1 && (arr[n-1]!=1 || arr[0]!=1)){
            cout << *max_element(arr.begin(),arr.end()) << "\n";
            continue;
        }
        if(ones==n-2 && n>2 && arr[0]!=1 && arr[n-1]!=1){
            cout << arr[0]+arr[n-1]-1 << "\n";
            continue;
        }
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        cout << sum-1 << "\n";
    }
}