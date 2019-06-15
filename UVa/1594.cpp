#include<bits/stdc++.h>
using namespace std;

long long arr[20],temp[20];

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int sp = 0;
		for(int a=0;a<n;a++) cin>>arr[a];
		while(sp!=1100)
		{
			for(int a=0;a<n;a++) temp[a] = abs(arr[a] - arr[(a+1)%n]);
			for(int a=0;a<n;a++) arr[a] = temp[a];
			sp++;
		}
		bool ada = false;
		for(int a=0;a<n;a++) if(arr[a]!=0) ada = true;
		printf("%s\n",(ada==true)?"LOOP":"ZERO");
	}
}
