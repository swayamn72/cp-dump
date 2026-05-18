#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        vi arr; set<ll> st;
        for(ll i=0; i<n; i++){
            if(s[i]=='0'){
                arr.push_back(i);
                st.insert(i);
            } 
        }        
        if(arr.size()==0){
            cout << "YES" << "\n";
            continue;
        }
        bool flag = true;
        vector<ll> dp(arr.size());
        if(arr[0]==0){
            dp[0]=0;
        }else{
            dp[0]=1;
        }
        for(ll i=1; i<arr.size(); i++){
            ll d = arr[i]-arr[i-1];
            if(d==1){
                dp[i] = 0;
            }else if(d==2){
                if(dp[i-1]==1) dp[i]=2;
                else if(dp[i-1]==2) dp[i]=1;
                else dp[i]=0;
            }else{
                if(dp[i-1]==1){
                    flag = false;
                    break;
                }
                dp[i] = 1;
            }
        }
        if(dp[arr.size()-1]==1 && arr[arr.size()-1]!=n-1) flag = false;
        cout << (flag ? "YES" : "NO") << "\n";
    }
}
// 0-can be left // 1-has to be right // 2-has to be left