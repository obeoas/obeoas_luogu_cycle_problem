#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//ѭ���ṹ
//01����Сֵ
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

//02����ƽ��
//����n��k������1��n֮����������������Է�Ϊ���ࣺA�������Ա�k������Ҳ����˵��k�ı��������� B �������ܡ�
//���������������ƽ��������ȷ��С�����1λ���ÿո���������ݱ�֤�������ĸ����������� 0
#include<stdio.h>
int main02() {
    int n, k;//��100��16
    scanf("%d%d", &n, &k);
    int max = n / k;//��������max*k�ҳ���
    int num1 = 0,num2 = 0;
    for (int i = 1; i <= max; i++) {
        num1 += i * k;//��1k��2k...max*k�������
    }
    for (int j = 1; j <= n; j++) { 
        if (j % k == 0) {
            continue;//�������A�����Ͳ���
        }
        else {
            num2 += j;//B�����ͼ�
        }
    }
    printf("%.1f %.1f", (float)num1 / max,(float)num2 / (n - max));//��ƽ��ֵ
    return 0;
}

//03һ��֮����ÿ���۰�
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

//04����ֱ��������
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

//05�׳�֮��(�߾�����)
#include<stdio.h>
int main05()
{
    int i, A[1005] = { 0 }, B[1005] = { 0 }, n, j;
    scanf("%d", &n);
    A[0] = B[0] = 1;
    for (i = 2; i <= n; i++) {
        for (j = 0; j < 100; j++)//һ��λ�Ƿ�ֹ���������Сһ��
            B[j] *= i;
        for (j = 0; j < 100; j++)
            if (B[j] > 9) {
                B[j + 1] += B[j] / 10;
                B[j] %= 10;
            }//����Ϊ���� n �Ľ׳� B ���������� B ���ɴ�ӡ�� n �Ľ׳�
        for (j = 0; j < 100; j++) {
            A[j] += B[j];
            if (A[j] > 9) {
                A[j + 1] += A[j] / 10;
                A[j] %= 10;
            }
        }//��forѭ����"�߾���"ģ��
    }
    //����Ϊ�������� A 
    for (i = 100; i >= 0 && A[i] == 0; i--);//�Ѹպò�Ϊ0����һ���ҳ�����������ҳ�������Ѹ�λ��0Ҳ��ӡ��������000...033
    for (j = i; j >= 0; j--)
        printf("%d", A[j]); //�����ӡ����λΪ�����±�����
    return 0;
}

//������룬��һ�γ��Եݹ�ʧ��
//#include<stdio.h>
//    void excess(int,int,int,int*);
//    int main() {
//        int n, x, m;
//        scanf("%d%d", &n, &x);
//        m = 1;//��¼n��λ��
//        int k = 0;//��¼��x��ȵĸ���
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
//        int z = i % (10 * m);//��ȥ���λ����
//        int y = i / (10 * m);//���λ����
//        if (z == x)(*k)++;
//        if (y == x)(*k)++;
//        if (z > 9) {
//            i = z;
//            excess(m, i, x, &k);
//        }
//    }

//06��������
//�˽ⷨ80��
//#include <stdio.h>
//void excess(int, int, int, int*);
//int main06() {
//        int n, x, m;
//        scanf("%d%d", &n, &x);
//        m = 1; //��¼n��λ��
//        int k = 0; //��¼��x��ȵĸ���
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
//        int digit = temp % 10;//��¼��λ����ֵdigit
//        if (digit == x) {
//            (*k)++;
//        }
//        temp /= 10;//ȥ����λ
//    }
//}

//��һ�ֽⷨ
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

//07�������
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

//08���
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

//09�������
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
//10�����ڴ�
#include<stdio.h>
#include<math.h>
int main10() {
    int L;//�ڴ�����
    scanf("%d", &L);
    int sum = 0;//������
    int num = 0;//��������
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
                break;//���һ��sum���֮ǰС��L����֮�����L����������ΪL��sum������Ѿ�����L�ˣ���Ҫ�������һ����n�Ĳ���
            }
            printf("%d\n", n);
            num++;
        }
    }
    printf("%d", num);
    return 0;
}

//11��������
#include<stdio.h>
#include<math.h>
int digit(int n,int m,int x) {//�����xλ������
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
int prime_num(int n) {//�ж��Ƿ�Ϊ����
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;//��������,����0
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
        int m = 1;//��¼λ��
        while (temp / 10 != 0) {
            m++;
            temp /= 10;
        }//ѭ���ó�λ��m
        
        for (int i = 1; i <= m / 2; i++) {
            if ( digit(n, m, i) != digit(n, m, m - i + 1)) {
                flag = 0;
                break;//���ǻ��������˳�ѭ��
            }
        }

        if (flag && prime_num(n)) {//�ж��Ƿ�Ϊ��������
            printf("%d\n", n);//��ӡ����
        }
        if (n == 9989900)break;
    }
    return 0;
}

//�ж��Ƿ�Ϊ������Ҳ���������º���
int palindrome(int n) {
    int sum = 0;
    int k = n;
    while (n != 0) {
        sum = sum * 10 + n % 10;
        n /= 10;//��ԭ��n����
    }
    if (sum == k)//�����ú����sum��ԭ���Ƿ���ͬ
        return 1;
    else
        return 0;
}

//12С������Ӿ
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

