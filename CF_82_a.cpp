#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    ll temp = 5;
    while(temp<n){
        n-=temp;
        temp*=2;
    }
    ll div = temp/5;
    ll val = 0;
    val += div;
    if(n<=val){
        cout << "Sheldon";
    }else if(n>val && n<=2*val){
        cout << "Leonard";
    }else if(n>2*val && n<=3*val){
        cout << "Penny";
    }else if(n>3*val && n<=4*val){
        cout << "Rajesh";
    }else{
        cout << "Howard";
    }
    // 20 : 4a 4b 4c 4d 4e
}