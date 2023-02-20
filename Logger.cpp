#include "Logger.h"
#include <iostream>
using namespace std;

void Logger::addLog(Type errortype, string msg, chrono::time_point<chrono::steady_clock> time)
{
    if(errortype >= _level){
        unique_lock l(_busy);
        _Logfile << levelNames_.at(errortype) << " [";
        chrono::seconds sec = chrono::duration_cast<chrono::seconds>(_begin - time);
        printTime(sec);
         _Logfile << "] " << msg;
    }
}

void Logger::printTime(chrono::seconds ms){
    auto d = chrono::duration_cast<chrono::days>(ms);
    ms -= d;
    auto h = chrono::duration_cast<chrono::hours>(ms);
    ms -= h;
    auto m = chrono::duration_cast<chrono::minutes>(ms);
    ms -= m;
    auto s = chrono::duration_cast<chrono::seconds>(ms);
    ms -= s;

    auto dc = d.count();
    auto hc = h.count();
    auto mc = m.count();
    auto sc = s.count();

    if(dc){
        cout << dc << ":";
    }
    else{
        cout << "00:";
    }
    if(hc){
         cout << hc << ":";
    }else{
        cout << "00:";
    }
    if(mc){
        cout << mc << ":";
    }else{
        cout << "00:";
    }
    if(sc){
        cout << sc;
    }else{
        cout << "00";
    }
}

