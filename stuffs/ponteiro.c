#include <stdio.h>

void main() {

int x = 10; 
int *pont;

pont = &x;

int y = 20;
pont = y;

printf("%i %i\n", x, y);
printf("%i " ,pont);
getchar();


}