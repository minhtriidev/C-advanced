#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char *error_message;
enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, error) do {error_message = error; longjmp(buf, (x));} while(0)


void readFile() {
    printf("Reading file...\n");
    THROW(FILE_ERROR, "File not found");
}

void networkOperation() {
    printf("Connecting...\n");
    THROW(NETWORK_ERROR, "Network error");
}

void calculateData() {
    printf("Calculating...\n");
    THROW(CALCULATION_ERROR, "Calculating error");
}

int main(){
    TRY {
        readFile();
        networkOperation();
        calculateData();
    } CATCH(FILE_ERROR) {
        printf("%s\n", error_message);
    } CATCH(NETWORK_ERROR) {
        printf("%s\n", error_message);
    } CATCH(CALCULATION_ERROR) {
    printf("%s\n", error_message);
    }

    return 0;
}

