#include <stdio.h>

void enter(char* massage, int* variable_int)	//������� ��� ���������� ���������� ���� int
{
	char c;
enter_begin:
	printf("%s", massage);
	do {								//��������� �������� � ������ ������
		c = getchar();
	} while (c == ' ');

	if (c == '\n') goto enter_begin;	//��������� ������ ������

	short minus;						//��������� ������������� �����
	if (c == '-')
	{
		c = getchar();
		minus = -1;
	}
	else
	{
		minus = 1;
	}

	*variable_int = 0;

	while (c >= '0' && c <= '9')
	{
		if (*variable_int * 10 + (int)c - '0' < 0)		//��������� ������ �� ������� int
		{
			while (getchar() != '\n');
			printf("input is too big\n");
			goto enter_begin;
		}
		*variable_int = *variable_int * 10 + (int)c - '0';
		c = getchar();
	}

	while (c == ' ')		//���� ��������� � �������� �� ������������ �����
	{
		c = getchar();
	}

	if (c != '\n')
	{
		while (getchar() != '\n');
		printf("invalid input\n");
		goto enter_begin;
	}
	*variable_int *= minus;
}

int gcd(int a, int b)			//����� ����������� ������ ��������
{
	while (a > 0 && b > 0)
	{
		if (a > b) a = a % b;
		else b = b % a;
	}
	return a + b;
}

int main()
{
	int x, y = 0, z = 0;

	do {												//���� ������
		enter("Enter first number: ", &x);
		if (x < 0)
		{
			printf("invalid input, natural number expacted\n");
		}
	} while (x < 0);
	printf("\n");

	do {
		enter("Enter second number: ", &y);
		if (y < 0)
		{
			printf("invalid input, natural number expacted\n");
		}
	} while (y < 0);
	printf("\n");

	do {
		enter("Enter third number: ", &z);
		if (z < 0)
		{
			printf("invalid input, natural number expacted\n");
		}
	} while (z < 0);
	printf("\n");
	
	if (x > y)
	{
		if (x > z)
		{
			int t = x;
			x = z;
			z = t;
		}
	}
	else
	{
		if (y > z)
		{
			int t = y;
			y = z;
			z = t;
		}
	}

	if (x * x + y * y == z * z)	printf("Pythagorean triple\n");
	else
	{
		printf("Not Pythagorean triple\n");
		return 0;
	}

	if (gcd(x, y) == 1 && gcd(x, z) == 1 && gcd(y, z) == 1) printf("Simple\n");
	else
	{
		printf("Not simple\n");
	}
	return 0;
}