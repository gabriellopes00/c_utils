#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int yb, mb, db, cy, cm, cd, dl = 0;
	
	printf("--- Days lived calculator ---\n");
	printf("Enter your year of birth:\n");
	scanf("%f", &yb);
	
	printf("Enter the current year:\n");
	scanf("%f", &cy);
	
	
	dl = (cy - yb) * 365;
	
	printf("This is the number of days lived: %f\n", dl);
	
	system("PAUSE");	
	return 0;
}
