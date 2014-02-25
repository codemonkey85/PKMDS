#ifdef PKMDS_CMAKE_USED
#include <pkmds/stdafx.h>
#else
#include "../include/pkmds/stdafx.h"
#endif
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}
std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
byte getbit(byte & input, byte n)
{
	return ((input) >> n) & 1;
}
byte getbit(uint16 & input, byte n)
{
	return ((input) >> n) & 1;
}
byte getbit(uint32 & input, byte n)
{
	return ((input) >> n) & 1;
}

void setbit(byte & input, byte n, byte val)
{
	if(val == 0)
	{
		input &= ~(1 << n);
	}
	else
	{
		input |= 1 << n;
	}
}
void setbit(uint16 & input, byte n, byte val)
{
	if(val == 0)
	{
		input &= ~(1 << n);
	}
	else
	{
		input |= 1 << n;
	}
}
void setbit(uint32 & input, byte n, byte val)
{
	if(val == 0)
	{
		input &= ~(1 << n);
	}
	else
	{
		input |= 1 << n;
	}
}
void togglebit(byte & input, byte n)
{
	input ^= 1 << n;
}
void togglebit(uint16 & input, byte n)
{
	input ^= 1 << n;
}
void togglebit(uint32 & input, byte n)
{
	input ^= 1 << n;
}
