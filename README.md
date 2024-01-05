# C-advanced

Trần Minh Trí

Lịch học: thứ 3, 5, 7; 8:9 pm

---

## **MỤC LỤC**

[**LESSON 1: MACRO**](#Lesson1)

- [**I. Quá trình biên dịch một chương trình C/C++**](#Quá-trình-biên-dịch-một-chương-trình-C)
    - [**1.Định nghĩa**](#1-định-nghĩa)
    - [**2. Hoạt động**](#2-hoạt-động)
        - [**a. Giai đoạn tiền xử lý – Preprocessor** ](#a-giai-đoạn-tiền-xử-lý-–-preprocessor)
        - [**b. Công đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly**](#b-công-đoạn-dịch-ngôn-ngữ-bậc-cao-sang-assembly)
        - [**c. Công đoạn dịch Assembly**](#c-công-đoạn-dịch-assembly)
        - [**d. Giai đoạn Linker**](#d-giai-đoạn-linker)

- [**II. #ifndef, #define, và #endif**](#ii-ifndef-define-và-endif)

[**LESSON 2: STDARG AND ASSSERT**](#Lesson2)

- [**I. Thư viện stdarg**](#i-thư-viện-stdarg)
- [**II. Thư viện assert**](#ii-thư-viện-assert)

[**LESSON 3: POINTER**](#Lesson3)

- [**I. POINTER**](#pointer)
- [**II. FUNCTION POINTER**](#function-pointer)
- [**III. VOID POINTER**](#void-pointer)
- [**IV. POINTER TO CONSTANT**](#pointer-to-constant)
- [**V. CONSTANT POINTER**](#constant-pointer)
- [**VI. POINTER TO POINTER**](#pointer-to-pointer)
- [**VII. NULL POINTER**](#null-pointer)

[**LESSON 4: EXTERN - STATIS - VOLATILE - REGISTER**](#Lesson4)

- [**I. EXTERN**](#extern)
- [**II. STATIS**](#statis)
    - [**1. STATIS LOCAL VARIABLES**](#1-statis-local-variables)
    - [**2. STATIS GLOBAL VARIABLES**](#2-statis-global-variables)
- [**III. VOLATILE**](#volatile)
- [**IV. REGISTER**](#register)

[**LESSON 5: GOTO - SETJMP**](#Lesson5)

- [**I. GOTO**](#goto)

- [**II. SETJMP**](#setjmp)

[**LESSON 6: BITMASK**](#Lesson6)

- [**I. NOT bitwise**](#not)

- [**II. AND bitwise**](#and)

- [**III. OR bitwise**](#or)

- [**IV. XOR bitwise**](#xor)

- [**V. SHIFT LEFT AND SHIFT RIGHT bitwise**](#shift)

[**LESSON 7: STRUCT - UNION**](#Lesson7)

- [**I. STRUCT**](#struct)

- [**II. UNION**](#union)

[**LESSON 8: MEMORY LAYOUT**](#Lesson8)

- [**I. TEXT SEGMENT**](#text-segment)

- [**II. DATA SEGMENT**](#data-segment)

- [**III. STACK**](#stack)

- [**IV. HEAP**](#heap)

- [**V. STACK VÀ HEAP**](#stack-va-heap)

[**LESSON 8: MEMORY LAYOUT**](#Lesson8)
---

<a name="Lesson1"></a>

# [**LESSON 1: MACRO**](#Lesson1)

<a name="Quá-trình-biên-dịch-một-chương-trình-C"></a>

## I. **Quá trình biên dịch một chương trình C/C++**

<a name="1-định-nghĩa"></a>

### **1. Định nghĩa**

Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

- Giai đoàn tiền xử lý (Pre-processor)
- Giai đoạn dịch NNBC sang Asembly (Compiler)
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
- Giai đoạn liên kết (Linker)

<div align="center">
    <img src="https://i.imgur.com/hrmqZ8q.png" alt="Your Image">
</div>

<a name="2-hoạt-động"></a>
### **2. Hoạt động**

<a name="a-giai-đoạn-tiền-xử-lý-–-preprocessor"></a>
#### **a. Giai đoạn tiền xử lý – Preprocessor**

Giai đoạn này sẽ thực hiện:

- Nhận mã nguồn
- Xóa bỏ tất cả chú thích, comments của chương trình
- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
- Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.

<a name="#b-công-đoạn-dịch-ngôn-ngữ-bậc-cao-sang-assembly"></a>

#### **b. Công đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly**

- Phân tích cú pháp (syntax) của mã nguồn NNBC
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

<a name="#c-công-đoạn-dịch-assembly"></a>

#### **c. Công đoạn dịch Assembly**

- Dịch chương trình => Sang mã máy 0 và 1
- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.

<a name="#d-giai-đoạn-linker"></a>

#### **d. Giai đoạn Linker**

- Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
- Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
- Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.

**Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.**


```C
Preprocessor
gcc -E main.c -o main.i


Complier
gcc -S main.i -o main.s


Assembler
gcc -c main.s -o main.o


Linker
gcc main.o -o main
```

<a name="#ii-ifndef-define-và-endif"></a>

## **II. #ifndef, #define, và #endif**


- Là các chỉ thị tiền xử lý (preprocessor directives) trong ngôn ngữ lập trình C và C++. Chúng được sử dụng để tạo ra các biểu thức điều kiện để ngăn chặn sự bao gồm (include) một tệp (file) tiêu đề (header file) nhiều lần trong cùng một đơn vị biên dịch (translation unit), nhằm tránh những vấn đề như định nghĩa nhiều lần hoặc xung đột.


- Dưới đây là cách chúng hoạt động:


#ifndef: Được viết tắt từ "if not defined" (nếu chưa được định nghĩa). Nó kiểm tra xem một macro cụ thể có được định nghĩa hay không. Nếu macro đó chưa được định nghĩa, mã giữa #ifndef và #endif sẽ được bao gồm.


#define: Định nghĩa macro cụ thể. Khi trình biên dịch gặp phải #define, nó định nghĩa macro đó, ngăn chặn việc bao gồm lại từ các tệp khác gây ra lỗi do định nghĩa nhiều lần.


#endif: Kết thúc khối biên dịch có điều kiện. Mã giữa #ifndef và #endif sẽ chỉ được bao gồm nếu macro cụ thể chưa được định nghĩa.


Việc sử dụng các chỉ thị này giúp tránh các vấn đề như:


- Định Nghĩa Nhiều Lần: Nếu một tệp tiêu đề được bao gồm ở nhiều nơi trong chương trình, điều này có thể dẫn đến việc định nghĩa nhiều lần các hàm, biến hoặc kiểu dữ liệu, gây ra lỗi từ trình liên kết.


- Xung Đột: Nếu hai hoặc nhiều tệp tiêu đề có cùng tên macro, chúng có thể xung đột với nhau. Việc sử dụng các chỉ thị này giúp ngăn chặn các xung đột này.

---

<a name="Lesson2"></a>

# [**LESSON 2: STDARG AND ASSSERT**](#Lesson2)

<a name="#i-thư-viện-stdarg"></a>

## **I. Thư viện stdarg**

- Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định.

- Các hàm như printf và scanf là ví dụ điển hình 

- va_list: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.

- va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.

- va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai

- va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.


**vd1:** Viết hàm tính tổng các số nguyên không biết trước số lượng input 

```c
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int result = 0;
    for (int i = 0; i < count; i++) {
        result += va_arg(args, int);
    }

    va_end(args);

    return result;
}

int main() {
    printf("Sum: %d\n", sum(4, 1, 2, 3, 4));
    return 0;
}
```

**vd2:** Giống vd1 nhưng thêm kiểu dữ liệu struct

```c
#include <stdio.h>
#include <stdarg.h>

typedef struct Data
{
    int x;
    double y;
} Data;

int sum(int count, ...) {

    va_list args;

    va_start(args, count);

    int result = 0;

    for (int i = 0; i < count; i++)
    {
        printf("value is: %d\n", va_arg(args, Data).x);
    }
   

    va_end(args);

    return result;

}

int main() {

    printf("size of int: %d\n", sizeof(__int64));

    printf("Sum: %d\n", sum(8, (Data){2,5.0} , 2, 3, 4.6, 10, 20.5 , 30 , 40));
    return 0;
}
```

**vd3:** Xử lý input với 2 loại cảm biến khác nhau, mỗi loại có số lượng thông số khác nhau

```c
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    TEMPERATURE_SENSOR,
    PRESSURE_SENSOR
} SensorType;

void processSensorData(SensorType type, ...) {
    va_list args;
    va_start(args, type);

    switch (type) {
        case TEMPERATURE_SENSOR: {
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            float temperature = va_arg(args, double); // float được promote thành double
            printf("Temperature Sensor ID: %d, Reading: %.2f degrees\n", sensorId, temperature);
            if (numArgs > 2) {
                // Xử lý thêm tham số nếu có
                char* additionalInfo = va_arg(args, char*);
                printf("Additional Info: %s\n", additionalInfo);
            }
            break;
        }
        case PRESSURE_SENSOR: {
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            int pressure = va_arg(args, int);
            printf("Pressure Sensor ID: %d, Reading: %d Pa\n", sensorId, pressure);
            if (numArgs > 2) {
                // Xử lý thêm tham số nếu có
                char* unit = va_arg(args, char*);
                printf("Unit: %s\n", unit);
            }
            break;
        }
    }

    va_end(args);
}

int main() {
    processSensorData(TEMPERATURE_SENSOR, 3, 1, 36.5, "Room Temperature");
    processSensorData(PRESSURE_SENSOR, 2, 2, 101325);
    return 0;
}


```

**vd4:** Gửi các lệnh khác nhau để điều khiển các thiết bị 

```c
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    TURN_ON,
    TURN_OFF,
    SET_LEVEL,
    SEND_MESSAGE
} CommandType;

void sendCommand(CommandType command, ...) {
    va_list args;
    va_start(args, command);

    switch (command) {
        case TURN_ON:
        case TURN_OFF: {
            int deviceID = va_arg(args, int);
            printf("Command: %s Device ID: %d\n", command == TURN_ON ? "Turn On" : "Turn Off", deviceID);
            break;
        }
        case SET_LEVEL: {
            int deviceID = va_arg(args, int);
            int level = va_arg(args, int);
            printf("Set Level of Device ID %d to %d\n", deviceID, level);
            break;
        }
        case SEND_MESSAGE: {
            char* message = va_arg(args, char*);
            printf("Send Message: %s\n", message);
            break;
        }
    }

    va_end(args);
}

int main() {
    sendCommand(TURN_ON, 1);
    sendCommand(TURN_OFF, 2);
    sendCommand(SET_LEVEL, 3, 75);
    sendCommand(SEND_MESSAGE, "Hello World");
    return 0;
}


```
<a name="ii-thư-viện-assert"></a>

## **II. Thư viện assert**

- Cung cấp macro assert. 
- Macro này được sử dụng để kiểm tra một điều kiện. 
- Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
- Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
- Dùng trong debug, dùng #define NDEBUG để tắt debug

**vd1:**

```c
#include <assert.h>

#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && (val) <= (max))

void setLevel(int level) {
    ASSERT_IN_RANGE(level, 1, 10);
    // Thiết lập cấp độ
}
```

**vd2:**

```c
#include <assert.h>
#include <stdint.h>

#define ASSERT_SIZE(type, size) assert(sizeof(type) == (size))

void checkTypeSizes() {
    ASSERT_SIZE(uint32_t, 4);
    ASSERT_SIZE(uint16_t, 2);
    // Kiểm tra các kích thước kiểu dữ liệu khác
}
```

---

<a name="Lesson3"></a>

# [**LESSON 3: POINTER**](#Lesson3)

<a name="pointer"></a>

## **I. POINTER**

- Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. 

- Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. 

<img src="https://i.imgur.com/N2JKlMe.png">

- Cách khai báo:

```c
int *ptr;  // con trỏ đến kiểu int
char *ptr_char;  // con trỏ đến kiểu char
float *ptr_float;  // con trỏ đến kiểu float
```

- Lấy địa chỉ của một biến và truy cập giá trị:

```c
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
int y = *ptr_x;  // y sẽ bằng giá trị của x
```

- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch:

```c
#include <stdio.h>
int main() {
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));return 0;
    }
```
- Ứng dụng:

```c
#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 10, b = 20;
    swap(&a, &b);
    printf("value a is: %d\n", a);
    printf("value b is: %d\n", b);
    return 0;
}


```
<a name="function-pointer"></a>

## **II. FUNCTION POINTER**

- Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.

- Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.

**vd1:**

```c
#include <stdio.h>
// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}
```

**vd2:**

```c
#include <stdio.h>

void sum(int a, int b)
{
    printf("Sum of %d and %d is: %d\n",a,b, a+b);
}

void subtract(int a, int b)
{
    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
}

void multiple(int a, int b)
{
    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
}

void divide(int a, int b)
{
    if (b == 0)
    {
        printf("Mau so phai khac 0\n");
        return;
    }
    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
}

void calculator(void (*ptr)(int, int), int a, int b)
{
    printf("Program calculate: \n");
    ptr(a,b);
}


int main()
{
    calculator(sum,5,2);
    calculator(subtract,5,2);
    calculator(multiple,5,2);
    calculator(divide,5,2);

    //void (*ptr[])(int, int) = {sum, divide, multiple};
    //ptr[0](5,6);

    return 0;
}

```

**vd3:**

```c
#include <stdio.h>
#include <string.h>

typedef struct {
   char ten[50];
   float diemTrungBinh;
   int id;
} SinhVien;

int stringCompare(const char *str1, const char *str2) {
   while (*str1 && (*str1 == *str2)) {
       str1++;
       str2++;
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}


// Hàm so sánh theo tên
int compareByName(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   return stringCompare(sv1->ten, sv2->ten);
}

// Hàm so sánh theo điểm trung bình
int compareByDiemTrungBinh(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   if (sv1->diemTrungBinh > sv2->diemTrungBinh)
   {
       return 1;
   }
  
   return 0;
}

// Hàm so sánh theo ID
int compareByID(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   return sv1->id - sv2->id;
}

// Hàm sắp xếp chung
void sort(SinhVien array[], size_t size, int (*compareFunc)(const void *, const void *)) {
   int i, j;
   SinhVien temp;
   for (i = 0; i < size-1; i++)    
       for (j = i+1; j < size; j++)
           if (compareFunc(array+i, array+j)>0) {
               temp = array[i];
               array[i] = array[j];
               array[j] = temp;
           }
}

void display(SinhVien *array, size_t size) {
   for (size_t i = 0; i < size; i++) {
       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
   }
   printf("\n");
}

int main() {
   SinhVien danhSachSV[] = {
       {  
           .ten = "Hoang",
           .diemTrungBinh = 7.5,
           .id = 100
       },
       {
           .ten = "Tuan",
           .diemTrungBinh = 4.5,
           .id = 101
       },
       {
           .ten = "Vy",
           .diemTrungBinh = 6.8,
           .id = 102},
       {  
           .ten = "Ngan",
           .diemTrungBinh = 5.6,
           .id = 10
       },
   };
   size_t size = sizeof(danhSachSV) / sizeof(danhSachSV[0]);

   // Sắp xếp theo tên
   sort(danhSachSV, size, compareByName);

   display(danhSachSV, size);

   // Sắp xếp theo điểm trung bình
   sort(danhSachSV, size, compareByDiemTrungBinh);

   display(danhSachSV, size);

   // Sắp xếp theo ID
   sort(danhSachSV, size, compareByID);

   display(danhSachSV, size);

   return 0;
}
```

**vd4:**

```c
#include <stdio.h>

typedef struct {
   void (*start)(int gpio);
   void (*stop)(int gpio);
   void (*changeSpeed)(int gpio, int speed);
} MotorController;

typedef int PIN;

// Các hàm chung
void startMotor(PIN pin) {
   printf("Start motor at PIN %d\n", pin);
}

void stopMotor(PIN pin) {
   printf("Stop motor at PIN %d\n", pin);
}

void changeSpeedMotor(PIN pin, int speed) {
   printf("Change speed at PIN %d: %d\n", pin, speed);
}

// Macro để khởi tạo GPIO và MotorController
#define INIT_MOTOR(motorName, pinNumber) \
   PIN g_##motorName = pinNumber; \
   MotorController motorName = {startMotor, stopMotor, changeSpeedMotor};

int main() {
   // Sử dụng macro để khởi tạo
   INIT_MOTOR(motorA, 1);
   INIT_MOTOR(motorB, 2);

   // Sử dụng motorA
   motorA.start(g_motorA);
   motorA.changeSpeed(g_motorA, 50);
   motorA.stop(g_motorA);

   // Sử dụng motorB
   motorB.start(g_motorB);
   motorB.changeSpeed(g_motorB, 75);
   motorB.stop(g_motorB);

   return 0;
}
```

<a name="void-pointer"></a>

## **III. VOID POINTER**

- Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.

- Cú pháp: `void *ptr_void;`

**vd:**
```c
#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int main() {
   
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    ptr = sum;
    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

    void *ptr1[] = {&value, &test, &letter , sum, array};

    printf("value: %d\n", *(int*)ptr1[0]);

    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}
```

<a name="pointer-to-constant"></a>

## **IV. POINTER TO CONSTANT**

- Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.

- Cú pháp:  `int const *ptr_const;` hoặc `const int *ptr_const;`

**vd:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int value = 5;
    int const *ptr_const = &value;
    //*ptr_const = 7; // wrong
    //ptr_const++; // right
    printf("value: %d\n", *ptr_const);
    value = 9;
    printf("value: %d\n", *ptr_const);
    
    return 0;
}
```

<a name="constant-pointer"></a>

## **V. CONSTANT POINTER**

- Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.

- Cú pháp: `int *const const_ptr = &value;`

**vd:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int value = 5;
    int test = 15;
    int *const const_ptr = &value;
    printf("value: %d\n", *const_ptr);
    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);
    //const_ptr = &test; // wrong
    return 0;
}
```

<a name="pointer-to-pointer"></a>

## **VI. POINTER TO POINTER**

- Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. 

- Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. 

- Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.

<img src="https://i.imgur.com/WDRFu8F.png">

**vd:**

```c
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    /*
        **ptr2 = &ptr1
        ptr2 = &ptr1;
        *ptr2 = ptr1 = &value;
        **ptr2 = *ptr1 = value
    */

    printf("address of value: %p\n", &value);
    printf("value of ptr1: %p\n", ptr1);

    printf("address of ptr1: %p\n", &ptr1);
    printf("value of ptr2: %p\n", ptr2);

    printf("dereference ptr2 first time: %p\n", *ptr2);

    printf("dereference ptr2 second time: %d\n", **ptr2);

    return 0;
}

```

<a name="null-pointer"></a>

## **VII. NULL POINTER**

- Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.

- Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.

```c
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    int score_game = 5;
    if (ptr == NULL)
    {
        ptr = &score_game;
        *ptr = 30;
        ptr = NULL;
    }
    

    return 0;
}

```

---

<a name="Lesson4"></a>

# [**LESSON 4: EXTERN - STATIS - VOLATILE - REGISTER**](#Lesson4)

<a name="extern"></a>

## **I. EXTERN**

- Khái niệm Extern trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. 

- Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.

- Biến được tham chiếu phải được khai báo ở cấp độ cao nhất (toàn cục).

- Để sử dụng được biến toàn cục ở một file khác, chúng ta phải khai báo lại biến và thêm từ khóa extern phía trước, để báo rằng biến này đã được khi báo ở file khác.

Cú pháp: `extern <kiểu dữ liệu> <Tên Biến>;`

Lưu ý: khi sử dụng extern, không được khai báo giá trị ban đầu cho biến

**vd1: ở file1.c ta có biến toàn cục GlobalVariable**
```c
int GlobalVariable = 0; // implicit definition 
void SomeFunction(); // function prototype (declaration) 
int main() 
{ 
  GlobalVariable = 1; 
  SomeFunction(); 
  return 0; 
}
```

**ở main.c ta cần dùng biến GlobalVariable này từ file1.c**
```c
extern int GlobalVariable; // implicit definition 
void SomeFunction(); // function prototype (declaration) 
int main() 
{ 
  GlobalVariable = 1; 
  SomeFunction(); 
  return 0; 
}
```

**vd2: main.c dùng hàm HelloWorl được extern từ test1.c**

thay vì dùng #include như bình thường ta dùng extern để xác định hàm cần sử dụng từ file khác

```c
//test1.c
#include <stdio.h>

void HelloWorld()
{
    printf("Hello World!");
}
```

```c
//main.c
#include <stdio.h>
// #include "test1.h" // đã comment dòng này

extern void HelloWorld();

int main()
{
    HelloWorld();
    return 0;
}
```

<a name="statis"></a>

## **II. STATIS**

<a name="1-statis-local-variables"></a>

### **1. STATIS LOCAL VARIABLES**

- Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.

**vd:**

```c
#include <stdio.h>

void exampleFunction() {
    static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
    count++;
    printf("Count: %d\n", count);
    }
    
int main() {
    exampleFunction();  // In ra "Count: 1"
    exampleFunction();  // In ra "Count: 2"
    exampleFunction();  // In ra "Count: 3"
    return 0;}
```
<a name="2-statis-global-variables"></a>

### **2. STATIS GLOBAL VARIABLES**

- Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.

**vd: Trong hàm main.c, sẽ không sử dụng được các hàm startMotor, stopMotor, stop trực tiếp mà phải truy cập chúng thông qua init_motor**

```c
//main.c
#include <stdio.h>
#include "motor.h"

int main() {
    // Khởi tạo một đối tượng MotorController
    MotorController myMotor;
    
    // Gọi hàm init_motor để khởi tạo myMotor
    init_motor(&myMotor);
    
    // Sử dụng các hàm từ myMotor
    PIN motorPin = 10; // Thay đổi giá trị PIN theo nhu cầu
    
    myMotor.start(motorPin);
    myMotor.changeSpeed(motorPin, 50);
    myMotor.stop(motorPin);

    return 0;
}
```

```c
//motor.h
#ifndef __MOTOR_H
#define __MOTOR_H

typedef struct {
    void (*start)(int gpio);
    void (*stop)(int gpio);
    void (*changeSpeed)(int gpio, int speed);
} MotorController;

typedef int PIN;

static void startMotor(PIN pin);
static void stopMotor(PIN pin);
static void changeSpeedMotor(PIN pin, int speed);

	 
void init_motor(MotorController *motorName); 


#endif
```

```c
//motor.c
#include <stdio.h>
#include "motor.h"


// General function
void startMotor(PIN pin) {
   printf("Start motor at PIN %d\n", pin);
}

void stopMotor(PIN pin) {
   printf("Stop motor at PIN %d\n", pin);
}

void changeSpeedMotor(PIN pin, int speed) {
   printf("Change speed at PIN %d: %d\n", pin, speed);
}

	 
void init_motor(MotorController *motorName)
{
	motorName->start = startMotor;
	motorName->stop = stopMotor;
	motorName->changeSpeed = changeSpeedMotor;
}
```
<a name="volatile"></a>

## **III. VOLATILE**

- Từ khóa volatile trong ngôn ngữ lập trình C được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.

- Việc sử dụng volatile đặc biệt có ý nghĩa trong trường hợp biến khai báo được sử dụng để cập nhật giá trị từ bên ngoài như đọc giá trị cảm biến, khi đó chúng ta cần cập nhật giá trị của biến một cách liên tục.


**vd: Biến i sau khi khai báo volatile sẽ không bị trình biên dịch tối ưu hóa, nó sẽ vẫn cập nhật giá trị liên tục trong vòng lặp while**
```c
#include "stm32f10x.h"

volatile int i = 0;
int a = 100;

int main()
{
	
	while(1)
	{
		i = *((int*) 0x20000000);
		if (i > 0)
		{
			break;
		}
		
	}
	a = 200;
}
```
<a name="register"></a>

## **IV. REGISTER**

- Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. 

- Việc này nhằm tăng tốc độ truy cập. Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này.

<img src="https://i.imgur.com/o2kYLC2.png">

**vd: khi có từ khóa 'register int i' thì kết quả là 'Thoi gian chay cua chuong trinh: 0.001000 giay' còn khi không có thì kết quả là 'Thoi gian chay cua chuong trinh: 0.003000 giay'**

```c
#include <stdio.h>
#include <time.h>

int main() {
    // Lưu thời điểm bắt đầu
    clock_t start_time = clock();
    register int i;

    // Đoạn mã của chương trình
    for (i = 0; i < 2000000; ++i) {
        // Thực hiện một số công việc bất kỳ
    }

    // Lưu thời điểm kết thúc
    clock_t end_time = clock();

    // Tính thời gian chạy bằng miligiây
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

    return 0;
}
```
---
<a name="Lesson5"></a>

# [**LESSON 5: GOTO - SETJMP**](#Lesson5)

<a name="Goto"></a>

## I. **Goto**

- goto là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm. 

- Mặc dù nó cung cấp khả năng kiểm soát flow của chương trình, nhưng việc sử dụng goto thường được xem là không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.

- goto sẽ cần thiết khi có nhiều vòng lặp lồng vào nhau (vd3) hoặc các mảng đa chiều trong xử lý ảnh.

**vd1: Dùng nhãn start và end thay thế cho vòng lặp for, while**

```c
#include <stdio.h>

int main() {
    int i = 0;
    // Đặt nhãn
    start:
    if (i >= 5) {
        goto end;  // Chuyển control đến nhãn "end"
        }
        printf("%d ", i);
        i++;
        goto start;  // Chuyển control đến nhãn "start"
        // Nhãn "end"
        end:
        printf("\n");
    return 0;
}
```

**vd2:Dùng nhãn skip_sleep để thay thế break trong switch case**

```c
#include <stdio.h>
void delay(double second)
{
    double start = 0;
    while (start < second * 6000000)
    {
        start++;
    }
}

// Khai báo các trạng thái đèn giao thông
typedef enum 
{
    RED,
    YELLOW,
    GREEN
} TrafficLightState;


int main() {
    

    // Ban đầu, đèn giao thông ở trạng thái đỏ
    TrafficLightState state = RED;

    // Vòng lặp vô hạn để mô phỏng đèn giao thông
    while (1) {
        switch (state) {
            case RED:
                printf("RED Light\n");
                delay(50);  // Giữ trạng thái đèn đỏ trong x giây
                
                // Chuyển đến trạng thái đèn vàng
                state = GREEN;
                goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
            case YELLOW:
                printf("YELLOW Light\n");
                delay(20);  // Giữ trạng thái đèn vàng trong y giây
                
                // Chuyển đến trạng thái đèn xanh
                state = RED;
                goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
            case GREEN:
                printf("GREEN Light\n");
                delay(100);  // Giữ trạng thái đèn xanh trong z giây
                
                // Chuyển đến trạng thái đèn đỏ
                state = YELLOW;
                goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
        }

        // Nhãn để nhảy qua sleep() khi chuyển trạng thái
        skip_sleep:;
    }

    return 0;
}
```

**vd3: In chữ trong biển quảng cáo, sử dụng nhiều vòng lặp lồng vào nhau và cần out ra khỏi vòng lặp ngay lặp tức khi nhấn button**

```c
#include <stdio.h>

void delay()
{
    double start;
    while (start < 60000000)
    {
        start++;
    }
    
}

char letter = 'A';

char first_sentence[] = "HELLO";
char second_sentence[] = "FASHION COTHES";
char third_sentence[] = "SUITABLE PRICE";


int letter_A[8][8] = {  {0,0,1,0,0,0,0,0},
                        {0,1,0,1,0,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,1,1,1,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},  };

int letter_H[8][8] = {  {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,1,1,1,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},  };

int letter_L[8][8] = {  {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,1,1,1,1,0,0,0},  };

/*
H, e, l,o, F, a, ....
*/

int button = 0;

typedef enum
{
    FIRST,
    SECOND,
    THIRD

}   Sentence;

int main() {

    Sentence sentence = FIRST;

    while(1)
    {
        switch (sentence)
        {
        case FIRST:
            for (int index = 0; index < sizeof(first_sentence); index++)
            {
                if (first_sentence[index] == 'H')
                {
                    for (int i = 0; i < 8; i++) 
                    {    
                        for (int j = 0; j < 8; j++) 
                        {
                            if (letter_H[i][j] == 1) 
                            {
                                printf("Turn on led at [%d][%d]\n", i,j);
                                if (button == 1)
                                {
                                   goto exit_loops;
                                }
                                
                            }
                        }
                        // tat den
                    }
                }
                if (first_sentence[index] == 'e')
                {
                    // in ra chu e
                }
            }
            printf("first sentence is done\n");
            delay();
            goto logic;

        case SECOND:
            for (int index = 0; index < sizeof(second_sentence); index++)
            {
                if (second_sentence[index] == 'A')
                {
                    for (int i = 0; i < 8; i++) 
                    {    
                        for (int j = 0; j < 8; j++) 
                        {
                            if (letter_A[i][j] == 1) 
                            {
                                printf("Turn on led at [%d][%d]\n", i,j);
                                if (button == 1)
                                {
                                   goto exit_loops;
                                }
                                
                            }
                        }
                        // tat den led
                    }
                }
                if (second_sentence[index] == 'F')
                {
                    // in ra chu F
                }
            }
            printf("second sentence is done\n");
            delay();
            goto logic;

        case THIRD:
            for (int index = 0; index < sizeof(third_sentence); index++)
            {
                if (third_sentence[index] == 'L')
                {
                    for (int i = 0; i < 8; i++) 
                    {    
                        for (int j = 0; j < 8; j++) 
                        {
                            if (letter_L[i][j] == 1) 
                            {
                                printf("Turn on led at [%d][%d]\n", i,j);
                                if (button == 1)
                                {
                                   goto exit_loops;
                                }
                                
                            }
                        }
                        // tat den led
                    }
                }
                if (third_sentence[index] == 'E')
                {
                    // in ra chu H
                }
            }
            printf("third sentence is done\n");
            delay();
            //button = 1;
            goto logic;
        }

        logic:
            if (sentence == FIRST)
            {
                sentence = SECOND;
            }
            else if (sentence == SECOND)
            {
                sentence = THIRD;
            }
            else if (sentence == THIRD)
            {
                sentence = FIRST;
            }
            goto exit;
            
        exit_loops:
            printf("Stop!\n");
            break;
        
        exit:;
         
    }
   
    return 0;
}

```

<a name="setjmp"></a>

## II. **SETJMP**

- setjmp.h là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là setjmp và longjmp. 

- Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ này.

- Nếu gọi longjmp và gán giá trị cho buff thì nó sẽ nhảy tới vị trí setjmp.

- setjmp khác với assert:

    - assert sẽ đưa ra cảnh báo lỗi và dừng chương trình (tức là những lỗi này là lỗi nghiêm trọng).

    - setjmp thì sẽ được sử dụng với những lỗi chưa đến mức phải dừng chương trình lại mà chỉ cần thực hiện chức năng báo lỗi hoặc in ra yêu cầu để khắc phục (ví dụ như khi đọc UART mà chưa có dữ liệu thì gửi yêu cầu để đọc lại).

**vd:**

```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x) longjmp(buf, (x))


double divide(int a, int b) {
    if (b == 0) {
        THROW(1); // Mã lỗi 1 cho lỗi chia cho 0
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("Error: Divide by 0!\n");
    }


    // Các xử lý khác của chương trình
    return 0;
}

```
---

<a name="Lesson6"></a>

# [**LESSON 6: BITMASK**](#Lesson6)

- Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).
	
- Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.


<a name="not"></a>

## **I. NOT bitwise**

- Dùng để thực hiện phép NOT bitwise trên từng bit của một số. Kết quả là bit đảo ngược của số đó.

- Cú pháp: `int result = ~num;`

<a name="and"></a>

## **II. AND bitwise**

- Dùng để thực hiện phép AND bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0 (chỉ đúng khi cả hai cùng đúng).

- Cú pháp: `int result = num1 & num2;`

<a name="or"></a>

## **III. OR bitwise**

- Dùng để thực hiện phép OR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu có hơn một bit tương ứng là 1 (chỉ cần 1 trong 2 cái đúng là được).

- Cú pháp: `int result = num1 | num2;`

<a name="xor"></a>

## **IV. XOR bitwise**

- Dùng để thực hiện phép XOR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu chỉ có một bit tương ứng là 1 (khác nhau là 1, giống nhau là 0).

- Cú pháp: `int result = num1 ^ num2;`

<a name="shift"></a>

## **V. SHIFT LEFT AND SHIFT RIGHT bitwise**

- Dùng để di chuyển bit sang trái hoặc sang phải.

- Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0. Ví dụ: 1 << 2 sẽ thành 0000 0100

- Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu). Ví dụ: 8 >> 2 sẽ thành 0000 0010

**vd1: Tùy chọn các đặc điểm cho nhân vật trong game**

```c
#include <stdio.h>
#include <stdint.h>

#define GENDER        (1 << 0)  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)
#define TSHIRT        (1 << 1)  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           (1 << 2)  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         (1 << 3)  // Bit 3: Giày (0 = Không, 1 = Có)
// Tự thêm 5 tính năng khác
#define FEATURE1      (1 << 4)  // Bit 4: Tính năng 1
#define FEATURE2      (1 << 5)  // Bit 5: Tính năng 2
#define FEATURE3      (1 << 6)  // Bit 6: Tính năng 3
#define FEATURE4      (1 << 7)  // Bit 7: Tính năng 4

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if ((features & GENDER) != 0) {
        printf("- Gender\n");
    }
    if ((features & TSHIRT) != 0 ) {
        printf("- T-Shirt\n");
    }
    if ((features & HAT) != 0) {
        printf("- Hat\n");
    }
    if ((features & SHOES) != 0 ) {
        printf("- Shoes\n");
    }
    // Thêm các điều kiện kiểm tra cho các tính năng khác
}


int main() {
    uint8_t options = 0;

    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT);

    // Tắt tính năng
    disableFeature(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}

```

**vd2: Bật tắt các LED được định nghĩa trước trong cùng 1 PORT**

```c
#include <stdio.h>
#include <stdint.h>

#define LED1 (1 << 0) // 0001
#define LED2 (1 << 1) // 0010
#define LED3 (1 << 2) // 0100
#define LED4 (1 << 3) // 1000


void enableLED(uint8_t *GPIO_PORT, uint8_t LED) {
    *GPIO_PORT |= LED;
}

void disableLED(uint8_t *GPIO_PORT, uint8_t LED) {
    *GPIO_PORT &= ~LED;
}

void stateLED(uint8_t *GPIO_PORT) {
    if (*GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (*GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (*GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }
}

int main() {
    uint8_t GPIO_PORT = 0; // Giả sử là biến điều khiển cổng GPIO

    // Bật LED1 và LED3
    enableLED(&GPIO_PORT, LED1 | LED3);

    // Kiểm tra trạng thái LED
    stateLED(&GPIO_PORT);

    // Tắt LED1 và bật LED2
    disableLED(&GPIO_PORT, LED1);
    enableLED(&GPIO_PORT, LED2);

    // Kiểm tra lại trạng thái LED
    stateLED(&GPIO_PORT);

    return 0;
}

```

**vd3: Sử dụng kết hợp với Macro và Struct nhằm tối ưu bộ nhớ cho chương trình**

```c
#include <stdio.h>
#include <stdint.h>

#define ENABLE 1
#define DISABLE 0

typedef struct {
    uint8_t LED1 : 1;
    uint8_t LED2 : 1;
    uint8_t LED3 : 1;
    uint8_t LED4 : 1;
    uint8_t LED5 : 1;
    uint8_t LED6 : 1;
    uint8_t LED7 : 1;
    uint8_t LED8 : 1;
} LEDStatus;


int main() {
    LEDStatus ledStatus = {.LED7 = ENABLE};

    // Bật LED 1 và 3
    ledStatus.LED1 = ENABLE;
    ledStatus.LED3 = ENABLE;

    // Kiểm tra trạng thái của LED 1
    if (ledStatus.LED7) {
        printf("LED7 is on\n");
    }
    return 0;
}

```

**vd4: Lựa chọn các thông số đặc điểm của xe**

```c
#include <stdio.h>
#include <stdint.h>

#define COLOR_RED 0
#define COLOR_BLUE 1
#define COLOR_BLACK 2
#define COLOR_WHITE 3

#define POWER_100HP 0
#define POWER_150HP 1
#define POWER_200HP 2

#define ENGINE_1_5L 0
#define ENGINE_2_0L 1

#define SUNROOF_MASK (1 << 0)     // 0001
#define PREMIUM_AUDIO_MASK (1 << 1) // 0010
#define SPORTS_PACKAGE_MASK (1 << 2) // 0100
// Thêm các bit masks khác tùy thuộc vào tùy chọn

typedef struct {
    uint8_t additionalOptions : 3; // 3 bits cho các tùy chọn bổ sung
    uint8_t CarColor : 2;
    uint8_t CarPower : 2;
    uint8_t CarEngine : 1;
} CarOptions;

void configureCar(CarOptions *car, uint8_t color, uint8_t power, uint8_t engine, uint8_t options) {
    car->CarColor = color;
    car->CarPower = power;
    car->CarEngine = engine;
    car->additionalOptions = options;
}

void setOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions |= optionMask;
}

void unsetOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions &= ~optionMask;
}

void displayCarOptions(const CarOptions car) {
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.CarColor]);
    printf("Power: %s\n", powers[car.CarPower]);
    printf("Engine: %s\n", engines[car.CarEngine]);
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No");
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
}


int main() {
    CarOptions myCar = {COLOR_BLACK, POWER_150HP, ENGINE_2_0L};

    setOption(&myCar, SUNROOF_MASK);
    setOption(&myCar, PREMIUM_AUDIO_MASK);
    
    displayCarOptions(myCar);
    printf("------------------\n");

    unsetOption(&myCar, PREMIUM_AUDIO_MASK); 
    displayCarOptions(myCar);

    printf("size of my car: %d\n", sizeof(CarOptions));

    return 0;
}

```
---

<a name="Lesson7"></a>

# [**LESSON 7: STRUCT - UNION**](#Lesson7)

<a name="struct"></a>

## **I. STRUCT**

- Trong ngôn ngữ lập trình C, struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. 

- Struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.

- Chú ý cách sắp xếp các biến trong struct để tối ưu bộ nhớ. Nên xếp các biến có kích thước lớn hơn ở trên cùng và giảm dần.

- Có 2 cách khai báo struct:

    - Cách 1: 

```c
struct structureName
{
dataType member1;
dataType member2;
...
};
```

**vd:**
```c
struct student {
    char name[30];
    int tuoi;
    char sodienthoai[20];
    float lop;
}

struct student sv1;
struct student sv2;
struct student sv[10];
```
    - Cách 2: 
```c
typedef struct
{
dataType member1;
dataType member2;
...
} structureName;
```
**vd:**
```c
typedef struct {
    char name[30];
    int tuoi;
    char sodienthoai[20];
    float lop;
} student;

student sv1;
student sv2;
student sv[10];
```

- Truy xuất dữ liệu:

    - Sử dụng “.” → Toán tử truy xuất tới thành viên khi khai báo biến bình thường.
    - Sử dụng “→” → Toán tử truy xuất tới thành viên khi biến là con trỏ.

**vd:**
```c
sutdent sv1;
sv1.name = "Tran Minh Tri"
sv1.sodienthoai = "0397033999"
sv1.tuoi = 22;
sv1.lop = 15;
```

hoặc 

```c
sutdent *sv1;
sv1->name = "Tran Minh Tri"
sv1->sodienthoai = "0397033999"
sv1->tuoi = 22;
sv1->lop = 15;
```

<a name="union"></a>

## **II. UNION**

- Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào cùng một vùng nhớ. 

- Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng. Điều này được ứng dụng nhằm tiết kiệm bộ nhớ.

- Cách khai báo và truy cập giống như struct.

- Ứng dụng kết hợp giữa union và struct: 

Khi muốn gửi dữ liệu chứa nhiều thông tin từ MCU A sang MCU B và MCU B chỉ nhận được dữ liệu đóng gói dưới dạng khung để thuận tiện và tiết kiệm tài nguyên bộ nhớ:

<img src="https://i.imgur.com/2ysRHlL.png">

- Giả sử frame gửi đi có các phần là id, data và checksum như hình vẽ:

<img src="https://i.imgur.com/ZzusxQN.png ">

- Ta sẽ sử dụng struct để tạo ra kiểu dữ liệu cho frame. Sau đó dùng tính chất sắp xếp bộ nhớ của union để đóng gói dữ liệu.

```c
#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;

    uint8_t frame[8];

} Data_Frame;


int main(int argc, char const *argv[])
{
    Data_Frame transmitter_data;
    
    strcpy(transmitter_data.data.id, "10");
    strcpy(transmitter_data.data.data, "1234");
    strcpy(transmitter_data.data.check_sum, "70");

	Data_Frame receiver_data;
    strcpy(receiver_data.frame, transmitter_data.frame);
	
    
    return 0;
}

```
---
<a name="Lesson8"></a>

# [**LESSON 8: MEMORY LAYOUT**](#Lesson8)

- Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.

<div align="center">
    <img src="https://i.imgur.com/IkureDG.png" alt="Your Image">
</div>

<a name="text-segment"></a>

## **I. TEXT SEGMENT**

- Text Segment là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để lưu trữ mã máy của chương trình. Cụ thể, Text Segment chứa mã máy đã được biên dịch từ mã nguồn của chương trình và được CPU thực thi để thực hiện các hành động quy định trong chương trình.

<div align="center">
    <img src="https://i.imgur.com/cBMKpEq.png" alt="Your Image">
</div>

- Mã máy:
    - Chứa tập hợp các lệnh thực thi.
    - Mã máy được tạo ra thông qua quá trình biên dịch từ mã nguồn của chương trình.
- Quyền truy cập: Text Segment thường có quyền đọc và thực thi, nhưng không có quyền ghi. Điều này ngăn chặn chương trình việc tự sửa đổi mã máy của nó.
- Kích thước cố định
- Lưu Trữ Hằng Số

<a name="data-segment"></a>

## **II. DATA SEGMENT**

- Data Segment là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để lưu trữ dữ liệu tĩnh của chương trình. Dữ liệu tĩnh bao gồm biến toàn cục và biến tĩnh (static), tức là các biến mà không phụ thuộc vào thời gian chạy của chương trình. 

<div align="center">
    <img src="https://i.imgur.com/GdUvtQQ.png" alt="Your Image">
</div>

- Biến Toàn Cục (Global Variables):
    - Các biến này có thể được truy cập từ bất kỳ hàm nào trong chương trình.
- Biến Tĩnh (Static Variables):
    - Chứa giá trị của các biến tĩnh, nghĩa là biến được khai báo với từ khóa static.
    - Có thể được truy cập chỉ trong phạm vi của hàm mà chúng được khai báo.

<div align="center">
    <img src="https://i.imgur.com/EiaB30o.png" alt="Your Image">
</div>

- Initialized Data Segment (Dữ liệu Đã Khởi Tạo):
    - Chứa các biến toàn cục và biến tĩnh được khởi tạo với giá trị khác 0.

<div align="center">
    <img src="https://i.imgur.com/ljj0s3y.png" alt="Your Image">
</div>

- Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo):
    - Chứa các biến toàn cục và biến tĩnh mà giá trị khởi tạo bằng 0 hoặc không gán giá trị.

- Quyền truy cập: Data Segment thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong quá trình thực thi của chương trình.
- Kích thước thay đổi: Kích thước của Data Segment có thể thay đổi trong quá trình thực thi của chương trình khi các biến được khởi tạo hoặc giải phóng.

<a name="stack"></a>

## **III. STACK**

- Stack là một phần quan trọng của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính. Nó được sử dụng để lưu trữ các biến cục bộ, các tham số truyền vào và các giá trị trả về từ hàm.

<div align="center">
    <img src="https://i.imgur.com/bGGhGkq.png" alt="Your Image">
</div>

- Quyền truy cập: Bộ nhớ trên Stack thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong suốt thời gian chương trình chạy.
- Chứa các biến cục bộ, tức là các biến được khai báo trong các hàm và chỉ có giá trị trong phạm vi của hàm đó.
- Kích thước cố định: phụ thuộc vào hệ điều hành, đối với Windows thường là 1MB, Linux là 8MB.

<a name="heap"></a>

## **IV. HEAP**

- Heap là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để cấp phát bộ nhớ động. Các biến được cấp phát trên heap không có kích thước xác định tại thời điểm biên dịch và có thể được quản lý động trong quá trình thực thi của chương trình.

<div align="center">
    <img src="https://i.imgur.com/Z6PZEhG.png" alt="Your Image">
</div>

- Cấp phát động:
    - Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.
    - Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
    - Các hàm như malloc(), calloc(), realloc(), và free() được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.

- malloc (Memory Allocation):
    - Chức năng: malloc được sử dụng để cấp phát một khối bộ nhớ có kích thước cụ thể (trong byte).
    - Cú pháp: `void* malloc(size_t size)`;
    - Sử dụng: Bạn cần chỉ định kích thước của bộ nhớ bạn muốn cấp phát, và nó trả về một con trỏ kiểu void* trỏ đến địa chỉ bắt đầu của khối bộ nhớ được cấp phát.

- calloc (Contiguous Allocation):
    - Chức năng: calloc được sử dụng để cấp phát một khối bộ nhớ và khởi tạo tất cả các byte của khối bằng giá trị 0.
    - Cú pháp: `void* calloc(size_t num_elements, size_t element_size)`;
    - Sử dụng: Bạn cần chỉ định số lượng phần tử và kích thước của mỗi phần tử, và nó trả về một con trỏ kiểu void* trỏ đến địa chỉ bắt đầu của khối bộ nhớ được cấp phát.

- Sự khác biệt chính giữa malloc và calloc:
    - Khởi tạo giá trị: malloc không khởi tạo giá trị của bộ nhớ cấp phát, trong khi calloc khởi tạo tất cả các byte của khối bộ nhớ bằng 0.
    - Tham số: malloc yêu cầu kích thước của bộ nhớ (tính bằng byte), trong khi calloc yêu cầu số lượng phần tử và kích thước của mỗi phần tử.

- realloc (Reallocate Memory):
    - Chức năng: realloc được sử dụng để thay đổi kích thước của một khối bộ nhớ đã được cấp phát trước đó.
    - Cú pháp: `void* realloc(void* ptr, size_t size)`;
    - Sử dụng: Bạn cần truyền con trỏ đã được cấp phát trước đó bằng malloc, calloc, hoặc realloc, cùng với kích thước mới bạn muốn cấp phát. Nó trả về con trỏ mới trỏ đến khối bộ nhớ đã được thay đổi.

**vd1:**
```c
#include <stdlib.h>

int main() {
    int *arr_malloc, *arr_calloc;
    size_t size = 5;

    // Sử dụng malloc
    arr_malloc = (int*)malloc(size * sizeof(int));

    // Sử dụng calloc
    arr_calloc = (int*)calloc(size, sizeof(int));

    // ...

    // Giải phóng bộ nhớ
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}

```

**vd2:**
```c
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{  
    int soluongkytu = 0;

    char* ten = (char*) malloc(sizeof(char) * soluongkytu);



    for (int i = 0; i < 3; i++)
    {
        printf("Nhap so luong ky tu trong ten: \n");
        scanf("%d", &soluongkytu);
        ten = realloc(ten, sizeof(char) * soluongkytu);
        printf("Nhap ten cua ban: \n");
        scanf("%s", ten);

        printf("Hello %s\n", ten);
    }
    
    return 0;
}

```
<a name="stack-va-heap"></a>

## **V. STACK VÀ HEAP**

- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).

---
- Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1MB, hệ điều hành Linux là 8MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
- Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
---
- Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong công việc của mình.
- Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay giải phóng vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

**vd:**
```c
#include <stdio.h>
#include <stdlib.h>

void test1()
{
    int array[3];
    for (int i = 0; i < 3; i++)
    {
        printf("address of array[%d]: %p\n", i, (array+i));
    }
    printf("----------------------\n");
}

void test2()
{
    int *array = (int*)malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("address of array[%d]: %p\n", i, (array+i));
    }
    printf("----------------------\n");
    //free(array);
}


int main(int argc, char const *argv[])
{  
    test1();
    test1();
    test2();
    test2();

    return 0;
}

```

**ta được kết quả: với test1 dùng stack nên vùng nhớ sẽ được tự động giải phóng sau khi ra khỏi hàm, còn test2 thì nếu không dùng `free` thì vùng nhớ chưa được giải phóng**

```c
address of array[0]: 0061FF00
address of array[1]: 0061FF04
address of array[2]: 0061FF08
----------------------       
address of array[0]: 0061FF00
address of array[1]: 0061FF04
address of array[2]: 0061FF08
----------------------
address of array[0]: 006E18B0
address of array[1]: 006E18B4
address of array[2]: 006E18B8
----------------------
address of array[0]: 006E18C8
address of array[1]: 006E18CC
address of array[2]: 006E18D0
----------------------
```
---
- Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...

```c
int foo(int x){
    printf("De quy khong gioi han\n");
    return foo(x);
    }
```
- Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
```c
int *A = (int *)malloc(18446744073709551615);
```
---
<a name="Lesson8"></a>

# [**LESSON 8: MEMORY LAYOUT**](#Lesson8)

- JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
- JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.

---
