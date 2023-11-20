#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//循环结构
//01找最小值
int main01() {
    int n;
    scanf("%d", &n);
    int* arr = NULL;
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int left = *arr;
    for (int j = 0; j < n; j++) {
        if (*(arr + j) < left) {
            left = *(arr + j);
            continue;
        }
    }
    printf("%d", left);
    return 0;
}

//02分类平均
//给定n和k，将从1到n之间的所有正整数可以分为两类：A类数可以被k整除（也就是说是k的倍数），而 B 类数不能。
//请输出这两类数的平均数，精确到小数点后1位，用空格隔开，数据保证两类数的个数都不会是 0
#include<stdio.h>
int main02() {
    int n, k;//如100，16
    scanf("%d%d", &n, &k);
    int max = n / k;//将最大的数max*k找出来
    int num1 = 0,num2 = 0;
    for (int i = 1; i <= max; i++) {
        num1 += i * k;//将1k，2k...max*k依次相加
    }
    for (int j = 1; j <= n; j++) { 
        if (j % k == 0) {
            continue;//如果遇到A类数就不加
        }
        else {
            num2 += j;//B类数就加
        }
    }
    printf("%.1f %.1f", (float)num1 / max,(float)num2 / (n - max));//求平均值
    return 0;
}

//03一尺之锤，每次折半
#include<stdio.h>
int main03() {
    int a;
    scanf("%d", &a);
    int n = 0;
    while (a != 0) {
        a /= 2;
        n++;
    }
    printf("%d", n);
    return 0;
}

//04数字直角三角形
#include<stdio.h>
int main04() {
    int n;
    scanf("%d", &n);
    int Sn = (1 + n) * n / 2;
    int x = 01;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <n - i; j++) {
            if (x / 10 == 0) {
                printf("0%d", x);
            }
            else {
                printf("%d", x);
            }
            x++;
        }
        if (i == n - 1)
            break;
        printf("\n");
    }
    return 0;
}

//05阶乘之和(高精运算)
#include<stdio.h>
int main05()
{
    int i, A[1005] = { 0 }, B[1005] = { 0 }, n, j;
    scanf("%d", &n);
    A[0] = B[0] = 1;
    for (i = 2; i <= n; i++) {
        for (j = 0; j < 100; j++)//一百位是防止溢出，可以小一点
            B[j] *= i;
        for (j = 0; j < 100; j++)
            if (B[j] > 9) {
                B[j + 1] += B[j] / 10;
                B[j] %= 10;
            }//以上为计算 n 的阶乘 B ，遍历数组 B 即可打印出 n 的阶乘
        for (j = 0; j < 100; j++) {
            A[j] += B[j];
            if (A[j] > 9) {
                A[j + 1] += A[j] / 10;
                A[j] %= 10;
            }
        }//该for循环是"高精加"模板
    }
    //以下为遍历数组 A 
    for (i = 100; i >= 0 && A[i] == 0; i--);//把刚好不为0的那一项找出来，如果不找出来，会把高位的0也打印出来，如000...033
    for (j = i; j >= 0; j--)
        printf("%d", A[j]); //倒序打印，高位为数组下标大的项
    return 0;
}

//错误代码，又一次尝试递归失败
//#include<stdio.h>
//    void excess(int,int,int,int*);
//    int main() {
//        int n, x, m;
//        scanf("%d%d", &n, &x);
//        m = 1;//记录n的位数
//        int k = 0;//记录与x相等的个数
//        int temp = n;
//        while (temp / 10 != 0) {
//            m++;
//            temp /= 10;
//        }
//        for (int i = 1; i <= n; i++) {
//            while (m >= 1) {
//                m--;
//                excess(m, i, x, &k);
//            }
//        }
//        printf("%d", k);
//        return 0;
//    }
//    void excess(int m, int i, int x, int *k){
//        int z = i % (10 * m);//除去最高位的数
//        int y = i / (10 * m);//最高位数字
//        if (z == x)(*k)++;
//        if (y == x)(*k)++;
//        if (z > 9) {
//            i = z;
//            excess(m, i, x, &k);
//        }
//    }

