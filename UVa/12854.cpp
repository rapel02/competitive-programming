#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[5];
	while(cin>>arr[0])
	{
		bool ada = true;
		for(int a=1;a<5;a++) cin>>arr[a];
		for(int a=0;a<5;a++)
		{
			int w;
			cin>>w;
			if(arr[a] + w != 1) ada = false;
		}
		printf("%c\n",(ada==true)?'Y':'N');
	}
}
