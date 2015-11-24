//
// Created by ezhang on 2015-10-18.
//
#include <string>
#include <stdexcept>
#include "gregorian.hpp"
#include "kattistime.h"
#include <math.h>

lab2::Gregorian::Gregorian(const lab2::Date * dateFormat) {
    _year = dateFormat->year();
    _month = dateFormat->month();
    _day = dateFormat->day();
    *this += dateFormat->mod_julian_day() -this->mod_julian_day();
}


unsigned int lab2::Gregorian::week_day() const {
    //+2 due to 2400001 %7 =2, from MJD to JD
    return (unsigned int) ((this->mod_julian_day() +2) %7 +1);
}

unsigned int lab2::Gregorian::days_per_week() const {
    return 7;
}

unsigned int lab2::Gregorian::days_this_month() const {
    if(_month==1 || _month==3 || _month==5 || _month==7 || _month==8||_month == 10 || _month == 12){
        return 31; //_day
    }
    if(_month==4 || _month==6 || _month==9 || _month==11){
        return 30;
    }
    if(isLeapYear()){
        return 29;
    }
    return 28;
}

unsigned int lab2::Gregorian::month_this_year() const {
    return 12;
}

std::string lab2::Gregorian::week_day_name() const {
    int weekNo = (this->mod_julian_day() +2)%7 +1;
    switch(weekNo){
        case 1 :
            return "monday";
        case 2 :
            return "tuesday";
        case 3 :
            return "wednesday";
        case 4 :
            return "thursday";
        case 5 :
            return "friday";
        case 6 :
            return "saturday";
        case 7 :
            return "sunday";
        default:
            return "picnic more";
    }
}

std::string lab2::Gregorian::month_name() const {
    switch (_month){
        case 1 :
            return "january";
        case 2 :
            return "february";
        case 3 :
            return "mars";
        case 4 :
            return "april";
        case 5 :
            return "may";
        case 6 :
            return "june";
        case 7 :
            return "july";
        case 8 :
            return "august";
        case 9 :
            return "september";
        case 10 :
            return "october";
        case 11 :
            return "november";
        case 12 :
            return "december";
        default:
            return "some micpic";
    }
}

int lab2::Gregorian::mod_julian_day() const {
    int a = (14-_month)/12;
    int y = _year + 4800 -a;
    int m = _month + 12*a -3;
    int JDN = _day + (153*m+2)/5 + 365*y + y/4 - y/100 + y/400 -32045;
    int MJDN = (int) floor(JDN - 2400000.5);
    return MJDN;
}

bool lab2::Gregorian::isLeapYear() const {
    if(!(_year%400)){ //divisible by 400 true
        return true;
    }
    if(!(_year%4)){ //if divisible by 4
        if(_year%100){ //but not 100
            return true;
        }
    }
    return false;
}

lab2::Gregorian::Gregorian(const lab2::Date &date) {
    _year = date.year();
    _month = date.month();
    _day = date.day();
    *this += date.mod_julian_day()-mod_julian_day();
}

void lab2::Gregorian::setDateToday() {
    time_t mytime;
    k_time(&mytime);

    // För att få ut datum lokalt
    struct tm *t = gmtime(&mytime);
    _year  = t->tm_year + 1900;
    _month = t->tm_mon + 1;      // månaderna och dagarna
    _day   = t->tm_mday;
}

lab2::Gregorian::Gregorian() :Date() {
    setDateToday();
}

lab2::Gregorian lab2::Gregorian::operator++(int i) {
    Gregorian answer = this;
    this->operator+=(1);
    return answer;
}

lab2::Gregorian lab2::Gregorian::operator--(int i) {
    Gregorian answer = this;
    this->operator+=(-1);
    return answer;
}

lab2::Gregorian::Gregorian(unsigned int year, unsigned int month, unsigned int day) {
    _year = year;
    if(month > month_this_year() || month < 1){
        throw std::invalid_argument("error in month format\n");
    }
    _month = month;
    if(day > days_this_month() || day < 1){
        throw std::invalid_argument("error in day format \n");
    }
    _day = day;
}
