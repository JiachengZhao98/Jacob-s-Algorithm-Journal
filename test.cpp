#include <iostream>
#include "string"

using namespace std;

int main()
{
    char c = '2';
    bool yn = isdigit(c);
    if (yn) cout << "yes" << std::endl;
    else cout<< "no"<<endl;
    return 0;
}
