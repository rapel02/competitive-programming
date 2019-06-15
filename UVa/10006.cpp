#include<bits/stdc++.h>
using namespace std;


int arr[]={561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};

int main()
{
	//cprime();
	int p;
	while(1)
	{
		scanf("%d",&p);
		if(p==0) break;
		bool car = false;
		int w = sizeof(arr)/4;
		for(int a=0;a<w;a++)
		{
			if(arr[a]==p) car = true;
		}
		if(car==true) printf("The number %d is a Carmichael number.\n",p);
		else printf("%d is normal.\n",p);
	}
}
