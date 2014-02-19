#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#include <pkmds/pkmds_gba.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_g5_sqlite.h"
#include "..\\..\\include\\pkmds\\pkmds_gba.h"
#endif
using namespace std;
void dostuff(pokemon_gen3 * pkm, int box, int slot);
int main(int argc, char* argv[])
{
	string savefile;
	const char * pkmfile = "C:\\Users\\michaelbond\\Dropbox\\Saves\\Squirtle_FireRed_ENCRYPTED.bin";
	savefile = "C:\\Users\\michaelbond\\Dropbox\\Saves\\Pokemon - Fire Red GBA_MODIFIED.sav";
	gbasavefilepacked* savin = new gbasavefilepacked();
	gbasavefile* sav = new gbasavefile();
	pokemon_gen3* pkm = new pokemon_gen3();
	read(savefile.c_str(),savin);
	buildgbasave(savin,sav);
	//cout << "Size of ppbonuses_struct: " << std::dec << sizeof(ppbonuses_struct) << " (0x" << std::hex << sizeof(ppbonuses_struct) << ")\n"; // << " (should be )\n";
	//cout << "Size of origins_struct: " << std::dec << sizeof(origins_struct) << " (0x" << std::hex << sizeof(origins_struct) << ")\n"; // << " (should be )\n";
	//cout << "Size of ivs_struct: " << std::dec << sizeof(ivs_struct) << " (0x" << std::hex << sizeof(ivs_struct) << ")\n"; // << " (should be )\n";
	//cout << "Size of growth_block: " << std::dec << sizeof(growth_block) << " (0x" << std::hex << sizeof(growth_block) << ")\n"; // << " (should be )\n";
	//cout << "Size of moves_block: " << std::dec << sizeof(moves_block) << " (0x" << std::hex << sizeof(moves_block) << ")\n"; // << " (should be )\n";
	//cout << "Size of evscondition_block: " << std::dec << sizeof(evscondition_block) << " (0x" << std::hex << sizeof(evscondition_block) << ")\n"; // << " (should be )\n";
	//cout << "Size of misc_block: " << std::dec << sizeof(misc_block) << " (0x" << std::hex << sizeof(misc_block) << ")\n"; // << " (should be )\n";
	//cout << "Size of pkmdata: " << std::dec << sizeof(pkmdata) << " (0x" << std::hex << sizeof(pkmdata) << ")\n"; // << " (should be )\n";
	//cout << "Size of pokemon_gen3: " << std::dec << sizeof(pokemon_gen3) << " (0x" << std::hex << sizeof(pokemon_gen3) << ")\n"; // << " (should be )\n";
	opendb("C:\\Users\\michaelbond\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite");
	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			pkm = &(sav->pcstorage.pcstorage[box][slot]);
			decryptgbapkm(pkm);
			shufflegbapkm(pkm,true);
			if(pkm->data.species != GBASpecies::NOTHING)
			{
				dostuff(pkm, box+1, slot+1);
			}
		}
	}
	closedb();
	cout << "\nEND\n";
	string test;
	cin >> test;
	return 0;
}
void dostuff(pokemon_gen3 * pkm, int box, int slot)
{
	cout << "Box " << box << ", Slot " << slot << ": " << lookuppkmname(convertgbaspecies(pkm->data.species)) << "\n";
}
