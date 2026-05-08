// 爱丽丝有n个人偶，每个人偶的身高依次是1、2、3......n
// 现在她要将这n个人偶摆成一排。但是人偶被设置了魔法。
// 假设对一个非两端的(不在队首也不在队尾)人偶x而言
// 她相邻的两个人偶，一个比a高、一个比a矮，那么就会爆炸。
// 爱丽丝想找到一种摆法，使得所有人偶都不会爆炸。你能帮帮她吗?

#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int left = 1, right = n;
    while (left <= right)
    {
        cout << left++ << ' ';
        if(left <= right)
            cout << right-- << ' ';
    }
}