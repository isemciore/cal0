/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "cal_cxxTest.cpp"

static matrix_cxxTest suite_matrix_cxxTest;

static CxxTest::List Tests_matrix_cxxTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_matrix_cxxTest( "cal_cxxTest.cpp", 15, "matrix_cxxTest", suite_matrix_cxxTest, Tests_matrix_cxxTest );

static class TestDescription_matrix_cxxTest_test_Julian_MJD : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Julian_MJD() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 39, "test_Julian_MJD" ) {}
 void runTest() { suite_matrix_cxxTest.test_Julian_MJD(); }
} testDescription_matrix_cxxTest_test_Julian_MJD;

static class TestDescription_matrix_cxxTest_test_Greorian_MJD : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Greorian_MJD() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 48, "test_Greorian_MJD" ) {}
 void runTest() { suite_matrix_cxxTest.test_Greorian_MJD(); }
} testDescription_matrix_cxxTest_test_Greorian_MJD;

static class TestDescription_matrix_cxxTest_test_jul_Construct : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_jul_Construct() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 57, "test_jul_Construct" ) {}
 void runTest() { suite_matrix_cxxTest.test_jul_Construct(); }
} testDescription_matrix_cxxTest_test_jul_Construct;

static class TestDescription_matrix_cxxTest_test_greg_Construct : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_greg_Construct() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 81, "test_greg_Construct" ) {}
 void runTest() { suite_matrix_cxxTest.test_greg_Construct(); }
} testDescription_matrix_cxxTest_test_greg_Construct;

static class TestDescription_matrix_cxxTest_test_leapYtest : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_leapYtest() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 113, "test_leapYtest" ) {}
 void runTest() { suite_matrix_cxxTest.test_leapYtest(); }
} testDescription_matrix_cxxTest_test_leapYtest;

static class TestDescription_matrix_cxxTest_test_DMconstants : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_DMconstants() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 196, "test_DMconstants" ) {}
 void runTest() { suite_matrix_cxxTest.test_DMconstants(); }
} testDescription_matrix_cxxTest_test_DMconstants;

static class TestDescription_matrix_cxxTest_test_JulianOverFlow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_JulianOverFlow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 215, "test_JulianOverFlow" ) {}
 void runTest() { suite_matrix_cxxTest.test_JulianOverFlow(); }
} testDescription_matrix_cxxTest_test_JulianOverFlow;

static class TestDescription_matrix_cxxTest_test_JulMonOverflow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_JulMonOverflow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 258, "test_JulMonOverflow" ) {}
 void runTest() { suite_matrix_cxxTest.test_JulMonOverflow(); }
} testDescription_matrix_cxxTest_test_JulMonOverflow;

static class TestDescription_matrix_cxxTest_test_GregOverFlow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_GregOverFlow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 270, "test_GregOverFlow" ) {}
 void runTest() { suite_matrix_cxxTest.test_GregOverFlow(); }
} testDescription_matrix_cxxTest_test_GregOverFlow;

static class TestDescription_matrix_cxxTest_test_GregMonOverflow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_GregMonOverflow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 314, "test_GregMonOverflow" ) {}
 void runTest() { suite_matrix_cxxTest.test_GregMonOverflow(); }
} testDescription_matrix_cxxTest_test_GregMonOverflow;

static class TestDescription_matrix_cxxTest_test_julGregconvertion : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_julGregconvertion() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 339, "test_julGregconvertion" ) {}
 void runTest() { suite_matrix_cxxTest.test_julGregconvertion(); }
} testDescription_matrix_cxxTest_test_julGregconvertion;

static class TestDescription_matrix_cxxTest_test_Comparison : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Comparison() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 386, "test_Comparison" ) {}
 void runTest() { suite_matrix_cxxTest.test_Comparison(); }
} testDescription_matrix_cxxTest_test_Comparison;

static class TestDescription_matrix_cxxTest_test_calendar : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_calendar() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 409, "test_calendar" ) {}
 void runTest() { suite_matrix_cxxTest.test_calendar(); }
} testDescription_matrix_cxxTest_test_calendar;

static class TestDescription_matrix_cxxTest_test_copy_normal : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_copy_normal() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 481, "test_copy_normal" ) {}
 void runTest() { suite_matrix_cxxTest.test_copy_normal(); }
} testDescription_matrix_cxxTest_test_copy_normal;

static class TestDescription_matrix_cxxTest_test_copy_convert : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_copy_convert() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 523, "test_copy_convert" ) {}
 void runTest() { suite_matrix_cxxTest.test_copy_convert(); }
} testDescription_matrix_cxxTest_test_copy_convert;

static class TestDescription_matrix_cxxTest_test_remove_event : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_remove_event() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 564, "test_remove_event" ) {}
 void runTest() { suite_matrix_cxxTest.test_remove_event(); }
} testDescription_matrix_cxxTest_test_remove_event;

static class TestDescription_matrix_cxxTest_test_add_conflict_time : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_add_conflict_time() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 620, "test_add_conflict_time" ) {}
 void runTest() { suite_matrix_cxxTest.test_add_conflict_time(); }
} testDescription_matrix_cxxTest_test_add_conflict_time;

#include <cxxtest/Root.cpp>
