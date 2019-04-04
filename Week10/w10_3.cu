#include <stdio.h>

__global__ void rev(char *a,int *len)
{
	int id=threadIdx.x;
	int val=a[id];
	int k=1;
	int sum=0;
	while(val>0)
	{
		int rem=val%2;
		rem*=k;
		k*=10;
		val/=2;
		sum+=rem;
	}
	printf("%c\t%d\n",a[id],sum);
}

int main()
{
	char a[20];
	int *d_m;
	char *d_a;

	printf("Enter String:");
	scanf("%s",a);

	int size = sizeof(int)*strlen(a);
	int len=strlen(a);

	cudaMalloc((void**)&d_a,size);
	cudaMalloc((void**)&d_m,sizeof(int));

	cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_m, &len, sizeof(int), cudaMemcpyHostToDevice);

	rev<<<1,len>>>(d_a,d_m);
	cudaFree(d_a);
	cudaFree(d_m);
}