//13���ַ�ת
int main13() {
    int N;
    int sum = 0;
    int flag = 0;
    scanf("%d", &N);
    if (N < 0)flag = 1;
    N = fabs(N);
    while ( N != 0 ) {
        sum = sum * 10 + N % 10;
        N /= 10;//ȥ����λ��
    }
    if (flag == 0)printf("%d", sum);
    else printf("-%d", sum);
    return 0;
}

//14����������Ǯ��쳲��������У�
int main1401() {
    int n;
    int a = 0, b = 1, t;
    //b������ʾ�������ֵ f(1),f(2)......
    scanf("%d", &n);
    while (n--) {
        t = a;//t��������һ��a��ֵ����һ��b��ֵ����Ϊ��һ��b��ֵΪa=0
        a = b;//a��ֵ�����ı䣬Ϊ����b��ֵ
        b += t;//��һ��b��ֵ��������b��ֵ
    }//����쳲���������
    printf("%.2f", (float)a);

}

#include<stdio.h>
#include<math.h>//pow(�˷�)��sqrt(����)�ڴ�ͷ�ļ���
int main1402()
{
    double n;
    scanf("%lf", &n);//����
    n = (pow((sqrt(5) + 1) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);//���ü��㹫ʽ���
    printf("%.2f", n);//���
    return 0;//����
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

//15�󼫲�range
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
    int range = search_max(arr, n) - search_min(arr, n);//����range
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

//������mode
//������
int search_mode(int* arr, int n) {
    int mode = 0;
    int num = 1;//�������ظ�����
    int temp = 1;//��ʱ���������ظ�����
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) == *(arr + j)) {
                temp++;
            }
        }
        if (temp > num) {//���ظ������Ƿ���ϴεĴ󣬴��˾Ͱ�������ֵ���³��µ�ֵ���ظ�����Ҳ����
            num = temp;
            temp = 1;//��1����֤��һ��ѭ��temp=1
            mode = *(arr + i);//��������¼����
        }
    }
    return mode;
}
//��һ�ַ���
int main0() {
    int n; // ���ݹ�ģ
    scanf("%d", &n);
    int arr[100] = { 0 }; // ���ڴ洢ÿ��Ԫ�س��ֵĴ������±��ʾԪ�ص�ֵ
    int maxCount = 0; // �����ִ���
    int maxElement = 0; // ���ִ�������Ԫ��
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        arr[num]++; // ��ӦԪ�صļ�����1

        if (arr[num] > maxCount) {//�����һ��ֵʱ��if���ִ��һ�Σ�ͬһ��numֵÿ�ظ�һ�Σ�if���ִ��һ��
            maxCount = arr[num];//ÿ�θ�ֵ��maxCount��ֵ�������numֵ���ظ����������������
            maxElement = num;//���������ظ����������numֵʱ��maxElement��ֵ�ͱ�����һ��
        }
    }
    printf("���ִ�������Ԫ���ǣ�%d\n", maxElement);
    return 0;
}


//16�����
//������Ȼ����˳�����е���󳤶�
//�������г�����23456���ţ�������Ϊ5����û�и��������ţ�5��Ϊ�����
int main16() {
    int n;
    int count = 1;//����ŵĴ�С
    int temp = 1;//��¼���ŵĴ�С
    int* arr = NULL;
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    scanf("%d", arr);
    for (int i = 1; i < n; i++) {
        scanf("%d", arr + i);
        if (*(arr + i) == *(arr + i - 1) + 1) {
            temp++;
        }
        else {//�ж�
            if (temp > count) {
                count = temp;
                temp = 1;//�жϺ���1
            }
        }
    }
    if (temp > count)
        count = temp;//��ֹһֱ������󣬵�count��ֵ����1
    printf("%d", count);
    return 0;
}

//17�������ֽ�
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

//18��������
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
//�����������������㷨
void print_n_matrix(int n) {//���n�׾���һ��forѭ��
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

void print_n_triangle(int n) {//����������Σ�����Ƕ��forѭ��
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

//19���
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
    int flag = 0;//����Ƿ��ҳ�
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

//21���Ĵ���ƻ�
int main21() {
    int arr[12] = { 0 };//ÿ�����õ�Ǯ//arr[0]Ϊ��һ�����õ�Ǯ
    int money[13] = { 0 };//ÿ����ĩ��Ǯ//money[0]Ϊ�տ�ʼ��Ǯ��money[1]Ϊ��һ���µ�Ǯ
    int sum = 0;//�����Ǵ��Ǯ
    int flag = 0;//����Ƿ����ֲ����õ����
    int i, j;
    for (i = 0; i < 12; i++)
        scanf("%d", arr + i);
    for (i = 0; i < 12; i++) {
        if ((money[i + 1] = money[i] + 300 - arr[i]) >= 0) {
            for (j = 3; j >= 1; j--) { 
                if (money[i + 1] >= j * 100) {
                    money[i + 1] -= j * 100;
                    break;//�����˼���
                }
            }
            sum += j * 100;
        }
        else {
            printf("-%d", i + 1);
            flag = 1;//������Ǯ�����õ����
            break;
        }
    }
    int total_money = sum / 5 + sum + money[12];
    if (flag == 0) printf("%d", total_money);//û����Ǯ�����õ�������ܵ�ǮΪ�������ǵõ�ԭ�����Ǯ��120%��Ǯ�����һ����ĩ��Ǯ
    return 0;
}