//06计数问题
//此解法80分
//#include <stdio.h>
//void excess(int, int, int, int*);
//int main06() {
//        int n, x, m;
//        scanf("%d%d", &n, &x);
//        m = 1; //记录n的位数
//        int k = 0; //记录与x相等的个数
//        int temp = n;
//        while (temp / 10 != 0) {
//            m++;
//            temp /= 10;
//        }
//        for (int i = 1; i <= n; i++) {
//            excess(m, i, x, &k);
//        }
//        printf("%d", k);
//        return 0;
//    }
//
//void excess(int m, int i, int x, int* k) {
//    int temp = i;
//    for (int j = 0; j < m; j++) {
//        int digit = temp % 10;//记录个位数的值digit
//        if (digit == x) {
//            (*k)++;
//        }
//        temp /= 10;//去掉个位
//    }
//}

//另一种解法
#include <stdio.h>
int main06() {
    int a, b, j = 0;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= a; i++) {
        int d = i;
        while (d > 0) {
            int c = d % 10;
            d = d / 10;
            if (c == b) {
                j++;
            }
        }
    }
    printf("%d", j);
    return 0;
}

//07级数求和
//int main07() {
//    int k;
//    scanf("%d",&k);
//    int Sn = 0;
//    unsigned long long int n = 1;
//    while (Sn < k) {
//        Sn += (long double)1 / n;
//        n++;
//    }
//    printf("%d", n);
//    return 0;
//}

//08金币
#include<stdio.h>
#include<math.h>
int Sn(int n) {
    int sum = (n + 1) * (n) / 2;
    return sum;
}
int main08() {
    int k;
    int n;
    scanf("%d",&k);
    for (int j = 1;; j++) {
        if (k >= Sn(j) && k < Sn(j + 1)) {
            n = j;
            break;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(i, 2);
    }
    int total = 0;
    if (k == Sn(n))
        total = sum;
    else
        total = (k - Sn(n)) * (n + 1) + sum;
    printf("%d", total);
    return 0;
}

//09数列求和
#include<stdio.h>
int main09() {
    int sum = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("%d", sum);
    return 0;
}
//10质数口袋
#include<stdio.h>
#include<math.h>
int main10() {
    int L;//口袋容量
    scanf("%d", &L);
    int sum = 0;//质数和
    int num = 0;//质数个数
    for (int n = 2;sum <=L; n++) {
        int temp = 0;
        for (int i = 2;i <= sqrt(n); i++) {
            if (n % i == 0) {
                temp = 1;
                break;
            }
        }
        if (temp == 0) {
            sum += n;
            if (sum > L) {
                sum -= n;
                break;//最后一步sum会加之前小于L但加之后大于L，由于容量为L，sum加完后已经大于L了，则要舍弃最后一步加n的操作
            }
            printf("%d\n", n);
            num++;
        }
    }
    printf("%d", num);
    return 0;
}

//11回文质数
#include<stdio.h>
#include<math.h>
int digit(int n,int m,int x) {//求出第x位的数字
    int y = n / pow(10, m - x);
    int divisor = pow(10, x - 1);
    int z;
    if (x == 1)
        z = y;
    else if (x >= 3)
        z = y % 10;
    else
        z = y % divisor;
    return z;
}
int prime_num(int n) {//判断是否为质数
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;//不是质数,返回0
        }
    }
    return 1;
}
int main11() {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int n = a; n <= b; n++) {
        int temp = n;
        int flag = 1;
        int m = 1;//记录位数
        while (temp / 10 != 0) {
            m++;
            temp /= 10;
        }//循环得出位数m
        
        for (int i = 1; i <= m / 2; i++) {
            if ( digit(n, m, i) != digit(n, m, m - i + 1)) {
                flag = 0;
                break;//不是回文数，退出循环
            }
        }

        if (flag && prime_num(n)) {//判断是否为回文质数
            printf("%d\n", n);//打印出来
        }
        if (n == 9989900)break;
    }
    return 0;
}

