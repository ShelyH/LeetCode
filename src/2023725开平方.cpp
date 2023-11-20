#include <iostream>
#include <type_traits>
using namespace std;

bool isPerfectSquare(int num)
{
    double n = num;
    double result;

    if (n == 1) {
        return true;
    }
    else {
        result = n / 2;
        for (int i = 1; i <= 100; i++) {
            if (result * result <= n) {
                break;
            }
            else {
                result = (result + (n / result)) / 2;
            }
        }
        // cout << result << endl;
        if (is_same<decltype(result), long long>::value) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main()
{
    bool res = isPerfectSquare(4);
    cout << res << endl;
    return 0;
}
