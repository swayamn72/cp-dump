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
    // cin >> t;
    while(t--){
        ll n,x; cin >> n >> x;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll res = 0;
        sort(arr.begin(),arr.end());
        ll ptr1 = 0, ptr2 = n-1;
        while(ptr1<=ptr2){
            if(arr[ptr1]+arr[ptr2]>x){
                res++;
                ptr2--;
            }else{
                res++;
                ptr1++;
                ptr2--;
            }
        }
        cout << res;
    }
}