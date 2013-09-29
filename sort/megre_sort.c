#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void __merge_sort(int argv[],int start,int end);
void _merge_data_in_array(int array[], int start, int middle, int end);

void merge_sort(int argv[],int length)
{
	if(NULL == argv || length==0)
		return;
	__merge_sort(argv,0,length-1);  
}


void __merge_sort(int argv[],int start,int end)
{
	if(start >= end) return;
	int middle = start + ((end-start) >>1);
	__merge_sort(argv,start,middle);
	__merge_sort(argv,middle+1,end);
	_merge_data_in_array(argv,start,middle,end);
}

void _merge_data_in_array(int array[], int start, int middle, int end)  
{  
    int length = end - start + 1;  
    int *pData = NULL;  
    int left = start;  
    int right = middle + 1;  
    int all = 0;  
  
    /* allocate new memory to the space */  
    pData = (int*) malloc(sizeof(int) * length);  
//    assert(NULL != pData);  
    memset(pData, 0, length);  
  
    /* begin to move data */  
    while(right <= end){  
        while(array[left] <= array[right] && left <= middle){  
            pData[all] = array[left]; left ++; all ++;  
        }  
  
        if(left > middle)  {  
            break;  
        }  
  
        while(array[left] > array[right] && right <= end){  
            pData[all] = array[right]; right ++; all ++;  
        }  
    }  
  
    /* move the left data */  
    if(left <= middle)  
        memmove(&pData[all], &array[left], sizeof(int) * (middle -left +1));  
  
    if(right <= end)  
        memmove(&pData[all], &array[right], sizeof(int) * (end - right + 1));  
      
    memmove(&array[start], pData, sizeof(int) * length);  
    free(pData);  
} 


int main(int argc,char **argv)
{
	int argv1[5] = {4,2,6,3,8};
	merge_sort(argv1,5);
	printf("%d %d %d %d %d \r\n",argv1[0],argv1[1],argv1[2],argv1[3],argv1[4]);

}
