#include <stdio.h>
#include <stdlib.h>

/* Compute statistics about input */
void outputResult(long); 
void outputDigits(long);
void outputCommaAndPeriod(long);
void outputLowercase(long);
void outputUppercase(long);

int main(int argc, char ** argv)
{
	long letters = 0;
	int c;

	while ( (c = getchar()) != EOF ) {	
		
		putchar(c);
		if (c >= '0' && c <= '9') {
			long spot = (1L << (c - '0'));
			if ((letters & spot) != spot) {
				letters += spot;
			}
		} else if (c == '.') {
			long spot = (1L << 10);
			if ((letters & spot) != spot) {
				letters += spot;
			}
		} else if (c == ',') {
			long spot = (1L << 11);
			if ((letters & spot) != spot) {
				letters += spot;
			}
		} else if (c >= 'A' && c <= 'Z') {
			long spot = (1L << (c - 53));
			if ((letters & spot) != spot) {
				letters += spot;
			}
		} else if (c >= 'a' && c <= 'z') {
			long spot = (1L << (c - 59));
			if ((letters & spot) != spot) {
				letters += spot;
			}
		}
		
		if ( c == '\n') {
			outputResult(letters);
			letters = 0;
		}
	}
	return 0;
}

void outputResult(long letters) {
	outputDigits(letters);
	outputCommaAndPeriod(letters);
	outputLowercase(letters);
	outputUppercase(letters);
	printf("\n");
}


void outputDigits(long letters) {
	int i;
	printf("digits '0'-'9':\t");
	for (i = 0; i < 10; ++i) {
		long spot = (1L << i);
		long res = letters & spot;
		if ( res == spot ) {
			printf(" %d", i);
		}
	}
	printf("\n");
}

void outputCommaAndPeriod(long letters) {
	int i;
	printf("period & comma:\t");
	for (i = 10; i < 12; ++i) {
		long spot = (1L << i);
		long res = letters & spot;
		if ( res == spot) {
			if (i == 10) {
				printf(" .");
			} else if (i == 11) {
				printf(" ,");
			}
		}
	}
	printf("\n");
}

void outputLowercase(long letters) {
	int i;
	printf("lower letters:\t");
	for (i = 38; i < 64; ++i) {
		long spot = (1L << i);
		long res = letters & spot;
		if ( res == spot ) {
			printf(" %c", (char)(i + 59));
		}
	}
	printf("\n");
}

void outputUppercase(long letters) {
	int i;
	printf("upper letters:\t");
	for (i = 12; i < 38; ++i) {
		long spot = (1L << i);
		long res = letters & spot;
		if ( res == spot ) {
			printf(" %c", (char)(i + 53));
		}
	}
	printf("\n");
}
