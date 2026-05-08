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
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end()); 
        vector<ll> v; v.push_back(arr[n-1]); arr.pop_back();
        set<ll> s; s.insert(v[0]);
        vector<ll> duplicates;
        vector<ll> uniques;
        for(ll i=0; i<n-1; i++){
            if(s.find(arr[i])!=s.end()){
                duplicates.push_back(arr[i]);
            }else{
                uniques.push_back(arr[i]);
                s.insert(arr[i]);
            }
        }
        for(auto a : uniques) v.push_back(a);
        for(auto a : duplicates) v.push_back(a);
        ll res = n*v[0];
        s.clear();
        ll curmex = 0;
        for(ll i=0; i<n; i++){
            s.insert(v[i]);
            while(s.find(curmex)!=s.end()) curmex++;
            res += curmex;
        }
        cout << res << "\n";
    }
}
