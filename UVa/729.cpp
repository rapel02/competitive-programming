#include<bits/stdc++.h>
using namespace std;

int arr[20];
int n,h;

void process(int pos,int res)
{
	if(res < 0) return ;
	if(pos < res) return ;
	if(pos == 0)
	{
		for(int a=0;a<n;a++) printf("%d",arr[a]);
		printf("\n");
		return ;
	}
	for(int a=0;a<2;a++)
	{
		arr[n - pos] = a;
		int red = 0;
		if(a == 1) red = 1;
		process(pos-1,res-red);
	}
	return ;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	bool isf = true;
	while(tc--)
	{
		if(!isf) printf("\n");
		isf = false;
		scanf("%d %d",&n,&h);
		process(n,h);
	}
}
