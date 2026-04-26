#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(ll i = 0; i < n; i++) cin >> arr[i];
        unordered_set<ll> s; ll curmex = 0;
        for(ll i=0; i<n; i++){
            s.insert(arr[i]);
            while(s.count(curmex)) curmex++;
        }
        if(curmex == 0){
            cout << "YES" << endl; 
            continue;
        }
        if(s.find(curmex+1)==s.end() && n==curmex){
            cout << "NO" << endl;
        }else if(s.find(curmex+1)==s.end()){
            cout << "YES" << endl;
        }else{
            ll left = -1; ll right = -1;
            for(ll i=0; i<n; i++){
                if(arr[i]==curmex+1){
                    left = i; break;
                }
            }
            for(ll i=n-1; i>=0; i--){
                if(arr[i]==curmex+1){
                    right = i; break;
                }
            }
            for(ll i=left; i<=right; i++) arr[i] = curmex;
            ll curmex2 = 0; s.clear();
            for(ll i=0; i<n; i++){
                s.insert(arr[i]);
                while(s.count(curmex2)) curmex2++;
            }
            if(curmex2==curmex+1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}