#include <cxxtest/TestSuite.h>
#include "kattistime.h"
#include "julian.hpp"
#include "gregorian.hpp"
#include "calendar.hpp"
#include <assert.h>             // assert(b) ger felmeddelande om b falsk
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "mod_Stripper.hpp"
//
using namespace lab2;
class matrix_cxxTest : public CxxTest::TestSuite {
    int a;
    unsigned _year;
    unsigned _month;
    unsigned _day;

    void setUp() {
        time_t mytime;
        time(&mytime);
        set_k_time(mytime);
        a = 2;

        time_t tp;
        time(&tp);
        struct tm *t = gmtime(&tp);
        _year  = (unsigned int) (t->tm_year + 1900);
        _month = (unsigned int) (t->tm_mon + 1);
        _day   = (unsigned int) t->tm_mday;


    }


public:
    void test_Julian_MJD() {
        Julian test1(1858,11,5);
        TS_ASSERT_EQUALS(0, test1.mod_julian_day());
        Julian test2(1858,11,4);
        TS_ASSERT_EQUALS(-1, test2.mod_julian_day());
        test1 = Julian(2400,1,1);
        TS_ASSERT_EQUALS(197657,test1.mod_julian_day());
    }

    void test_Greorian_MJD(){
        Gregorian test1(1858,5,1);
        TS_ASSERT_EQUALS(-200,test1.mod_julian_day());
        test1 = Gregorian(1858,11,17);
        TS_ASSERT_EQUALS(0, test1.mod_julian_day());
        test1 = Gregorian(2400,12,31);
        TS_ASSERT_EQUALS(198006, test1.mod_julian_day());
    }

    void test_jul_Construct(){
        Julian test0(2015,10,22);
        Julian test1(2014,2,5);
        Julian test2(test1);
        Date* julPoint;
        Date & julDateRef = test0;

        julPoint = &test1;



        TS_ASSERT_EQUALS(test0.year(),2015);
        TS_ASSERT_EQUALS(test0.month(),10);
        TS_ASSERT_EQUALS(test0.day(),22);
        TS_ASSERT_EQUALS(test2.year(),2014);
        TS_ASSERT_EQUALS(test2.month(),2);
        TS_ASSERT_EQUALS(test2.day(),5);
        TS_ASSERT_EQUALS(julPoint->year(),2014);
        TS_ASSERT_EQUALS(julPoint->month(),2);
        TS_ASSERT_EQUALS(julPoint->day(),5);
        TS_ASSERT_EQUALS(julDateRef.year(),2015);
        TS_ASSERT_EQUALS(julDateRef.month(),10);
        TS_ASSERT_EQUALS(julDateRef.day(),22);
    }
    void test_greg_Construct(){
        Gregorian test0;
        Gregorian test1(2312,1,31);
        Gregorian test2(test1);
        Date& gregDPoin = test2;
        Date* gregDatRef;
        gregDatRef = &test0;

        TS_ASSERT_EQUALS(test0.day(),_day);
        TS_ASSERT_EQUALS(test0.month(),_month);
        TS_ASSERT_EQUALS(test0.year(),_year);
        TS_ASSERT_EQUALS(test1.year(),2312);
        TS_ASSERT_EQUALS(test1.month(),1);
        TS_ASSERT_EQUALS(test1.day(),31);

        TS_ASSERT_EQUALS(test1.year(),2312);
        TS_ASSERT_EQUALS(test1.month(),1);
        TS_ASSERT_EQUALS(test1.day(),31);

        TS_ASSERT_EQUALS(test2.year(),2312);
        TS_ASSERT_EQUALS(test2.month(),1);
        TS_ASSERT_EQUALS(test2.day(),31);

        TS_ASSERT_EQUALS(gregDPoin.year(),2312);
        TS_ASSERT_EQUALS(gregDPoin.month(),1);
        TS_ASSERT_EQUALS(gregDPoin.day(),31);

        TS_ASSERT_EQUALS(gregDatRef->year(),_year);
        TS_ASSERT_EQUALS(gregDatRef->month(),_month);
        TS_ASSERT_EQUALS(gregDatRef->day(),_day);
    }

