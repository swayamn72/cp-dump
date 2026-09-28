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
        vi even, odd;
        for(ll i=0; i<n; i++){
            if(i%2) odd.push_back(arr[i]);
            else even.push_back(arr[i]);
        }        
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        vi v(n);
        ll i = 0, ptr = 0;
        while(i<n){
            v[i] = even[ptr++]; i+=2;
        }
        i = 1; ptr = 0;
        while(i<n){
            v[i] = odd[ptr++]; i+=2;
        }
        for(auto a : v) cout << a << " ";
        cout << "\n";
    }
}