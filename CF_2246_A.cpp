#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n);
        ll ptr1 = 1, ptr2 = 2;
        for(ll i=0; i<n; i++){
            if(i%2==0){
                arr[i] = ptr2;
                ptr2+=2;
            }else{
                arr[i] = ptr1;
                ptr1+=2;
            }
        }
        for(auto a : arr) cout << a << " ";
        cout << "\n";
    }
}