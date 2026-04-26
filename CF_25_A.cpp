#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> arr(n); for(ll i=0; i<n; i++) cin >> arr[i];
    vector<ll> odd; vector<ll> even;
    for(ll i=0; i<n; i++) {
        if(arr[i] % 2 == 0) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }
    if(even.size()==1){
        for(ll i=0; i<n; i++) if(arr[i]%2==0){
            cout << i+1 << "\n";
            break;
        }
    }else{
        for(ll i=0; i<n; i++) if(arr[i]%2==1){
            cout << i+1 << "\n";
            break;
        }
    }
}