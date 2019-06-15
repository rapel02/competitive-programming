#include<bits/stdc++.h>
using namespace std;

int arr[10];

bool compute(int tot,int id)
{
	if(id==5 && tot==23)  return true;
	if(id==5) return false;
	for(int a=0;a<3;a++)
	{
		if(a==0 && compute(tot+arr[id],id+1)==true) return true;
		if(a==1 && compute(tot-arr[id],id+1)==true) return true;
		if(a==2 && compute(tot*arr[id],id+1)==true) return true;
	}
	return false;
}

int main()
{
	while(1)
	{
		int tot = 0;
		
		for(int a=0;a<5;a++)
		{
			scanf("%d",&arr[a]);
			tot+=arr[a];
		}
		if(tot==0) break;
		sort(arr,arr+5);
		bool ans = false;
		do
		{
			if(compute(arr[0],1)==true) ans = true;
		}while(next_permutation(arr,arr+5));
		if(ans==true) printf("Possible\n");
		else printf("Impossible\n");
	}
}
