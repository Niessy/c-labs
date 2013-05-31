#include <stdio.h>

/* Parse Tokens */

#define ZERO 0
#define WS 1
#define OCT 2
#define HEX 3
#define DEC 4
#define ILL 5
#define XSTATE 6
#define DECL 7
#define HEXL 8
#define OCTL 9

int updateValue(int, int, int);
int whatState(int, int);
int isDigit(int);
int isZero(int);
int isOctal(int);
int isWhiteSpace(int);
int isIllegal(int);
int isHex(int);
void outputState(int, int, int);

int main(int argc, char ** argv) {

	int state = 1;
	int c, d;
	int number = 0;
	
	while ( (c = getchar()) != EOF ) {	
		if ( isWhiteSpace(c) && state != WS ) {
			++number;
			outputState(state, d, number);	
			state = WS;
			d = 0;
		} else if ( isWhiteSpace(c) ) {
			state = WS;
		} else {
			state = whatState(c, state);
			d = updateValue(state, d, c);
		}
		
	}
	return 0;
}

int updateValue(int state, int d, int c) {
	/* Update decimal value based on state */
	if ( state == OCTL || state == DECL || state ==  HEXL ) {
		return d;
	}
	if ( state == DEC ) {
		return d * 10 + (c - '0');
	} else if ( state == OCT ) {
		return d * 8 + (c - '0');	
	} else if ( state == HEX ) {
		if ( c >= '0' && c <= '9' ) {
			return d * 16 + ( c - '0' );
		} else if ( c >= 'a' && c <= 'f' ) {
			return d * 16 + ( c - 'a' + 10 );
		} else if ( c >= 'A' && c <= 'F' ) {
			return d * 16 + ( c - 'A' + 10 );
		}
	}
	return 0;
}

int whatState(int c, int state) {
	/* If it's illegal it's still illegal */
	if ( state == ILL ) {
		return state;
	}

	/* Possible states from whitespace */
	if ( isZero(c) && state == WS ) {
		return ZERO;
	} else if ( isDigit(c) && state == WS ) {
		return DEC;
	} else if ( isIllegal(c) && state == WS) {
		return ILL;
	} 
	
	/* Possible states from zero */
	if ( isOctal(c) && state == ZERO ) {
		return OCT;
	} else if ( (c == 'x' || c == 'X' ) && state == ZERO ) {
		return XSTATE;
	}

	/* Possible states from OCT */
	if ( isOctal(c) && state == OCT ) {
		return OCT;
	} else if ( c == 'L' && state == OCT ) {
		return OCTL;
	}

	/* Possible states from HEX */
	if ( isHex(c) && ( state == HEX || state == XSTATE ) ) {
		return HEX;
	} else if (c == 'L' && state == HEX) {
		return HEXL;
	}

	/* Possible states from DEC */
	if ( isDigit(c) && state == DEC ) {
		return DEC;
	} else if ( isZero(c) && state == DEC ) {
		return DEC;
	} else if ( c == 'L' && state == DEC) {
		return DECL;
	}

	return ILL;
}

int isWhiteSpace(int c) {
	if ( c == ' ' || c == '\n' ) {
		return 1;
	}
	return 0;
}

int isDigit(int c) {
	if ( c >= '1' && c <= '9') {
		return 1;
	}
	return 0;
}

int isOctal(int c) {
	if ( c >= '0' && c <= '7') {
		return 1;
	}
	return 0;
}

int isIllegal(int c) {
	if ( c >= '0' && c <= '9') {
		return 0;
	}
	return 1;
}

int isZero(int c) {
	if (c == '0') { 
		return 1; 
	}
	return 0;
}

int isHex(int c) {
	if ( c >= '0' && c <= '9') {
		return 1;
	} else if ( c >= 'a' && c <= 'f') {
		return 1;
	} else if ( c >= 'A' && c <= 'F') {
		return 1;
	}
	return 0;
}

void outputState(int state, int d, int number) {
	printf("%d\t", number);
	switch ( state ) {
		case DEC:
			printf("decimal -> %d", d);
			break;
		case OCT:
			printf("octal -> %d", d);
			break;
		case HEX:
			printf("hex -> %d", d);
			break;
		case ZERO:
			printf("decimal -> %d", d);
			break;
		case DECL:
			printf("decimal -> %d (long)", d);
			break;
		case OCTL:
			printf("octal -> %d (long)", d);
			break;
		case HEXL:
			printf("hex -> %d (long)", d);
			break;
		case XSTATE:
			printf("illegal");
			break;
		case ILL:
			printf("illegal");
			break;
	}
	printf("\n"); 
}
