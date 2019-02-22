__kernel void vector_add(__global int *A,__global int* C){
//Get the index of the current work item
int i=get_global_id(0);
//Do the operation
int dec = A[i];
	int oct = 0, r, p = 1;
	while (dec != 0) {
		r = dec % 8;
		oct = oct + p * r;
		dec /= 8;
		p *= 10;
	}
C[i] = oct
   
}
