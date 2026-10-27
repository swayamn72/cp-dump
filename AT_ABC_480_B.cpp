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
       ll n,m; cin >> n >> m;
       vector<string> arr1(n); for(auto &x : arr1) cin >> x;
       vector<string> arr2(m); for(auto &x : arr2) cin >> x;
       vi res(n);
       for(ll i=0; i<m; i++){

            ll cnt = 0;
            ll val = -1;
            for(ll j=0; j<n; j++){
                if(arr2[i]==arr1[j]){
                    cnt++;
                    val = j;
                }
            }
            if(cnt==1){
                res[val]++;
                continue;
            }
            cnt = 0; val = -1;
            for(ll j=0; j<n; j++){
                if(arr2[i].size()!=arr1[j].size()) continue;
                ll diff = 0;
                for(ll k=0; k<arr2[i].size(); k++){
                    if(arr2[i][k]!=arr1[j][k]) diff++;
                }
                if(diff==1){
                    cnt++; 
                    val = j;
                }
            }
            if(cnt!=1) continue;
            res[val]++;
       }
       for(auto a : res) cout << a << "\n";
    }
}