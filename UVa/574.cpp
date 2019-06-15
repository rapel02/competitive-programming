#include<bits/stdc++.h>
using namespace std;

int arr[15];
int ans[15];
int rem[15];
bool ada;
int n,r;
FILE *fp = fopen("574.txt","w");

void compute(int val,int pos,int k)
{
	if(val==0)
	{
		bool diff = true;
		for(int a=0;a<k;a++)
			if(rem[a]!=ans[a]) diff = false;
		if(diff==true) return ;
		for(int a=0;a<k;a++)
		{
			if(a!=0) fprintf(fp,"+");
			fprintf(fp,"%d",ans[a]);
			rem[a] = ans[a];
		}
		ada = true;
		fprintf(fp,"\n");
		return ;
	}
	else if(pos==r) return ;
	else
	{
		int rem = r;
		if(val-arr[pos]>=0)
		{
			ans[k] = arr[pos];
			compute(val-arr[pos],pos+1,k+1);
		}
		for(int a=pos;a<r;a++)
		{
			if(arr[a]!=arr[pos])
			{
				compute(val,a,k);
			}
		}
	}
	return ;
}

int main()
{
	while(1)
	{
		memset(rem,0,sizeof(rem));
		ada = false;
		scanf("%d %d",&n,&r);
		if(n+r==0) break;
		for(int a=0;a<r;a++) scanf("%d",&arr[a]);
		for(int a=0;a<r;a++)
		{
			int rem = a;
			for(int b=a+1;b<r;b++)
			{
				if(arr[rem]<arr[b])
				{
					rem = b;
				}
			}
			swap(arr[rem],arr[a]);
		}
		fprintf(fp,"Sums of %d:\n",n);
		compute(n,0,0);
		if(ada==false) fprintf(fp,"NONE\n");
	}
}
