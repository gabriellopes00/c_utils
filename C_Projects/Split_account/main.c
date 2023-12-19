#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float vl_ac, vl_t, vl_i = 0.0;
	
	printf("--- Split restaurant bill ---\n");
	printf("Enter the total bill amount: \n");
	scanf("%f", &vl_ac);
	
	vl_t = vl_ac * (1 + 10 / 100);
	vl_i = vl_t / 3;
	
	printf("The amount each must pay is: R$%f\n", vl_i);
	
	system("PAUSE"); 
	return 0;
}
