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
	//const char * pkmfile = "C:\\Users\\michaelbond\\Dropbox\\ShinyJirachiWSHMKR.3gpkm";
	savefile = "C:\\Users\\michaelbond\\Dropbox\\Saves\\Pokemon - Fire Red GBA_MODIFIED.sav";
	gbasavefilepacked* savin = new gbasavefilepacked();
	gbasavefile* sav = new gbasavefile();
	//gbasavehalf_unscrambled * unscrambled = new gbasavehalf_unscrambled();
	pokemon_gen3* pkm = new pokemon_gen3();
	read(savefile.c_str(),savin);

	buildgbasave(savin,sav);

	//gbasaveblockpacked * block = new gbasaveblockpacked();

	//cout << "Section A\n";
	//for(int i = 0; i < 16; i++)
	//{
	//	cout << "sectionid " << int(sav->savea.blocks[i].footer.sectionid) << ", saveindex " << int(sav->savea.blocks[i].footer.saveindex) << "\n";
	//	block = &(sav->savea.blocks[i]);
	//}
	//cout << "\n\nSection B\n";
	//for(int i = 0; i < 16; i++)
	//{
	//	cout << "sectionid " << int(sav->saveb.blocks[i].footer.sectionid) << ", saveindex " << int(sav->saveb.blocks[i].footer.saveindex) << "\n";
	//	block = &(sav->saveb.blocks[i]);
	//}
	//cout << "\n\n";

	////sortsavefile(sav);
	////unscrambled = reinterpret_cast<gbasavehalf_unscrambled*>(&(sav->savefilea.blocks[5]));

	//cout << "Size of gbasavefooter: " << std::dec << sizeof(gbasavefooter) << " (0x" << std::hex << sizeof(gbasavefooter) << ")\n"; // << " (should be )\n";
	//cout << "Size of gbasaveblockpacked: " << std::dec << sizeof(gbasaveblockpacked) << " (0x" << std::hex << sizeof(gbasaveblockpacked) << ")\n"; // << " (should be )\n";
	//cout << "Size of gbasavehalfpacked: " << std::dec << sizeof(gbasavehalfpacked) << " (0x" << std::hex << sizeof(gbasavehalfpacked) << ")\n"; // << " (should be )\n";
	//cout << "Size of gbasavefilepacked: " << std::dec << sizeof(gbasavefilepacked) << " (0x" << std::hex << sizeof(gbasavefilepacked) << ")\n"; // << " (should be )\n";
	//cout << "Size of gbapcstorage: " << std::dec << sizeof(gbapcstorage) << " (0x" << std::hex << sizeof(gbapcstorage) << ")\n"; // << " (should be )\n";
	//cout << "Size of gbasavefile: " << std::dec << sizeof(gbasavefile) << " (0x" << std::hex << sizeof(gbasavefile) << ")\n"; // << " (should be )\n";

	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			pkm = &(sav->pcstorage.pcstorage[box][slot]);
			decryptgbapkm(pkm);
			shufflegbapkm(pkm,true);
			//read(pkmfile,pkm);

			if(pkm->data.species != GBASpecies::NOTHING)
			{
				dostuff(pkm, box+1, slot+1);
			}
		}
	}
	string test;
	cin >> test;
	return 0;
}
void dostuff(pokemon_gen3 * pkm, int box, int slot)
{
	//cout << sizeof(pokemon_gen3) << "\n";
	if(pkm->data.species == GBASpecies::rattata)
	{
		cout << "Box " << box << ", Slot " << slot << ": " << int(pkm->data.species) << "\n";
	}
}
