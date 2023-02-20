#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <chrono>
#include <shared_mutex>

using namespace std;

enum Type {
    Invalid,
    Trace,
    Debug,
    Info,
    Warning,
    Error
};

const unordered_map<int, string> levelNames_ = {
    { Invalid, "Invalid"},
    { Trace, "Trace"},
    { Debug, "Debug"},
    { Info, "Info"},
    { Error, "Error"},
    { Warning, "Warning"},
};




class Logger{
public:
  Logger(Type level):
  _begin(chrono::steady_clock::now()),
  _level(level)
  {
    _file.open(_FILENAME, _file.out | _file.app);
  }

  ~Logger();
  void addLog(Type errortype, string msg, chrono::time_point
                <std::chrono::steady_clock> time= 
                chrono::steady_clock::now()){

  }
private:
  chrono::time_point<std::chrono::steady_clock> _begin;
  Type _level;
  string _FILENAME = "Log.txt";
  fstream _file;
  ofstream _Logfile;
  shared_mutex _busy;
};