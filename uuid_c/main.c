#include <sys/random.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned short int genhex()
{

	// Generate a number less than 0x67.
	unsigned short int n = rand() % 0x67;

	// If in range, return generated number.
	if ((n > 0x2f && n < 0x3a) || (n > 0x60 && n < 0x67))
		return n;
	
	// Recursively run again to generate a proper number.
	return genhex();
}

int main()
{
	// Initialise rng.
	time_t *t = (time_t *) malloc(sizeof(time_t));
	srand((unsigned) time(t));

	// Initialise uuid array.
	const size_t LENGTH = 36;
	unsigned short int uuid[LENGTH];

	// Fill array.
	for (int i = 0; i < LENGTH; i++) {
		if (i == 8 || i == 13 || i == 18 || i == 23) {
			uuid[i] = 0x2d;
			i++;
		}
		uuid[i] = genhex();
	}

	// Convert UUID into text.
	char str[LENGTH];
	for (int i = 0; i < 36; i++)
		str[i] = (char) uuid[i];
	

	// Print UUID and exit. 
	printf("%s\n", str);
	return 0;
}
