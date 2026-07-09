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
        string s1,s2; cin >> s1 >> s2;
        ll res = -1;
        ll left = 2, right = min(s1.size(),s2.size());

        vi pref1(s1.size());
        pref1[0] = (s1[0]-'0');
        for(ll i=1; i<s1.size(); i++){
            pref1[i] = (pref1[i-1] + (s1[i]-'0'))%10;
        }
        // for(auto a : pref1) cout << a << " ";
        // cout << "\n";
        vi pref2(s2.size());
        pref2[0] = (s2[0]-'0');
        for(ll i=1; i<s2.size(); i++){
            pref2[i] = (pref2[i-1] + (s2[i]-'0'))%10;
        }
        // for(auto a : pref2) cout << a << " ";
        // cout << "\n";

        vi suff1(s1.size());
        suff1[s1.size()-1] = s1[s1.size()-1]-'0';
        for(ll i=s1.size()-2; i>=0; i--){
            suff1[i] = (suff1[i+1] + (s1[i]-'0'))%10;
        }
        // for(auto a : suff1) cout << a << " ";
        // cout << "\n";

        vi suff2(s2.size());
        suff2[s2.size()-1] = s2[s2.size()-1]-'0';
        for(ll i=s2.size()-2; i>=0; i--){
            suff2[i] = (suff2[i+1] + (s2[i]-'0'))%10;
        }
        // for(auto a : suff2) cout << a << " ";
        // cout << "\n";    
        string a = "";
        for(auto x : pref1) a += ('0'+x);
        string b = "";
        for(auto x : pref2) b += ('0'+x);

        ll n = a.size(), m = b.size();
        if(pref1[n-1]!=pref2[m-1]){
            cout << -1 << "\n";
            continue;
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(a[i-1]==b[j-1]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }

        cout << dp[n][m] << "\n";

        // while(left<=right){
        //     ll m = left + (right-left)/2;
        //     bool flag = false;
        //     set<string> s1;

        //     for(ll i=0; i<s1.size()-m; i++){
        //         string temp = "";
        //         temp += pref
        //         for(ll j=i; j<i+m; j++){

        //         }
        //     }
        // }

        // cout << res << "\n";
    }
}