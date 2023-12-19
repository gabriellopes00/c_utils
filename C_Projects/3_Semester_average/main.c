#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
   float n1, n2, n3, n4, a = 0.0;
	
   printf("--- Semester average calculator ---\n");

   printf("Enter the face-to-face activity notes: \n");
   scanf("%f", &n1);

   printf("Enter the online activity notes: \n");
   scanf("%f", &n2);

   printf("Enter the first exam note: \n");
   scanf("%f", &n3);
   
   printf("Enter the second exam note: \n");
   scanf("%f", &n4);

   if(n1 >= 0.0 && n1 <= 10.0 && n2 >= 0.0 && n2 <= 10.0 && n3 >= 0.0 && n3 <= 10.0 && n4 >= 0.0 && n4 <= 10.0){
     a = (n1 * 10)/ 100 + (n2 * 20)/ 100 + (n3 * 30)/ 100 + (n4 * 40)/ 100;
     printf("Your final grade is: %f\n", a);
   } else {
     printf("Please enter a grade from 0 to 10.\n");
   }
 	
   system("PAUSE");	
   return 0;
}
