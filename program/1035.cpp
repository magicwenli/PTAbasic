/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-03-16 23:06:25
 * @Description  : 1035 插入与归并 (25 分)
 * @FilePath     : /wesley/PTAbasic/program/1035.cpp
 */

// 首先判断是否为插入排序的中间序列，如果不是则为归并排序
// 判断方法很简单，插入排序前面一定有一段序列是非递减的，而后面的序列是和原序列相同的

#include <algorithm>
#include <iostream>
using namespace std;
int n;  // length of the array

void insertSort(int a[], int b[]) {
    bool is_insert = false;
    for (int i = 2; i <= n; i++) {
        sort(a, a + i);
        if (is_insert) {
            cout << "Insertion Sort" << endl;
            cout << a[0];
            for (int j = 1; j < n; j++) {
                cout << " " << a[j];
            }
            return;
        }
        if (equal(a, a + n, b))  // Tests a range for element-wise equality.
            is_insert = true;
    }
}

void margeSort(int a[], int b[]) {
    bool is_marge = false;
    for (int i = 2;; i *= 2) {
        for (int j = 0; j < n; j += i) {  // 对前 2、4、8、16个数进行排序
            sort(a + j, a + (j + i < n ? j + i : n));
        }
        if (is_marge) {
            cout << "Merge Sort" << endl;
            cout << a[0];
            for (int j = 1; j < n; j++) cout << " " << a[j];
            return;
        }
        if (equal(a, a + n, b))  // 判断是否为归并排序
            is_marge = true;
        if (i > n) break;  // 超出索引则返回
    }
}
int main() {
    cin >> n;
    int a1[100], a2[100], b[100];
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
        a2[i] = a1[i];
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    insertSort(a2, b);
    margeSort(a1, b);
    return 0;
}