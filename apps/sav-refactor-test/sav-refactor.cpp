#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#include <pkmds/pkmds_vector.h>
//#include <pkmds/pkm_report.h>
#else
//#include "..\\..\\include\\pkmds\\pkmds_g5_sqlite.h"
//#include "..\\..\\include\\pkmds\\pkmds_vector.h"
//#include "..\\..\\include\\pkmds\\pkm_report.h"
#include "../../include/pkmds/pkmds_gba.h";
#endif
using namespace std;
//void print_item_name(item_obj item);
//void dostuff(pokemon_obj & pkm);
//ofstream ofile;
int main(int argc, char* argv[])
{
	gbasavefile * sav = new gbasavefile();
	gbapokemon * pkm = new gbapokemon();
	//read("C:\\Users\\michaelbond\\Dropbox\\Saves\\Pokemon - Fire Red GBA.SAV",sav);
	read("C:\\Users\\michaelbond\\Dropbox\\Saves\\pokemon_emerald_version.gsb",sav);
	sortsavefile(sav);
	gbasavehalf_unscrambled * unscrambled_sav = new gbasavehalf_unscrambled();
	unscrambled_sav = reinterpret_cast<gbasavehalf_unscrambled*>(&(sav->savefilea.blocks[5]));
	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			pkm = &(unscrambled_sav->pcstorage[box][slot]);
			decryptgbapkm(pkm);
			shufflegbapkm(pkm,true);
			//if(pkm->encrypted.growth.tameness == 70)
			//{
			//	cout << "stop";
			//}
		}
	}
	pkm = &(unscrambled_sav->pcstorage[0][0]);
	cout << "Checksum before: " << pkm->checksum << "\n";
	calcchecksum(pkm);
	cout << "Checksum after: " << pkm->checksum << "\n";
	//std::ofstream *out = new std::ofstream("C:\\Users\\michaelbond\\Downloads\\TimeMachine\\TEST.3gpkm",std::ios::binary);
	//out->write(reinterpret_cast<char*>(pkm), sizeof(gbapokemon));
	//out->close();
	//delete out;
	//out = 0;
	cout << "stop";
	//const char * filename = "C:\\Users\\michaelbond\\Dropbox\\Saves\\white2.sav";//"IN.sav";
	//string saveout = "OUT.sav";
	//bw2sav_obj* sav = new bw2sav_obj;
	//read(filename,sav);
	//bool isbw2 = savisbw2(sav);
	//decryptparty(sav->cur.party);
	//decryptpc(sav->cur);
	//opendb("C:\\Users\\michaelbond\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite");
	////ofile.open("OUT.txt");
	////ofile << "Pokemon Trainer " << "(" << "" << ")'s Bag\n";
	////ofile << "=============================\nItems\n=============================\n";
	////for_each(sav->cur.bag./*->*/items_pocket.begin(),sav->cur.bag./*->*/items_pocket.end(),print_item_name);
	////ofile << "=============================\nMedicine\n=============================\n";
	////for_each(sav->cur.bag./*->*/medicine_pocket.begin(),sav->cur.bag./*->*/medicine_pocket.end(),print_item_name);
	////ofile << "=============================\nMachines\n=============================\n";
	////for_each(sav->cur.bag./*->*/tms_pocket.begin(),sav->cur.bag./*->*/tms_pocket.end(),print_item_name);
	////ofile << "=============================\nBerries\n=============================\n";
	////for_each(sav->cur.bag./*->*/berries_pocket.begin(),sav->cur.bag./*->*/berries_pocket.end(),print_item_name);
	////ofile << "=============================\nKey Items\n=============================\n";
	////for_each(sav->cur.bag./*->*/keyitems_pocket.begin(),sav->cur.bag./*->*/keyitems_pocket.end(),print_item_name);
	////ofile.close();
	//for(int pslot = 0; pslot < sav->cur.party.size; pslot++)
	//{
	//	if(sav->cur.party.pokemon[pslot].pkm_data.species != Species::NOTHING)
	//	{
	//		dostuff(sav->cur.party.pokemon[pslot].pkm_data);
	//	}
	//}
	//for(int box = 0; box < sav->cur.boxes.size(); box++)
	//{
	//	for(int slot = 0; slot < sav->cur.boxes[box].pokemon.size(); slot++)
	//	{
	//		if(sav->cur.boxes[box].pokemon[slot].species != Species::NOTHING)
	//		{
	//			dostuff(sav->cur.boxes[box].pokemon[slot]);
	//		}
	//	}
	//}
	//calcpartychecksum(&(sav->cur),isbw2);
	//for(int box = 0; box < 24; box++)
	//{
	//	calcboxchecksum(&(sav->cur),box,isbw2);
	//}
	//encryptparty(sav->cur.party);
	//encryptpc(sav->cur);
	//closedb();
	//fixsavchecksum(sav, isbw2);
	//write(saveout.c_str(),sav);
	//delete sav;
	//sav = 0;
	//int test;
	//cin >> test;
	//PokemonColors::pokemoncolors pkmcolor = PokemonColors::yellow;
	//cout << std::hex << getpkmcolorhex(int(pkmcolor)) << "\n";
	//int test;
	//cin >> test;
	return 0;
}
//void print_item_name(item_obj item)
//{
//	if(item.id != Items::NOTHING)
//	{
//		if((((int)(item.id) >= (int)Items::tm01) & ((int)(item.id) <= (int)Items::tm92)) |
//			(((int)(item.id) >= (int)Items::tm93) & ((int)(item.id) <= (int)Items::tm95)) |
//			(((int)(item.id) >= (int)Items::hm01) & ((int)(item.id) <= (int)Items::hm06)))
//		{
//			ofile << lookupitemname((int)(item.id)) << " (" << getmachinemovename(Items::items((int)(item.id))) + ") X " << item.quantity << "\n";
//		}
//		else
//		{
//			ofile << lookupitemname((int)(item.id)) << " X " << item.quantity << "\n";
//		}
//	}
//}
//void dostuff(pokemon_obj & pkm)
//{
//	//pkm.species = Species::psyduck;
//	cout << std::hex << getpkmcolorhex(getpokemoncolor(pkm.species)) << "\n";
//}
