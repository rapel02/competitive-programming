#include<bits/stdc++.h>
using namespace std;

char name1[10004],name2[1005];

int main()
{
	while(scanf("%[^\n]",name1)!=EOF)
	{
		getchar();
		int len=strlen(name1);
		int tot1=0;
		for(int a=0;a<len;a++)
		{
			if(tolower(name1[a])>='a' && tolower(name1[a])<='z')tot1+=(tolower(name1[a])-'a'+1);
		}
		while(tot1>=10)
		{
			int k=tot1;
			int temp=0;
			while(k!=0)
			{
				temp=temp+k%10;
				k/=10;
			}
			tot1=temp;
		}
		scanf("%[^\n]",name2);  getchar();
		int lens=strlen(name2);
		int tot2=0;
		for(int a=0;a<lens;a++)
		{
			if(tolower(name2[a])>='a' && tolower(name2[a])<='z')tot2+=(tolower(name2[a])-'a'+1);
		}
		while(tot2>=10)
		{
			int k=tot2;
			int temp=0;
			while(k!=0)
			{
				temp=temp+k%10;
				k/=10;
			}
			tot2=temp;
		}
		printf("%.2f %%\n",(100.00*min(tot1,tot2))/max(tot1,tot2));
	}
}
