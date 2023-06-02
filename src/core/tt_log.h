#ifndef __LOG_H__
#define __LOG_H__

#include<iostream>
template <typename T>
std::ostream &STD_COUT(std::ostream &os, const T &arg) { return os << arg;}
   
template <typename T, typename... Types>
std::ostream &STD_COUT(std::ostream &os, const T &firstArg, const Types &...args){ os << firstArg << " "; return STD_COUT(os, args...);}

#define LOG(...)  STD_COUT(std::cout, __VA_ARGS__)
#define LOG_FILE(ofs, ...)  STD_COUT(ofs, __VA_ARGS__)

#endif // __LOG_H__