#include <unistd.h>
#include "iostream"
#include "stdio.h"
using namespace std;

int main() {
    int pid = getpid();
    int num = 1;
    int printNum = pid;

    while (num <= 10000) {
        cout<<"pid_"<<num<<" forever "<<printNum;
        num++;
        printNum = pid * num;
    }
    return 0;
}
