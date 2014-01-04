#pragma once
#ifdef _MSC_VER
#define DllExport __declspec(dllexport)
#else
#define DllExport __attribute__((visibility("default")))
#endif
//#if (defined __APPLE__)
//#endif
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <array>
#include <math.h>
#include <algorithm>
#include <ctime>
typedef unsigned char byte; // 8 bits
typedef unsigned short int uint16; // 16 bits
typedef unsigned int uint32; // 32 bits
#if (defined __linux__) || (defined __APPLE__)
#define strcpy__ strcpy
#else
#define strcpy__ strcpy_s
#endif
static const int LANG_ID = 9;
static const int VERSION_GROUP = 11;
static const int GENERATION = 5;
static const int BUFF_SIZE = 955;
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
byte getbit(byte & input, byte n);
byte getbit(uint16 & input, byte n);
byte getbit(uint32 & input, byte n);
