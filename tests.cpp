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
CxxTest::StaticSuiteDescription suiteDescription_matrix_cxxTest( "cal_cxxTest.cpp", 12, "matrix_cxxTest", suite_matrix_cxxTest, Tests_matrix_cxxTest );

static class TestDescription_matrix_cxxTest_test_Julian_MJD : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Julian_MJD() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 36, "test_Julian_MJD" ) {}
 void runTest() { suite_matrix_cxxTest.test_Julian_MJD(); }
} testDescription_matrix_cxxTest_test_Julian_MJD;

static class TestDescription_matrix_cxxTest_test_Greorian_MJD : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Greorian_MJD() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 45, "test_Greorian_MJD" ) {}
 void runTest() { suite_matrix_cxxTest.test_Greorian_MJD(); }
} testDescription_matrix_cxxTest_test_Greorian_MJD;

static class TestDescription_matrix_cxxTest_test_jul_Construct : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_jul_Construct() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 54, "test_jul_Construct" ) {}
 void runTest() { suite_matrix_cxxTest.test_jul_Construct(); }
} testDescription_matrix_cxxTest_test_jul_Construct;

static class TestDescription_matrix_cxxTest_test_greg_Construct : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_greg_Construct() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 78, "test_greg_Construct" ) {}
 void runTest() { suite_matrix_cxxTest.test_greg_Construct(); }
} testDescription_matrix_cxxTest_test_greg_Construct;

static class TestDescription_matrix_cxxTest_test_leapYtest : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_leapYtest() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 110, "test_leapYtest" ) {}
 void runTest() { suite_matrix_cxxTest.test_leapYtest(); }
} testDescription_matrix_cxxTest_test_leapYtest;

static class TestDescription_matrix_cxxTest_test_DMconstants : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_DMconstants() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 193, "test_DMconstants" ) {}
 void runTest() { suite_matrix_cxxTest.test_DMconstants(); }
} testDescription_matrix_cxxTest_test_DMconstants;

static class TestDescription_matrix_cxxTest_test_JulianOverFlow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_JulianOverFlow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 212, "test_JulianOverFlow" ) {}
 void runTest() { suite_matrix_cxxTest.test_JulianOverFlow(); }
} testDescription_matrix_cxxTest_test_JulianOverFlow;

static class TestDescription_matrix_cxxTest_test_JulMonOverflow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_JulMonOverflow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 255, "test_JulMonOverflow" ) {}
 void runTest() { suite_matrix_cxxTest.test_JulMonOverflow(); }
} testDescription_matrix_cxxTest_test_JulMonOverflow;

static class TestDescription_matrix_cxxTest_test_GregOverFlow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_GregOverFlow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 267, "test_GregOverFlow" ) {}
 void runTest() { suite_matrix_cxxTest.test_GregOverFlow(); }
} testDescription_matrix_cxxTest_test_GregOverFlow;

static class TestDescription_matrix_cxxTest_test_GregMonOverflow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_GregMonOverflow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 311, "test_GregMonOverflow" ) {}
 void runTest() { suite_matrix_cxxTest.test_GregMonOverflow(); }
} testDescription_matrix_cxxTest_test_GregMonOverflow;

static class TestDescription_matrix_cxxTest_test_julGregconvertion : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_julGregconvertion() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 336, "test_julGregconvertion" ) {}
 void runTest() { suite_matrix_cxxTest.test_julGregconvertion(); }
} testDescription_matrix_cxxTest_test_julGregconvertion;

static class TestDescription_matrix_cxxTest_test_Comparison : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Comparison() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 383, "test_Comparison" ) {}
 void runTest() { suite_matrix_cxxTest.test_Comparison(); }
} testDescription_matrix_cxxTest_test_Comparison;

static class TestDescription_matrix_cxxTest_test_calendar : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_calendar() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 406, "test_calendar" ) {}
 void runTest() { suite_matrix_cxxTest.test_calendar(); }
} testDescription_matrix_cxxTest_test_calendar;

#include <cxxtest/Root.cpp>
