#include "Logger.h"

void Logger::addLog(Type errortype, string msg, chrono::time_point
                <std::chrono::steady_clock> time)
{
    if(errortype >= _level){
        unique_lock l(_busy);
        _Logfile << levelNames_.at(errortype) << ' ';
        _Logfile << " [" <<std::chrono::duration_cast<std::chrono::milliseconds>(_begin- time).count() << "] " << msg;
    }
}
