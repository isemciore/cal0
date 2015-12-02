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
    protected:
        class internal_date {
        private:
            DateType start_date_;
            DateType end_date_;
            int hour_;
            int minute_;

            int end_hour_;
            int end_minute_;

        public:
            internal_date(DateType start_date, int hour, int minute, DateType end_date, int end_hour, int end_minute)
                    : start_date_(start_date), hour_(hour), minute_(minute), end_date_(end_date), end_hour_(end_hour), end_minute_(end_minute) { }

            bool operator<(const internal_date &int_date) const {
                if (end_date_ == int_date.end_date_) {
                    if (hour_ == int_date.hour_) {
                        return minute_ < int_date.minute_;
                    }
                    else if (hour_ < int_date.hour_) {
                        return true;
                    } else {
                        return false;
                    }
                }
                return (end_date_ < int_date.end_date_);
            }
            DateType get_start_date()const { return start_date_;}
            DateType get_end_type()const {return end_date_;}
            int start_hour()const{ return hour_;}
            int start_minute()const{ return minute_;}
            int end_hour()const{ return end_hour_;}
            int end_minute()const{ return end_minute_;}

            bool delta_time_exclude_date(const DateType &src_date,const int &hour,const int &min) const{
                internal_date temp(src_date,hour,min,src_date,hour,min);
                internal_date temp_start(start_date_,hour_,minute_,start_date_,hour_,minute_);
                internal_date temp_end(end_date_,end_hour_,end_minute_,end_date_,end_hour_,end_minute_);
                if (temp < temp_end&& temp_start < temp){
                    return false;
                }
                return true;
            }
        };
    public:
        typedef typename std::multimap<DateType,std::string>::iterator mapItType;

        typedef typename std::multimap<internal_date,std::string>::iterator map_date_to_event_iterator_type;

    private:
        DateType watchDate;
        //std::multimap<DateType,std::string> map_date_to_event_; //Mayby create struct for more data then key with multiple values
        std::multimap<internal_date,std::string> map_internal_date_to_event;


    public:
        ~Calendar();
        Calendar();

        template <class SrcDType>
        Calendar(const Calendar<SrcDType> & src);
        std::multimap<internal_date,std::string> get_date_evemtname_map() const {return map_internal_date_to_event;}
        DateType getWatchDate() const{return watchDate;}

        bool set_date(unsigned, unsigned, unsigned);


        friend std::ostream& operator<<(std::ostream& os, const Calendar<DateType> & cal) {
            std::multimap<internal_date,std::string> map_calendar_date_event = cal.get_date_evemtname_map();
            DateType wtchDte = cal.getWatchDate();
            internal_date search_from_date(wtchDte,0,0,wtchDte,0,0);

            typename Calendar<DateType>::map_date_to_event_iterator_type lower_bound = map_calendar_date_event.lower_bound(search_from_date);
            typename Calendar<DateType>::map_date_to_event_iterator_type endIt = map_calendar_date_event.end();

            auto date_from_format_to_string = [](typename Calendar<DateType>::map_date_to_event_iterator_type iterator,bool startDate)->std::string{//Lambda function test
                std::string temp;
                DateType date_tmp;
                int relv_hour;
                int relv_minute;
                if(startDate){
                    date_tmp = iterator->first.get_start_date();
                    relv_hour = iterator->first.start_hour();
                    relv_minute = iterator->first.start_minute();
                }
                else{
                    date_tmp = iterator->first.get_end_type();
                    relv_hour = iterator->first.end_hour();
                    relv_minute = iterator->first.end_minute();
                }


                temp = std::to_string(date_tmp.year());
                if(date_tmp.month() < 10){temp.append(std::to_string(0));}
                temp.append(std::to_string(date_tmp.month()));
                if(date_tmp.day() < 10){temp.append(std::to_string(0));};
                temp.append(std::to_string(date_tmp.day()));
                temp.append("T");
                if(relv_hour<10){temp.append("0");}
                temp.append(std::to_string(relv_hour));
                if(relv_minute<10){temp.append("0");}
                temp.append(std::to_string(relv_minute));
                temp.append("CET");
                return temp;
            };
            os << "BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:DD2387CuCAL\n";

            while(lower_bound != endIt){
                os<< "BEGIN:VEVENT\nUID:ezhang@kth.se\n";
                os << "DTSTAMP:" << date_from_format_to_string(lower_bound,true) << "\n";
                os << "DTSTART:" << date_from_format_to_string(lower_bound,true) << "\n";
                os << "DTEND:" << date_from_format_to_string(lower_bound,false) << "\n";
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
        bool add_event(std::string eventName, unsigned day, unsigned month, unsigned year);
        bool add_event(std::string eventName, unsigned day, unsigned month, unsigned year, int hour_start, int min_start);
        bool add_event(std::string eventName, unsigned day, unsigned month, unsigned year, int hour_start, int min_start, int event_length);



        bool remove_event(std::string eventname);
        bool remove_event(std::string eventname, unsigned int day);
        bool remove_event(std::string eventname, unsigned int day, unsigned int month);
        bool remove_event(std::string,unsigned,unsigned,unsigned);
        bool remove_event(std::string, unsigned, unsigned, unsigned,int h_s, int m_s);
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
        /*
        while(fElt != lElt){
            DateType tempDate = fElt->first;
            std::string tempString = fElt->second;
            map_date_to_event_.insert(std::make_pair(tempDate,tempString));
            fElt++;
        }*/

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
        return add_event(eventName,day,month,year,13,00);
    }
    template<class DateType>
    bool Calendar<DateType>::add_event(std::string eventName, unsigned day, unsigned month, unsigned year, int h_start, int m_start ){
        return add_event(eventName,day,month,year,h_start,m_start, 4*60);
    }
    template<class DateType>
    bool Calendar<DateType>::add_event(std::string eventName, unsigned day, unsigned month, unsigned year, int h_start, int m_start, int event_length ){
        DateType start_date;
        DateType end_date;
        try{start_date = DateType(year,month,day);end_date=DateType(year,month,day);} catch(...){return false;}
        if (h_start< 0 || h_start >=24 ||m_start<0 || m_start > 60 || event_length< 0){
            return false;
        }
        int deltaMin = event_length%60;
        int minEnd = m_start + deltaMin;
        int deltaHour = event_length/60;
        if (deltaMin+m_start >=60){
            deltaHour++;
            minEnd = minEnd%60;
        }
        int deltaDays = (deltaHour+h_start)/24;
        int hour_end = (deltaHour+h_start)%24;
        end_date += deltaDays;

        internal_date temp_date(start_date,h_start,m_start,end_date,hour_end,minEnd);
        map_date_to_event_iterator_type it_pair = map_internal_date_to_event.upper_bound(temp_date);

        if (it_pair==map_internal_date_to_event.end() || it_pair->first.delta_time_exclude_date(end_date,hour_end,minEnd)){
            if (it_pair==map_internal_date_to_event.begin() || (it_pair--)->first.delta_time_exclude_date(start_date,h_start,m_start)){
                map_internal_date_to_event.insert(std::make_pair(temp_date,eventName));
                return true;
            }
        }
        return false;
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
        try { DateType(year, month, day); } catch (...) { return false; }
        DateType start_date(year,month,day);
        internal_date search_from_date(start_date,0,0,start_date,0,0);
        start_date++;
        internal_date search_to_date(start_date,0,0,start_date,0,0);

        typename Calendar<DateType>::map_date_to_event_iterator_type start_pair = map_internal_date_to_event.upper_bound(search_from_date);
        typename Calendar<DateType>::map_date_to_event_iterator_type end_pair = map_internal_date_to_event.upper_bound(search_to_date);
        while(start_pair != end_pair){
            if(start_pair->second == eventname){
                map_internal_date_to_event.erase(start_pair);
                return true;
            }
            start_pair++;
        }
        return false;
    }
    template<class DateType>
    bool Calendar<DateType>::remove_event(std::string eventname,  unsigned day, unsigned month, unsigned year,int hour, int min) {
        try { DateType(year, month, day); } catch (...) { return false; }
        DateType start_date(year,month,day);
        internal_date target_date(start_date,hour,min,start_date,hour,min);//just to find iterator to closets day as time is specified
        //As key only hashes function of date comparision, begin date

        typename Calendar<DateType>::map_date_to_event_iterator_type it_pair = map_internal_date_to_event.find(target_date);

        if (it_pair == map_internal_date_to_event.end()){
            return false;
        }
        if(it_pair->second == eventname){
            map_internal_date_to_event.erase(it_pair);
            return true;
        }
        return false;//as no event can occure at same time
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


}
#endif //CAL0_CALENDAR_H


