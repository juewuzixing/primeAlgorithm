#include <iostream>
#include <cmath>
#include <chrono>

const int MAX = 100000;

using namespace std;

/*
 * 质数定义：一个大于1的自然数，除了1和它本身外，不能被其他自然数（质数）整除。
 * 算法1：（定义）判断一个整数n是否为质数，只需用2到n-1之间的每一个整数去除，
 * 如果都不能被整除，那么n就是一个质数
*/

void primeAlgorithmOne() {
    int j;
    for (int i = 2; i <= MAX; i++) {
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (i == j) {
            cout << "i: " << i << "\n";
        }
    }
}

/*
 * 算法2：（质数筛选定理）n不能够被不大于根号n的任何质数整除，则n是一个质数
*/
void primeAlgorithmTwo() {
    int j;
    // 2是质数直接输出
    cout << "i: 2" << "\n";
    // 偶数不是质数，步长可以加大
    for (int i = 3; i <= MAX; i += 2) {
        float temp = static_cast<float>(i);
        int mid = static_cast<int>(sqrt(temp));
        // i是奇数，当然不能被偶数整除，步长也可以加大
        for (j = 3; j <= mid; j += 2) {
            if (i % j == 0) {
                break;
            }
        }
        if (j > mid) {
            cout << "i: " << i << "\n";
        }
    }
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    primeAlgorithmOne();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    cout << "int_ms1: " << int_ms1.count() << "ms" << "\n";

    auto t3 = std::chrono::high_resolution_clock::now();
    primeAlgorithmTwo();
    auto t4 = std::chrono::high_resolution_clock::now();
    auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
    cout << "int_ms2: " << int_ms2.count() << "ms" << "\n";
    return 0;
}
