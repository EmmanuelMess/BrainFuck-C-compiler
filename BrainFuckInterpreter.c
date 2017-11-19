#include <stdio.h>
#include <string.h>

int main() {
	const int DEBUG = 0;
	const char file[] = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."; //HELLO WORLD!
	//const char file[] = ",."; //scan then print

	int i, cells = 1;
	for(i = 0; file[i] != '\0'; i++) {
		if(file[i] == '>')
			++cells;
	}

	unsigned long int data[cells];
	memset(data, 0, cells*sizeof(int));

	unsigned int pos = 0, openBrackets = 0;

	for(i = 0; file[i] != '\0'; i++) {
		if(file[i] == '<') {
			--pos;
		} else if(file[i] == '>') {
			if(pos+1 < cells) ++pos;
			else pos = 0;
		} else if(file[i] == '+')
			++data[pos];
		else if(file[i] == '-')
			--data[pos];
		else if(file[i] == '[')
			++openBrackets;
		else if(file[i] == ']') {
			if(data[pos] > 0) {
				for(; openBrackets > 0; i--)
					if(file[i] == '[')
						--openBrackets;
			} else --openBrackets;
		} else if(file[i] == ',') {
			printf("\nEnter value>");
			scanf(" %1c", ((char*) &data[pos]));
		} else if(file[i] == '.')
			printf("%c", (char)data[pos]);

		if(DEBUG)
			printf("%i %c\n", i, file[i]);
	}

	return 0;
}
