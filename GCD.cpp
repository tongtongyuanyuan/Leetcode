//
// Created by Tong Xue on 2019-08-16.
//

#include <iostream>

using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    int a = 3025;
    int b = 1025;
    cout << gcd(a, b) << "";
}