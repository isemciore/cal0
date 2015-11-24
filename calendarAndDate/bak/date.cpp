//
// Created by ezhang on 2015-10-13.
//

#include <iostream>
#include "date.hpp"
#include <math.h>

namespace lab2{
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