#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float distance, price_liter, consumption, total_price, total_liters = 0.0;
	
	printf("--- Travel cost ---\n");
	printf("Enter the distance to be covered: \n");
	scanf("%f", &distance);

	printf("Enter price per liter of fuel (any type): \n");
	scanf("%f", &price_liter);
	
	printf("Enter the mileage the vehicle does per liter of fuel (distance driven on 1 liter): \n");
	scanf("%f", &consumption);
	
	total_liters = distance / consumption;
	total_price = (distance / consumption) * price_liter;
	
	printf("The amount of liters that will be needed to cover the given distance is: %f\n", total_liters);
	printf("The total cost of the trip will be: R$%f\n", total_price);
	
	system("PAUSE");
	return 0;
}
