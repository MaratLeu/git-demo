#include "Count.h"

#include <QtTest>

class TestCount: public QObject
{
    Q_OBJECT

private slots:
    void init();
    void test_Count();
    void test_Count_data();
private:
    const int num0 = 0;
    Count mCalc;
};

void TestCount::init() {
    mCalc.SetNum(num0);
}

void TestCount::test_Count_data() {
    QTest::addColumn<int>("num");
    QTest::addColumn<QVector<int>>("mas");

    QVector<int> mas1 = {0, 0, 0, 1, 0, 1, 0, 1, 0, 0};
    QVector<int> mas2 = {0, 0, 1, 2, 1, 0, 0, 1, 1, 0};
    QVector<int> mas3 = {1, 0, 1, 1, 0, 0, 2, 1, 1, 0};
    QVector<int> mas4 = {0, 0, 3, 0, 0, 0, 0, 0, 0, 0};

    QTest::newRow("573") << 573 << mas1;
    QTest::newRow("374823") << 374823 << mas2;
    QTest::newRow("3762806") << 3762806 << mas3;
    QTest::newRow("222") << 222 << mas4;
}

void TestCount::test_Count()
{
    // retrieve data
    QFETCH(int, num);
    QFETCH(QVector<int>, mas);

    // set values
    mCalc.SetNum(num);

    vector<int> masStd(mas.begin(), mas.end());
    QCOMPARE(mCalc.count(), masStd);
}

QTEST_APPLESS_MAIN(TestCount)

#include "tst_test_count.moc"
