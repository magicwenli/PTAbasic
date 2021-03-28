/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-03-28 11:03:11
 * @Description  : 1036 跟奥巴马一起编程 (15 分)
 * @FilePath     : /PTAbasic/program/1036.cpp
 */

#include <iostream>
using namespace std;

int main() {
    int num;
    char c;
    cin >> num >> c;
    // 1
    for (int i = 0; i < num; i++) {
        cout << c;
    }
    cout << endl;
    // 2
    for (int i = 0; i < (num + 1) / 2 - 2; i++) {
        cout << c;
        for (int i = 1; i < num - 1; i++) {
            cout << ' ';
        }
        cout << c << endl;
    }
    // 3
    if (num > 1) {
        for (int i = 0; i < num; i++) {
            cout << c;
        }
    }

    return 0;
}