#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_gba.h"
#endif
using namespace std;
void dostuff(pokemon_gen3 * pkm);
int main(int argc, char* argv[])
{
  string savefile;
	// Either you can name your in file manually
	savefile = "IN.sav";
	// Or you can drag and drop your in file onto the .exe
	//savefile = argv[1];
	//// Name your out file
	//string saveout = "OUT.sav";
	// Declare your SAV and PKM pointers
	gbasavefile* sav = new gbasavefile();
	pokemon_gen3* pkm = new pokemon_gen3();
	// Read your SAV object from the file
	read(savefile.c_str(),sav);
	sortsavefile(sav);
	for(int box = 0; box < 18; box++)
	{
	  for(int slot = 0; slot < 30; slot++)
	  {
	    	pkm = &(sav->savefilea.pcstorage[box][slot]);
	    	decryptgbapkm(pkm);
	    	dostuff(pkm);
	  }
	}
	string test;
	cin >> test;
	return 0;
}
void dostuff(pokemon_gen3 * pkm)
{
  
}
