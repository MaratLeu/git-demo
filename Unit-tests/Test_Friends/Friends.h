// example class to test
#include <vector>
using namespace std;
class Friends
{
public:
    Friends(int M_num = 0) : a(M_num), b(M_num) {}

    bool isFriends() {
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i < a; i++) {
            if (a % i == 0)
                sum1 += i;
            else
                sum1 += 0;
        }
        for (int k = 1; k < b; k++) {
            if (b % k == 0)
                sum2 += k;
            else
                sum2 += 0;
        }
        if ((sum2 == a) && (sum1 == b) && (a != b)) {
            return true;
        }
        return false;
    }


    void SetA(int m_a) {
        a = m_a;
    }

    void SetB(int m_b) {
        b = m_b;
    }

private:
    int a;
    int b;
};
