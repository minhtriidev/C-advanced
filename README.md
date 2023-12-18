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

---

<a name="Lesson1"></a>

# **LESSON 1: MACRO**

<a name="Quá-trình-biên-dịch-một-chương-trình-C"></a>

## I. **Quá trình biên dịch một chương trình C/C++**

<a name="1-định-nghĩa"></a>

### **1. Định nghĩa**

Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

- Giai đoàn tiền xử lý (Pre-processor)
- Giai đoạn dịch NNBC sang Asembly (Compiler)
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
- Giai đoạn liên kết (Linker)

<img src="https://i.imgur.com/hrmqZ8q.png">

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

# **LESSON 2: STDARG AND ASSSERT**

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

# **LESSON 3: POINTER**

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

# **LESSON 4: EXTERN - STATIS - VOLATILE - REGISTER**

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

# **LESSON 5: GOTO - SETJMP**

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

[**LESSON 6: BITMASK**](#Lesson6)

---
