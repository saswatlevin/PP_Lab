include <stdio.h>

__global__ void sub(char *a,char *b,int *lenA,int *lenB)
{
	int id=threadIdx.x;
	int flag=1;
	for(int i=0;i<*lenB;i++)
	{
		if(a[id+i]!=b[i])
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		printf("FOUND\n");
}

int main()
{
	char a[20], b[20];
	int *d_m,*d_v;
	char *d_a, *d_b;

	printf("Enter String:");
	scanf("%s",a);
	printf("Enter Sub String:");
	scanf("%s",b);

	int sizeA = sizeof(char)*strlen(a);
	int sizeB = sizeof(char)*strlen(b);
	int lenA=strlen(a);
	int lenB=strlen(b);

	cudaMalloc((void**)&d_a,sizeA);
	cudaMalloc((void**)&d_b,sizeB);
	cudaMalloc((void**)&d_m,sizeof(int));
	cudaMalloc((void**)&d_v,sizeof(int));

	cudaMemcpy(d_a, &a, sizeA, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, &b, sizeB, cudaMemcpyHostToDevice);
	cudaMemcpy(d_m, &lenA, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_v, &lenB, sizeof(int), cudaMemcpyHostToDevice);

	sub<<<1,lenA>>>(d_a, d_b,d_m,d_v);
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_m);
	cudaFree(d_v);
}

