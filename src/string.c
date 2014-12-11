#include <stdio.h>
#include <stdlib.h>

char *getStr(char *str);

int main(void)
{
	char *abc = "abc";
	char *new_str;
	new_str = getStr(abc);
	//printf("%s", *abc); don't really need this
}

char *getStr(char *str) {
	printf("%s\n", str);
	//return str;
}