#include <iostream>
#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_g5.h"
#endif
using namespace std;
int main()
{
	string empty;
	string fromfile = "", tofile = "";
	bw2sav_obj *fromsav = new bw2sav_obj;
	bw2sav_obj *tosav = new bw2sav_obj;
	cout << "Enter the file name of the save file to import from:\n";
	getline(cin,fromfile);
	read(fromfile.c_str(),fromsav);
	cout << "Found data for trainer ";
	wcout << fromsav->cur.party.pokemon[0].pkm_data.otname;
	cout << "\n"; // " (ID " << (int)fromsav->cur.tid << ")\n";
	cout << "Enter the file name of the save file to export to:\n";
	getline(cin,tofile);
	read(tofile.c_str(),tosav);
	cout << "Found data for trainer ";
	wcout << tosav->cur.party.pokemon[0].pkm_data.otname;
	cout << "\n"; // " (ID " << (int)tosav->cur.tid << ")\n";
	bool isbw2 = false;
	isbw2 = (getchecksum(tosav->cur,BW2_OFFSETS::chkcalcloc,BW2_OFFSETS::chkcalclen)) == (getchkfromsav(tosav->cur,true));
	cout << "Now beginning Pokemon transfer from ";
	wcout << fromsav->cur.party.pokemon[0].pkm_data.otname;
	cout << " to ";
	wcout << tosav->cur.party.pokemon[0].pkm_data.otname;
	cout << ":\n";
	for(int box = 0; box < 24; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			tosav->cur.boxes[box].pokemon[slot] = fromsav->cur.boxes[box].pokemon[slot];
		}
		calcboxchecksum(tosav->cur,box,isbw2);
	}
	if(isbw2)
	{
		calcchecksum(tosav->cur, BW2_OFFSETS::chkcalcloc, BW2_OFFSETS::chkcalclen, BW2_OFFSETS::chkloc);
	}
	else
	{
		calcchecksum(tosav->cur, BW_OFFSETS::chkcalcloc, BW_OFFSETS::chkcalclen, BW_OFFSETS::chkloc);
	}
	write(tofile.c_str(),tosav);
	cout << "Transfer complete. Press the [Enter] key to exit.\n";
	getline(cin,empty);
	return 0;
}
