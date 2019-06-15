#include<bits/stdc++.h>
using namespace std;

int arr[250000];

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int a=0;a<n;a++) cin>>arr[a];
		bool ada = true;
		for(int a=1;a<n;a++) if(arr[a] == arr[a-1]) ada = false;
		printf("%sboring\n",(ada==true)?"non-":"");
	}
}
