#include <iostream>
#include<cmath>

using namespace std;

int main()
{
    int num = 111123145;
    int pos = 2;

    // long digit = (num >> pos);
    cout << num / static_cast<int>(pow(10, pos)) % 10 << endl;
    system("pause");
    return 0;
}