//判断是否为回文数也可以用以下函数
int palindrome(int n) {
    int sum = 0;
    int k = n;
    while (n != 0) {
        sum = sum * 10 + n % 10;
        n /= 10;//将原数n倒置
    }
    if (sum == k)//看倒置后的数sum与原数是否相同
        return 1;
    else
        return 0;
}

//12小玉在游泳
#include<stdio.h>
#include<math.h>
int main12() {
    float sum = 2;
    float s;
    int n = 1;
    scanf("%f", &s);
    while (sum < s) {
        sum += 2 * pow(98e-2,n);
        n++;
    }
    printf("%d", n);
    return 0;
}

//13数字反转
int main13() {
    int N;
    int sum = 0;
    int flag = 0;
    scanf("%d", &N);
    if (N < 0)flag = 1;
    N = fabs(N);
    while ( N != 0 ) {
        sum = sum * 10 + N % 10;
        N /= 10;//去掉个位数
    }
    if (flag == 0)printf("%d", sum);
    else printf("-%d", sum);
    return 0;
}

//14月落乌啼算钱（斐波那契数列）
int main1401() {
    int n;
    int a = 0, b = 1, t;
    //b用来表示各个项的值 f(1),f(2)......
    scanf("%d", &n);
    while (n--) {
        t = a;//t被赋予上一个a的值即上一个b的值，认为上一个b的值为a=0
        a = b;//a的值发生改变，为现在b的值
        b += t;//上一个b的值加上现在b的值
    }//满足斐波那契数列
    printf("%.2f", (float)a);

}

#include<stdio.h>
#include<math.h>//pow(乘方)和sqrt(开方)在此头文件中
int main1402()
{
    double n;
    scanf("%lf", &n);//读入
    n = (pow((sqrt(5) + 1) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);//套用计算公式求解
    printf("%.2f", n);//输出
    return 0;//结束
}

#include<stdio.h>
int main1403() {
    int n, i;
    long long a = 1, b = 1, c = 1;
    scanf("%d", &n);
    for (i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%lld.00", c);

}

//15求极差range
int main15() {
    int search_max(int*, int);
    int search_min(int*, int);
    int n;
    scanf("%d", &n);
    int* arr = NULL;
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int range = search_max(arr, n) - search_min(arr, n);//极差range
    printf("%d", range);
    free(arr);
    return 0;
}

int search_max(int* arr, int n) {
    int max = *arr;
    for (int i = 1; i < n; i++) {
        if (max < *(arr + i)) {
            max = *(arr + i);
        }
    }
    return max;
}

int search_min(int* arr, int n) {
    int min = *arr;
    for (int i = 1; i < n; i++) {
        if (min > *(arr + i)) {
            min = *(arr + i);
        }
    }
    return min;
}

//求众数mode
//函数法
int search_mode(int* arr, int n) {
    int mode = 0;
    int num = 1;//众数的重复次数
    int temp = 1;//暂时的众数的重复次数
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) == *(arr + j)) {
                temp++;
            }
        }
        if (temp > num) {//看重复次数是否比上次的大，大了就把众数的值更新成新的值，重复次数也更新
            num = temp;
            temp = 1;//置1，保证下一次循环temp=1
            mode = *(arr + i);//将众数记录下来
        }
    }
    return mode;
}
//另一种方法
int main0() {
    int n; // 数据规模
    scanf("%d", &n);
    int arr[100] = { 0 }; // 用于存储每个元素出现的次数，下标表示元素的值
    int maxCount = 0; // 最大出现次数
    int maxElement = 0; // 出现次数最多的元素
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        arr[num]++; // 对应元素的计数加1

        if (arr[num] > maxCount) {//输入第一个值时，if语句执行一次，同一个num值每重复一次，if语句执行一次
            maxCount = arr[num];//每次赋值，maxCount的值会随这个num值的重复次数的增大而增大
            maxElement = num;//当发现有重复次数更多的num值时，maxElement的值就被更新一次
        }
    }
    printf("出现次数最多的元素是：%d\n", maxElement);
    return 0;
}


