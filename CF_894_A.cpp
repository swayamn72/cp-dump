#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    string s; cin >> s;
    vector<int> dp(4,0);
    dp[0] = 1;
    for(auto a : s){
        if(a=='Q'){
            dp[3] += dp[2];
            dp[1] += dp[0];
        }else if(a=='A'){
            dp[2]+=dp[1];
        }
    }
    cout << dp[3];
}
