#include<bits/stdc++.h>
using namespace std;

long long arr[5];

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		for(int a=0;a<4;a++) cin>>arr[a];
		sort(arr,arr+4);
		bool issq = true;
		for(int a=0;a<4;a++) if(arr[a]!=arr[0]) issq = false;
		if(issq==true)
		{
			printf("square\n");
			continue;
		}
		else if(arr[0] == arr[1] && arr[2] == arr[3])
		{
			printf("rectangle\n");
		}
		else if(arr[0] + arr[1] + arr[2] <= arr[3])
		{
			printf("banana\n");
		}
		else printf("quadrangle\n");
	}
}