    void test_leapYtest(){
        Julian jDate(1899,02,28);
        Gregorian gDate(1899,02,28);

        TS_ASSERT_EQUALS(jDate.days_this_month(),28);
        TS_ASSERT_EQUALS(gDate.days_this_month(),28);
        jDate++;
        gDate++;
        //NO LEAP YEAR
        TS_ASSERT_EQUALS(gDate.day(),1);
        TS_ASSERT_EQUALS(gDate.month(),3);
        TS_ASSERT_EQUALS(jDate.day(),1);
        TS_ASSERT_EQUALS(jDate.month(),3);
        TS_ASSERT_EQUALS(jDate.days_this_month(),31);
        TS_ASSERT_EQUALS(gDate.days_this_month(),31);
        jDate.add_year(1);
        gDate.add_year(1);
        TS_ASSERT_EQUALS(jDate.days_this_month(),31);
        TS_ASSERT_EQUALS(gDate.days_this_month(),31);
        //LEAP YEAR FOR JULIAN; NOT FOR GREG
        TS_ASSERT_EQUALS(gDate.day(),1);
        TS_ASSERT_EQUALS(gDate.month(),3);
        TS_ASSERT_EQUALS(gDate.year(),1900)
        gDate--;
        TS_ASSERT_EQUALS(gDate.day(),28);
        TS_ASSERT_EQUALS(gDate.month(),2);
        TS_ASSERT_EQUALS(gDate.year(),1900)

        TS_ASSERT_EQUALS(jDate.day(),1);
        TS_ASSERT_EQUALS(jDate.month(),3);
        TS_ASSERT_EQUALS(jDate.year(),1900)
        jDate--;
        TS_ASSERT_EQUALS(jDate.day(),29);
        TS_ASSERT_EQUALS(jDate.month(),2);
        TS_ASSERT_EQUALS(jDate.year(),1900)


        TS_ASSERT_EQUALS(jDate.days_this_month(),29);
        TS_ASSERT_EQUALS(gDate.days_this_month(),28);

        //LEAP YEAR FOR GREG AND JUL
        gDate.add_year(100);
        gDate++;
        jDate.add_year(100);
        TS_ASSERT_EQUALS(gDate.day(),29);
        TS_ASSERT_EQUALS(gDate.month(),2);
        TS_ASSERT_EQUALS(gDate.year(),2000)
        TS_ASSERT_EQUALS(jDate.day(),29);
        TS_ASSERT_EQUALS(jDate.month(),2);
        TS_ASSERT_EQUALS(jDate.year(),2000)
        TS_ASSERT_EQUALS(jDate.days_this_month(),29);
        TS_ASSERT_EQUALS(gDate.days_this_month(),29);

        gDate.add_month(1);
        jDate.add_month(1);
        TS_ASSERT_EQUALS(jDate.days_this_month(),31);
        TS_ASSERT_EQUALS(gDate.days_this_month(),31);
        gDate.add_month(1);
        jDate.add_month(1);
        TS_ASSERT_EQUALS(jDate.days_this_month(),30);
        TS_ASSERT_EQUALS(gDate.days_this_month(),30);
        gDate.add_month(1);
        jDate.add_month(1);
        TS_ASSERT_EQUALS(jDate.days_this_month(),31);
        TS_ASSERT_EQUALS(gDate.days_this_month(),31);
        gDate.add_month(1);
        jDate.add_month(1);
        TS_ASSERT_EQUALS(jDate.days_this_month(),30);
        TS_ASSERT_EQUALS(gDate.days_this_month(),30);
        gDate.add_month(1);
        jDate.add_month(1);
        TS_ASSERT_EQUALS(jDate.days_this_month(),31);//July
        TS_ASSERT_EQUALS(gDate.days_this_month(),31);
        gDate.add_month(1);
        jDate.add_month(1);
        TS_ASSERT_EQUALS(jDate.days_this_month(),31);//aug
        TS_ASSERT_EQUALS(gDate.days_this_month(),31);
        gDate.add_month(1);
        jDate.add_month(1);
        TS_ASSERT_EQUALS(jDate.days_this_month(),30);//sept
        TS_ASSERT_EQUALS(gDate.days_this_month(),30);
    }

