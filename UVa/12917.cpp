#include<bits/stdc++.h>
using namespace std;

int main()
{
	int p,h,o;
	while(cin>>p>>h>>o) printf("%s win!\n",(o-p < h)?"Hunters":"Props");
}
