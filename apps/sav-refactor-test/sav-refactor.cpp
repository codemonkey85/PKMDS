#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_g5_sqlite.h"
#endif
using namespace std;
void print_item_name(item_obj item);
int main(int argc, char* argv[])
{
	//string savefile;
	// Either you can name your in file manually
	const char * filename = "C:\\Users\\michaelbond\\Documents\\GitHub\\PKMDS\\Test Sav\\TEST SAV.sav";//"IN.sav";
	// Or you can drag and drop your in file onto the .exe
	//savefile = argv[1];
	// Name your out file
	string saveout = "OUT.sav";
	// Declare your SAV and PKM pointers
	//bw2sav_obj* sav = new bw2sav_obj;
	sav_object * sav = new sav_object;
	party_pkm * ppkm = new party_pkm;
	pokemon_obj* pkm = new pokemon_obj;
	//item_obj * item = new item_obj;
	// Read your SAV object from the file
	read(filename,sav);
	sav->sav_type = SAV_TYPES::BW2;
	sav->setdata();
	// Open your database file
	opendb("C:\\Users\\michaelbond\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite");
	//// Iterate through the members of your Pokemon party
	//for(unsigned int i = 0; i < sav->cur.party.size; i++)
	//{
	//	// Set your PKM pointer to the current party member
	//	pkm = &(sav->cur.party.pokemon[i].pkm_data);
	//	// Decrypt the party member
	//	decryptpkm(pkm);
	//	// Do stuff with PKM, which is now the party Pokemon at party slot [SLOT + 1]
	//	pkm->species = Species::psyduck;
	//	// Recalculate the party data of the current party member
	//	pctoparty(&(sav->cur.party.pokemon[i]),pkm);
	//	// Encrypt the current party member
	//	encryptpkm(&(sav->cur.party.pokemon[i]));
	//}
	//// Fix the party block checksum
	//calcpartychecksum(&(sav->cur));
	// Iterate through each PC storage box and slot
	//for(int box = 0; box < sav->pc_storage_size; box++)
	//{
	//	for(int slot = 0; slot < 30; slot++)
	//	{
	//		// Set your PKM pointer to the current stored Pokemon
	//		pkm = &(sav->pc_storage[box].pokemon[slot]);
	//		// Decrypt the stored Pokemon
	//		decryptpkm(pkm);
	//		// Determine whether or not this is an empty slot
	//		if(int(pkm->species) != 0)
	//		{
	//			// Do stuff with PKM, which now points to the Pokemon at box [BOX + 1] and slot [SLOT + 1]
	//			//pkm->species = Species::psyduck;
	//			cout << lookuppkmname(pkm) << "\n";
	//		}
	//		// Encrypt the current stored Pokemon
	//		encryptpkm(pkm);
	//	}
	//	// Fix the checksum of the current box
	//	//calcboxchecksum(&(sav->cur),box,savisbw2(sav));
	//}
	cout << "Items:\n";
	for_each(sav->bag->items_pocket.begin(),sav->bag->items_pocket.end(),print_item_name);
	cout << "\nMedicine:\n";
	for_each(sav->bag->medicine_pocket.begin(),sav->bag->medicine_pocket.end(),print_item_name);
	cout << "\nMachines:\n";
	for_each(sav->bag->tms_pocket.begin(),sav->bag->tms_pocket.end(),print_item_name);
	cout << "\nBerries:\n";
	for_each(sav->bag->berries_pocket.begin(),sav->bag->berries_pocket.end(),print_item_name);
	cout << "\nKey Items:\n";
	for_each(sav->bag->keyitems_pocket.begin(),sav->bag->keyitems_pocket.end(),print_item_name);
	// Close the database file
	closedb();
	// Fix the save file checksums
	//fixsavchecksum(sav);
	// Write the save file to the disk
	//write(saveout.c_str(),sav);
	// Clean up your pointers
	delete sav;
	sav = 0;
	ppkm = 0;
	pkm = 0;
	//item = 0;
	string test = "";
	getline(cin,test);
	// Exit the program and return 0
	return 0;
}
void print_item_name(item_obj item)
{
	if(item.id != Items::NOTHING)
	{
		if((((int)(item.id) >= (int)Items::tm01) & ((int)(item.id) <= (int)Items::tm92)) |
			(((int)(item.id) >= (int)Items::tm93) & ((int)(item.id) <= (int)Items::tm95)) |
			(((int)(item.id) >= (int)Items::hm01) & ((int)(item.id) <= (int)Items::hm06)))
		{
			cout << lookupitemname((int)(item.id)) << " (" << getmachinemovename(Items::items((int)(item.id))) + ") X " << item.quantity << "\n";
		}
		else
		{
			cout << lookupitemname((int)(item.id)) << " X " << item.quantity << "\n";
		}
	}
}
//#include <iostream>
//using namespace std;
//sav_object * sav = new sav_object;
//pokemon_obj * pkm = new pokemon_obj;
//int main()
//{
//	const char * filename = "C:\\Users\\michaelbond\\Documents\\GitHub\\PKMDS\\Test Sav\\TEST SAV.sav";
//	read(filename, sav);
//	sav->sav_type = SAV_TYPES::BW2;
//	sav->setdata();
//	pkm = &(sav->pc_storage[0].pokemon[0]);
//	decryptpkm(pkm);
//	pkm->species = Species::abra;
//	cout << (int)(sav->pc_storage[0].pokemon[0].species);
//	string test;
//	cin >> test;
//}
