#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1="CABACA";
	string str2="BAC";
	int p=str2[0]*100+str2[1]*10+str2[2]*1;
	int t=str1[0]*100+str1[1]*10+str1[2]*1;
	int n=str1.length();
	int m=str2.length();
	for(int i=0;i<=n-m;i++){
		if(p==t){
			int j;
			for(j=0;j<m;j++){
				if(str1[i+j]!=str2[j]){
				break;
			}
		}
				if(j==m){
					cout<<"Pattern found at index:"<<i<<endl;
					return 0;
				}
			}
			if(i<n-m){
		    	t=(t-str1[i]*100)*10+str1[i+m];
		    }
		}
		return 0;
	}
	
	