#include "event_counters.h"

event_counters::event_counters(std::string name) : eventName(name)
{

}

int event_counters::howManyEvent()
{
    std::lock_guard < std::mutex > lock ( eventMutex);
    return eventList.size();
}

void event_counters::addEvent(  std::string date, std::string note)
{
    eventStruct d;
    d.date = date;
    d.note = note;
    std::lock_guard < std::mutex > lock ( eventMutex);
    eventList.push_back(d);
}

std::string event_counters::getEvent()
{
    std::string ret;
    std::lock_guard < std::mutex > lock ( eventMutex);
    for (auto i : eventList){
        ret += i.date + " "+ i.note + "\n";
    }

    return ret;
}

void event_counters::clearEvent( )
{
    std::lock_guard < std::mutex > lock ( eventMutex);
    eventList.clear();
}

std::string event_counters::getEventName()
{
    return eventName;
}
