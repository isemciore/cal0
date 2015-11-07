//
// Created by ezhang on 2015-10-13.
//

#ifndef CAL0_DATE_H
#define CAL0_DATE_H
#include <iostream>
#include <math.h>
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

    unsigned Date::day() const {return _day;}
    unsigned Date::year() const {return _year;}
    unsigned Date::month() const {return _month;}
    Date::Date() {
    }
    Date::~Date() {  }

    Date& Date::operator=(const Date &date) {
        _day = date.day();
        _month = date.month();
        _year = date.year();
        *this += (date.mod_julian_day() - this->mod_julian_day());
        return *this;
    }

    bool Date::operator==(const Date &date) const {
        return (this->mod_julian_day() == date.mod_julian_day());
    }

    bool Date::operator!=(const Date &date) const {
        return this->mod_julian_day() != date.mod_julian_day();
    }

    bool Date::operator<(const Date &date) const {
        return this->mod_julian_day() < date.mod_julian_day();
    }

    bool Date::operator<=(const Date &date) const {
        return this->mod_julian_day() <= date.mod_julian_day();
    }

    bool Date::operator>(const Date &date) const {
        return this->mod_julian_day() > date.mod_julian_day();
    }

    bool Date::operator>=(const Date &date) const {
        return this->mod_julian_day() >= date.mod_julian_day();
    }

    void Date::add_year(int n) {
        /*if( (_year+n > maxYear) || (_year+n < minYear)){
            std::cout << "Warning or something might be unspported\n";
        }*/
        _year += n;
        if(_month > month_this_year()){
            _month = month_this_year();
        }
        if(_day > days_this_month()){
            _day = days_this_month();
        }

    }

    void Date::add_month(int n) {
        int yearShift = (int) floor( (double) (((int) _month) + n -1)/ ((int) month_this_year()));

        //if(n < 0){yearShift--;}
        add_year(yearShift);
        _month = ((12+(((int)_month-1+  n ) % 12)) % 12) +1;
        //Updating year according to removed/added number of month
        if(_day>days_this_month()){
            _day = days_this_month();
        }
    }

    Date& Date::operator++() {
        *this +=1;
        return *this;
    }

    Date& Date::operator--() {
        *this +=(-1);
        return *this;
    }

    Date& Date::operator-=(int d) {
        *this += -d;
        return *this;
    }
    Date &Date::operator+=(int d) {
        int tmpDay = _day +d;

        while((tmpDay < 1)||(tmpDay > (int) days_this_month()) ){
            if(tmpDay < 1){
                this->add_month((-1));
                tmpDay += days_this_month();
            }
            else if( tmpDay> (int) days_this_month()){
                tmpDay -= days_this_month();
                this->add_month(1);
            }
        }
        _day =(unsigned) tmpDay;
        return *this;
    }

    unsigned int Date::operator-(const Date &date) const {
        return (((int) this->mod_julian_day()) - ((int) date.mod_julian_day()));
    }




    std::ostream& operator<< (std::ostream& output, const Date & src){
        output << src.year() <<"-";
        if(src.month() < 10){
            output << 0;
        }
        output << src.month() <<"-";
        if(src.day() < 10){
            output << 0;
        }
        output<<src.day();
        return output;
    }

    unsigned int Date::months_per_year() const {
        return this->month_this_year();
    }

    std::string Date::simPrint(){
        std::string temp;
        temp = std::to_string(this->year());
        temp.append("-");
        if(this->month() < 10){
            temp.append("0");
        }
        temp.append(std::to_string(this->month()));
        temp.append("-");
        if (this->day() < 10){
            temp.append("0");
        }
        temp.append(std::to_string(this->day()));
        return temp;
    }
}
#endif //CAL0_DATE_H


/*
ostream& operator<< (ostream& out, const Date& mc) {
mc.print(out);
return out;
}*/

