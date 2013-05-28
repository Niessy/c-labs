#include <stdio.h>

/* 
 *  IF return the same result as FF because
 *  the Integer passed in is converted to a float.
 *  In IF it's by operation is FF it's converted
 *  via function argument.
 *
*/

float cal_IF (int, char, float);
float cal_II (int, char, int);
float cal_FF (float, char, float);

int main(int argc, char ** argv)
{
	int first;
	float second;
	char op;

	while (1) {
		printf("Enter operand_1 operator operand_2 separated by blanks>");	
		scanf("%d %c %f", &first, &op, &second);

		if (first == -1 && second == -1) { 
			return 0.0;
		}

		printf("Your input '%d %c %f' result in %f (calIF) and %f (calII) and %f cal(FF)\n",
				first, op, second, cal_IF(first, op, second), cal_II(first, op,second),
				cal_FF(first, op, second));
		printf("\n");
	}

	return 0;
}


float cal_IF (int first, char  op, float second) {
	switch (op) {
		case '/':
			return first / second;
		case '+':
			return first + second;
		case '*':
			return first * second;
		case '-':
			return first - second;
	}
	return 0.0;
}

float cal_II (int first, char op, int second) {
	switch (op) {
		case '/':
			return first / second;
		case '+':
			return first + second;
		case '*':
			return first * second;
		case '-':
			return first - second;
	}
	return 0.0;
}

float cal_FF (float first, char op, float second) {
	switch (op) {
		case '/':
			return first / second;
		case '+':
			return first + second;
		case '*':
			return first * second;
		case '-':
			return first - second;
	}
	return 0.0;
}
