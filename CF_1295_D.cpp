// You are given two integers a and m
// Calculate the number of integers x
// such that 0≤x<m
// and gcd(a,m)=gcd(a+x,m)

// let   gcd(a,m) = gcd(a+x,m) = g
// bcz g divides a and m and x let a = A.g and m = M.g  and let x = k.g
//  gcd(A.g + k.g , M.g) = g
//  gcd(A+k , M) = 1

// 0 <= x < m
// 0 <= k.g < M.g
// 0 <= k < M


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
    cin >> t;
    while(t--){
        ll a,m; cin >> a >> m;
        ll g = gcd(a,m);
        ll M = m/g;
        auto phi = [](ll n)->ll{
            ll res = n;
            for(ll i=2; i*i<=n; i++){
                if(n%i==0){
                    while(n%i==0) n/=i;
                    res -= (res/i);
                }  
            }
            if(n>1) res -= res/n;
            return res;
        };
        cout << phi(M) << "\n";
    }
}