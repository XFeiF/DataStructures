#include<stdio.h>
#include<malloc.h>

int main()
{
	int len;
	int *start;
	int *end;

	printf("Please input Array size:");
	scanf("%d",&len);

	start = (int *)malloc(len*sizeof(int));
	end   = (int *)malloc(len*sizeof(int));

	printf("Input DATA: ");
	for(int i=0;i<len;i++)
		scanf("%d",&start[i]);

	for(int current=0;current<len;current++)
	{
		for(int k=0;k<len-current;k++)
			end[k] = start[current+k];
		for(int t=len-current,j=0;t<len;t++,j++)
			end[t] = start[j];
		printf("After move %d left: ", current);
		for(int m=0;m<len;m++)
			printf("%d ",end[m]);
		printf("\n");
	}

	getchar();
	return 0;
}
