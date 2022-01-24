#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArray(vector<int> &arr)
{
    int n=arr.size();                             // To get the length of array
    for(int i=0;i<n/2;i++)
	{
	   // swap(arr[i],arr[n-i-1]);            we can also use this inbuilt function to get the swapping done
	   int t=arr[i];
	   arr[i]=arr[n-i-1];
	   arr[n-i-1]=t;
	}
	return arr;
}


// The code written below this comment is to check the written code by giving input manually

int main() {
    int n;
    cin>>n;
    
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	vector<int> x=reverseArray(arr);
	
	for(int i=0;i<n;i++)
	cout<<x[i]<<" ";
	
	return 0; 
}