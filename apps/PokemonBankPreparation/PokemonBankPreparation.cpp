#include "../../include/pkmds/pkmds_g5.h"
void fixpkm(pokemon_obj * pkm);
using namespace std;
int main(int argc, char* argv[])
{
	bw2sav_obj * sav = new bw2sav_obj();
	party_pkm * ppkm = new party_pkm();
	pokemon_obj * pkm = new pokemon_obj();
	bool savread = false;
#ifdef _DEBUG
	read("IN.sav",sav);
	savread = true;
#else
	if(argc > 1)
	{
		read(argv[1],sav);
		savread = true;
	}
#endif
	if(savread)
	{
		bool isbw2 = savisbw2(sav);
		for(int pslot = 0; pslot < sav->cur.party.size; pslot++)
		{
			ppkm = &(sav->cur.party.pokemon[pslot]);
			decryptpkm(ppkm);
			pkm = &(ppkm->pkm_data);
			fixpkm(pkm);
			encryptpkm(ppkm);
		}
		for(int box = 0; box < 24; box++)
		{
			for(int slot = 0; slot < 30; slot++)
			{
				pkm = &(sav->cur.boxes[box].pokemon[slot]);
				decryptpkm(pkm);
				fixpkm(pkm);
				encryptpkm(pkm);
			}
			calcboxchecksum(&(sav->cur),box,isbw2);
		}
		calcpartychecksum(&(sav->cur),isbw2);
		fixsavchecksum(sav,isbw2);
		write("OUT.sav",sav);
	}
}
void fixpkm(pokemon_obj * pkm)
{
	if(pkm->species != Species::NOTHING)
	{
		deletehms(pkm);
	}
}
