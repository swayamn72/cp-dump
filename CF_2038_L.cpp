#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll divi = n/3;
    ll res = 2*divi;
    ll rem = n%3;
    if(rem==2){
        res++; n++;
    }else{
        n+= (rem*2);
    }
    res += (n+1)/2;
    cout << res;
}