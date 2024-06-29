#include <QtTest>
#include "Friends.h"

class Test_Friends : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void test_Friends();
    void test_Friends_data();
private:
    const int num0 = 0;
    Friends mCalc;
};
void Test_Friends::init() {
    mCalc.SetA(num0);
    mCalc.SetB(num0);
}

void Test_Friends::test_Friends_data() {
    QTest::addColumn<int>("m_a");
    QTest::addColumn<int>("m_b");
    QTest::addColumn<bool>("res");

    QTest::newRow("220 и 284") << 220 << 284 << true;
    QTest::newRow("10 и 9") << 10 << 9 << false;
    QTest::newRow("22 и 24") << 22 << 24 << false;
    QTest::newRow("1184 и 1210") << 1184 << 1210 << true;
}

void Test_Friends::test_Friends()
{
    // retrieve data
    QFETCH(int, m_a);
    QFETCH(int, m_b);
    QFETCH(bool, res);

    // set values
    mCalc.SetA(m_a);
    mCalc.SetB(m_b);

    QCOMPARE(mCalc.isFriends(), res);
}

QTEST_APPLESS_MAIN(Test_Friends)

#include "tst_test_friends.moc"
