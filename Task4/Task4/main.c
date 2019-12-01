#include <stdio.h>
#include <math.h>
#include <time.h>

void LLT(int p)
{
	long long S = 4;
	long long M = pow(2, p) - 1;
	for (int i = 2; i < sqrt(p); i++)		//���� p ���������, �� M ���� ���������
		if (p % i == 0)
			return 0;
	for (int i = 1; i < p - 1; i++)		    //���� ���� � ������
	{
		S = (S * S - 2) % M;
	}
	if (S == 0 || p == 2)
		printf("%lld\n", M);
}

int main()
{
	for (int i = 1; i < 32; i++)
	{
		LLT(i);
	}
}