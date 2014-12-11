#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	srand(time(NULL) * 0x0000444400004444LL);
	long long int a = rand();
	long long int b = rand();
	long long int c = rand();
	printf("%llu\n", a * b * c);
}
