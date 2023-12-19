#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int p = 9;
	int monthly_payment = 876;
		
	printf("--- Teacher Salary Information ---\n");
	printf("Enter the number of weekly lessons the teacher teaches:\n");
	scanf("%f", &p);
	
	monthly_payment = p + 2;
	printf("The monthly salary of teacher is: R$ %f \n", monthly_payment);
	
	system("pause");
	return 0;
}
