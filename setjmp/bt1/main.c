//ví dụ phép chia có a,b thuộc khoảng [0; 100] 

//exception 1: b == 0
//exception 2: a < 0 || a > 100 || b < 0 || b > 100
/*------------------------------------------------*/
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char *error_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, error) do {error_code = error; longjmp(buf, (x));} while(0)


double divide(int a, int b) {
    if (b == 0) {
        THROW(1, "Error: Divide by 0!\n"); // Mã lỗi 1 cho lỗi chia cho 0
    }
    else if (a < 0 || a > 100 || b < 0 || b > 100)
    {
        THROW(2, "Error: a or b is not in the range [0; 100]!\n"); // Mã lỗi a, b không thuộc khoảng [0; 100]
    }
    return (double)a / b;
}

int main() {
    int a = 100;
    int b = -10;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("%s\n", error_code);
    } CATCH(2){
        printf("%s\n", error_code);
    }
    return 0;
}
