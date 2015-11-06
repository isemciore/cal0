//
// Created by ezhang on 2015-10-13.
//

#ifndef CAL0_DATE_H
#define CAL0_DATE_H

#include <bits/c++config.h>
#include <bits/stringfwd.h>
#include <iosfwd>

namespace lab2 {

    //std::ostream& operator<<(std::ostream&, const Date&);

    class Date {
    protected:
        unsigned _day;
        unsigned _month;
        unsigned _year;

        unsigned minYear = 1858;
        unsigned maxYear = 2558;


    public :
        friend std::ostream& operator<<(std::ostream& os, const Date &);
        //Constructor
        //Date(unsigned int,unsigned int,unsigned int);
        //Constructor may not use virtual functions
        Date(); //should do nothing
        //Date(const Date&);
        //virtual Date(const Date*);
        virtual ~Date();
        Date& operator=(const Date&);

        //memfun
        unsigned year() const;
        unsigned month() const;
        unsigned day() const;

        virtual unsigned int week_day() const = 0;
        virtual unsigned int days_per_week() const = 0;
        virtual unsigned int days_this_month() const = 0;
        virtual unsigned int month_this_year() const = 0;
        virtual std::string week_day_name() const = 0;
        virtual std::string month_name() const = 0;
        virtual void setDateToday() = 0;
        virtual int mod_julian_day() const = 0;//Date converted to julian day?
        //virtual std::size_t rawDay() const = 0;

        void add_year(int n= 1);
        void add_month(int n= 1);
        Date& operator++();
        Date& operator--();
        Date& operator+=(int d);
        Date& operator-=(int d);
        unsigned int operator-(const Date &)const;

        bool operator==(const Date &) const;
        bool operator!=(const Date &) const;
        bool operator< (const Date &) const;
        bool operator<=(const Date &) const;
        bool operator> (const Date &) const;
        bool operator>=(const Date &) const;

        /* postfix, requires correct "return type" must be implemented in derivied class

        virtual Date operator++(int d) = 0;
        virtual Date operator--(int d) = 0;
        */
         //Fixxing dateTest assumptions:
        unsigned int months_per_year() const;//not tested should perhaps not work as it calls virtual function?
        std::string simPrint();
    };
}
#endif //CAL0_DATE_H


/*
ostream& operator<< (ostream& out, const Date& mc) {
mc.print(out);
return out;
}*/

