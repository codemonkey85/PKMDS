#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_vector.h>
#else
#include "../../PKMDS/include/pkmds/pkmds_vector.h"
#endif
#ifndef __cplusplus_cli
bool comparebyspeciesasc(const pokemon_obj &a, const pokemon_obj &b)
{
	return a.species < b.species;
}
void sortbyspeciesasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebyspeciesasc);
}
bool comparebygenderasc(const pokemon_obj &a, const pokemon_obj &b)
{
    return (int)(calcpkmgender(a)) < (int)(calcpkmgender(b));
}
void sortbygenderasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebygenderasc);
}
bool comparebyformasc(const pokemon_obj &a, const pokemon_obj &b)
{
	return a.form_int < b.form_int;
}
void sortbyformasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebyformasc);
}
bool comparebyattackasc(const pokemon_obj &a, const pokemon_obj &b)
{
	return getpkmstat(a,Stat_IDs::attack) < getpkmstat(b,Stat_IDs::attack);
}
void sortbyattackasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebyattackasc);
}
bool comparebydefenseasc(const pokemon_obj &a, const pokemon_obj &b)
{
	return getpkmstat(a,Stat_IDs::defense) < getpkmstat(b,Stat_IDs::defense);
}
void sortbydefenseasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebydefenseasc);
}
bool comparebyspeedasc(const pokemon_obj &a, const pokemon_obj &b)
{
	return getpkmstat(a,Stat_IDs::speed) < getpkmstat(b,Stat_IDs::speed);
}
void sortbyspeedasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebyspeedasc);
}
bool comparebyspatkasc(const pokemon_obj &a, const pokemon_obj &b)
{
	return getpkmstat(a,Stat_IDs::spatk) < getpkmstat(b,Stat_IDs::spatk);
}
void sortbyspatkasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebyspatkasc);
}
bool comparebyspdefasc(const pokemon_obj &a, const pokemon_obj &b)
{
	return getpkmstat(a,Stat_IDs::spdef) < getpkmstat(b,Stat_IDs::spdef);
}
void sortbyspdefasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebyspdefasc);
}
bool comparebyhpasc(const pokemon_obj &a, const pokemon_obj &b)
{
	return getpkmstat(a,Stat_IDs::hp) < getpkmstat(b,Stat_IDs::hp);
}
void sortbyhpasc(std::vector<pokemon_obj>& pkm)
{
	std::sort(pkm.begin(), pkm.end(), comparebyhpasc);
}
std::vector<pokemon_obj> *getpcvector(bw2savblock_obj * block, const bool encrypted)
{
	std::vector<pokemon_obj> *vpkm = new std::vector<pokemon_obj>;
	for(int box = 0; box < 24; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			if(encrypted)
			{
				decryptpkm(&(block->boxes[box].pokemon[slot]));
			}
			//if(block->boxes[box].pokemon[slot].blocka.species != 0)
			if(int(block->boxes[box].pokemon[slot].species) != 0)
			{
				vpkm->push_back(block->boxes[box].pokemon[slot]);
			}
			if(encrypted)
			{
				encryptpkm(&(block->boxes[box].pokemon[slot]));
			}
		}
	}
	return vpkm;
}
std::vector<pokemon_obj*> *getpcvectorp(bw2savblock_obj * block, const bool encrypted)
{
	std::vector<pokemon_obj*> *vpkm = new std::vector<pokemon_obj*>;
	for(int box = 0; box < 24; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			if(encrypted)
			{
				decryptpkm(&(block->boxes[box].pokemon[slot]));
			}
			//if(block->boxes[box].pokemon[slot].blocka.species != 0)
			if(int(block->boxes[box].pokemon[slot].species) != 0)
			{
				vpkm->push_back(&(block->boxes[box].pokemon[slot]));
			}
			if(encrypted)
			{
				encryptpkm(&(block->boxes[box].pokemon[slot]));
			}
		}
	}
	return vpkm;
}



