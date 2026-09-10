#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll x; cin >> x;
        if(x==0){
            cout << "Z" << "\n";
            continue;
        }
        vector<char> arr(50,'A');
        ll temp = 0;
        for(ll i=49; i>=1; i--){
            if(i-temp<=x){
                x-=(i-temp);
                arr[i] = 'C';
                temp++;
            }
        }
        string res = "";
        for(auto a : arr){
            res += 'R';
            res += a;
        }
        cout << res.size() << "\n";
        cout << res;
    }
} 