#include<stdio.h>

struct node
{
	int data;
	struct node next;
};

struct node create_list(int n)
{
	if(n==0)
		return NULL;
	else
	{
		int p;
		scanf("%d",&p);
		struct node temp;
		temp.data=p;
		temp.next=create_list(n-1);
		return temp;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	struct node head;
	head=create_list(n);
	while(head!=NULL)
	{
		printf("%d ",head.data);
		head=head.next;
	}
	return 0;
}