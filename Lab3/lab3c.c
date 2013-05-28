#include <stdio.h>
#define MAX_SIZE 20

void getReverse(char dest[], char src[]);

int main(int argc, const char *argv[])
{
	char src[MAX_SIZE];
	char dest[MAX_SIZE];
	while ( scanf(" %[^\n]s", src) != EOF ) {
		getReverse(dest, src);
		printf("%s\n", dest);
		printf("\n");
	}
	return 0;
}

void getReverse(char dest[], char src[]) {
	int i = 0;
	while (src[i] != '\0') {
		i += 1;		
	}
	int j;
	dest[i] = '\0';
	int k = i - 1;
	for (j = 0; j < i; j++) {
		dest[j] = src[k];	
		k -= 1;
	}
}
