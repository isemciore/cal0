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
CxxTest::StaticSuiteDescription suiteDescription_matrix_cxxTest( "cal_cxxTest.cpp", 10, "matrix_cxxTest", suite_matrix_cxxTest, Tests_matrix_cxxTest );

static class TestDescription_matrix_cxxTest_test_Julian_MJD : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Julian_MJD() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 33, "test_Julian_MJD" ) {}
 void runTest() { suite_matrix_cxxTest.test_Julian_MJD(); }
} testDescription_matrix_cxxTest_test_Julian_MJD;

static class TestDescription_matrix_cxxTest_test_Greorian_MJD : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Greorian_MJD() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 42, "test_Greorian_MJD" ) {}
 void runTest() { suite_matrix_cxxTest.test_Greorian_MJD(); }
} testDescription_matrix_cxxTest_test_Greorian_MJD;

static class TestDescription_matrix_cxxTest_test_jul_Construct : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_jul_Construct() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 51, "test_jul_Construct" ) {}
 void runTest() { suite_matrix_cxxTest.test_jul_Construct(); }
} testDescription_matrix_cxxTest_test_jul_Construct;

static class TestDescription_matrix_cxxTest_test_greg_Construct : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_greg_Construct() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 75, "test_greg_Construct" ) {}
 void runTest() { suite_matrix_cxxTest.test_greg_Construct(); }
} testDescription_matrix_cxxTest_test_greg_Construct;

static class TestDescription_matrix_cxxTest_test_leapYtest : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_leapYtest() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 107, "test_leapYtest" ) {}
 void runTest() { suite_matrix_cxxTest.test_leapYtest(); }
} testDescription_matrix_cxxTest_test_leapYtest;

static class TestDescription_matrix_cxxTest_test_DMconstants : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_DMconstants() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 190, "test_DMconstants" ) {}
 void runTest() { suite_matrix_cxxTest.test_DMconstants(); }
} testDescription_matrix_cxxTest_test_DMconstants;

static class TestDescription_matrix_cxxTest_test_JulianOverFlow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_JulianOverFlow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 209, "test_JulianOverFlow" ) {}
 void runTest() { suite_matrix_cxxTest.test_JulianOverFlow(); }
} testDescription_matrix_cxxTest_test_JulianOverFlow;

static class TestDescription_matrix_cxxTest_test_JulMonOverflow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_JulMonOverflow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 252, "test_JulMonOverflow" ) {}
 void runTest() { suite_matrix_cxxTest.test_JulMonOverflow(); }
} testDescription_matrix_cxxTest_test_JulMonOverflow;

static class TestDescription_matrix_cxxTest_test_GregOverFlow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_GregOverFlow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 264, "test_GregOverFlow" ) {}
 void runTest() { suite_matrix_cxxTest.test_GregOverFlow(); }
} testDescription_matrix_cxxTest_test_GregOverFlow;

static class TestDescription_matrix_cxxTest_test_GregMonOverflow : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_GregMonOverflow() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 308, "test_GregMonOverflow" ) {}
 void runTest() { suite_matrix_cxxTest.test_GregMonOverflow(); }
} testDescription_matrix_cxxTest_test_GregMonOverflow;

static class TestDescription_matrix_cxxTest_test_julGregconvertion : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_julGregconvertion() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 333, "test_julGregconvertion" ) {}
 void runTest() { suite_matrix_cxxTest.test_julGregconvertion(); }
} testDescription_matrix_cxxTest_test_julGregconvertion;

static class TestDescription_matrix_cxxTest_test_Comparison : public CxxTest::RealTestDescription {
public:
 TestDescription_matrix_cxxTest_test_Comparison() : CxxTest::RealTestDescription( Tests_matrix_cxxTest, suiteDescription_matrix_cxxTest, 380, "test_Comparison" ) {}
 void runTest() { suite_matrix_cxxTest.test_Comparison(); }
} testDescription_matrix_cxxTest_test_Comparison;

#include <cxxtest/Root.cpp>
