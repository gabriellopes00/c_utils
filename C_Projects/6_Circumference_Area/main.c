#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float a, r = 0.0;
	
	printf("--- Calculation of the circumference area ---\n");
	printf("Enter the radius of the circle\n");
	scanf("%f", &r);
	
	a = 3.14 * (r * r);
	
	printf("The area of the circle is: %f\n", a);
	
	system("pause");
	return 0;
}
