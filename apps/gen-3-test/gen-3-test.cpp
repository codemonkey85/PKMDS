#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_gba.h>
#else
//#include "..\\..\\include\\pkmds\\pkmds_sql.h"
#include "..\\..\\include\\pkmds\\pkmds_gba.h"
#endif
using namespace std;
int main(int argc, char* argv[])
{
	if(argc > 1)
	{
	string savefile = argv[1];
	gbasavefilepacked* savin = new gbasavefilepacked();
	gbasavefile* sav = new gbasavefile();
	pokemon_gen3* gbapkm = new pokemon_gen3();
	pokemon_obj * pkm = new pokemon_obj();
	read(savefile.c_str(),savin);
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
				if((box == 0) & (slot == 0))
				{
					convertgen3pkmtogen5(gbapkm,pkm);
					cout << lookuppkmname(pkm) << "\n";
				}
			}
		}
	}
	closedb();
	cout << "\nEND\n";
	}
	return 0;
}
