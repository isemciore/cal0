// projektlokala headerfiler
#include "kattistime.h"
#include "julian.hpp"
#include "gregorian.hpp"
#include "calendar.hpp"
// STL headerfiler
#include <iostream>
#include <assert.h>             // assert(b) ger felmeddelande om b falsk
#include <ctime>


// Obs att testerna f�ruts�tter att dina klasser returnerar
// m�nader och dagar indexerade fr�n ETT. Testerna �r inte
// fullst�ndiga


int main()
{
    using namespace lab2;        // Exponera funktionalitet i namnrymden lab2

    ////////////////////////////////////////////////////////////
    // Sätt tiden. OBS skicka inte nedanstående kod till kattis
    time_t mytime;
    time(&mytime);
    set_k_time(mytime);
    ////////////////////////////////////////////////////////////


    Julian tj;                  // ok: defaultkonstruktor ger dagens datum
    Gregorian gtoday;           // ok för gregorian också
    std::cout << "Idag är det " << gtoday << std::endl;
    assert(tj - gtoday == 0);
    Gregorian tg(2006, 10, 31); // ok: sätt datum explicit
    // följande fungerar också:
    // Gregorian(2000, Gregorian::October, 31)
    Date &j = tj;               // åtkomst av funktioner genom Dates interface
    Date &g = tg;
    Date &today = gtoday;

    {
        Julian j1;
        Date & d1 = j1;
        Julian j2(d1);
        Date * dp = &j2;
        Julian j3(dp);
    }

    time_t tp;
    time(&tp);
    struct tm *t = gmtime(&tp);
    int year  = t->tm_year + 1900;
    int month = t->tm_mon + 1;      // månaderna och dagarna
    int day   = t->tm_mday;         // indexerade från ETT

    std::cout << "Testing constructors..." << std::endl;
    assert(today.year() == year &&          // rätt initierad
           today.month() == month &&
           today.day() == day);
    assert(g.year() == 2006 &&              // rätt initierad
           g.month() == 10 &&
           g.day() == 31);                  // obs! ettindexerade

    std::cout << "Testing access..." << std::endl;
    assert(g.days_per_week() == 7);         // rätt antal dagar per vecka
    assert(j.days_per_week() == 7);         // rätt antal dagar per vecka
    assert(g.days_this_month() == 31);      // rätt antal dagar denna månad
    assert(g.months_per_year() == 12);      // rätt antal månader per år
    assert(j.months_per_year() == 12);      // rätt antal månader per år
    assert(g.week_day() == 2); // rätt veckodag

    std::cout << "Testing manipulation..." << std::endl;
    ++g;                                    // prefix ökning
    assert(g.week_day() == 3); // rätt veckodag
    --g;                                    // prefix minskning
    assert(g.week_day() == 2); // rätt veckodag
    g += 2;                                 // lägg till två dagar
    assert(g.week_day() == 4); // rätt veckodag
    g -= 3;                     // dra bort tre dagar
    g.add_month();              // lägg till en månad
    g.add_month(-1);            // dra bort en månad
    g.add_year(10);             // lägg till tio år.

    std::cout << "Testing miscellaneous functions..." << std::endl;
    Julian jj(tj);              // kopieringskonstruktor
    const Gregorian gg;
    gg.year();                  // gg konstant, läsa går bra
    g = gg;                     // tilldelning
    if(g == gg ||               // jämförelse
       g != gg ||               // jämförelse
       g < gg ||                // jämförelse
       g >= gg)                 // jämförelse
    {}

    std::cout << "Testing boundary violations";
    Gregorian temp(1900, 1, 1);
    Date &d = temp;

    // loopa över dagar och kolla att inga gränser över/underskrids
    for(int i = 0; i < 100000; ++i, ++d)
    {
        if(!(i % 5000))        // utskrift på framsteg
        {
            std::cout << ".";
            flush(std::cout);
        }
        int m[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(d.year() >= 1900 &&
           d.month() >= 1 && d.month() <= 12 &&
           d.day() >= 1 && d.day() <= m[d.month() - 1])
        {}
        else
        {
            std::cout << std::endl;
            std::cout << "boundary checks failed: " << std::endl;
            std::cout << d.year() << ", "
            << d.month() << ", "
            << d.day() << std::endl;
            return 1;
        }
    }
    std::cout << std::endl;

    std::cout << "Testing leap years..." << std::endl;
    // testa om skottåren för sekelskiften fungerar som de ska
    for(int y = 1958; y < 2500; y += 100)
    {
        Gregorian temp(y, 2, 28);
        Date &e = temp;
        ++e;                                   // lägg till en dag
        if((y % 400 == 0 && e.day() == 29) ||  // skottdag (obs! ETTindexerad)
           (y % 400 != 0 && e.day() == 1))     // ej skottdag
        {}
        else
        {
            std::cout << std::endl << "leap day test failed: " << std::endl;
            std::cout << e.year() << ", "
            << e.month() << ", "
            << e.day() << std::endl;
            return 1;
        }
    }

    std::cout << std::endl << "All tests were successful." << std::endl;



    Gregorian gregDate(2015,10,20);
    Julian julDate(2020,5,3);
    gregDate.add_month(1);
    std::cout << gregDate.simPrint()<<"\n";
    assert(gregDate.simPrint() == ("2015-11-20"));
    gregDate.add_month(-24);

    assert(gregDate.simPrint() == ("2013-11-20"));
    gregDate.add_year(-20);
    assert(gregDate.simPrint() == ("1993-11-20"));
    gregDate-=20;
    assert(gregDate.simPrint() == ("1993-10-31"));



    Gregorian gDate(1900,1,1);
    Julian jDate = gDate;

    assert(gDate.mod_julian_day() == jDate.mod_julian_day());
    assert(gDate.mod_julian_day()==15020);
    assert(jDate.simPrint() == ("1899-12-20"));

    jDate = Julian(1900,1,1);
    gDate = jDate;
    assert(gDate.simPrint() == ("1900-01-13"));
    assert(gDate.mod_julian_day()==jDate.mod_julian_day());
    assert(gDate.mod_julian_day()==15032);

    gDate = Gregorian(1858,11,16);
    jDate = gDate;
    assert(gDate.mod_julian_day()==jDate.mod_julian_day());
    assert(gDate.mod_julian_day()==-1);
    gDate = Gregorian(1858,11,17);
    jDate = gDate;
    assert(gDate.mod_julian_day()==0);
    assert(gDate.mod_julian_day()==jDate.mod_julian_day());
    gDate = Gregorian(1858,11,18);
    jDate = gDate;
    assert(jDate.mod_julian_day()==1);
    assert(gDate.mod_julian_day()==jDate.mod_julian_day());




    gDate = Gregorian(1992,02,20);
    gDate.add_month(-9);
   assert(gDate.simPrint() == ("1991-05-20"));
    gDate+=-8;


    assert(gDate.simPrint() == ("1991-05-12"));
    ++gDate;
    assert(gDate.simPrint() == ("1991-05-13"));
    gDate--;
    assert(gDate.simPrint() == ("1991-05-12"));




    gDate = Gregorian(2010,9,23);
    jDate = gDate;
    Julian j2Date = gDate;
    gDate.add_month(5);
    assert(gDate.simPrint() == ("2011-02-23"));
    gDate+=6;
    assert(gDate.simPrint() == ("2011-03-01"));


    assert(jDate.simPrint() == ("2010-09-10"));
    jDate.add_month(5);
    jDate.add_year(1);
    assert(jDate.simPrint() == ("2012-02-10"));
    jDate+=20;
    assert(jDate.simPrint() == ("2012-03-01"));
    jDate.add_month(15);
    assert(jDate.simPrint() == ("2013-06-01"));
    jDate.add_year(19);
    assert(jDate.simPrint() == ("2032-06-01"));



    assert(j2Date.simPrint() == ("2010-09-10"));
    j2Date.add_month(20);
    assert(j2Date.simPrint() == ("2012-05-10"));
    j2Date += 20;
    assert(j2Date.simPrint() == ("2012-05-30"));
    j2Date.add_year(20);
    assert(j2Date.simPrint() == ("2032-05-30"));


//more leap test
    Julian j3Date(1900,03,01);
    j3Date -=1;//leap year
    assert(j3Date.simPrint() == ("1900-02-29"));
    j3Date.add_month(60);
    assert(j3Date.simPrint() == ("1905-02-28"));
    j3Date.add_month(-60);
    assert(j3Date.simPrint() == ("1900-02-28"));
    j3Date.add_month(12*100);
    j3Date++;
    assert(j3Date.simPrint() == ("2000-02-29"));
    j3Date -=-365;
    assert(j3Date.simPrint() == ("2001-02-28"));
    ++j3Date;
    j3Date.add_year(399);
    assert(j3Date.simPrint() == ("2400-03-01"));
    --j3Date;
    assert(j3Date.simPrint() == ("2400-02-29"));

    Julian j4Date = j3Date++;
    assert(j4Date < j3Date);
    j4Date = j3Date;
    assert(j4Date == j3Date);
    j4Date = j3Date--;
    assert(j4Date > j3Date);
    j4Date = --j3Date;
    assert(j4Date == j3Date);
    j4Date = ++j3Date;
    assert(j4Date == j3Date);


    Gregorian g3Date(1900,03,01);
    g3Date -=1; //no leap year
    assert(g3Date.simPrint() == ("1900-02-28"));

    std::cout << std::endl << "All date tests were successful." << std::endl;



    /*
    std::cout << "CALENDAR TESTS\n";
    Calendar<Gregorian> testCalendar;
    testCalendar.add_event("derp");
    testCalendar.add_event("preDerp",29);
    testCalendar.add_event("pre2Derp",29,05);
    testCalendar.add_event("pre3Derp",29,06,2014);
    testCalendar.add_event("sameDatePre3",29,06,2014);
    testCalendar.remove_event("pre3Derp",29,06,2014);
    testCalendar.printAllEvent();


    Calendar<Julian> testJulCalendar = testCalendar;

    testJulCalendar.printAllEvent();

    Gregorian test = testCalendar.getWatchDate();
    std::cout << test << "\n";





    std::cout << "additional tests\n";
    Gregorian blublub(2004,01,30);
    blublub.add_month(1);
    std::cout << blublub << "\n";

    blublub = Gregorian(2003,01,30);
    blublub.add_month(1);
    std::cout << blublub << "\n";

    blublub = Gregorian(2000,01,20);
    blublub.add_year(5);
    std::cout << blublub << "\n";

    blublub = Gregorian(2004,02,29);
    blublub.add_year(1);
    std::cout << blublub << "\n";

    blublub = Gregorian(2004,02,29);
    blublub.add_year(4);
    std::cout << blublub << "\n";


    std::cout << testCalendar <<"\n";
    */
    // f�ljande ska inte g� att kompilera
#if 0
    gg.leap_year();             // fel: kan inte komma �t protected/private medlem
    gg = g;                     // fel: kan inte tilldela konstant
    ++gg;                       // fel: kan inte �ndra p� en konstant
#endif

    return 0;
}

