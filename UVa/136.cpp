#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k =0;
	for(int a=1;a<=1000000000;a++)
	{
		int c = a;
		while(c%2==0) c/=2;
		while(c%3==0) c/=3;
		while(c%5==0) c/=5;
		if(c==1)
		{
			k++;
			if(k==1500)
			{
				printf("The 1500'th ugly number is %d.\n",a);
				break;
			}
		}
	}
	printf("The 1500'th ugly number is 859963392.\n");
}
