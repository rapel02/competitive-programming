#include<bits/stdc++.h>
using namespace std;

int arr[1500000];
int id;

int num_div(int b)
{
	int k = 0;
	int a;
	for(a=1;a*a<=b;a++)
	{
		if(b%a==0) k+=2;
	}
	if((a-1)*(a-1)==b) k--;
	return k;
}

void precom()
{
	arr[0] = 1;
	id = 0;
	while(arr[id]<1000000)
	{
		id++;
		arr[id] = arr[id-1] + num_div(arr[id-1]);
	}
	//printf("%d %d %d\n",id,arr[id],arr[id-1]);
}

int main()
{
	precom();
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		int l = -1;
		int r = -2;
		int lo = 0;
		int hi = id;
		while(lo<=hi)
		{
			int mid = (lo+hi)/2;
			if(arr[mid] >= A) hi = mid-1, l = mid;
			else lo = mid+1;
		}
		lo = 0;
		hi = id;
		while(lo<=hi)
		{
			int mid = (lo+hi)/2;
			if(arr[mid]<=B) lo = mid + 1, r = mid;
			else hi = mid-1;
		}
		printf("Case %d: %d\n",tc,max(r - l + 1,0));
	}
}
