//
// Created by ezhang on 2015-10-18.
//

#ifndef CAL0_GREGORIAN_HPP
#define CAL0_GREGORIAN_HPP
#include "date.hpp"

namespace lab2{
   class Gregorian : public Date{

   public:
       Gregorian();
       using Date::Date;
       Gregorian(const Date *);
       Gregorian(const Date &);
       Gregorian(unsigned, unsigned, unsigned);
       unsigned int week_day() const override ;
       unsigned int days_per_week() const override ;
       unsigned int days_this_month() const override ;
       unsigned int month_this_year() const override ;
       std::string week_day_name() const override ;
       std::string month_name() const override ;

       Gregorian operator++(int);
       Gregorian operator--(int);
       using Date::operator++; //Not sure why Date::Date is not enough
       using Date::operator--;
       using Date::operator+=;
       using Date::operator-=;
       int mod_julian_day() const override;


   private:
       virtual void setDateToday() override;
       inline bool isLeapYear() const;
   };

}


#endif //CAL0_GREGORIAN_HPP
