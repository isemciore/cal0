//
// Created by ezhang on 2015-10-18.
//

#include <string>
#include "julian.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>
#include "kattistime.h"
unsigned int lab2::Julian::week_day() const {
    //MJD TO JD
    return (unsigned int) ((this->mod_julian_day() +2 )%7 +1);
}

unsigned int lab2::Julian::days_per_week() const {
    return 7;
}

unsigned int lab2::Julian::days_this_month() const {
    if(_month==1 || _month==3 || _month==5 || _month==7 || _month==8||_month == 10 || _month == 12){
        return 31;
    }
    if(_month==4 || _month==6 || _month==9 || _month==11){
        return 30;
    }
    if(isLeapYear()){
        return 29;
    }
    return 28;
}

unsigned int lab2::Julian::month_this_year() const {
    return 12;
}

std::string lab2::Julian::week_day_name() const {
    int weekNo = (this->mod_julian_day() +2 )%7 +1;
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
            return "picnic moar";
    }
}

std::string lab2::Julian::month_name() const {
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

int lab2::Julian::mod_julian_day() const {
    //https://en.wikipedia.org/wiki/Julian_day#Calculation
    int a = (14-_month)/12;
    int y = _year + 4800 -a;
    int m = _month + 12*a -3;
    int JDN = _day + (153*m+2)/5 + 365*y + y/4 - 32083;
    int MJDN = (int) floor(JDN - 2400000.5);
    return MJDN;
}

/*void lab2::Julian::print(std::ostream &ostream) const {

}*/

inline bool lab2::Julian::isLeapYear() const{
    return !(_year%4);
}

lab2::Julian::Julian(const lab2::Date * datePointer) {
    _year = datePointer->year();
    _month = datePointer->month();
    _day = datePointer->day();
    *this +=datePointer->mod_julian_day() - this->mod_julian_day();

}

lab2::Julian::Julian(const lab2::Date & date) {
    _year = date.year();
    _month = date.month();
    _day = date.day();
    *this += date.mod_julian_day() - mod_julian_day();

}

void lab2::Julian::setDateToday() {


    time_t mytime;
    k_time(&mytime);

    // För att få ut datum lokalt
    struct tm *t = gmtime(&mytime);
    _year  = t->tm_year + 1900;
    _month = t->tm_mon + 1;      // månaderna och dagarna
    _day   = t->tm_mday;
    /*
    _year = 2015;
    _month = 10;
    _day = 30;*/

    *this += kattisTimeToJulian() - mod_julian_day();
}

lab2::Julian::Julian():Date() {
    setDateToday();
}

int lab2::Julian::kattisTimeToJulian() {
    int a = (14-_month)/12;
    int y = _year + 4800 -a;
    int m = _month + 12*a -3;
    int JDN = _day + (153*m+2)/5 + 365*y + y/4 - y/100 + y/400 -32045;
    int MJDN = (int) (JDN - 2400000.5);
    return MJDN;
}

lab2::Julian lab2::Julian::operator++(int i) {
    Julian answer = this;
    this->operator+=(1);
    return answer;
}

lab2::Julian lab2::Julian::operator--(int i) {
    Julian answer = this;
    this->operator+=(-1);
    return answer;
}

lab2::Julian::Julian(unsigned int year, unsigned int month, unsigned int day) {
    _year = year;
    if(month > month_this_year() || month < 1){
        throw std::invalid_argument("");
    }
    _month = month;
    if(day > days_this_month() || day < 1){
        throw std::invalid_argument("") ;
    }
    _day = day;
}
