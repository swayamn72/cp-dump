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
        ll n,k; cin >> n >> k;
        vi arr(n,-1);
        bool flag = true;
        int allotted = 0;
        ll index = 0;
        ll val = 1;
        while(allotted<n){
            vector<ll> v;
            for(int i=index; i<n; i+=k){
                v.push_back(i);
            }
            if(flag){
                allotted += v.size();
                for(auto a : v) arr[a] = val++;
                flag = !flag; 
            }else{
                reverse(v.begin(),v.end());
                allotted += v.size();
                for(auto a : v) arr[a] = val++;
                flag = !flag; 
            }
            index++;
        }      
        for(auto a : arr) cout << a << " ";  
        cout << "\n";
    }
}