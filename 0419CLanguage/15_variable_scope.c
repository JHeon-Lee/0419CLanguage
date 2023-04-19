#include <stdio.h>

int global; // ���� ���� - ��𿡼��� ���� ����

char var1 = 'G';

void LocalCount();
void StaticCount();

int main()
{
	int a; // ���� ����

	printf("�ʱ�ȭ ���� ���� global �� : %d\n", global); // ---> 0�� ����

	printf("main������ var 1 : %c\n", var1);
	{
		char var1 = 'L';
		printf("{}������ var 1 : %c\n", var1); // --> �������� �켱��, L
	}
	printf("main������ var 1 : %c\n", var1); // --> �ٽ� �������� ���� G

	for (int i = 0; i < 5; i++)
	{
		;
	}
	
	for (int i = 0; i < 5; i++)
	{
		LocalCount(); // count�� LocalCount��  ���������̹Ƿ� ���꿡 ���þ��� 1�� ���
		StaticCount(); // static�� ���� ����
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

// ���������� ���� ��� ���ϴ°� ����

// static ���� - ��������, ���������� ������ ����������