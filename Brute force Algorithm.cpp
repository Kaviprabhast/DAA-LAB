#include<iostream>
#include<string.h>
using namespace std;
int compare(string str1,string str2){
	int j;
	int N=str1.length();
	int M=str2.length();
	for(int i=0;i<=N-M;i++){
		for(j=0;j<M;j++){
			if(str1[i+j]!=str2[j])
			break;
		}
		if(j==M){
			return i;
		}
	}
	return -1;
}
int main(){
	string str1="Hello";
	string str2="o";
	int result=compare(str1,str2);
	if(result!=-1)
	cout<<"Found at index: "<<result<<endl;
	else
	cout<<"Not found";
	return 0;
}
