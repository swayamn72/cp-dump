#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll buffer = arr[0] - 1;
        bool flag = true;
        for(ll i=1; i<n; i++){
            ll target = i+1;
            if(arr[i]<target){
                ll need = target - arr[i];
                if(buffer<need){
                    flag = false;
                    break;
                }
                buffer -= need;
            }else{
                buffer += (arr[i]-target);
            }
        }        
        cout << (flag ? "YES" : "NO") << "\n";
    }
}