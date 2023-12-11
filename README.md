# C-advanced

Trần Minh Trí

Lịch học: thứ 3, 5, 7; 8:9 pm

# **MỤC LỤC**

[**LESSON 1: MACRO**](#Lesson1)

[**LESSON 2: STDARG AND ASSSERT**](#Lesson2)

[**LESSON 3: POINTER**](#Lesson3)

<a name="Lesson1"></a>

# **LESSON 1: MACRO**

# **Quá trình biên dịch một chương trình C/C++**

## **1. Định nghĩa**

Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

- Giai đoàn tiền xử lý (Pre-processor)
- Giai đoạn dịch NNBC sang Asembly (Compiler)
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
- Giai đoạn liên kết (Linker)

<img src="https://i.imgur.com/hrmqZ8q.png">

## **2. Hoạt động**

**a. Giai đoạn tiền xử lý – Preprocessor**

Giai đoạn này sẽ thực hiện:

- Nhận mã nguồn
- Xóa bỏ tất cả chú thích, comments của chương trình
- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
- Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.

**b. Cộng đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly**

- Phân tích cú pháp (syntax) của mã nguồn NNBC
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

**c. Công đoạn dịch Assembly**

- Dịch chương trình => Sang mã máy 0 và 1
- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.

**d. Giai đoạn Linker**

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


**#ifndef, #define, và #endif**


Là các chỉ thị tiền xử lý (preprocessor directives) trong ngôn ngữ lập trình C và C++. Chúng được sử dụng để tạo ra các biểu thức điều kiện để ngăn chặn sự bao gồm (include) một tệp (file) tiêu đề (header file) nhiều lần trong cùng một đơn vị biên dịch (translation unit), nhằm tránh những vấn đề như định nghĩa nhiều lần hoặc xung đột.


- Dưới đây là cách chúng hoạt động:


#ifndef: Được viết tắt từ "if not defined" (nếu chưa được định nghĩa). Nó kiểm tra xem một macro cụ thể có được định nghĩa hay không. Nếu macro đó chưa được định nghĩa, mã giữa #ifndef và #endif sẽ được bao gồm.


#define: Định nghĩa macro cụ thể. Khi trình biên dịch gặp phải #define, nó định nghĩa macro đó, ngăn chặn việc bao gồm lại từ các tệp khác gây ra lỗi do định nghĩa nhiều lần.


#endif: Kết thúc khối biên dịch có điều kiện. Mã giữa #ifndef và #endif sẽ chỉ được bao gồm nếu macro cụ thể chưa được định nghĩa.


Việc sử dụng các chỉ thị này giúp tránh các vấn đề như:


- Định Nghĩa Nhiều Lần: Nếu một tệp tiêu đề được bao gồm ở nhiều nơi trong chương trình, điều này có thể dẫn đến việc định nghĩa nhiều lần các hàm, biến hoặc kiểu dữ liệu, gây ra lỗi từ trình liên kết.


- Xung Đột: Nếu hai hoặc nhiều tệp tiêu đề có cùng tên macro, chúng có thể xung đột với nhau. Việc sử dụng các chỉ thị này giúp ngăn chặn các xung đột này.

<a name="Lesson2"></a>

# **LESSON 2: STDARG AND ASSSERT**

## **Thư viện stdarg**

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

## **Thư viện assert**

<a name="Lesson3"></a>

## **LESSON 3: POINTER**