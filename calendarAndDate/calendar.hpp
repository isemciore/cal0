//
// Created by erik on 2015-10-30.
//

#ifndef CAL0_CALENDAR_H
#define CAL0_CALENDAR_H
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "date.hpp"

namespace lab2 {
    template<typename DateType>
    class Calendar {
        typedef typename std::multimap<DateType,std::string>::iterator mapItType;
    private:
        DateType watchDate;
        std::multimap<DateType,std::string> map; //Mayby create struct for more data then key with multiple values


    public:
        ~Calendar();
        Calendar();

        template <class SrcDType>
        Calendar(const Calendar<SrcDType> & src);
        std::multimap<DateType,std::string> get_map() const {return map;}
        DateType getWatchDate() const{return watchDate;}

        bool set_date(unsigned, unsigned, unsigned);

        friend std::ostream& operator<<(std::ostream& os, const Calendar<DateType> & cal) {
            typename Calendar<DateType>::mapItType startIt = cal.get_map().lower_bound(cal.getWatchDate());
            typename Calendar<DateType>::mapItType endIt = cal.get_map().end();
            auto dFormat = [](typename Calendar<DateType>::mapItType iterator)->std::string{//Lambda function test
                std::string temp;
                temp = std::to_string(iterator->first.year());
                if(iterator->first.month() < 10){temp.append(std::to_string(0));}
                temp.append(std::to_string(iterator->first.month()));
                if(iterator->first.day() < 10){temp.append(std::to_string(0));};
                temp.append(std::to_string(iterator->first.day()));
                temp.append("T170000CET");
                return temp;
            };
            os << "BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:DD2387CuCAL\n";

            while(startIt != endIt){
                os<< "BEGIN:VEVENT\nUID:ezhang@kth.se\n";
                os<<"DTSTAMP:"<<dFormat(startIt)<<"\n";
                os<<"DTSTART:"<<dFormat(startIt)<<"\n";
                os<<"DTEND:"<<dFormat(startIt)<<"\n";
                os<< "SUMMARY:" << startIt->second<<"\n";
                os<<"END:VEVENT\n";
                startIt++;
            }
            os<<"END:VCALENDAR\n";
            return os;
        }


        bool add_event(std::string eventName);
        bool add_event(std::string eventName, unsigned int day);
        bool add_event(std::string eventName, unsigned int day, unsigned int month);
        bool add_event(std::string, unsigned day, unsigned month, unsigned year);

        void printAllEvent();
        bool remove_event(std::string eventname);
        bool remove_event(std::string eventname, unsigned int day);
        bool remove_event(std::string eventname, unsigned int day, unsigned int month);
        bool remove_event(std::string,unsigned,unsigned,unsigned);
    };

    template<class DateType>
    Calendar<DateType>::~Calendar() { }

    template<class DateType>
    Calendar<DateType>::Calendar():watchDate() { }

    template <class DateType>
    template <class SrcDType>
    Calendar<DateType>::Calendar(const Calendar<SrcDType> & src){
        std::multimap<SrcDType,std::string> srcMap = src.get_map();
        typedef typename std::multimap<SrcDType,std::string>::iterator targetItType;

        watchDate = src.getWatchDate();
        targetItType fElt = srcMap.begin();
        targetItType lElt = srcMap.end();
        while(fElt != lElt){
            DateType tempDate = fElt->first;
            std::string tempString = fElt->second;
            map.insert(std::make_pair(tempDate,tempString));
            fElt++;
        }

    }

    template<class DateType>
    bool Calendar<DateType>::set_date(unsigned int year, unsigned int month, unsigned int day) {
        DateType temp(year,month,day);
        watchDate = temp;
        return true;
    }

    template<class DateType>
    bool Calendar<DateType>::add_event(std::string eventName){
        return add_event(eventName,watchDate.day());
    }
    template<class DateType>
    bool Calendar<DateType>::add_event(std::string eventName, unsigned day){
        return add_event(eventName,day,watchDate.month());
    }
    template<class DateType>
    bool Calendar<DateType>::add_event(std::string eventName, unsigned day, unsigned month){
        return add_event(eventName,day,month,watchDate.year());
    }
    template<class DateType>
    bool Calendar<DateType>::add_event(std::string eventName, unsigned day, unsigned month, unsigned year ){
        std::pair<mapItType, mapItType> iTpair = map.equal_range(DateType(year,month,day));
        mapItType itStart = iTpair.first;
        mapItType itEnd = iTpair.second;

        while(itStart!=itEnd){
            if(itStart->second==eventName){
                return false;
            }
            itStart++;
        }
        map.insert(std::make_pair(DateType(year,month,day),eventName));
        return true;
    }


    template<class DateType>
    bool Calendar<DateType>::remove_event(std::string eventname) {
        return remove_event(eventname,watchDate.day());
    }
    template<class DateType>
    bool Calendar<DateType>::remove_event(std::string eventname,  unsigned day) {
        return remove_event(eventname,day,watchDate.month());
    }
    template<class DateType>
    bool Calendar<DateType>::remove_event(std::string eventname,  unsigned day, unsigned month) {
        return remove_event(eventname,day,month,watchDate.year());
    }
    template<class DateType>
    bool Calendar<DateType>::remove_event(std::string eventname,  unsigned day, unsigned month, unsigned year ) {


        std::pair<mapItType, mapItType> iTpair = map.equal_range(DateType(year,month,day));
        mapItType itStart = iTpair.first;
        mapItType itEnd = iTpair.second;
        if(itStart==itEnd){
            return false;
        }

        while(itStart != itEnd){
            if(itStart->second == eventname){
                map.erase(itStart);
            }
            itStart++;
        }
        return true;
    }
/*
    template<typename DateType>
    std::ostream& operator<<(std::ostream& os, const Calendar<DateType> & calendar){
        typename Calendar<DateType>::mapItType startIt = calendar.get_map().lower_bound(calendar.getWatchDate());
        typename Calendar<DateType>::mapItType endIt = calendar.get_map().end();
        auto dFormat = [](typename Calendar<DateType>::mapItType iterator)->std::string{//Lambda function test
            std::string temp;
            temp = std::to_string(iterator->first.year());
            if(iterator->first.month() < 10){temp.append(std::to_string(0));}
            temp.append(std::to_string(iterator->first.month()));
            if(iterator->first.day() < 10){temp.append(std::to_string(0));};
            temp.append(std::to_string(iterator->first.day()));
            temp.append("T170000CET");
            return temp;
        };
        os << "BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:DD2387CuCAL\n";

        while(startIt != endIt){

            os<< "BEGIN:VEVENT\nUID:ezhang@kth.se\n";
            os<<"DTSTAMP:"<<dFormat(startIt)<<"\n";
            os<<"DTSTART:"<<dFormat(startIt)<<"\n";
            os<<"DTEND:"<<dFormat(startIt)<<"\n";
            os<< "SUMMARY:" << startIt->second<<"\n";
            os<<"END:VEVENT";
        }
        os<<"END:VCALENDAR\n";
        return os;
    }*/

    template<typename DateType>
    void Calendar<DateType>::printAllEvent() {
        for(auto elt:map){
            std::cout<< elt.first << " with data " << elt.second << " \n";
        }

    }

}
#endif //CAL0_CALENDAR_H
