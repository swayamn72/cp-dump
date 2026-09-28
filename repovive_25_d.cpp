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
        bool flag = true;
        ll sum = 0;
        for(ll i=0; i<n; i++){
            sum += arr[i];
            if(arr[i]==0) sum--;
            if(sum<(i+1)){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        
    }
}