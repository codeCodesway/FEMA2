#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#define ll long long

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string p;
	string t;

	cin>>p;
	cin>>t;

	char a = p[0];
	ll phash = 0;
	ll thash = 0;

	for(int i = 0;i<p.size();i++){
		ll k = p[i];
		ll m = t[i];
		phash+=k;
		thash+=m;

	}





	vector<int> arr;

	for(int i = 0;i<=t.size()-p.size();i++){
		if(i==0){
			if(phash==thash&&a==t[i]){
				arr.push_back(i);continue;
			}else{
				continue;
			}
		}
		ll k = t[i-1];
		ll m = t[i+p.size()-1];
		thash=thash-k;
		thash = thash+m;

		if(phash==thash&&a==t[i]){arr.push_back(i);}

	}
	vector<int>ans;

	for(int i = 0;i<arr.size();i++){
		int k = arr[i];
		int j;
		for( j = 0;j<p.size();j++){
			if(p[j]==t[k]){k++;
				continue;
			}else{break;}
		}
		if(j == p.size()){ans.push_back(arr[i]);}
	}
	
	for(int i = 0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}