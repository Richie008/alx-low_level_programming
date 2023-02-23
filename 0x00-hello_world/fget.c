#include <stdio.h>

int main(void)
{
	char name[100];
	int age;
	printf("what is your name");
	fgets(name, 100, stdin);
	printf("what is your age");
	scanf("%d", age);

	printf("your name is %s. You are %d years" name, age);
	puts("your info is under");
	puts(name);
	puts("%d", age);
	
	return (0);
}
