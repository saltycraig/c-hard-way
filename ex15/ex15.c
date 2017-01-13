#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa" };

	// first way
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	
	for (i = 0; i < count; i++) {
		printf("%s had %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	// second way - better but not optimal
	int *cur_age = ages;
	char **cur_name = names;

	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n", 
			*(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	// third way - best option
	for (i = 0; i < count; i++) {
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// fourth way - super fast but error prone
	for (cur_name = names, cur_age = ages; 
		(cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
	
	return 0;
}