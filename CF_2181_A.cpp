#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; 
    cin >> n >> m;

    map<char, ll> mp1;
    vector<string> arr(n); 
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        for(auto a : arr[i]) mp1[a]++; 
    } 

    vector<ll> res(n, -1);
    for(ll i=0; i<n; i++){
        string s = arr[i];
        map<char, ll> mp3;
        for(auto a : s) mp3[a]++;

        ll ans = LLONG_MAX;
        bool possible = true;

        for(auto const& [ch, count] : mp3){
            ll val2 = mp1[ch] - count;
            
            if(val2 == 0) {
                possible = false;
                break;
            }

            ll available_letters = (m * val2) - count;

            if(available_letters < 0) {
                possible = false;
                break;
            }
            
            ans = min(ans, available_letters / val2);
        }

        if(!possible) res[i] = -1;
        else res[i] = (ans == LLONG_MAX ? 0 : ans);
    }

    for(ll i=0; i<n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}