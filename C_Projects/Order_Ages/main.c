#include <stdio.h>
#include <string.h>

int main() {
    char name1[50], name2[50];
    int age1, age2;

    printf("Enter the name of the first student: ");
    scanf("%s", name1);
    printf("Enter the age of the first student: ");
    scanf("%d", &age1);

    printf("Enter the name of the second student: ");
    scanf("%s", name2);
    printf("Enter the age of the second student: ");
    scanf("%d", &age2);

    if (age1 == age2) {
        printf("The ages given are the same. The program will be terminated.\n");
        return 1;
    }

    if (age1 > age2) {
        char temp_name[50];
        int temp_age;

        strcpy(temp_name, name1);
        temp_age = age1;

        strcpy(name1, name2);
        age1 = age2;

        strcpy(name2, temp_name);
        age2 = temp_age;
    }

    printf("Students sorted by age:\n");
    printf("Name: %s, Age: %d\n", name1, age1);
    printf("Name: %s, Age: %d\n", name2, age2);

    return 0;
}

