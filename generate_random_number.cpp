#include <iostream>
#include <cstdlib>
#include "time.h"
using namespace std;
 
//Two ways to generate random numbers

// 1. use rand() function, in "cstdlib" library

void generateRandomNum_1() {
       cout <<"RAND_MAX:"<< RAND_MAX << endl;
       for (int i = 0; i < 5; i++)
              cout << rand() << endl;        // each time you run this loop, the results are the SAME !!!           
}

// 2. use srand() function
// with header file "time.h"
void generateRandomNum_2() {
    cout <<"RAND_MAX:"<< RAND_MAX << endl;
    srand((unsigned)time(NULL));        // generate different random seed
    for (int i = 0; i < 5; i++) {
        cout << rand() << endl;
    }
}

/*
要产生指定范围内的随机数，可以先使用rand()函数产生一个[0,RAND_MAX]范围内的随机数，然后在变换到指定范围内。
产生[a,b)的随机数，可以使用 (rand() % (b-a))+a;
产生[a,b]的随机数，可以使用 (rand() % (b-a+1))+a;
产生(a,b]的随机数，可以使用 (rand() % (b-a))+a+1;
通用公式：a+rand() % n;
其中：a为范围起始位置，n为整数的范围
产生[a,b]的随机数，可以使用 a+(int)b*rand()/(RAND_MAX+1);
产生[0,1]的浮点数，可以使用 rand()/double(RAND_MAX);
*/

int main() {
    generateRandomNum_2();
    return 0;
}
