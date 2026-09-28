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
        ll n,k; cin >> n >> k;
        ll res;
        vi arr(n,0);
        for(ll i=0; i<=3000; i++){
            for(ll j=0; j<n; j++){
                if(j==(i%n)) continue;
                arr[j]++;
            }
            bool flag = true;
            for(auto a : arr){
                if(a<k){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res=i+1;
                break;
            }
        }
        cout << res;
    }
}