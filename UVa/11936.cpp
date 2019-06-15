#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int arr[3];
		for(int a=0;a<3;a++) scanf("%d",&arr[a]);
		sort(arr,arr+3);
		bool ada = true;
		if(arr[0]<=0) ada = false;
		if(arr[0] + arr[1] <= arr[2]) ada = false;
		if(ada==false) printf("Wrong!!\n");
		else printf("OK\n");
	}
}
