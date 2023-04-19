#include <stdio.h>

int global; // 전역 변수 - 어디에서든 접근 가능

char var1 = 'G';

void LocalCount();
void StaticCount();

int main()
{
	int a; // 지역 변수

	printf("초기화 하지 않은 global 값 : %d\n", global); // ---> 0이 잡힘

	printf("main에서의 var 1 : %c\n", var1);
	{
		char var1 = 'L';
		printf("{}에서의 var 1 : %c\n", var1); // --> 지역변수 우선시, L
	}
	printf("main에서의 var 1 : %c\n", var1); // --> 다시 전역변수 찍힘 G

	for (int i = 0; i < 5; i++)
	{
		;
	}
	
	for (int i = 0; i < 5; i++)
	{
		LocalCount(); // count가 LocalCount의  지역변수이므로 연산에 관련없이 1만 뜬다
		StaticCount(); // static은 값이 증가
	}

	return 0;
}

void LocalCount()
{
	int count = 1;

	printf("local count : %d\n", count);
	count++;

	return;
}

void StaticCount()
{
	static int count = 1;
	printf("static count : %d\n", count);
	count++;
}

// 전역변수는 많이 사용 안하는게 좋음

// static 변수 - 지역변수, 전역변수의 장점을 가지고있음