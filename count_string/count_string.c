/*
统计一个字符串中有多少个单词，每个单词是以空格隔开，
	主要使用到状态机的思想
分为 初始化状态 空格状态 字符状态
	初始化状态 如果为空格，则为空格状态，如果为字符状态，count加一，切换到字符状态
	字符状态   如果为空格，则为空格状态，如果为字符，不用处理，直接返回，结束，返回count
	空格状态   如果为空格
	
*/
#include <stdio.h>

typedef enum {
	Init_state=1,
	Work_state,
	Spac_state,	
};


int count_strings(char *ptr)
{
	int count = 0;
	int state = Init_state;
	char value;
	
	while(1)
	{
		value = *ptr++;
		switch(state){
			case Init_state :
				if(' ' != value){
			        count++; state=Work_state;
				} else{
				state=Spac_state;
				}
				break;
					
			case Work_state :
				if(' ' == value) state=Spac_state;
				else if('\0' == value) return count;
				break;
			case Spac_state : 
				if(' ' != value){
					count++;
					state=Work_state;
				}
				else if('\0' == value) return count;
				break;	
		}


	}




} 


int main(int argc,char **argv)
{

	printf("the count of string is %d\r\n",count_strings("asd"));	
	printf("the count of string is %d\r\n",count_strings("asdi asdsaf asfd"));

	return 0;
}
