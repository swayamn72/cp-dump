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
        vi res;
        bool flag = true;
        for(ll i=n-1; i>=0; i--){
            if(flag && arr[i]>0){
                res.push_back(i+1);
                flag = !flag;
            }else if(!flag && arr[i]<0){
                res.push_back(i+1);
                flag = !flag;
            }
        }      
        cout << res.size() << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";  
    }
}