    void test_DMconstants(){
        Julian jDate;
        Gregorian gDate;

        for(int i = 0;i<100;i++){
            jDate.add_year(1);
            gDate.add_year(1);
            TS_ASSERT_EQUALS(jDate.month_this_year(),12);
            TS_ASSERT_EQUALS(gDate.month_this_year(),12);
        }
        for(int i = 0;i<100;i++){
            jDate += 5;
            gDate += 5;
            TS_ASSERT_EQUALS(jDate.days_per_week(),7);
            TS_ASSERT_EQUALS(gDate.days_per_week(),7);
        }
    }


    void test_JulianOverFlow() {
        Julian jDate(1950, 10, 20);
        jDate += 100;
        TS_ASSERT_EQUALS(jDate.year(), 1951);
        TS_ASSERT_EQUALS(jDate.month(), 1);
        TS_ASSERT_EQUALS(jDate.day(), 28)
        TS_ASSERT_EQUALS(jDate.mod_julian_day(), 33687);
        jDate += 1000;
        TS_ASSERT_EQUALS(jDate.year(), 1953);
        TS_ASSERT_EQUALS(jDate.month(), 10);
        TS_ASSERT_EQUALS(jDate.day(), 24)
        TS_ASSERT_EQUALS(jDate.mod_julian_day(), 34687);
        jDate += 12456;
        TS_ASSERT_EQUALS(jDate.year(), 1987);
        TS_ASSERT_EQUALS(jDate.month(), 12);
        TS_ASSERT_EQUALS(jDate.day(), 1)
        TS_ASSERT_EQUALS(jDate.mod_julian_day(), 47143);
        for (int i = 0; i < 10000; i++) {
            ++jDate;
        }
        for (int i = 0; i < 5000; i++) {
            jDate++;
        }
        for (int i = 0; i < 5000; i++) {
            jDate+=1;
        }
        TS_ASSERT_EQUALS(jDate.year(), 2042);
        TS_ASSERT_EQUALS(jDate.month(), 9);
        TS_ASSERT_EQUALS(jDate.day(), 3);
        for (int i = 0; i < 3000; i++) {
            --jDate;
        }
        for (int i = 0; i < 2000; i++) {
            jDate--;
        }
        for (int i = 0; i < 1000; i++) {
            jDate-=1;
        }
        TS_ASSERT_EQUALS(jDate.year(), 2026);
        TS_ASSERT_EQUALS(jDate.month(), 3);
        TS_ASSERT_EQUALS(jDate.day(), 31);
        TS_ASSERT_EQUALS(jDate.mod_julian_day(), 61143);
    }
    void test_JulMonOverflow(){
        Julian jDate = Julian(1999,01,31);
        jDate.add_month(1);
        TS_ASSERT_EQUALS(jDate.day(),28);
        jDate.add_month(-1);
        TS_ASSERT_EQUALS(jDate.day(),28);
        jDate+=3;
        jDate.add_month(13);
        TS_ASSERT_EQUALS(jDate.year(),2000);
        TS_ASSERT_EQUALS(jDate.day(),29);
    }

