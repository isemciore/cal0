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
    public:
        typedef typename std::multimap<DateType,std::string>::iterator mapItType;
    protected:
        class internal_date {
        private:
            DateType date_;
            int hour_;
            int minute_;
        public:
            internal_date(DateType date, int hour, int minute)
                    : date_(date), hour_(hour), minute_(minute) { }

            bool operator<(const internal_date &int_date) const {
                if (date_ == int_date.date_) {
                    if (hour_ == int_date.hour_) {
                        return minute_ < int_date.minute_;
                    }
                    else if (hour_ < int_date.hour_) {
                        return true;
                    } else {
                        return false;
                    }
                }
                return (date_ < int_date.date_);
            }
        };
    private:
        DateType watchDate;
        std::multimap<DateType,std::string> map_date_to_event_; //Mayby create struct for more data then key with multiple values

        std::multimap<internal_date,std::string> map_internal_date_to_event;
        std::multimap<std::string,internal_date> map_event_to_internal_date;



    public:
        ~Calendar();
        Calendar();

        template <class SrcDType>
        Calendar(const Calendar<SrcDType> & src);
        std::multimap<DateType,std::string> get_date_evemtname_map() const {return map_date_to_event_;}
        DateType getWatchDate() const{return watchDate;}

        bool set_date(unsigned, unsigned, unsigned);


        friend std::ostream& operator<<(std::ostream& os, const Calendar<DateType> & cal) {
            std::multimap<DateType,std::string> map_calendar_date_event = cal.get_date_evemtname_map();
            /*
            auto sI = map_calendar_date_event.begin();
            auto sE = map_calendar_date_event.end();
            while(sI!=sE){
                std::cout << sI->second << "\n";
                sI++;
            }
            std::cout<< "\n\n"<<map_calendar_date_event.size()<<"\n";
            std::cout << cal.get_map().size() << "\n";

            for(auto elt: map_calendar_date_event){
                std::cout << elt.second << "\n";
            }
            */
            //typename Calendar<DateType>::mapItType lower_bound = cal.get_map().lower_bound(cal.getWatchDate());
            //typename Calendar<DateType>::mapItType endIt = cal.get_map().end();
            typename Calendar<DateType>::mapItType lower_bound = map_calendar_date_event.lower_bound(cal.getWatchDate());
            //typename Calendar<DateType>::mapItType lower_bound = map_calendar_date_event.begin();
            typename Calendar<DateType>::mapItType endIt = map_calendar_date_event.end();

            auto date_format_to_string = [](typename Calendar<DateType>::mapItType iterator)->std::string{//Lambda function test
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

            while(lower_bound != endIt){
                os<< "BEGIN:VEVENT\nUID:ezhang@kth.se\n";
                os<<"DTSTAMP:"<< date_format_to_string(lower_bound)<<"\n";
                os<<"DTSTART:"<< date_format_to_string(lower_bound)<<"\n";
                os<<"DTEND:"<< date_format_to_string(lower_bound)<<"\n";
                os<< "SUMMARY:" << lower_bound->second<<"\n";
                os<<"END:VEVENT\n";
                lower_bound++;
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
        std::multimap<SrcDType,std::string> srcMap = src.get_date_evemtname_map();
        typedef typename std::multimap<SrcDType,std::string>::iterator targetItType;

        watchDate = src.getWatchDate();
        targetItType fElt = srcMap.begin();
        targetItType lElt = srcMap.end();
        while(fElt != lElt){
            DateType tempDate = fElt->first;
            std::string tempString = fElt->second;
            map_date_to_event_.insert(std::make_pair(tempDate,tempString));
            fElt++;
        }

    }

    template<class DateType>
    bool Calendar<DateType>::set_date(unsigned int year, unsigned int month, unsigned int day) {
        try{DateType(year,month,day);} catch(...){return false;}
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
        try{DateType(year,month,day);} catch(...){return false;}
        std::pair<mapItType, mapItType> iTpair = map_date_to_event_.equal_range(DateType(year,month,day));
        mapItType itStart = iTpair.first;
        mapItType itEnd = iTpair.second;

        while(itStart!=itEnd){ //Kollar igenom för att inte eventet redan finns
            if(itStart->second==eventName){
                return false;
            }
            itStart++;
        }
        map_date_to_event_.insert(std::make_pair(DateType(year,month,day),eventName));
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
        try{DateType(year,month,day);} catch(...){return false;}

        std::pair<mapItType, mapItType> iTpair = map_date_to_event_.equal_range(DateType(year,month,day));
        mapItType itStart = iTpair.first;
        mapItType itEnd = iTpair.second;
        if(itStart==itEnd){
            return false;
        }

        while(itStart != itEnd){
            if(itStart->second == eventname){
                map_date_to_event_.erase(itStart);
                return true;
            }
            itStart++;
        }
        return false;
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
        for(auto elt:map_date_to_event_){
            std::cout<< elt.first << " with data " << elt.second << " \n";
        }

    }

}
#endif //CAL0_CALENDAR_H
