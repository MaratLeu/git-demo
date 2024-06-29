// example class to test
#include <vector>
    using namespace std;
class Count
{
public:
    Count(int M_num = 0) : num(M_num) {}

    vector<int> count() {
        vector<int> mas(10, 0);

        while (num != 0) {
            int digit = num % 10;
            mas[digit]++;
            num /= 10;
        }

        return mas;
    }

    void SetNum(int a) {
        num = a;
    }

private:
    int num;
};