bool comparebyspeciesascp(pokemon_obj *a, pokemon_obj *b)
{
	//return a->blocka.species < b->blocka.species;
	return a->species < b->species;
}
void sortbyspeciesascp(std::vector<pokemon_obj*>* pkm)
{
	//std::sort((*pkm).begin(), (*pkm).end(), comparebyspeciesascp);
	std::sort(((*pkm).begin()),((*pkm).end()),comparebyspeciesascp);
	//std::sort((*pkm).begin(), (*pkm).end(), comparebyspeciesascp);
}
bool comparebygenderascp(const pokemon_obj *a, const pokemon_obj *b)
{
    return (int)(calcpkmgender(a)) < (int)(calcpkmgender(b));
}
//void sortbygenderascp(std::vector<pokemon_obj>* pkm)
//{
//	std::sort(pkm->begin(), pkm->end(), comparebygenderascp);
//}
bool comparebyformascp(const pokemon_obj *a, const pokemon_obj *b)
{
	//return a->blockb.forms.form < b->blockb.forms.form;
	return a->form_int < b->form_int;
}
//void sortbyformascp(std::vector<pokemon_obj>* pkm)
//{
//	std::sort(pkm->begin(), pkm->end(), comparebyformascp);
//}
bool comparebyattackascp(const pokemon_obj *a, const pokemon_obj *b)
{
	return getpkmstat(a,Stat_IDs::attack) < getpkmstat(b,Stat_IDs::attack);
}
//void sortbyattackascp(std::vector<pokemon_obj>* pkm)
//{
//	std::sort(pkm->begin(), pkm->end(), comparebyattackascp);
//}
bool comparebydefenseascp(const pokemon_obj *a, const pokemon_obj *b)
{
	return getpkmstat(a,Stat_IDs::defense) < getpkmstat(b,Stat_IDs::defense);
}
//void sortbydefenseascp(std::vector<pokemon_obj>* pkm)
//{
//	std::sort(pkm->begin(), pkm->end(), comparebydefenseascp);
//}
bool comparebyspeedascp(const pokemon_obj *a, const pokemon_obj *b)
{
	return getpkmstat(a,Stat_IDs::speed) < getpkmstat(b,Stat_IDs::speed);
}
//void sortbyspeedascp(std::vector<pokemon_obj>* pkm)
//{
//	std::sort(pkm->begin(), pkm->end(), comparebyspeedascp);
//}
bool comparebyspatkascp(const pokemon_obj *a, const pokemon_obj *b)
{
	return getpkmstat(a,Stat_IDs::spatk) < getpkmstat(b,Stat_IDs::spatk);
}
//void sortbyspatkascp(std::vector<pokemon_obj>* pkm)
//{
//	std::sort(pkm->begin(), pkm->end(), comparebyspatkascp);
//}
bool comparebyspdefascp(const pokemon_obj *a, const pokemon_obj *b)
{
	return getpkmstat(a,Stat_IDs::spdef) < getpkmstat(b,Stat_IDs::spdef);
}
//void sortbyspdefascp(std::vector<pokemon_obj>* pkm)
//{
//	std::sort(pkm->begin(), pkm->end(), comparebyspdefascp);
//}
bool comparebyhpascp(const pokemon_obj *a, const pokemon_obj *b)
{
	return getpkmstat(a,Stat_IDs::hp) < getpkmstat(b,Stat_IDs::hp);
}
//void sortbyhpascp(std::vector<pokemon_obj>* pkm)
//{
//	std::sort(pkm->begin(), pkm->end(), comparebyhpascp);
//}
bool comparebyitemidasc(const item_obj & a, const item_obj & b)
{
	return a.id < b.id;
}
bool comparebyitemiddesc(const item_obj & a, const item_obj & b)
{
	return a.id > b.id;
}
void sortbyitemidasc(std::array<item_obj,310> &items)
{
	std::sort(items.begin(), items.end(), comparebyitemidasc);
}
void sortbyitemiddesc(std::array<item_obj,310> &items)
{
	std::sort(items.begin(), items.end(), comparebyitemiddesc);
}
#endif
