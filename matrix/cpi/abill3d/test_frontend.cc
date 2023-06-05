#ifdef test_FrontEnd
#define MYLOGLEVEL 2
void myMessageOutput(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
        if (MYLOGLEVEL <= 0)
            fprintf(stderr, "Debug: %s\n", msg);
        break;
    case QtWarningMsg:
        if (MYLOGLEVEL <= 1)
            fprintf(stderr, "Warning: %s\n", msg);
        break;
    case QtCriticalMsg:
        if (MYLOGLEVEL <= 2)
            fprintf(stderr, "Critical: %s\n", msg);
        break;
    case QtFatalMsg:
        if (MYLOGLEVEL <= 3)
            fprintf(stderr, "Fatal: %s\n", msg);
        abort();
    }
}
//
// Definition of testcases: Normal tests
//
void FrontEndItemTests::timeout()
{
    timed_out = true;
    timer.stop();
}
// Before all tests
void FrontEndItemTests::initTestCase()
{
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(timeout()));
}
// After all tests
void FrontEndItemTests::cleanupTestCase()
{
}
// Before each test
void FrontEndItemTests::init()
{
    boolItem = new FrontEndItem("/Test/Bool");
    intItem = new FrontEndItem("/Test/Int");
    stringItem = new FrontEndItem("/Test/String");
    doubleItem = new FrontEndItem("/Test/Double");
    stringListItem = new FrontEndItem("/Test/StringList");
    intListItem = new FrontEndItem("/Test/IntList");
    doubleListItem = new FrontEndItem("/Test/DoubleList");
    boolListItem = new FrontEndItem("/Test/BoolList");
    unsetBeforeItem = new FrontEndItem("/Test/UnsetBefore");
    unsetAfterItem = new FrontEndItem("/Test/UnsetAfter");
    signalSpy = new SignalListener();
    QObject::connect(boolItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::connect(intItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::connect(stringItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::connect(doubleItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::connect(stringListItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::connect(intListItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::connect(doubleListItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::connect(boolListItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
}
// After each test
void FrontEndItemTests::cleanup()
{
    QObject::disconnect(boolItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::disconnect(intItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::disconnect(stringItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::disconnect(doubleItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::disconnect(stringListItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::disconnect(intListItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::disconnect(doubleListItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    QObject::disconnect(boolListItem, SIGNAL(valueChanged()), signalSpy, SLOT(valueChanged()));
    delete signalSpy;
    delete boolItem;
    delete intItem;
    delete stringItem;
    delete doubleItem;
    delete stringListItem;
    delete intListItem;
    delete doubleListItem;
    delete boolListItem;
    delete unsetBeforeItem;
    delete unsetAfterItem;
    timer.stop();
}
void FrontEndItemTests::path()
{
    QCOMPARE(boolItem->key(), QString("/Test/Bool"));
    QCOMPARE(intItem->key(), QString("/Test/Int"));
    QCOMPARE(stringItem->key(), QString("/Test/String"));
    QCOMPARE(doubleItem->key(), QString("/Test/Double"));
    QCOMPARE(stringListItem->key(), QString("/Test/StringList"));
    QCOMPARE(intListItem->key(), QString("/Test/IntList"));
    QCOMPARE(doubleListItem->key(), QString("/Test/DoubleList"));
    QCOMPARE(boolListItem->key(), QString("/Test/BoolList"));
    QCOMPARE(unsetBeforeItem->key(), QString("/Test/UnsetBefore"));
    QCOMPARE(unsetAfterItem->key(), QString("/Test/UnsetAfter"));
}
void FrontEndItemTests::external_values()
{
    // These values are set before this program starts.
    QCOMPARE(boolItem->value().toBool(), true);
    QCOMPARE(intItem->value().toInt(), 123);
    QCOMPARE(stringItem->value().toString(), QString("Hello FrontEnd"));
    QCOMPARE(doubleItem->value().toDouble(), 3.5);
    QCOMPARE(stringListItem->value().toStringList(), QStringList() << "Hello" << "FrontEnd" << QString::fromUtf8("ÄÖÜ"));
    QCOMPARE(intListItem->value().toList(), QList<QVariant>() << 1 << 2 << 3 << 4);
    QCOMPARE(doubleListItem->value().toList(), QList<QVariant>() << 3.5 << 3.5 << 3.5);
    QCOMPARE(boolListItem->value().toList(), QList<QVariant>() << false << true << true << false);
    QCOMPARE(unsetBeforeItem->value().isValid(), false);
    QCOMPARE(unsetAfterItem->value().isValid(), true);
}
void FrontEndItemTests::set_bool()
{
    signalSpy->numberOfCalls = 0;
    boolItem->set(false);
    QCOMPARE(boolItem->value().toBool(), false);
    boolItem->set(true);
    QCOMPARE(boolItem->value().toBool(), true);
    QCOMPARE(signalSpy->numberOfCalls, 2);
}
void FrontEndItemTests::set_int()
{
    signalSpy->numberOfCalls = 0;
    intItem->set(12);
    QCOMPARE(intItem->value().toInt(), 12);
    intItem->set(-5);
    QCOMPARE(intItem->value().toInt(), -5);
    QCOMPARE(signalSpy->numberOfCalls, 2);
}
void FrontEndItemTests::set_string()
{
    signalSpy->numberOfCalls = 0;
    stringItem->set("Hi");
    QCOMPARE(stringItem->value().toString(), QString("Hi"));
    QCOMPARE(signalSpy->numberOfCalls, 1);
}
void FrontEndItemTests::set_unicode_string()
{
    signalSpy->numberOfCalls = 0;
    stringItem->set(QString::fromUtf8("Höäü"));
    QCOMPARE(stringItem->value().toString(), QString::fromUtf8("Höäü"));
    QCOMPARE(signalSpy->numberOfCalls, 1);
}
void FrontEndItemTests::set_double()
{
    signalSpy->numberOfCalls = 0;
    doubleItem->set(1.2345);
    QCOMPARE(doubleItem->value().toDouble(), 1.2345);
    QCOMPARE(signalSpy->numberOfCalls, 1);
}
void FrontEndItemTests::set_string_list()
{
    signalSpy->numberOfCalls = 0;
    stringListItem->set(QStringList() << "one" << "two" << "three");
    QCOMPARE(stringListItem->value().toStringList(), QStringList() << "one" << "two" << "three");
    QCOMPARE(signalSpy->numberOfCalls, 1);
}
void FrontEndItemTests::set_int_list()
{
    signalSpy->numberOfCalls = 0;
    intListItem->set(QList<QVariant>() << 10 << 11 << 12);
    QCOMPARE(intListItem->value().toList(), QList<QVariant>() << 10 << 11 << 12);
    QCOMPARE(signalSpy->numberOfCalls, 1);
}
void FrontEndItemTests::set_double_list()
{
    signalSpy->numberOfCalls = 0;
    doubleListItem->set(QList<QVariant>() << 1.1 << 2.2 << 3.3);
    QCOMPARE(doubleListItem->value().toList(), QList<QVariant>() << 1.1 << 2.2 << 3.3);
    QCOMPARE(signalSpy->numberOfCalls, 1);
}
void FrontEndItemTests::set_bool_list()
{
    signalSpy->numberOfCalls = 0;
    boolListItem->set(QList<QVariant>() << true << true << false);
    QCOMPARE(boolListItem->value().toList(), QList<QVariant>() << true << true << false);
    QCOMPARE(signalSpy->numberOfCalls, 1);
}
void FrontEndItemTests::unset ()
{
    signalSpy->numberOfCalls = 0;
    boolItem->unset();
    QCOMPARE(boolItem->value().isValid(), false);
    QCOMPARE(signalSpy->numberOfCalls, 1);
}
void FrontEndItemTests::list_dirs ()
{
    FrontEndItem test("/Test");
    QStringList dirs = test.listDirs();
    QVERIFY (!dirs.contains("/Test/Bool"));
    QVERIFY (!dirs.contains("/Test/Int"));
    QVERIFY (!dirs.contains("/Test/String"));
    QVERIFY (!dirs.contains("/Test/Double"));
    QVERIFY (!dirs.contains("/Test/StringList"));
    QVERIFY (!dirs.contains("/Test/IntList"));
    QVERIFY (!dirs.contains("/Test/DoubleList"));
    QVERIFY (!dirs.contains("/Test/BoolList"));
    QVERIFY (!dirs.contains("/Test/UnsetBefore"));
    QVERIFY (!dirs.contains("/Test/UnsetAfter"));
    QVERIFY (dirs.contains("/Test/Dir"));
}
void FrontEndItemTests::list_entries ()
{
    FrontEndItem test("/Test");
    QStringList entries = test.listEntries();
    QVERIFY (!entries.contains("/Test/Bool"));  // has been unset above
    QVERIFY (entries.contains("/Test/Int"));
    QVERIFY (entries.contains("/Test/String"));
    QVERIFY (entries.contains("/Test/Double"));
    QVERIFY (entries.contains("/Test/StringList"));
    QVERIFY (entries.contains("/Test/IntList"));
    QVERIFY (entries.contains("/Test/DoubleList"));
    QVERIFY (entries.contains("/Test/BoolList"));
    QVERIFY (!entries.contains("/Test/UnsetBefore"));
    QVERIFY (entries.contains("/Test/UnsetAfter"));
    QVERIFY (!entries.contains("/Test/Dir"));
}
void FrontEndItemTests::get_default ()
{
    intItem->unset();
    QCOMPARE(intItem->value(123).toInt(), 123);
    intItem->set(234);
    QCOMPARE(intItem->value(123).toInt(), 234);
}
void FrontEndItemTests::propagate ()
{
    FrontEndItem secondIntItem("/Test/Int");
    secondIntItem.set(3000);
    QVERIFY_TIMEOUT(2000, intItem->value() == secondIntItem.value());
    QCOMPARE(signalSpy->numberOfCalls, 2);
}
void FrontEndItemTests::set_external()
{
    // This must be the last test case.  The values that are set here
    // are checked after this program exits.
    boolItem->set(false);
    intItem->set(54321);
    stringItem->set("Good bye FrontEnd");
    doubleItem->set(-2.5);
    stringListItem->set(QStringList() << "Good" << "bye" << "FrontEnd" << QString::fromUtf8("äöü"));
    intListItem->set(QList<QVariant>() << 5 << 4 << 3 << 2 << 1);
    doubleListItem->set(QList<QVariant>() << -2.5 << -2.5);
    boolListItem->set(QList<QVariant>() << false << false << true << true);
    unsetAfterItem->set(QVariant());
}
QTEST_MAIN(FrontEndItemTests);
#endif // test_FrontEnd