    void test_GregOverFlow(){
        Gregorian gDate(1850,10,20);
        TS_ASSERT_EQUALS(gDate.year(),1850);
        TS_ASSERT_EQUALS(gDate.month(),10);
        TS_ASSERT_EQUALS(gDate.day(),20)
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),-2950);
        gDate += 20000;
        TS_ASSERT_EQUALS(gDate.year(),1905);
        TS_ASSERT_EQUALS(gDate.month(),7);
        TS_ASSERT_EQUALS(gDate.day(),24)
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),17050);
        for(int i = 0; i<10000;i++){
            ++gDate;
        }
        for(int i = 0; i<5000;i++){
            gDate++;
        }
        for(int i = 0; i<5000;i++){
            gDate +=1;
        }
        TS_ASSERT_EQUALS(gDate.year(),1960);
        TS_ASSERT_EQUALS(gDate.month(),4);
        TS_ASSERT_EQUALS(gDate.day(),26)
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),37050);
        gDate += 50000;
        TS_ASSERT_EQUALS(gDate.year(),2097);
        TS_ASSERT_EQUALS(gDate.month(),3);
        TS_ASSERT_EQUALS(gDate.day(),18)
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),87050);
        for(int i = 0; i<10000;i++){
            --gDate;
        }
        for(int i = 0; i<5000;i++){
            gDate--;
        }
        for(int i = 0; i<5000;i++){
            gDate-=1;
        }
        TS_ASSERT_EQUALS(gDate.year(),2042);
        TS_ASSERT_EQUALS(gDate.month(),6);
        TS_ASSERT_EQUALS(gDate.day(),15)
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),67050);
    }

    void test_GregMonOverflow(){
        Gregorian gDate = Gregorian(1999,01,31);
        gDate.add_month(1);
        TS_ASSERT_EQUALS(gDate.day(),28);
        gDate.add_month(-1);
        TS_ASSERT_EQUALS(gDate.day(),28);
        gDate+=3;
        gDate.add_month(13);
        TS_ASSERT_EQUALS(gDate.year(),2000);
        TS_ASSERT_EQUALS(gDate.day(),29);


        gDate = Gregorian(2099,01,31);
        gDate.add_month(1);
        TS_ASSERT_EQUALS(gDate.day(),28);
        gDate.add_month(-1);
        TS_ASSERT_EQUALS(gDate.day(),28);
        gDate+=3;
        gDate.add_month(13);
        TS_ASSERT_EQUALS(gDate.year(),2100);
        TS_ASSERT_EQUALS(gDate.day(),28);

    }


    void test_julGregconvertion(){
        Julian jDate(1900,02,29);
        Gregorian gDate(jDate);
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),jDate.mod_julian_day());
        jDate+=10000;
        gDate+=10000;
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),jDate.mod_julian_day());
        gDate = Gregorian(1900,03,01);
        jDate = gDate;
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),jDate.mod_julian_day());
        jDate+=10000;
        gDate+=10000;
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),jDate.mod_julian_day());

        gDate = Gregorian(2010,10,10);
        Date *dGregPointer = &gDate;
        Date & dGregRef = gDate;
        Julian j2Date(dGregPointer);
        Julian j3Date(dGregRef);
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),j2Date.mod_julian_day());
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),j3Date.mod_julian_day());
        dGregRef+=500;
        (*dGregPointer)+=500;
        j2Date+=1000;
        j3Date+=1000;
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),j2Date.mod_julian_day());
        TS_ASSERT_EQUALS(gDate.mod_julian_day(),j3Date.mod_julian_day());


        jDate = Julian(1840,4,30);
        Date *dJulPointer = &jDate;
        Date & dJulRef = jDate;
        Gregorian g2Date(dJulPointer);
        Gregorian g3Date(dJulRef);
        TS_ASSERT_EQUALS(jDate.mod_julian_day(),g2Date.mod_julian_day());
        TS_ASSERT_EQUALS(jDate.mod_julian_day(),g3Date.mod_julian_day());

        dJulRef+=500;
        (*dJulPointer)+=500;
        g2Date+=1000;
        g3Date+=1000;
        TS_ASSERT_EQUALS(jDate.mod_julian_day(),g2Date.mod_julian_day());
        TS_ASSERT_EQUALS(jDate.mod_julian_day(),g3Date.mod_julian_day());

    }


    void test_Comparison(){
        Julian jDate;
        Gregorian gDate;
        TS_ASSERT_EQUALS(jDate , gDate);
        TS_ASSERT(jDate>=gDate);
        TS_ASSERT(gDate>=jDate);
        TS_ASSERT_LESS_THAN_EQUALS(jDate,gDate);
        TS_ASSERT_LESS_THAN_EQUALS(gDate,jDate);
        gDate++;
        TS_ASSERT_LESS_THAN(jDate,gDate);
        TS_ASSERT_LESS_THAN_EQUALS(jDate,gDate);
        TS_ASSERT(gDate > jDate);
        TS_ASSERT(gDate >= jDate);

        jDate+=2;
        TS_ASSERT_LESS_THAN(gDate,jDate);
        TS_ASSERT_LESS_THAN_EQUALS(gDate,jDate);
        TS_ASSERT(jDate>gDate);
        TS_ASSERT(jDate>=gDate);

    }


    void test_calendar(){
        Calendar<Gregorian> cal;
        std::cout << "FÖRSTA PRINT\n\n";
        cal.set_date(2000,12,2);
        cal.add_event("Vardagjämning", 20, 3); // år = 2000
        cal.add_event("Första advent", 1,12,2000); // år = 2000, månad = 12

        cal.add_event("Basketträning", 4, 12, 2000);
        cal.add_event("Basketträning", 11, 12, 2000);
        cal.add_event("Nyårsfrukost", 1, 1, 2001);
        cal.add_event("Julafton", 24, 12);
        cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
        cal.add_event("Julafton", 24);
        cal.add_event("Min första cykel", 20, 12, 2000);
        mod_Stripper<Gregorian> stripperTest;
        stripperTest << cal;
        stringstream ss;
        ss << stripperTest;
        std::string test_string = ss.str();

        //kollar att adderat rätt
        TS_ASSERT_DIFFERS(test_string.find("0012041300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012041700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Basketträning"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012111300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012111700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Basketträning"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012201300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012201700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Min första cykel"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012241300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012241700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Julafton"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0101011300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0101011700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Nyårsfrukost"),std::string::npos);
        //visar inte upp fel
        TS_ASSERT_EQUALS(test_string.find("Vardagjämning"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("Kalle Anka hälsar god jul"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("Första advent"),std::string::npos);

        cal.remove_event("Julafton",24);


        mod_Stripper<Gregorian> stripper2Test;
        stripper2Test << cal;
        stringstream ss2;
        ss2 << stripper2Test;
        std::string test_string2 = ss2.str();
        TS_ASSERT_EQUALS(test_string2.find("Julafton"),std::string::npos);
        TS_ASSERT_EQUALS(test_string2.find("Vardagjämning"),std::string::npos);
        TS_ASSERT_EQUALS(test_string2.find("Kalle Anka hälsar god jul"),std::string::npos);
        TS_ASSERT_EQUALS(test_string2.find("Första advent"),std::string::npos);

        TS_ASSERT_DIFFERS(test_string2.find("0012041300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("0012041700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("Basketträning"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("0012111300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("0012111700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("Basketträning"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("0012201300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("0012201700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("Min första cykel"),std::string::npos);
        TS_ASSERT_EQUALS(test_string2.find("0012241300"),std::string::npos);
        TS_ASSERT_EQUALS(test_string2.find("0012241700"),std::string::npos);
        TS_ASSERT_EQUALS(test_string2.find("Julafton"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("0101011300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("0101011700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string2.find("Nyårsfrukost"),std::string::npos);

    }

    void test_copy_normal(){
        Calendar<Gregorian> cal;
        cal.set_date(2000,12,2);
        cal.add_event("Vardagjämning", 20, 3); // år = 2000
        cal.add_event("Första advent", 1,12,2000); // år = 2000, månad = 12

        cal.add_event("Basketträning", 4, 12, 2000);
        cal.add_event("Basketträning", 11, 12, 2000);
        cal.add_event("Nyårsfrukost", 1, 1, 2001);
        cal.add_event("Julafton", 24, 12);
        cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
        cal.add_event("Julafton", 24);
        cal.add_event("Min första cykel", 20, 12, 2000);

        Calendar<Gregorian> cal2 = cal;
        mod_Stripper<Gregorian> stripperTest;
        stripperTest << cal2;
        stringstream ss;
        ss << stripperTest;
        std::string test_string = ss.str();

        TS_ASSERT_DIFFERS(test_string.find("0012041300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012041700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Basketträning"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012111300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012111700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Basketträning"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012201300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012201700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Min första cykel"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012241300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012241700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Julafton"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0101011300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0101011700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Nyårsfrukost"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("Vardagjämning"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("Kalle Anka hälsar god jul"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("Första advent"),std::string::npos);

    }

    void test_copy_convert(){
        Calendar<Gregorian> cal;
        cal.set_date(2000,12,2);
        cal.add_event("Vardagjämning", 20, 3); // år = 2000
        cal.add_event("Första advent", 1,12,2000); // år = 2000, månad = 12

        cal.add_event("Basketträning", 4, 12, 2000);
        cal.add_event("Basketträning", 11, 12, 2000);
        cal.add_event("Nyårsfrukost", 1, 1, 2001);
        cal.add_event("Julafton", 24, 12);
        cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
        cal.add_event("Julafton", 24);
        cal.add_event("Min första cykel", 20, 12, 2000);

        Calendar<Julian> cal2 = cal;
        mod_Stripper<Julian> stripperTest;
        stripperTest << cal2;
        stringstream ss;
        ss << stripperTest;
        std::string test_string = ss.str();

        TS_ASSERT_DIFFERS(test_string.find("0011211300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0011211700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Basketträning"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0011281300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0011281700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Basketträning"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012071300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012071700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Min första cykel"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012111300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012111700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Julafton"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012191300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("0012191700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("Nyårsfrukost"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("Vardagjämning"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("Kalle Anka hälsar god jul"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("Första advent"),std::string::npos);
    }

    void test_remove_event(){
        Calendar<Gregorian> cal;
        cal.set_date(2024,5,12);
        cal.add_event("aa");
        cal.add_event("aa",12,5,2024,20,00,1);
        cal.add_event("ab",13);
        cal.add_event("ac",20,6);
        cal.add_event("aa",3,8,2030,23,59,60*25);

        mod_Stripper<Gregorian> stripperTest;
        stripperTest << cal;
        stringstream ss;
        ss << stripperTest;
        std::string test_string = ss.str();

        TS_ASSERT_DIFFERS(test_string.find("2405121300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405121700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("aa"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405122000"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405122001"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("aa"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405131300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405131700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("ab"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2406201300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2406201700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("ac"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("3008032359"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("3008050059"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("aa"),std::string::npos);

        cal.remove_event("aa");
        mod_Stripper<Gregorian> stripperTest2;
        stripperTest2 << cal;
        stringstream ss2;
        ss2 << stripperTest2;
        test_string = ss2.str();

        TS_ASSERT_EQUALS(test_string.find("2405121300"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("2405121700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405122000"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405122001"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("aa"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405131300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2405131700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("ab"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2406201300"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("2406201700"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("ac"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("3008032359"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("3008050059"),std::string::npos);
        TS_ASSERT_DIFFERS(test_string.find("aa"),std::string::npos);

    }


    void test_add_conflict_time(){
        Calendar<Gregorian> cal;
        cal.set_date(2024,5,12);
        cal.add_event("aa");
        cal.add_event("aa",12,5,2024,20,00,10);
        cal.add_event("missing",12,5,2024,20,05,1);
        cal.add_event("ab",13);
        cal.add_event("ac",20,6);
        cal.add_event("aa",3,8,2030,23,59,60*25);
        cal.add_event("miss2ing",4,8,30,1,1,1);
        cal.add_event("miss3ing",2020,1,1,1,1,60*24*365*10);
        mod_Stripper<Gregorian> stripperTest;
        stripperTest << cal;
        stringstream ss;
        ss << stripperTest;
        std::string test_string = ss.str();

        TS_ASSERT_EQUALS(test_string.find("missing"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("miss2ing"),std::string::npos);
        TS_ASSERT_EQUALS(test_string.find("miss3ing"),std::string::npos);

    }
    
};
