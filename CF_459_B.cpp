#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll maxv = *max_element(arr.begin(),arr.end());
    ll minv = *min_element(arr.begin(),arr.end());
    cout << maxv-minv << " ";
    ll count1 = 0, count2 = 0;
    for(auto a : arr){
        if(a==maxv) count1++;
        else if(a==minv) count2++;
    }
    if(maxv==minv){
        cout << ((count1)*(count1-1))/2;
    }else{
        cout << count1*count2;
    }
}