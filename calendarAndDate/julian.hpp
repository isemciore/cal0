//
// Created by ezhang on 2015-10-18.
//

#ifndef CAL0_JULIAN_HPP
#define CAL0_JULIAN_HPP
#include "date.hpp"

namespace lab2{
    class Julian : public Date {

    public:
        Julian();
        using Date::Date;
        Julian(unsigned year, unsigned month, unsigned day);
        Julian(const Date *);
        Julian(const Date &);
        unsigned int week_day() const override;
        unsigned int days_per_week() const override;
        unsigned int days_this_month() const override;
        unsigned int month_this_year() const override;
        std::string week_day_name() const override;
        std::string month_name() const override;
        int mod_julian_day() const override;
        Julian operator--(int);
        Julian operator++(int);
        using Date::operator++;
        using Date::operator--;
        using Date::operator+=;
        using Date::operator-=;

    private:
        int kattisTimeToJulian();//greg version of MJD
        virtual void setDateToday() override ;
        inline bool isLeapYear() const;
    };

}
#endif //CAL0_JULIAN_HPP
