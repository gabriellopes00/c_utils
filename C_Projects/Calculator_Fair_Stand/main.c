#include <stdio.h>
#include <stdlib.h>

int main() {
    int pineapples, dozen_orange;
    float cassava_kilos;

    printf("Quantity of pineapples (unit): ");
    scanf("%d", &pineapples);

    printf("Number of oranges (dozens): ");
    scanf("%d", &dozen_orange);

    printf("Quantity of cassava (kilograms): ");
    scanf("%f", &cassava_kilos);

    float pineapples_price, oranges_price, cassava_price;

    if (pineapples >= 3) {
        pineapples_price = pineapples * 4.00;
    } else {
        pineapples_price = pineapples * 5.00;
    }

    if (dozen_orange >= 2) {
        oranges_price = dozen_orange * 6.00;
    } else {
        oranges_price = dozen_orange * 8.00;
    }

    if (cassava_kilos >= 3.0) {
        cassava_price = cassava_kilos * 3.00;
    } else {
        cassava_price = cassava_kilos * 4.00;
    }

    float total = pineapples_price + oranges_price + cassava_price;

    printf("\nTotal price of pineapples: R$ %.2f\n", pineapples_price);
    printf("Total price of oranges: R$ %.2f\n", oranges_price);
    printf("Total price of cassavas: R$ %.2f\n", cassava_price);
    printf("\nTotal amount spent by the customer: R$ %.2f\n", total);

    return 0;
}

