#include <stdio.h>
#include "math_utils.h" // Bao gồm file tiêu đề

// Định nghĩa hàm đã khai báo trong file tiêu đề
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

float div(float a, float b) {
    return (a / b);
}


// Chương trình chính
int main() {
    printf("Sum of 3 and 5 is %d\n", add(3, 5));
    printf("Difference  of 3 and 5 is %d\n", sub(3, 5));
    printf("Product of 3 and 5 is %d\n", mul(3, 5));
    printf("Quotient of 3 and 5 is %f\n", div(3, 5));

    return 0;
}