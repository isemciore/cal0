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
        cal.add_event("Basketträning", 4, 12, 2000);
        cal.add_event("Basketträning", 11, 12, 2000);
        cal.add_event("Nyårsfrukost", 1, 1, 2001);
        cal.add_event("Första advent", 1,12,2000); // år = 2000, månad = 12
        cal.add_event("Vardagjämning", 20, 3); // år = 2000
        cal.add_event("Julafton", 24, 12);
        cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
        cal.add_event("Julafton", 24); // En likadan händelse samma datum ska
// ignoreras och inte sättas in i kalendern
        cal.add_event("Min första cykel", 20, 12, 2000);
        cal.remove_event("Basketträning", 4);
        std::cout << cal;

        std::cout << "\nNEWLINES\n\n\n";


        // OBS! Vårdagjämning och första advent är
        // före nuvarande datum och skrivs inte ut
        std::cout << "----------------------------------------" << std::endl;
        cal.remove_event("Vårdagjämning", 20, 3, 2000);
        cal.remove_event("Kalle Anka hälsar god jul", 24, 12, 2000);
        cal.set_date(2000, 11, 2);
        if (! cal.remove_event("Julafton", 24)) {
            std::cout << " cal.remove_event(\"Julafton\", 24) tar inte"<< std::endl
            << " bort något eftersom aktuell månad är november" << std::endl;
        }
        std::cout << "----------------------------------------" << std::endl;
        std::cout << cal;



        Calendar<Julian> julCal(cal);



    }
    
};
