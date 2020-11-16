#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int minm(int a,int b){
	if(a>b)
		return b;
	else
		return a;
}

int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string arr;
		cin>>arr;
		
		int count = 0;
		int mcount = 0;
		int icount = 0;
		for(int i = 0;i<arr.size();i++){			// loop to count count of magnet and iron...
			if(arr[i]=='M')
				mcount++;
			if(arr[i]=='I')
				icount++;
		}

		int mincount = minm(mcount,icount);

// 		int end_reach = 0;
		for(int i = 0;i<arr.size();i++){
		    
			if(arr[i]=='M'){
				int found = 0;
				int power = k+1;
				int ind_found = -5;
				
				for(int j = i-1;j>=0;j--){				// searching in left....
					// if(arr[i]==" "){continue;}
					power--;
					if(arr[j]=='X')
					break;
					
					if(power<=0)
					break;
					
					
					if(arr[j]=='I'){
						found = 1;
						ind_found = j;
					//	break;
						
					}
					if(arr[j]==':'){
						power--;
					}
					
				}
				
				if(found ==1){
					arr[ind_found]='Z';					// replacing found iron by dummy character
					count++;
					continue;
				}
				
				power = k+1;
				
				for(int j = i+1;j<arr.size();j++){     // seracging right;
					power--;
					if(arr[j]=='X')
					break;
					if(power<=0)
					break;
				
					
					if(arr[j]=='I'){
						found = 1;
						ind_found = j;
						break;
					}
					if(arr[j]==':'){
						power--;
					}
					
				
				}
				
				if(found ==1){
					arr[ind_found]='Z';			// replacing iron by dummy character.....
					count++;
					continue;
				}
				
			}

			if(count== mincount)				// Check if count equals to minimum count of iron and magnet 
			{	break;}
		}
		
		cout<<count<<endl;
		
		// for(int i=0;i<arr.size();i++){
			// cout<<arr[i]<<" ";
		// }cout<<endl;
	}
	return 0;
}