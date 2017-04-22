#include<iostream>
#define LL long long
using namespace std;
const int N=100000+5; 
bool prime[N];
int p[N],tot;
void init()
{
	for(int i=2;i<N;i++)
		prime[i]=true;
	for(int i=2;i<N;i++)
	{
		if(prime[i]) p[tot++]=i;
		for(int j=0;j<tot&&i*p[j]<N;j++)
		{
			prime[i*p[j]]=false;
			if(i%p[j]==0) break;
		}
	}
} 
int a[100005];
int main()
{
	init(); 
	LL n,k,j=0,cot=0,flag=1;
	cin>>n>>k;
	int i=0;
	while(n)
	{
		if(n==1)
		{
			flag=0;break;
		}
		if(cot==k-1)
		{
			a[j]=n;
			break;
		}
			
		if(prime[n])
		{
			if(cot==k-1)
			{
				a[j]=n;
				break;
			}
			else
			{
				if(cot<k-1) flag=0;
			}
		}
		if(n%p[i]==0)
		{
			a[j++]=p[i];
			cot++;
			n/=p[i];
		} 
		else
		{
			i++;
		}
		if(cot==k) break;
	}
	a[j]=n;
	if(!flag)
		cout<<-1;
	else
	{
		for(int i=0;i<=j;i++)
		{
			cout<<a[i]<<" ";
		}
	}
}
