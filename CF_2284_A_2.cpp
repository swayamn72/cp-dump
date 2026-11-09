#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.rbegin(),arr.rend());
        ll a = 0, b = 0;
        for(auto x : arr){
            x = (1<<x);
            if(a<b){
                a+=x;
            }else{
                b+=x;
            }
        }        
        cout << a*b << "\n";
    }
}