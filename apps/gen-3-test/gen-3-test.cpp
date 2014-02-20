#ifdef PKMDS_CMAKE_USED
//#include <pkmds/pkmds_sql.h>
#include <pkmds/pkmds_gba.h>
#else
//#include "..\\..\\include\\pkmds\\pkmds_sql.h"
#include "..\\..\\include\\pkmds\\pkmds_gba.h"
#endif
//#include <string>
//#include <locale>
using namespace std;
string outputpath = "C:\\Users\\Michael Bond\\Downloads\\GBA PKM DUMPED\\";
int main(int argc, char* argv[])
{
	string savefile;
	//savefile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\pokemon_emerald_version - Copy2.sav";
	savefile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\Pokemon - Fire Red GBA_MODIFIED.sav";
	const char * pkmfile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\Gengar_heart.3gpkm";
	gbasavefilepacked* savin = new gbasavefilepacked();
	gbasavefile* sav = new gbasavefile();
	pokemon_gen3* gbapkm = new pokemon_gen3();
	pokemon_obj * pkm = new pokemon_obj();
	read(savefile.c_str(),savin);
	buildgbasave(savin,sav);
	opendb("C:\\Users\\Michael Bond\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite");

	//read(pkmfile,gbapkm);
	//dostuff(gbapkm);

	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			gbapkm = &(sav->pcstorage.pcstorage[box][slot]);
			decryptgbapkm(gbapkm);
			shufflegbapkm(gbapkm,true);
			if(gbapkm->data.species != GBASpecies::NOTHING)
			{
				//if(gbapkm->data.species == GBASpecies::squirtle)
				//{
				//uint32 * ribbons = reinterpret_cast<uint32*>(&(gbapkm->data.ribbons));
				//if(*ribbons != 0)
				//{
				if((box == 0) & (slot == 0))
				{
					//dostuff(gbapkm);
					convertgen3pkmtogen5(gbapkm,pkm);
				}
				//}
				//}
			}
		}
	}
	closedb();
	cout << "\nEND\n";
	string test;
	//cin >> test;
	return 0;
}
