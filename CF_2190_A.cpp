#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll t; cin >> t; 
	while(t--){
	    ll n; cin >> n;
	    string s; cin >> s;
	    string s1 = s;
	    sort(s1.begin(),s1.end());
	    if(s==s1){
	        cout << "BOB" << "\n";
	        continue;
	    }else{
	        cout << "ALICE" << "\n";
	    }
	    vector<ll> res;
	    for(ll i=0; i<n; i++) if(s[i]!=s1[i]) res.push_back(i+1);
	    for(auto a : res) cout << a << " ";
	    cout << "\n";
	}
}
