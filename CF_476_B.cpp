#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll fact(ll n) {
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b; cin >> a >> b;
    ll left = 0, right = 0;
    for(auto x : a){
        if(x=='+') right++;
        else left++;
    }
    ll curleft = 0, curright = 0, unknown = 0;
    for(auto x : b){
        if(x=='+') curright++;
        else if(x=='-') curleft++;
        else unknown++;
    }
    if(curright>right || curleft>left){
        cout << 0;
        return 0;
    }
    ll rightneed = right - curright;
    ll leftneed = left - curleft;
    if(unknown==0){
        cout << 1;
        return 0;
    }
    double curr = (double) fact(unknown) / (fact(rightneed)*fact(leftneed));
    double total = pow(2,unknown);
    cout << fixed << setprecision(9) << curr/total;
}