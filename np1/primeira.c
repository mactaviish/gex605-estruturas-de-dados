#include <stdio.h>

int resto(int minuendo, int subtraendo) {
	int result = 0;
	
	if (minuendo < subtraendo)
		result = minuendo;
	if (minuendo >= subtraendo)
		result = resto(minuendo - subtraendo, subtraendo);
}

int main() {
	int result = resto(11,3);
	printf("%d", result);

	return 0;
}