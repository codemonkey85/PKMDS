#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_gba.h>
#else
#include "../../PKMDS-G5/include/pkmds/pkmds_gba.h"
#endif
void read(const char* file_name, gbasavefile *data)
{
	std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(gbasavefile));
	in->close();
	delete in;
	in = 0;
}
void sortsavefile(gbasavefile * sav)
{
	sortsaveblocks(&(sav->savefilea));
	sortsaveblocks(&(sav->savefileb));
}
void sortsaveblocks(gbasavehalf * savehalf)
{
	std::vector<gbasaveblock*> * theblocks = new std::vector<gbasaveblock*>;
	for(int i = 0; i < 14; i++)
	{
		theblocks->push_back(&(savehalf->blocks[i]));
	}
	sortblocks(theblocks);
	byte * data = new byte[0x14000];
	for(int i = 0; i < 14; i++)
	{
		memcpy(&(data[0x1000*i]),(*theblocks)[i],0x1000);
	}
	memcpy(savehalf,&data,0x14000);
}
bool compareblocks(gbasaveblock *a, gbasaveblock *b)
{
	return a->footer.blockid < b->footer.blockid;
}
void sortblocks(std::vector<gbasaveblock*> * theblocks)
{
	std::sort((*theblocks).begin(),(*theblocks).end(),compareblocks);
}
void decryptgbapkm(gbapokemon * pkm)
{
	uint32 key = (pkm->trainerid  ^ pkm->pid);
	uint32 * pkmpnt = reinterpret_cast<uint32*>(&(pkm->encrypted));
	for(int i = 0; i < 12; i++)
	{
		pkmpnt[i] = (pkmpnt[i] ^ key);
	}
}
const byte t_shuffle[24][4] = {
	{0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1},
	{0,3,1,2}, {0,3,2,1}, {1,0,2,3}, {1,0,3,2},
	{1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
	{2,0,1,3}, {2,0,3,1}, {2,1,0,3}, {2,1,3,0},
	{2,3,0,1}, {2,3,1,0}, {3,0,1,2}, {3,0,2,1},
	{3,1,0,2}, {3,1,2,0}, {3,2,0,1}, {3,2,1,0}
};
void shufflegbapkm(gbapokemon * pkm, bool un)
{
	byte * pkmpnt = reinterpret_cast<byte*>(&(pkm->encrypted));
	byte temp[48];
	byte mode = (((((uint32*) pkmpnt)[0] >> 0xD) & 0x1F) % 24);

	if (un) {
		memcpy(&(temp[t_shuffle[mode][0] * 12]), &pkmpnt[0 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][1] * 12]), &pkmpnt[1 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][2] * 12]), &pkmpnt[2 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][3] * 12]), &pkmpnt[3 * 12], 12);
	} else {
		memcpy(&(temp[0 * 12]), &pkmpnt[t_shuffle[mode][0] * 12], 12);
		memcpy(&(temp[1 * 12]), &pkmpnt[t_shuffle[mode][1] * 12], 12);
		memcpy(&(temp[2 * 12]), &pkmpnt[t_shuffle[mode][2] * 12], 12);
		memcpy(&(temp[3 * 12]), &pkmpnt[t_shuffle[mode][3] * 12], 12);
	}
	memcpy(&pkmpnt, &temp, 48);
}
