#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_g5_sqlite.h"
#endif

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	opendb("veekun-pokedex.sqlite");
	char * filename;
	pokemon_obj * pkm = new pokemon_obj;
	ofstream myfile;
	myfile.open("OUTPUT.csv",ios::out);
	myfile << "Dex No,PID,OT,ID,SID,Nickname,Gender,Level,Nature,Ability,Location,Ribbon,Ball,Move 1,Move 2,Move 3,Move 4\n";
	for(int i = 1; i < argc; i++)
	{
		filename = argv[i];
		read(filename,pkm);
		ostringstream o;
		std::wstring wstr;
		o << (int)(pkm->species);
		o << ",";
		o << (pkm->pid);
		o << ",";
		wstr = getpkmotname(pkm);
		o << std::string(wstr.begin(),wstr.end());
		o << ",";
		o << (pkm->tid);
		o << ",";
		o << (pkm->sid);
		o << ",";
		wstr = getpkmnickname(pkm);
		o << std::string(wstr.begin(),wstr.end());
		o << ",";
		o << getpkmgendername(pkm);
		o << ",";
		o << (getpkmlevel(pkm));
		o << ",";
		o << getnaturename(pkm);
		o << ",";
		o << lookupabilityname(pkm);
		o << ",";
		o << getpkmmetlocname(pkm);
		o << ",";
		o << "RIBBON";
		o << ",";
		o << lookupitemname(balltoitem((int)(pkm->ball)));
		o << ",";
		for(int move = 0; move < 3; move++)
		{
			o << lookupmovename(pkm,move) << ",";
		}
		o << lookupmovename(pkm,3);
		o << "\n";
		string str = o.str();
		myfile << str;
	}
	myfile.close();
	closedb();
	return 0;
}
