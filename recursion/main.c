#include <stdio.h>




// 递归
void binary_to_ascii(unsigned int value)
{
	unsigned int que;
	que = value/10;
	if(que != 0)
		binary_to_ascic(que);
	printf("the %c\r\n",'0' + value%10);
}

int main()
{
	binary_to_ascic(4267);
	return 0;

}
