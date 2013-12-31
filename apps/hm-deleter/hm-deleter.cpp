#include "hm-deleter.h"
using namespace std;
bw2sav_obj * sav;
party_pkm * ppkm;
pokemon_obj * pkm;
bool isbw2;
int main(int argc, char* argv[])
{
	for(int i = 0; i < argc; i++)
	{
		try
		{
			deleteHMs(argv[i]);
		}
		catch(...){}
	}
	return 0;
}
void deleteHMs(const char * filename)
{
	sav = new bw2sav_obj;
	ppkm = new party_pkm;
	pkm = new pokemon_obj;
	read(filename,sav);
	isbw2 = savisbw2(sav);
	vector<string> ribbonnames;
	for(int slot = 0; slot < sav->cur.party.size; slot++)
	{
		ppkm = &(sav->cur.party.pokemon[slot]);
		pkm = reinterpret_cast<pokemon_obj*>(ppkm->pkm_data);
		decryptpkm(ppkm);
		if(pkm->species != Species::NOTHING)
		{
			for(int move = 3; move >= 0; move--)
			{
				if(
					(pkm->moves[move] == Moves::cut) | 
					(pkm->moves[move] == Moves::fly) | 
					(pkm->moves[move] == Moves::surf) | 
					(pkm->moves[move] == Moves::strength) | 
					(pkm->moves[move] == Moves::waterfall) | 
					(pkm->moves[move] == Moves::dive)
					)
				{
					deletemove(pkm->moves,byte(move));
				}
			}
			if(pkm->moves[0] == Moves::NOTHING)
			{
				pkm->moves[0] = Moves::return_;
			}
		}
		calcchecksum(pkm);
		encryptpkm(ppkm);
	}
	calcpartychecksum(&(sav->cur),isbw2);
	for(int box = 0; box < 24; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			pkm = &(sav->cur.boxes[box].pokemon[slot]);
			decryptpkm(pkm);
			if(pkm->species != Species::NOTHING)
			{
				for(int move = 3; move >= 0; move--)
				{
					if(
						(pkm->moves[move] == Moves::cut) | 
						(pkm->moves[move] == Moves::fly) | 
						(pkm->moves[move] == Moves::surf) | 
						(pkm->moves[move] == Moves::strength) | 
						(pkm->moves[move] == Moves::waterfall) | 
						(pkm->moves[move] == Moves::dive)
						)
					{
						deletemove(pkm->moves,byte(move));
					}
				}
				if(pkm->moves[0] == Moves::NOTHING)
				{
					pkm->moves[0] = Moves::return_;
				}
			}
			calcchecksum(pkm);
			encryptpkm(pkm);
		}
		calcboxchecksum(&(sav->cur),box,isbw2);
	}
	fixsavchecksum(sav,isbw2);
	write("OUT.sav",sav);
}