//16最长连号
//即按自然数的顺序排列的最大长度
//如数组中出现了23456连着，则连号为5，若没有更长的连号，5即为最长连号
int main16() {
    int n;
    int count = 1;//最长连号的大小
    int temp = 1;//记录连号的大小
    int* arr = NULL;
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    scanf("%d", arr);
    for (int i = 1; i < n; i++) {
        scanf("%d", arr + i);
        if (*(arr + i) == *(arr + i - 1) + 1) {
            temp++;
        }
        else {//中断
            if (temp > count) {
                count = temp;
                temp = 1;//中断后置1
            }
        }
    }
    if (temp > count)
        count = temp;//防止一直连到最后，但count的值还是1
    printf("%d", count);
    return 0;
}

//17质因数分解
int main17() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            printf("%d", n / i);
            break;
        }
    }
    return 0;
}

//18求三角形
int main18() {
    int n;
    scanf("%d", &n);
    void print_n_matrix(int);
    void print_n_triangle(int);
    print_n_matrix(n);
    printf("\n");
    print_n_triangle(n);
    return 0;
}
//以下两个函数两种算法
void print_n_matrix(int n) {//输出n阶矩阵，一层for循环
    for (int i = 1; i <= n * n; i++) {
        if (i % n == 0 && i <= 9) {
            printf("0%d\n", i);
        }
        else if (i % n == 0 && i > 9) {
            printf("%d\n", i);
        }
        else if (i <= 9)
            printf("0%d", i);
        else
            printf("%d", i);
    }
}

void print_n_triangle(int n) {//输出下三角形，两层嵌套for循环
    int num = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n- i; k++)
            printf("  ");
        for (int j = 1; j <= i; j++) {
            num++;
            if (num <= 9)
                printf("0%d", num);
            else
                printf("%d", num);
        }
        printf("\n");
    }
}

//19打分
int main19() {
    int n;
    scanf("%d", &n);
    int arr[1000] = { 0 };
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int max = search_max(arr, n);
    int min = search_min(arr, n);
    int flag1 = 0, flag2 = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == min)
        {
            if (flag1 == 0)
            {
                *(arr + i) = 0;
                flag1 = 1;
            }
        }
        if (*(arr + i) == max)
        {
            if (flag2 == 0)
            {
                *(arr + i) = 0;
                flag2 = 1;
            }
        }
        sum += *(arr + i);
    }
    float average_value =(float)sum / (n - 2);
    printf("%.2f", average_value);
    return 0;
}

//20Davor
int main20() {
    int n;
    int flag = 0;//标记是否找出
    scanf("%d", &n);
    for (int k = 1;;k++) {
        if (flag == 1)break;
        for (int x = 100; x > 0; x--) {
            if (364 * x + 1092 * k == n) {
                printf("%d\n%d", x, k);
                flag = 1;
                break;
            }
        }
    }
    return 0;
}

//21津津的储蓄计划
int main21() {
    int arr[12] = { 0 };//每个月用的钱//arr[0]为第一个月用的钱
    int money[13] = { 0 };//每个月末的钱//money[0]为刚开始的钱，money[1]为第一个月的钱
    int sum = 0;//妈妈那存的钱
    int flag = 0;//标记是否会出现不够用的情况
    int i, j;
    for (i = 0; i < 12; i++)
        scanf("%d", arr + i);
    for (i = 0; i < 12; i++) {
        if ((money[i + 1] = money[i] + 300 - arr[i]) >= 0) {
            for (j = 3; j >= 1; j--) { 
                if (money[i + 1] >= j * 100) {
                    money[i + 1] -= j * 100;
                    break;//看存了几百
                }
            }
            sum += j * 100;
        }
        else {
            printf("-%d", i + 1);
            flag = 1;//出现了钱不够用的情况
            break;
        }
    }
    int total_money = sum / 5 + sum + money[12];
    if (flag == 0) printf("%d", total_money);//没出现钱不够用的情况，总的钱为从妈妈那得到原来存的钱的120%的钱加最后一个月末的钱
    return 0;
}
