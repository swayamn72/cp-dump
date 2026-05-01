#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    cin >> n >> k;
    if(n==1){
        cout << -1 << "\n";
        return 0;
    }
    if(k==1){
        cout << n << "\n";
        return 0;
    }
    ll size = 0;
    vector<ll> v;
    for(ll i=2; i*i<=n; i++){
        while(n%i==0 && size<k-1){
            n/=i;
            v.push_back(i);
            size++;
        }
    }
    if(n<=1 || v.size()!=k-1){
        cout << -1 << "\n";
        return 0;
    }
    for(auto a : v) cout << a << " ";
    cout << n;
    return 0;
}