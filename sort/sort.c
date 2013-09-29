#include <stdio.h>


/*插入排序*/
/*
1,从第一个元素开始，该元素可以认定已经被排序
2，取出下一个元素，在已经排序的元素序列中中从后向前扫描
3，如果该元素大于新元素，将该元素移动到下一个位置
4，重复步骤3，直到找到已排序的元素小于或者等于元素的位置
5，将新元素插入到该位置后
6，重复步骤2~5
*/
static void insertion_sort(int argv[],int length)
{
	int i;
	int j;
	int temp;
	for(i=1;i<length;i++){
		if(argv[i-1] > argv[i]){
		temp = argv[i];
		j=i;	
		while(j>0 && argv[j-1] > temp){
			argv[j]=argv[j-1];
			j--;
		}
		argv[j]=temp;
		}
	}

}

/*
args first >=1
*/
static void inter_sort(int argv[],int first,int last)
{
	int i;j;
	int temp;
	for(i= first+1;i<=last;i++){
	if(argv[first] > argv[i]){
		temp = argv[i];
		j=i-1;
		while(j>0 && argv[j-1] > temp){
			argv[j] = argv[j-1];
			j--;
		}
		argv[i] = temp;
	}
	}

}

/*选择排序法*/
void select_sort(int argv[],int length)
{
	int inner,outer;
	int temp;
	int index;
	int value;
	if(argv == NULL || length =0)
		return 0;
	for(outer = 0; outer<length-1 ;outer++)
	{
		value = argv[outer];
		index = outer;
		for(inner=outer+1;inner<length;inner++)
		{
			if(argv[inner] < value){
			value = argv[inner];
			index = inner;
			}
		}
		if(index = outer) continue;
		temp = argv[index];
		argv[index] = argv[outer];
		argv[outer] = temp;
	} 

}


/*冒泡排序*/
void bubb_sort(int argv, int length)
{
	

}
