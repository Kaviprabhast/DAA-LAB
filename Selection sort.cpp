#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
	for(int i=0;i<n;i++){
	int min_idx=i;
	for(int j=i+1;j<n;j++){
		if(arr[j]<arr[min_idx])
		    min_idx=j;
	}
	if(min_idx!=i)
	   swap(arr[min_idx],arr[i]);
}
}
void printArray(int arr[],int n){
	for(int i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){
	int arr[]={11,45,25,75,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,n);
	cout<<"Sorted Array:\n";
	printArray(arr,n);
	return 0;
}