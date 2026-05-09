#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k; cin >> n >> k;
    vector<vector<ll>> arr(n);
    for(ll i=0; i<n; i++){
        ll num; cin >> num; 
        arr[i].resize(num);
        for(ll j=0; j<num; j++){
            ll x; cin >> x;
            arr[i][j] = x;
        }
    }
    vi c(n); for(auto &x : c) cin >> x;
    ll index; ll num;
    for(int i=0; i<n; i++){
        ll size = arr[i].size();
        if(size*(c[i]) < k){
            k -= (size*(c[i]));
        }else{
            index = i;
            num = i+1;
            break;
        }
    }
    k--;
    cout << arr[index][k % arr[index].size()];
}