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
    cin >> t;
    while(t--){
        ll n; cin >> n;
        string a,b; cin >> a >> b;
        vi arr1; for(auto x : a) arr1.push_back(x-'0');    
        vi arr2; for(auto x : b) arr2.push_back(x-'0');  
        ll red = 0, blue = 0;
        for(ll i=0; i<n; i++){
            if(arr1[i]>arr2[i]) red++;
            else if(arr1[i]<arr2[i]) blue++;
        }
        if(red==blue){
            cout << "EQUAL" << "\n";
            continue;
        }
        if(red<blue) cout << "BLUE" << "\n";
        else cout << "RED" << "\n";
    }
} 