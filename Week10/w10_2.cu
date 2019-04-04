#include <stdio.h>

__global__ void rev(char *a,char *b,int *len)
{
	int id=threadIdx.x;
	b[id]=a[*len-id-1];
	b[*len-id-1]=a[id];
}

int main(void)
{
	char a[20], b[20];
	int *d_m;
	char *d_a, *d_b;

	printf("Enter String:");
	scanf("%s",a);

	int size = sizeof(int)*strlen(a);
	int len=strlen(a);

	cudaMalloc((void**)&d_a,size);
	cudaMalloc((void**)&d_b,size);
	cudaMalloc((void**)&d_m,sizeof(int));

	cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_m, &len, sizeof(int), cudaMemcpyHostToDevice);

	rev<<<1,len>>>(d_a, d_b,d_m);

	cudaMemcpy(&b,d_b, size, cudaMemcpyDeviceToHost);
	printf("%s\n",b);
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_m);
}
