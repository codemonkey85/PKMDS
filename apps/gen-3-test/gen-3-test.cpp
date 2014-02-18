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
	const char * pkmfile = "C:\\Users\\Michael Bond\\Dropbox\\ShinyJirachiWSHMKR.3gpkm";
	savefile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\pokemon_emerald_version.gsb";
	gbasavefile* sav = new gbasavefile();
	gbasavehalf_unscrambled * unscrambled = new gbasavehalf_unscrambled();
	pokemon_gen3* pkm = new pokemon_gen3();
	read(savefile.c_str(),sav);
	sortsavefile(sav);
	unscrambled = reinterpret_cast<gbasavehalf_unscrambled*>(&(sav->savefilea.blocks[5]));
	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			pkm = &(unscrambled->pcstorage[box][slot]);
			decryptgbapkm(pkm);
			shufflegbapkm(pkm,true);
			//read(pkmfile,pkm);

			if(pkm->data.species != GBASpecies::NOTHING)
			{
				dostuff(pkm);
			}
		}
	}
	string test;
	cin >> test;
	return 0;
}
void dostuff(pokemon_gen3 * pkm)
{
	cout << sizeof(pokemon_gen3) << "\n";
	cout << int(pkm->data.species) << "\n";
}
