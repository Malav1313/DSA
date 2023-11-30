#include <stdio.h>

float area_of_trapezium(float a, float b, float h) {
  return 0.5 * (a + b) * h;
}

int main() {
  float a, b, h, area;

  printf("Enter the length of sides of the trapezium: ");
  scanf("%f %f", &a, &b);

  printf("Enter the height of the trapezium: ");
  scanf("%f", &h);

  area = area_of_trapezium(a, b, h);

  printf("The area of the trapezium is: %f\n", area);

  return 0;
}