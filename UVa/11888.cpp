#include<bits/stdc++.h>
using namespace std;

string in1,in2;

int T[250000];
int len1;

void pre()
{
	int i=-1,j = 0;
	T[j] = i;
	while(j!=len1)
	{
		while(i>=0 && in1[i]!=in1[j]) i = T[i];
		i++;
		j++;
		T[j] = i;
	}
}

int search(int len2)
{
	int i=0,j = 0;
	while(j!=len2)
	{
		while(i>=0 && in1[i]!=in2[j]) i = T[i];
		i++;
		j++;
	}
	return i;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int palin = 0;
		cin>>in1;
		in2 = in1;
		len1 = in1.length();
		pre();
		reverse(in2.begin(),in2.end());
		int ans = search(in2.length());
		if(ans == len1)
		{
			palin = 1;
			int mid = in2.length()/2;
			int t = search(mid);
			if(t == mid)
			{
				bool ada = true;
				for(int a=mid;a<len1;a++)
				{
					if(in1[a] != in1[len1 - 1 - a + mid] ) ada = false;
				}
				if(ada) palin = 2;
			}
		}
		else
		{
			bool ada = true;
			for(int a=ans;a<len1;a++)
			{
				if(in1[a] != in1[len1-a+ans - 1]) ada = false;
			}
			if(ada) palin = 2;
		}
		if(palin == 2) printf("alindrome\n");
		else if(palin == 1) printf("palindrome\n");
		else printf("simple\n");
	}
}
