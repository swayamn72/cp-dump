#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll index = -1;
        ll res3 = 0;
        ll ones1 = 0;
        for(ll i=0; i<n; i++){
            if(arr[i]==1){
                ones1++;
            }else{
                res3 += ones1;
            }
        }
        
        for(ll i=0; i<n; i++){
            if(arr[i]==0){
                arr[i] = 1 - arr[i];
                index = i;
                break;
            }
        }
    
        ll res1 = 0, res2 = 0;
        if(index!=-1){
            ll ones = 0;
            for(ll i=0; i<n; i++){
                if(arr[i]==1){
                    ones++;
                }else{
                    res1 += ones;
                }
            }
            arr[index] = 1 - arr[index];
        }
        index = -1;
        for(ll i=n-1; i>=0; i--){
            if(arr[i]==1){
                arr[i] = 1 - arr[i];
                index = i;
                break;
            }
        }
        if(index!=-1){
            ll ones = 0;
            for(ll i=0; i<n; i++){
                if(arr[i]==1){
                    ones++;
                }else{
                    res2 += ones;
                }
            }
            arr[index] = 1 - arr[index];
        }
        cout << max({res1,res2,res3}) << "\n";
    }
}