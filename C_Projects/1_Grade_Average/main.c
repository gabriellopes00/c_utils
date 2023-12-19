#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float m, a, b = 0.0;
  unsigned int i;
  
  printf("--- Average calculator ---\n");

  printf("Enter your first note:\n");
  scanf("%f", &a);
  
  printf("Enter your second note:\n");
  scanf("%f", &b);
  
  
  if(n1 >= 0.0 && n1 <= 10.0 && n2 >= 0.0 && n2 <= 10.0 && n3 >= 0.0 && n3 <= 10.0){
  	a = (n1 + n2 + n3) / 3;
  	printf("Your final grade is: %f\n", a);
  } else {
  	printf("Please enter a grade from 0 to 10.\n");
  }
  
  system("PAUSE");	
  return 0;
}
