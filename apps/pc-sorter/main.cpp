#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#include <pkmds/pkmds_vector.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_g5_sqlite.h"
#include "..\\..\\include\\pkmds\\pkmds_vector.h"
#endif
using namespace std;
int main(int argc, char* argv[])
{
	string saveout = "OUT.sav";
	bw2sav_obj* sav = new bw2sav_obj;
	read(argv[1],sav);
	bool bw2 = savisbw2(sav);
	std::vector<pokemon_obj> *vpkm = new std::vector<pokemon_obj>;
	vpkm = getpcvector(&(sav->cur));
	std::vector<pokemon_obj>::const_iterator pkmit;
	pkmit = vpkm->begin();
	sortbyspeciesasc(*vpkm);
	pokemon_obj * blankpkm = new pokemon_obj;
	pkmit = vpkm->begin();
	pokemon_obj * pkm = new pokemon_obj;
	for(int box = 0; box < 24; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			if(((box*30)+slot) < vpkm->size())
			{
				*pkm = *pkmit;
				encryptpkm(pkm);
				sav->cur.boxes[box].pokemon[slot] = *pkm;
				pkmit++;
			}
			else
			{
				sav->cur.boxes[box].pokemon[slot] = *blankpkm;
			}
		}
		calcboxchecksum(&(sav->cur),box,bw2);
	}
	fixsavchecksum(sav,bw2);
	write(saveout.c_str(),sav);
	delete pkm;
	pkm = 0;
	delete vpkm;
	vpkm = 0;
	delete sav;
	sav = 0;
	return 0;
}
