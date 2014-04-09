#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_gba.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_gba.h"
#endif
using namespace std;
int main(int argc, char* argv[])
{
	const char * savefile = "";
	if(argc > 1)
	{
		savefile = argv[1];
	}
	else
	{
		savefile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\VBA\\Pokemon FireRed.sav";
	}
	gbasavefilepacked* savin = new gbasavefilepacked();
	gbasavefile* sav = new gbasavefile();
	pokemon_gen3* gbapkm = new pokemon_gen3();
	pokemon_obj * pkm = new pokemon_obj();
	read(savefile,savin);
	buildgbasave(savin,sav);
	opendb("C:\\Users\\Michael Bond\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite");
	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			gbapkm = &(sav->pcstorage.pcstorage[box][slot]);
			decryptgbapkm(gbapkm);
			shufflegbapkm(gbapkm,true);
			if(gbapkm->data.species != GBASpecies::NOTHING)
			{
				gbapkm->data.item = GBAItems::awakening;
				calcchecksum(gbapkm);
				//convertgen3pkmtogen5(gbapkm,pkm);
				//cout << lookuppkmname(pkm) << "\n";
			}
			shufflegbapkm(gbapkm,false);
			decryptgbapkm(gbapkm);
		}
	}
	closedb();
	write(/*savefile*/"C:\\Users\\Michael Bond\\Dropbox\\Saves\\VBA\\Pokemon FireRed_OUT.sav",sav,savin);
	cout << "\nEND\n";
	return 0;
}
