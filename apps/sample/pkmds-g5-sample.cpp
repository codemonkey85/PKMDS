#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_g5_sqlite.h"
#endif
using namespace std;
int main(int argc, char* argv[])
{
	string savefile;
	// Either you can name your in file manually
	savefile = "IN.sav";
	// Or you can drag and drop your in file onto the .exe
	//savefile = argv[1];
	// Name your out file
	string saveout = "OUT.sav";
	// Declare your SAV and PKM pointers
	bw2sav_obj* sav = new bw2sav_obj;
	pokemon_obj* pkm = new pokemon_obj;
	// Read your SAV object from the file
	read(savefile.c_str(),sav);
	// Open your database file
	opendb("veekun-pokedex.sqlite");
	// Iterate through the members of your Pokemon party
	for(unsigned int i = 0; i < sav->cur.party.size; i++)
	{
		// Set your PKM pointer to the current party member
		pkm = &(sav->cur.party.pokemon[i].pkm_data);
		// Decrypt the party member
		decryptpkm(pkm);
		// Do stuff with PKM, which is now the party Pokemon at party slot [SLOT + 1]
		pkm->species = Species::psyduck;
		// Recalculate the party data of the current party member
		pctoparty(&(sav->cur.party.pokemon[i]),pkm);
		// Encrypt the current party member
		encryptpkm(&(sav->cur.party.pokemon[i]));
	}
	// Fix the party block checksum
	calcpartychecksum(&(sav->cur));
	// Iterate through each PC storage box and slot
	for(int box = 0; box < 24; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			// Set your PKM pointer to the current stored Pokemon
			pkm = &(sav->cur.boxes[box].pokemon[slot]);
			// Decrypt the stored Pokemon
			decryptpkm(pkm);
			// Determine whether or not this is an empty slot
			if(int(pkm->species) != 0)
			{
				// Do stuff with PKM, which now points to the Pokemon at box [BOX + 1] and slot [SLOT + 1]
				pkm->species = Species::psyduck;
			}
			// Encrypt the current stored Pokemon
			encryptpkm(pkm);
		}
		// Fix the checksum of the current box
		calcboxchecksum(&(sav->cur),box,savisbw2(sav));
	}
	// Close the database file
	closedb();
	// Fix the save file checksums
	fixsavchecksum(sav);
	// Write the save file to the disk
	write(saveout.c_str(),sav);
	// Clean up your pointers
	delete sav;
	sav = 0;
	pkm = 0;
	// Exit the program and return 0
	return 0;
}
