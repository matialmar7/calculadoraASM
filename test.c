#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char binaryNumber[] = "11001";
	int bin, dec = 0;
	
	bin = atoi(binaryNumber);

	for(int i = 0; bin; i++, bin /= 10)
		if (bin % 10)
			dec += pow(2, i);

	printf("%d", dec);

	return 0;
}

// This code is contributed by whysodarkbro
