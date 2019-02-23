#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>

//Max source size of the kernel string
#define MAX_SOURCE_SIZE 0x100000

int main(void) {
    //Create 2 input vectors
    int i;
    int LIST_SIZE;
    printf("\nEnter how many elements");
    scanf("%d", &LIST_SIZE);

    int*A = (int*) malloc(sizeof(int) * LIST_SIZE);

    int *B = (int*) malloc(sizeof(int) * LIST_SIZE);
    //Initialize the input vectors
    printf("\nEnter A");
    for (i = 0; i < LIST_SIZE; ++i) {
        scanf("%d",&A[i]);
    }
    
    /*printf("\nEnter B");
    for (i = 0; i < LIST_SIZE; ++i) {
        scanf("%d",&B[i]);
    }*/

    //Load the kernel source code into the array source_str

    FILE*fp;
    char*source_str;
    size_t source_size;
    fp = fopen("vectorCLKernel.cl", "r");
    if (!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        getchar();
        exit(1);
    }
    source_str = (char*) malloc(MAX_SOURCE_SIZE);
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);
    //Get platform and device information
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;

    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    printf("\nGetPlatformIDs=%d\t",ret);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id,
            &ret_num_devices);
    printf("\nGetDeviceIDs=%d\t",ret);
    //Create an OpenCL context
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
    
    //Create a command queue
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id,
            NULL, &ret);

    //Creates memory buffers on the device for each vector A,B and C

    cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE
            * sizeof(int), NULL, &ret);
    /*cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE
            * sizeof(int), NULL, &ret);*/
    cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, LIST_SIZE
            * sizeof(int), NULL, &ret);

    //Copy the lists A and B to their respective memory buffers
    ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, LIST_SIZE
            * sizeof(int), A, 0, NULL, NULL);
    printf("\nEnqueueWriteBuffer=%d\t",ret);
    /*ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, LIST_SIZE
            * sizeof(int), B, 0, NULL, NULL);
    printf("\nEnqueueWriteBuffer=%d\t",ret);*/

    //Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1,
            (const char**) &source_str, (const size_t*) &source_size, &ret);

    //Build the program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    printf("\nBuildProgram=%d\t",ret);   

    //Create the OpenCL kernel object
    cl_kernel kernel = clCreateKernel(program, "vector_add", &ret);

    //Set the arguments of the kernel
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*) &a_mem_obj);
    printf("\nSetKernelArg0=%d\t",ret);
    /*ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*) &b_mem_obj);
    printf("\nSetKernelArg1=%d\t",ret);*/
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*) &c_mem_obj);
    printf("\nSetKernelArg2=%d\t",ret);
    //Execute the OpenCL kernel on the array
    size_t global_item_size = LIST_SIZE;
    size_t local_item_size = 1;

    //Execute the kernel on the device
    cl_event event;
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,
            &global_item_size, &local_item_size, 0, NULL, NULL);
    printf("\nEnqueueNDRangeKernel=%d\t",ret);
    ret = clFinish(command_queue);
    printf("\nFinish=%d\t",ret);
    //Read the memory buffer C on the device to the local variable C
    int*C = (int*) malloc(sizeof(int) * LIST_SIZE);
    ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0, LIST_SIZE
            * sizeof(int), C, 0, NULL, NULL);
    printf("\nEnqueueReadBuffer=%d\t",ret);
    //Display the result to the screen
    printf("\nA= ");
    for (i = 0; i < LIST_SIZE; ++i)
        printf("%d\t", A[i]);
    //printf("\nB= ");
    /*for (i = 0; i < LIST_SIZE; ++i)
        printf("%d\t", B[i]);*/
    printf("\nC= ");
    for (i = 0; i < LIST_SIZE; ++i)
        printf("%d\t", C[i]);



    //Clean up
    ret = clFlush(command_queue);
    printf("\nFlush=%d\t",ret);
    ret = clReleaseKernel(kernel);
    printf("\nReleaseKernel=%d\t",ret);
    ret = clReleaseMemObject(a_mem_obj);
    /*printf("\nmem_object_a=%d\t",ret);
    ret = clReleaseMemObject(b_mem_obj);*/
    printf("\nmem_object_b=%d\t",ret);
    ret = clReleaseMemObject(c_mem_obj);
    printf("\nmem_object_c=%d\t",ret);
    ret = clReleaseCommandQueue(command_queue);
    printf("\nReleaseCommandQueue=%d\t",ret);
    ret = clReleaseContext(context);
    printf("\nReleaseContext=%d\t",ret);
    
    free(A);
    //free(B);
    free(C);
    
    getchar();
    return 0;
}
