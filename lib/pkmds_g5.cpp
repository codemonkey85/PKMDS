#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5.h>
#else
#include "../../PKMDS/include/pkmds/pkmds_g5.h"
#endif
int balltoitem(int ball)
{
	int item = 0;
	switch ((Balls::balls)ball)
	{
	case Balls::pokeball:
		item = (int)Items::pokeball;
		break;
	case Balls::pokeball_:
		item = (int)Items::pokeball;
		break;
	case Balls::cherishball:
		item = (int)Items::cherishball;
		break;
	case Balls::diveball:
		item = (int)Items::diveball;
		break;
	case Balls::dreamball:
		item = (int)Items::dreamball;
		break;
	case Balls::duskball:
		item = (int)Items::duskball;
		break;
	case Balls::fastball:
		item = (int)Items::fastball;
		break;
	case Balls::friendball:
		item = (int)Items::friendball;
		break;
	case Balls::greatball:
		item = (int)Items::greatball;
		break;
	case Balls::healball:
		item = (int)Items::healball;
		break;
	case Balls::heavyball:
		item = (int)Items::heavyball;
		break;
	case Balls::levelball:
		item = (int)Items::levelball;
		break;
	case Balls::loveball:
		item = (int)Items::loveball;
		break;
	case Balls::lureball:
		item = (int)Items::lureball;
		break;
	case Balls::luxuryball:
		item = (int)Items::luxuryball;
		break;
	case Balls::masterball:
		item = (int)Items::masterball;
		break;
	case Balls::moonball:
		item = (int)Items::moonball;
		break;
	case Balls::nestball:
		item = (int)Items::nestball;
		break;
	case Balls::netball:
		item = (int)Items::netball;
		break;
	case Balls::premierball:
		item = (int)Items::premierball;
		break;
	case Balls::quickball:
		item = (int)Items::quickball;
		break;
	case Balls::repeatball:
		item = (int)Items::repeatball;
		break;
	case Balls::safariball:
		item = (int)Items::safariball;
		break;
	case Balls::sportball:
		item = (int)Items::sportball;
		break;
	case Balls::timerball:
		item = (int)Items::timerball;
		break;
	case Balls::ultraball:
		item = (int)Items::ultraball;
		break;
	default:
		item = (int)Items::pokeball;
		break;
	}
	return item;
}
const byte t_shuffle[24][4] = {
	{ 0, 1, 2, 3 }, { 0, 1, 3, 2 }, { 0, 2, 1, 3 }, { 0, 2, 3, 1 },
	{ 0, 3, 1, 2 }, { 0, 3, 2, 1 }, { 1, 0, 2, 3 }, { 1, 0, 3, 2 },
	{ 1, 2, 0, 3 }, { 1, 2, 3, 0 }, { 1, 3, 0, 2 }, { 1, 3, 2, 0 },
	{ 2, 0, 1, 3 }, { 2, 0, 3, 1 }, { 2, 1, 0, 3 }, { 2, 1, 3, 0 },
	{ 2, 3, 0, 1 }, { 2, 3, 1, 0 }, { 3, 0, 1, 2 }, { 3, 0, 2, 1 },
	{ 3, 1, 0, 2 }, { 3, 1, 2, 0 }, { 3, 2, 0, 1 }, { 3, 2, 1, 0 }
};
void shuffle(pokemon_obj * pkm, bool un)
{
	byte * raw = pkm->_raw_data_u8; // reinterpret_cast<byte*>(pkm);
	byte temp[128];
	byte mode = (((((uint32*)raw)[0] >> 0xD) & 0x1F) % 24);

	if (un)
	{
		memcpy(&(temp[t_shuffle[mode][0] * 32]), &raw[8 + 0 * 32], 32);
		memcpy(&(temp[t_shuffle[mode][1] * 32]), &raw[8 + 1 * 32], 32);
		memcpy(&(temp[t_shuffle[mode][2] * 32]), &raw[8 + 2 * 32], 32);
		memcpy(&(temp[t_shuffle[mode][3] * 32]), &raw[8 + 3 * 32], 32);
	}
	else
	{
		memcpy(&(temp[0 * 32]), &raw[8 + t_shuffle[mode][0] * 32], 32);
		memcpy(&(temp[1 * 32]), &raw[8 + t_shuffle[mode][1] * 32], 32);
		memcpy(&(temp[2 * 32]), &raw[8 + t_shuffle[mode][2] * 32], 32);
		memcpy(&(temp[3 * 32]), &raw[8 + t_shuffle[mode][3] * 32], 32);
	}
	memcpy(&raw[8], &temp, 128);
}
void shuffle(pokemon_obj & pkm, bool un)
{
	byte * raw = pkm._raw_data_u8; // reinterpret_cast<byte*>(&pkm);
	byte temp[128];
	byte mode = (((((uint32*)raw)[0] >> 0xD) & 0x1F) % 24);

	if (un)
	{
		memcpy(&(temp[t_shuffle[mode][0] * 32]), &raw[8 + 0 * 32], 32);
		memcpy(&(temp[t_shuffle[mode][1] * 32]), &raw[8 + 1 * 32], 32);
		memcpy(&(temp[t_shuffle[mode][2] * 32]), &raw[8 + 2 * 32], 32);
		memcpy(&(temp[t_shuffle[mode][3] * 32]), &raw[8 + 3 * 32], 32);
	}
	else
	{
		memcpy(&(temp[0 * 32]), &raw[8 + t_shuffle[mode][0] * 32], 32);
		memcpy(&(temp[1 * 32]), &raw[8 + t_shuffle[mode][1] * 32], 32);
		memcpy(&(temp[2 * 32]), &raw[8 + t_shuffle[mode][2] * 32], 32);
		memcpy(&(temp[3 * 32]), &raw[8 + t_shuffle[mode][3] * 32], 32);
	}
	memcpy(&raw[8], &temp, 128);
}
void unshufflepkm(pokemon_obj *pkm)
{
	shuffle(pkm, true);
}
void shufflepkm(pokemon_obj *pkm)
{
	shuffle(pkm, false);
}
void unshufflepkm(pokemon_obj &pkm)
{
	shuffle(pkm, true);
}
void shufflepkm(pokemon_obj &pkm)
{
	shuffle(pkm, false);
}
void pkmcrypt(pokemon_obj& pkm)
{
	pkmprng prng;
	prng.mseed = pkm.checksum;
	uint16 * words = pkm._raw_data_u16; // reinterpret_cast<uint16*>(&pkm);
	for (int i = 4; i < 68; i++)
	{
		words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
	}
}
void pkmcrypt(party_field& pkm, uint32 pid)
{
	pkmprng prng;
	prng.mseed = pid;
	uint16 * words = reinterpret_cast<uint16*>(&pkm);
	for (int i = 0x0; i < 0x2a; i++)
	{
		words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
	}
}
void pkmcrypt(party_field* pkm, uint32 pid)
{
	pkmprng prng;
	prng.mseed = pid;
	uint16 * words = reinterpret_cast<uint16*>(pkm);
	for (int i = 0x0; i < 0x2a; i++)
	{
		words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
	}
}
void encryptpkm(pokemon_obj& pkm)
{
	shufflepkm(pkm);
	pkmcrypt(pkm);
	pkm.ispartydatadecrypted = false;
	pkm.isboxdatadecrypted = false;
}
void decryptpkm(pokemon_obj& pkm)
{
	pkmcrypt(pkm);
	unshufflepkm(pkm);
	pkm.ispartydatadecrypted = true;
	pkm.isboxdatadecrypted = true;
}
void decryptpartypkm_it(party_pkm & pkm)
{
	decryptpkm(pkm);
}
void decryptpkm_it(pokemon_obj & pkm)
{
	decryptpkm(pkm);
}
void encryptpartypkm_it(party_pkm & pkm)
{
	encryptpkm(pkm);
}
void encryptpkm_it(pokemon_obj & pkm)
{
	encryptpkm(pkm);
}
void encryptpkm(party_pkm& pkm)
{
	shufflepkm(&pkm);
	pkmcrypt(&pkm);
	pkmcrypt(pkm.party_data, pkm.pid);
	pkm.ispartydatadecrypted = false;
	pkm.isboxdatadecrypted = false;
}
void decryptpkm(party_pkm& pkm)
{
	pkmcrypt(&pkm);
	pkmcrypt(pkm.party_data, pkm.pid);
	unshufflepkm(&pkm);
	pkm.ispartydatadecrypted = true;
	pkm.isboxdatadecrypted = true;
}
void encryptpkm(party_pkm* pkm)
{
	shufflepkm(pkm);
	pkmcrypt(pkm);
	pkmcrypt(pkm->party_data, pkm->pid);
	pkm->ispartydatadecrypted = false;
	pkm->isboxdatadecrypted = false;
}
void decryptpkm(party_pkm* pkm)
{
	pkmcrypt(pkm);
	pkmcrypt(&(pkm->party_data), pkm->pid);
	unshufflepkm(pkm);
	pkm->ispartydatadecrypted = true;
	pkm->isboxdatadecrypted = true;
}
void pkmcrypt(pokemon_obj* pkm)
{
	pkmprng prng;
	prng.mseed = pkm->checksum;
	uint16 * words = pkm->_raw_data_u16; // reinterpret_cast<uint16*>(pkm);
	for (int i = 4; i < 68; i++)
	{
		words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
	}
}
void encryptpkm(pokemon_obj* pkm)
{
	shufflepkm(pkm);
	pkmcrypt(pkm);
	pkm->ispartydatadecrypted = false;
	pkm->isboxdatadecrypted = false;
}
void decryptpkm(pokemon_obj* pkm)
{
	pkmcrypt(pkm);
	unshufflepkm(pkm);
	pkm->ispartydatadecrypted = true;
	pkm->isboxdatadecrypted = true;
}
uint16 getchecksum(pokemon_obj * pkm)
{
	uint32 chk = 0;
	uint16* p = (uint16*)pkm;
	for (uint16* i = p + 0x04; i < p + 0x43; i++)
	{
		chk += *i;
	}
	chk = chk & 0xffff;
	return uint16(chk);
}
uint16 getchecksum(bw2savblock_obj &block, const int start, const int length){
	byte* data = reinterpret_cast<byte*>(&block);
	int sum = 0xFFFF;
	for (int i = start; i < start + length; i++)
	{
		sum = (sum << 8) ^ SeedTable[(byte)(data[i] ^ (byte)(sum >> 8))];
	}
	return (uint16)sum;
}
void calcpartychecksum(bw2savblock_obj &block, bool bw2)
{
	int start = 0;
	if (bw2)
	{
		start = BW2_OFFSETS::partypkm;
	}
	else
	{
		start = BW_OFFSETS::partypkm;
	}
	uint16 chk = getchecksum(block, start, partysize);
	block.party.checksum = chk;
	byte* data = reinterpret_cast<byte*>(&block);
	if (bw2)
	{
		memcpy(data + (long)BW2_OFFSETS::chkcalcloc + 0x34, &chk, 2);
	}
	else
	{
		memcpy(data + (long)BW_OFFSETS::chkcalcloc + 0x34, &chk, 2);
	}
}
void calcboxchecksum(bw2savblock_obj &block, int boxindex, bool bw2)
{
	int start = (0x400 + (boxindex * 0x1000));
	uint16 chk = getchecksum(block, start, boxsize);
	block.boxes[boxindex].checksum = chk;
	byte* data = reinterpret_cast<byte*>(&block);
	if (bw2)
	{
		memcpy(data + (long)BW2_OFFSETS::chkcalcloc + 2 + (boxindex * 2), &chk, 2);
	}
	else
	{
		memcpy(data + (long)BW_OFFSETS::chkcalcloc + 2 + (boxindex * 2), &chk, 2);
	}
}
void calcchecksum(bw2savblock_obj &block, int start, int length, int loc)
{
	byte* data = reinterpret_cast<byte*>(&block);
	int sum = 0xFFFF;
	for (int i = start; i < start + length; i++)
	{
		sum = (sum << 8) ^ SeedTable[(byte)(data[i] ^ (byte)(sum >> 8))];
	}
	uint16 chk = (uint16)sum;
	memcpy(&*(data + loc), &chk, 2);
}
uint16 getchkfromsav(bw2savblock_obj &block, bool bw2)
{
	byte* data = reinterpret_cast<byte*>(&block);
	uint16 chk;
	if (bw2)
	{
		chk = (data[(long)BW2_OFFSETS::chkloc]) + (data[(long)BW2_OFFSETS::chkloc + 1] * 256);
	}
	else
	{
		chk = (data[(long)BW_OFFSETS::chkloc]) + (data[(long)BW_OFFSETS::chkloc + 1] * 256);
	}
	return chk;
}
void calcchecksum(pokemon_obj& pkm) // Calculates and assigns the checksum for the given Pokemon object.
{
	uint32 chk = 0;
	uint16* p = (uint16*)&pkm;
	for (uint16* i = p + 0x04; i < p + 0x43; i++)
	{
		chk += *i;
	}
	chk = chk & 0xffff;
	pkm.checksum = chk;
}
uint16 getchecksum(bw2savblock_obj *block, const int start, const int length)
{
	byte* data = reinterpret_cast<byte*>(block);
	int sum = 0xFFFF;
	for (int i = start; i < start + length; i++)
	{
		sum = (sum << 8) ^ SeedTable[(byte)(data[i] ^ (byte)(sum >> 8))];
	}
	return (uint16)sum;
}
void calcpartychecksum(bw2savblock_obj *block, bool bw2)
{
	int start = 0;
	if (bw2)
	{
		start = BW2_OFFSETS::partypkm;
	}
	else
	{
		start = BW_OFFSETS::partypkm;
	}
	uint16 chk = getchecksum(block, start, partysize);
	block->party.checksum = chk;
	byte* data = reinterpret_cast<byte*>(block);
	if (bw2)
	{
		memcpy(data + (long)BW2_OFFSETS::chkcalcloc + 0x34, &chk, 2);
	}
	else
	{
		memcpy(data + (long)BW_OFFSETS::chkcalcloc + 0x34, &chk, 2);
	}
}
void calcboxchecksum(bw2savblock_obj *block, int boxindex, bool bw2)
{
	int start = (0x400 + (boxindex * 0x1000));
	uint16 chk = getchecksum(block, start, boxsize);
	block->boxes[boxindex].checksum = chk;
	byte* data = reinterpret_cast<byte*>(block);
	if (bw2)
	{
		memcpy(data + (long)BW2_OFFSETS::chkcalcloc + 2 + (boxindex * 2), &chk, 2);
	}
	else
	{
		memcpy(data + (long)BW_OFFSETS::chkcalcloc + 2 + (boxindex * 2), &chk, 2);
	}
}
void calcchecksum(bw2savblock_obj *block, int start, int length, int loc)
{
	byte* data = reinterpret_cast<byte*>(block);
	int sum = 0xFFFF;
	for (int i = start; i < start + length; i++)
	{
		sum = (sum << 8) ^ SeedTable[(byte)(data[i] ^ (byte)(sum >> 8))];
	}
	uint16 chk = (uint16)sum;
	memcpy(&*(data + loc), &chk, 2);
}
uint16 getchkfromsav(bw2savblock_obj *block, bool bw2)
{
	byte* data = reinterpret_cast<byte*>(block);
	uint16 chk;
	if (bw2)
	{
		chk = (data[(long)BW2_OFFSETS::chkloc]) + (data[(long)BW2_OFFSETS::chkloc + 1] * 256);
	}
	else
	{
		chk = (data[(long)BW_OFFSETS::chkloc]) + (data[(long)BW_OFFSETS::chkloc + 1] * 256);
	}
	return chk;
}
void calcchecksum(pokemon_obj* pkm) // Calculates and assigns the checksum for the given Pokemon object.
{
	uint32 chk = 0;
	uint16* p = (uint16*)pkm;
	for (uint16* i = p + 0x04; i < p + 0x43; i++)
	{
		chk += *i;
	}
	chk = chk & 0xffff;
	pkm->checksum = chk;
}
bool savisbw2(bw2sav_obj &sav)
{
	return (getchecksum(sav.cur, (long)BW2_OFFSETS::chkcalcloc, (long)BW2_OFFSETS::chkcalclen)) == (getchkfromsav(sav.cur, true));
}
bool savisbw2(bw2sav_obj *sav)
{
	return (getchecksum(sav->cur, (long)BW2_OFFSETS::chkcalcloc, (long)BW2_OFFSETS::chkcalclen)) == (getchkfromsav(sav->cur, true));
}
void fixsavchecksum(bw2sav_obj &sav, bool isbw2)
{
	if (isbw2)
	{
		calcchecksum(sav.cur, (long)BW2_OFFSETS::chkcalcloc, (long)BW2_OFFSETS::chkcalclen, (long)BW2_OFFSETS::chkloc);
	}
	else
	{
		calcchecksum(sav.cur, (long)BW_OFFSETS::chkcalcloc, (long)BW_OFFSETS::chkcalclen, (long)BW_OFFSETS::chkloc);
	}
}
void fixsavchecksum(bw2sav_obj *sav, bool isbw2)
{
	if (isbw2)
	{
		calcchecksum(sav->cur, (long)BW2_OFFSETS::chkcalcloc, (long)BW2_OFFSETS::chkcalclen, (long)BW2_OFFSETS::chkloc);
	}
	else
	{
		calcchecksum(sav->cur, (long)BW_OFFSETS::chkcalcloc, (long)BW_OFFSETS::chkcalclen, (long)BW_OFFSETS::chkloc);
	}
}
void fixtrainerdatachecksum(bw2savblock_obj * block)
{
	calcchecksum(block, 0x19400, 0xB0, 0x194B2);
}
void fixbagchecksum(bw2savblock_obj * block)
{
	calcchecksum(block, 0x18400, 0x9EC, 0x18DEE);
}
void write(const char* file_name, pokemon_obj& data) // Writes the given Pokemon data to the given file name.
{
	bool encryptstatus[2] = { data.ispartydatadecrypted, data.isboxdatadecrypted };
	data.ispartydatadecrypted = false;
	data.isboxdatadecrypted = false;
	std::ofstream *out = new std::ofstream(file_name, std::ios::binary);
	out->write(reinterpret_cast<char*>(&data), sizeof(pokemon_obj));
	//out->write(data._raw_data_p, sizeof(pokemon_obj));
	out->close();
	delete out;
	out = 0;
	data.ispartydatadecrypted = encryptstatus[0];
	data.isboxdatadecrypted = encryptstatus[1];
}
void write(const char* file_name, pokemon_obj* data) // Writes the given Pokemon data to the given file name.
{
	bool encryptstatus[2] = { data->ispartydatadecrypted, data->isboxdatadecrypted };
	data->ispartydatadecrypted = false;
	data->isboxdatadecrypted = false;
	std::ofstream *out = new std::ofstream(file_name, std::ios::binary);
	out->write(reinterpret_cast<char*>(data), sizeof(pokemon_obj));
	//out->write(data->_raw_data_p, sizeof(pokemon_obj));
	out->close();
	delete out;
	out = 0;
	data->ispartydatadecrypted = encryptstatus[0];
	data->isboxdatadecrypted = encryptstatus[1];
}
void write(const wchar_t* file_name, pokemon_obj* data) // Writes the given Pokemon data to the given file name.
{
	bool encryptstatus[2] = { data->ispartydatadecrypted, data->isboxdatadecrypted };
	data->ispartydatadecrypted = false;
	data->isboxdatadecrypted = false;
	std::ofstream *out = new std::ofstream(file_name, std::ios::binary);
	out->write(reinterpret_cast<char*>(data), sizeof(pokemon_obj));
	//out->write(data->_raw_data_p, sizeof(pokemon_obj));
	out->close();
	delete out;
	out = 0;
	data->ispartydatadecrypted = encryptstatus[0];
	data->isboxdatadecrypted = encryptstatus[1];
}
void write(const char* file_name, bw2sav_obj& data) //
{
	std::ofstream *out = new std::ofstream(file_name, std::ios::binary);
	out->write(reinterpret_cast<char*>(&data), sizeof(bw2sav_obj));
	out->close();
	delete out;
	out = 0;
}
void write(const char* file_name, bw2sav_obj *data) //
{
	std::ofstream *out = new std::ofstream(file_name, std::ios::binary);
	out->write(reinterpret_cast<char*>(data), sizeof(bw2sav_obj));
	out->close();
	delete out;
	out = 0;
}
void write(const wchar_t* file_name, bw2sav_obj *data) //
{
	std::ofstream *out = new std::ofstream(file_name, std::ios::binary);
	out->write(reinterpret_cast<char*>(data), sizeof(bw2sav_obj));
	out->close();
	delete out;
	out = 0;
}
void read(const char* file_name, pokemon_obj& data) // Reads the given file and assigns the data to the given Pokemon object.
{
	std::ifstream *in = new std::ifstream(file_name, std::ios::binary);
	in->read(reinterpret_cast<char*>(&data), sizeof(pokemon_obj));
	//in->read(data._raw_data_p, sizeof(pokemon_obj));
	in->close();
	delete in;
	in = 0;
}
void read(const char* file_name, pokemon_obj *data) // Reads the given file and assigns the data to the given save file object.
{
	std::ifstream *in = new std::ifstream(file_name, std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(pokemon_obj));
	//in->read(data->_raw_data_p, sizeof(pokemon_obj));
	in->close();
	delete in;
	in = 0;
}
void read(const wchar_t* file_name, pokemon_obj *data) // Reads the given file and assigns the data to the given save file object.
{
	std::ifstream *in = new std::ifstream(file_name, std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(pokemon_obj));
	//in->read(data->_raw_data_p, sizeof(pokemon_obj));
	in->close();
	delete in;
	in = 0;
}
void read(const char* file_name, bw2sav_obj& data) // Reads the given file and assigns the data to the given save file object.
{
	std::ifstream *in = new std::ifstream(file_name, std::ios::binary);
	in->read(reinterpret_cast<char*>(&data), sizeof(bw2sav_obj));
	in->close();
	delete in;
	in = 0;
}
void read(const char* file_name, bw2sav_obj *data) // Reads the given file and assigns the data to the given save file object.
{
	std::ifstream *in = new std::ifstream(file_name, std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(bw2sav_obj));
	in->close();
	delete in;
	in = 0;
}
void read(const wchar_t* file_name, bw2sav_obj *data) // Reads the given file and assigns the data to the given save file object.
{
	std::ifstream *in = new std::ifstream(file_name, std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(bw2sav_obj));
	in->close();
	delete in;
	in = 0;
}
void read(const char* file_name, sav_object *data) // Reads the given file and assigns the data to the given save file object.
{
	std::ifstream *in = new std::ifstream(file_name, std::ios::binary);
	in->read(reinterpret_cast<char*>(&(data->DATA)), sizeof(bw2sav_obj));
	in->close();
	delete in;
	in = 0;
}
std::wstring getpkmnickname(const pokemon_obj &pkm)
{
#if (defined __linux__) || (defined __APPLE__)
	return getwstring((char*)pkm.nickname, 22);
#else
	return getwstring(pkm.nickname);
#endif
}
std::wstring getpkmotname(const pokemon_obj &pkm)
{
#if (defined __linux__) || (defined __APPLE__)
	return getwstring((char*)pkm.otname, 16);
#else
	return getwstring(pkm.otname);
#endif
}
void setpkmnickname(pokemon_obj &pkm, wchar_t input[], int length)
{
	if (length > NICKLENGTH){ length = NICKLENGTH; }
	memset(&(pkm.nickname), '\0', NICKLENGTH * 2);
	memcpy(&(pkm.nickname), input, length * 2);
	if (length < NICKLENGTH)
	{
		memset(&(pkm.nickname[length]), 0xffff, 2);
		memset(&(pkm.nickname[NICKLENGTH - 1]), 0xffff, 2);
	}
}
void setpkmotname(pokemon_obj &pkm, wchar_t input[], int length)
{
	if (length > OTLENGTH){ length = OTLENGTH; }
	memset(&(pkm.otname), '\0', OTLENGTH * 2);
	memcpy(&(pkm.otname), input, length * 2);
	if (length < OTLENGTH)
	{
		memset(&(pkm.otname[length]), 0xffff, 2);
		memset(&(pkm.otname[OTLENGTH - 1]), 0xffff, 2);
	}
}
std::wstring getpkmnickname(const pokemon_obj *pkm)
{
#if (defined __linux__) || (defined __APPLE__)
	return getwstring((char*)pkm->nickname, NICKLENGTH*2);
#else
	return getwstring(pkm->nickname);
#endif
}
std::wstring getpkmotname(const pokemon_obj *pkm)
{
#if (defined __linux__) || (defined __APPLE__)
	return getwstring((char*)pkm->otname, OTLENGTH*2);
#else
	return getwstring(pkm->otname);
#endif
}
void setpkmnickname(pokemon_obj *pkm, wchar_t input[], int length)
{
	if (length > NICKLENGTH){ length = NICKLENGTH; }
	memset(&(pkm->nickname), '\0', NICKLENGTH * 2);
	memcpy(&(pkm->nickname), input, length * 2);
	if (length < NICKLENGTH)
	{
		memset(&(pkm->nickname[length]), 0xffff, 2);
		memset(&(pkm->nickname[NICKLENGTH - 1]), 0xffff, 2);
	}
}
void setpkmotname(pokemon_obj *pkm, wchar_t input[], int length)
{
	if (length > OTLENGTH){ length = OTLENGTH; }
	memset(&(pkm->otname), '\0', OTLENGTH * 2);
	memcpy(&(pkm->otname), input, length * 2);
	if (length < OTLENGTH)
	{
		memset(&(pkm->otname[length]), 0xffff, 2);
		memset(&(pkm->otname[OTLENGTH - 1]), 0xffff, 2);
	}
}
void setsavetrainername(bw2sav_obj *sav, wchar_t input[], int length)
{
	if (length > OTLENGTH){ length = OTLENGTH; }
	memset(&(sav->cur.trainername), '\0', OTLENGTH * 2);
	memcpy(&(sav->cur.trainername), input, length * 2);
	if (length < OTLENGTH)
	{
		memset(&(sav->cur.trainername[length]), 0xffff, 2);
		memset(&(sav->cur.trainername[OTLENGTH - 1]), 0xffff, 2);
	}
}
void setsaveboxname(bw2sav_obj *sav, int box, wchar_t input[], int length)
{
	if (length > BOXNAMELENGTH){ length = BOXNAMELENGTH; }
	memset(&(sav->cur.boxnames[box]), '\0', BOXNAMELENGTH * 2);
	memcpy(&(sav->cur.boxnames[box]), input, length * 2);
	if (length < BOXNAMELENGTH)
	{
		memset(&(sav->cur.boxnames[box][length]), 0xffff, 2);
		memset(&(sav->cur.boxnames[box][BOXNAMELENGTH - 1]), 0xffff, 2);
	}
}
Genders::genders getpkmgender(const pokemon_obj &pkm)
{
	if (pkm.female){ return Genders::female; };
	if (pkm.genderless){ return Genders::genderless; };
	return Genders::male;
}
Genders::genders getpkmgender(const pokemon_obj *pkm)
{
	if (pkm->female){ return Genders::female; };
	if (pkm->genderless){ return Genders::genderless; };
	return Genders::male;
}
void setpkmgender(pokemon_obj &pkm, int gender)
{
	switch (gender)
	{
	case Genders::male:
		pkm.female = false;
		pkm.genderless = false;
		break;
	case Genders::female:
		pkm.female = true;
		pkm.genderless = false;
		break;
	case Genders::genderless:
		pkm.female = false;
		pkm.genderless = true;
		break;
	}
}
bool getpkmshiny(const pokemon_obj &pkm){
	uint32 p1, p2, E, F;
	p1 = (pkm.pid & 0xFFFF0000) >> 16;
	p2 = pkm.pid & 0xFFFF;
	E = pkm.tid ^ pkm.sid;
	F = p1 ^ p2;
	return (E ^ F) < 8;
}
bool pkmmetasegg(const pokemon_obj &pkm)
{
	return ((pkm.eggdate.year != 0) & (pkm.eggdate.month != 0) & (pkm.eggdate.day != 0));
}
void setpkmgender(pokemon_obj *pkm, int gender)
{
	switch (gender)
	{
	case Genders::male:
		pkm->female = false;
		pkm->genderless = false;
		break;
	case Genders::female:
		pkm->female = true;
		pkm->genderless = false;
		break;
	case Genders::genderless:
		pkm->female = false;
		pkm->genderless = true;
		break;
	}
}
bool getpkmshiny(const pokemon_obj *pkm){
	uint32 p1, p2, E, F;

	p1 = (pkm->pid & 0xFFFF0000) >> 16;
	p2 = pkm->pid & 0xFFFF;
	E = pkm->tid ^ pkm->sid;
	F = p1 ^ p2;
	return (E ^ F) < 8;
}
bool pkmmetasegg(const pokemon_obj *pkm){
	return (((bool)(pkm->isegg)) | ((pkm->eggdate.year != 0) & (pkm->eggdate.month != 0) & (pkm->eggdate.day != 0)));
}
void put_pkm(box_obj &box, const int slot, pokemon_obj &pkm, const bool isencrypted)
{
	if (!isencrypted)
	{
		encryptpkm(pkm);
	}
	box.pokemon[slot] = pkm;
}
void swap_pkm(box_obj &frombox, const int fromslot, box_obj &tobox, const int toslot)
{
	std::swap(frombox.pokemon[fromslot], tobox.pokemon[toslot]);
	//pokemon_obj frompkm, topkm;
	//frompkm = frombox.pokemon[fromslot];
	//topkm = tobox.pokemon[toslot];
	//frombox.pokemon[fromslot] = topkm;
	//tobox.pokemon[toslot] = frompkm;
}
void swap_pkm(box_obj *frombox, const int fromslot, box_obj *tobox, const int toslot)
{
	std::swap(frombox->pokemon[fromslot], tobox->pokemon[toslot]);
	//pokemon_obj frompkm, topkm;
	//frompkm = frombox->pokemon[fromslot];
	//topkm = tobox->pokemon[toslot];
	//frombox->pokemon[fromslot] = topkm;
	//tobox->pokemon[toslot] = frompkm;
}
void swap_pkm(party_pkm *a, party_pkm *b)
{
	std::swap(*a, *b);
}
void swap_pkm(pokemon_obj *a, pokemon_obj *b)
{
	std::swap(*a, *b);
}
void swap_pkm(party_pkm *a, pokemon_obj *b)
{
	memset(&(a->party_data), 0, sizeof(party_field));
	pokemon_obj * pkmpa = new pokemon_obj();
	pkmpa = a;
	std::swap(*pkmpa, *b);
}
void swap_pkm(pokemon_obj *a, party_pkm *b)
{
	memset(&(b->party_data), 0, sizeof(party_field));
	pokemon_obj * pkmpb = new pokemon_obj();
	pkmpb = b;
	std::swap(*pkmpb, *a);
}
void swap_pkm(party_pkm &a, party_pkm &b)
{
	std::swap(a, b);
}
void swap_pkm(pokemon_obj &a, pokemon_obj &b)
{
	std::swap(a, b);
}
void swap_pkm(party_pkm &a, pokemon_obj &b)
{
	memset(&(a.party_data), 0, sizeof(party_field));
	pokemon_obj * pkmpa = new pokemon_obj();
	pkmpa = &a;
	std::swap(*pkmpa, b);
}
void swap_pkm(pokemon_obj &a, party_pkm &b)
{
	memset(&(b.party_data), 0, sizeof(party_field));
	pokemon_obj * pkmpb = new pokemon_obj();
	pkmpb = &b;
	std::swap(*pkmpb, a);
}
void put_pkm(box_obj *box, const int slot, pokemon_obj *pkm, const bool isencrypted)
{
	if (!isencrypted)
	{
		encryptpkm(pkm);
	}
	box->pokemon[slot] = *pkm;
}
void remove_pkm(box_obj &box, const int slot)
{
	// TODO: Test blank pkm
	//pokemon_obj blank = {};
	pokemon_obj blank;
	memset(&blank, 0, sizeof(pokemon_obj));
	encryptpkm(blank);
	box.pokemon[slot] = blank;
}
void remove_pkm(box_obj *box, const int slot)
{
	//pokemon_obj blank = {};
	pokemon_obj blank;
	memset(&blank, 0, sizeof(pokemon_obj));
	encryptpkm(blank);
	box->pokemon[slot] = blank;
}
void remove_pkm(bw2savblock_obj * block, const int slot)
{
	std::vector<party_pkm> party(6);
	std::copy(block->party.pokemon.begin(), block->party.pokemon.end(), party.begin());
	party.erase(party.begin() + slot);
	party_pkm * blankpp = new party_pkm;
	std::fill(block->party.pokemon.begin(), block->party.pokemon.end(), (*blankpp));
	std::copy(party.begin(), party.end(), block->party.pokemon.begin());
}
void remove_pkm(bw2sav_obj * sav, const int slot)
{
	std::vector<party_pkm> party(6);
	std::copy(sav->cur.party.pokemon.begin(), sav->cur.party.pokemon.end(), party.begin());
	party.erase(party.begin() + slot);
	party_pkm * blankpp = new party_pkm;
	blankpp->isboxdatadecrypted = true;
	std::fill(sav->cur.party.pokemon.begin(), sav->cur.party.pokemon.end(), (*blankpp));
	for (int i = 0; i < party.size(); i++)
	{
		if (party[i].species == Species::NOTHING)
		{
			party.erase(party.begin() + i);
		}
	}
	std::copy(party.begin(), party.end(), sav->cur.party.pokemon.begin());
}
void remove_pkm(pokemon_obj * pkm, bool encrypt)
{
	pokemon_obj blankpkm;
	*pkm = blankpkm;
	if (encrypt)
	{
		encryptpkm(pkm);
	}
}
void remove_pkm(party_pkm * pkm, bool encrypt)
{
	party_pkm blankpkm;
	*pkm = blankpkm;
	if (encrypt)
	{
		encryptpkm(pkm);
	}
}
void depositpkm(bw2savblock_obj * block, const int party_slot, box_obj * box, const int box_slot)
{
	party_pkm ppkm = block->party.pokemon[party_slot];
	remove_pkm(block, party_slot);
	put_pkm(box, box_slot, &ppkm, !(ppkm.isboxdatadecrypted));
}
pokemon_obj * getpcstorageavailableslot(bw2sav_obj * sav, int & box, int & slot, int startbox)
{
	box = -1;
	slot = -1;
	pokemon_obj * pkm = new pokemon_obj();
	Species::species speciestest = Species::NOTHING;
	int boxcount = 0;
	for (int boxc = startbox; boxcount < 24; boxc++)
	{
		if (boxc == 24)
		{
			boxc = 0;
		}
		for (int slotc = 0; slotc < 30; slotc++)
		{
			pkm = &(sav->cur.boxes[boxc].pokemon[slotc]);
			if (pkm->isboxdatadecrypted == false)
			{
				decryptpkm(pkm);
				speciestest = pkm->species;
				encryptpkm(pkm);
			}
			else
			{
				speciestest = pkm->species;
			}
			if (speciestest == Species::NOTHING)
			{
				box = boxc;
				slot = slotc;
				return pkm;
			}
		}
		boxcount++;
	}
	return pkm;
}
void storepkm(bw2sav_obj * sav, pokemon_obj * pkm, int startbox)
{
	int box = 0;
	int slot = 0;
	pokemon_obj * pcslot = getpcstorageavailableslot(sav, box, slot, startbox);
	if ((box != -1) & (slot != -1))
	{
		*pcslot = *pkm;
	}
}
double getpkmhappiness(const pokemon_obj &pkm)
{
	return pkm.tameness / 255.0;
}
double getpkmhappiness(const pokemon_obj *pkm)
{
	return pkm->tameness / 255.0;
}
int getpkmhatchsteps(const pokemon_obj &pkm)
{
	return (pkm.tameness * 255);
}
int getpkmhatchsteps(const pokemon_obj *pkm)
{
	return (pkm->tameness * 255);
}
std::string getgendername(const int gender)
{
	switch (gender)
	{
	case Genders::male:
		return "Male";
	case Genders::female:
		return "Female";
	case Genders::genderless:
		return "Genderless";
	default:
		return "Male";
	}
}
std::string getpkmotgendername(const pokemon_obj &pkm)
{
	return getgendername(pkm.otgender);
}
int gethiddenpowerpower(const pokemon_obj &pkm)
{
	int power = 0;
	int u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
	if ((pkm.ivs.hp % 4 == 2) | (pkm.ivs.hp % 4 == 3)){ u = 1; }
	if ((pkm.ivs.attack % 4 == 2) | (pkm.ivs.attack % 4 == 3)){ v = 1; }
	if ((pkm.ivs.defense % 4 == 2) | (pkm.ivs.defense % 4 == 3)){ w = 1; }
	if ((pkm.ivs.speed % 4 == 2) | (pkm.ivs.speed % 4 == 3)){ x = 1; }
	if ((pkm.ivs.spatk % 4 == 2) | (pkm.ivs.spatk % 4 == 3)){ y = 1; }
	if ((pkm.ivs.spdef % 4 == 2) | (pkm.ivs.spdef % 4 == 3)){ z = 1; }
	power = (int)(floor((double)(((u + 2 * v + 4 * w + 8 * x + 16 * y + 32 * z) * 40 / 63) + 30)));
	return power;
}
int gethiddenpowertype(const pokemon_obj &pkm)
{
	int type = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	a = (int)(!(pkm.ivs.hp % 2 == 0));
	b = (int)(!(pkm.ivs.attack % 2 == 0));
	c = (int)(!(pkm.ivs.defense % 2 == 0));
	d = (int)(!(pkm.ivs.speed % 2 == 0));
	e = (int)(!(pkm.ivs.spatk % 2 == 0));
	f = (int)(!(pkm.ivs.spdef % 2 == 0));
	type = (int)(floor((double)((a + 2 * b + 4 * c + 8 * d + 16 * e + 32 * f) * 15 / 63)));
	return hiddenpowertypes[type];
}
std::string getpkmotgendername(const pokemon_obj *pkm)
{
	return getgendername(pkm->otgender);
}
int gethiddenpowerpower(const pokemon_obj *pkm)
{
	int power = 0;
	int u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
	if ((pkm->ivs.hp % 4 == 2) | (pkm->ivs.hp % 4 == 3)){ u = 1; }
	if ((pkm->ivs.attack % 4 == 2) | (pkm->ivs.attack % 4 == 3)){ v = 1; }
	if ((pkm->ivs.defense % 4 == 2) | (pkm->ivs.defense % 4 == 3)){ w = 1; }
	if ((pkm->ivs.speed % 4 == 2) | (pkm->ivs.speed % 4 == 3)){ x = 1; }
	if ((pkm->ivs.spatk % 4 == 2) | (pkm->ivs.spatk % 4 == 3)){ y = 1; }
	if ((pkm->ivs.spdef % 4 == 2) | (pkm->ivs.spdef % 4 == 3)){ z = 1; }
	power = (int)(floor((double)(((u + 2 * v + 4 * w + 8 * x + 16 * y + 32 * z) * 40 / 63) + 30)));
	return power;
}
int gethiddenpowertype(const pokemon_obj *pkm)
{
	int type = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	a = (int)(!(pkm->ivs.hp % 2 == 0));
	b = (int)(!(pkm->ivs.attack % 2 == 0));
	c = (int)(!(pkm->ivs.defense % 2 == 0));
	d = (int)(!(pkm->ivs.speed % 2 == 0));
	e = (int)(!(pkm->ivs.spatk % 2 == 0));
	f = (int)(!(pkm->ivs.spdef % 2 == 0));
	type = (int)(floor((double)((a + 2 * b + 4 * c + 8 * d + 16 * e + 32 * f) * 15 / 63)));
	return hiddenpowertypes[type];
}
std::string getballname(const int ball)
{
	return ballnames[ball];
}
std::string getballname(const pokemon_obj &pkm)
{
	return getballname(pkm.ball);
}
std::string getballname(const pokemon_obj *pkm)
{
	return getballname(pkm->ball);
}
std::wstring getboxname(const bw2savblock_obj *block, int boxnum)
{
	std::wstring name;
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
	std::string str_name = block->boxnames[boxnum];
	wchar_t boxname_buffer[11];
	memset(boxname_buffer, 0, 11);
	mbstowcs(boxname_buffer, str_name.c_str(), 11);
#else
	name = block->boxnames[boxnum];
#endif
#endif
	if (name.find((wchar_t)0xffff))
	{
		name = name.substr(0, name.find((wchar_t)0xffff));
	}
	return name;
}
std::wstring getboxname(const bw2savblock_obj &block, int boxnum)
{
	std::wstring name;
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
	std::string str_name = block.boxnames[boxnum];
	wchar_t boxname_buffer[11];
	memset(boxname_buffer, 0, 11);
	mbstowcs(boxname_buffer, str_name.c_str(), 11);
#else
	name = block.boxnames[boxnum];
#endif
#endif

	if (name.find((wchar_t)0xffff))
	{
		name = name.substr(0, name.find((wchar_t)0xffff));
	}
	return name;
}
time_t * advstrttime(const bw2savblock_obj &block)
{
	time_t * ret = new time_t;
	//    *ret = block.adventurestarted + 946684800;
	return ret;
}
time_t * advstrttime(const bw2savblock_obj *block)
{
	time_t * ret = new time_t;
	//    *ret = block->adventurestarted + 946684800;
	return ret;
}
std::string advstrttimestring(const bw2savblock_obj &block)
{
	time_t * adstarttime = new time_t;
	adstarttime = advstrttime(&block);
	tm * ptm = new tm;
#if (defined __linux__) || (defined __APPLE__) || (defined __CYGWIN__)
	ptm = gmtime(adstarttime);
#else
	gmtime_s(ptm, adstarttime);
#endif
	ptm->tm_year += 1900;
	std::ostringstream o;
	o << ptm->tm_year << "/" << ptm->tm_mon << "/" << ptm->tm_mday << " " << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec;
	std::string retval;
	retval = o.str().c_str();
	return retval;
}
std::string advstrttimestring(const bw2savblock_obj *block)
{
	time_t * adstarttime = new time_t;
	adstarttime = advstrttime(block);
	tm * ptm = new tm;
#if (defined __linux__) || (defined __APPLE__) || (defined __CYGWIN__)
	ptm = gmtime(adstarttime);
#else
	gmtime_s(ptm, adstarttime);
#endif
	ptm->tm_year += 1900;
	std::ostringstream o;
	o << ptm->tm_year << "/" << ptm->tm_mon << "/" << ptm->tm_mday << " " << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec;
	std::string retval;
	retval = o.str().c_str();
	return retval;
}
std::wstring getsavtrainername(const bw2savblock_obj & block)
{
#if (defined __linux__) || (defined __APPLE__) || (defined __CYGWIN__)
	return getwstring((char*)block.trainername, 0x10);
#else
	return getwstring(block.trainername);
#endif
}
std::wstring getsavtrainername(const bw2savblock_obj * block)
{
#if (defined __linux__) || (defined __APPLE__) || (defined __CYGWIN__)
	return getwstring((char*)block->trainername, 0x10);
#else
	return getwstring(block->trainername);
#endif
}
std::wstring getwstring(std::wstring in, int maxlength)
{
	std::wstring out = in;
	if (maxlength == 0)
	{
		if (out.find((wchar_t)0xffff))
		{
			out = out.substr(0, out.find((wchar_t)0xffff));
		}
	}
	else
	{
		if (out.find((wchar_t)0xffff))
		{
			if (out.find((wchar_t)0xffff) < maxlength)
			{
				out = out.substr(0, out.find((wchar_t)0xffff));
			}
			else
			{
				out = out.substr(0, maxlength);
			}
		}
	}
	return out;
}
std::wstring getwstring(std::string in)
{
	std::string out = in;
	if (out.find((char)0xffff))
	{
		out = out.substr(0, out.find((char)0xffff));
	}
	std::wstring retval(out.begin(), out.end());
	return retval;
}
std::wstring getwstring(char* in, int len)
{
	unsigned char arr[24]; //Large enough for longest text value stored in game
	memset(arr, '\0', 24);
	memcpy(arr, &in, len);
	for (int i = 0; i < len; i++)
	{
		//        if(arr[i] == 0xFF)
		//        {
		//            break;
		//        }
		//        else
		//        {
		arr[i] = in[2 * i];
		//        }
	}
	std::string out = (char*)arr;
	if (out.find((char)0xffff))
	{
		out = out.substr(0, out.find((char)0xffff));
	}
	std::wstring retval(out.begin(), out.end());
	return retval;
}
Types::types getarceustype(int form)
{
	Types::types arceustypes[] =
	{
		Types::normal,
		Types::fighting,
		Types::flying,
		Types::poison,
		Types::ground,
		Types::rock,
		Types::bug,
		Types::ghost,
		Types::steel,
		Types::fire,
		Types::water,
		Types::grass,
		Types::electric,
		Types::psychic,
		Types::ice,
		Types::dragon,
		Types::dark
	};
	return arceustypes[form];
}
std::string getpkrsstatus(const pokemon_obj * pkm)
{
	std::string status = "";
	if ((pkm->pkrs.days > 0) & (pkm->pkrs.strain > 0))
	{
		status = "Infected";
	}
	if ((pkm->pkrs.days == 0) & (pkm->pkrs.strain > 0))
	{
		status = "Cured";
	}
	return status;
}
std::array<bool, 80> getribbonswitches(const pokemon_obj * pkm)
{
	int ribnum = 0;
	std::array<bool, 80> switches;
	for (int bit = 0; bit < 16; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->sribbon1), 2);
		switches[ribnum] = (getbit(rib, bit) == 1);
		ribnum++;
		//		switches.push_back(getbit(rib,bit) == 1);
	}
	for (int bit = 0; bit < 12; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->uribbon), 2);
		switches[ribnum] = (getbit(rib, bit) == 1);
		ribnum++;
		//		switches.push_back(getbit(rib,bit) == 1);
	}
	for (int bit = 0; bit < 16; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->sribbon3), 2);
		switches[ribnum] = (getbit(rib, bit) == 1);
		ribnum++;
		//		switches.push_back(getbit(rib,bit) == 1);
	}
	for (int bit = 0; bit < 4; bit++)
	{
		byte rib;
		memcpy(&rib, &(pkm->sribbon4), 1);
		switches[ribnum] = (getbit(rib, bit) == 1);
		ribnum++;
		//		switches.push_back(getbit(rib,bit) == 1);
	}
	for (int bit = 0; bit < 16; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->hribbon1), 2);
		switches[ribnum] = (getbit(rib, bit) == 1);
		ribnum++;
		//		switches.push_back(getbit(rib,bit) == 1);
	}
	for (int bit = 0; bit < 16; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->hribbon2), 2);
		switches[ribnum] = (getbit(rib, bit) == 1);
		ribnum++;
		//		switches.push_back(getbit(rib,bit) == 1);
	}
	return switches;
}
std::vector<std::string> getobtainedribbons(const pokemon_obj * pkm)
{
	std::vector<std::string> ribbonnames;
	for (int bit = 0; bit < 16; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->sribbon1), 2);
		if (getbit(rib, bit) == 1)
		{
			ribbonnames.push_back(ribbon_names[bit]);
		}
	}
	for (int bit = 0; bit < 12; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->uribbon), 2);
		if (getbit(rib, bit) == 1)
		{
			ribbonnames.push_back(ribbon_names[bit + 16]);
		}
	}
	for (int bit = 0; bit < 16; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->sribbon3), 2);
		if (getbit(rib, bit) == 1)
		{
			ribbonnames.push_back(ribbon_names[bit + 12]);
		}
	}
	for (int bit = 0; bit < 4; bit++)
	{
		byte rib;
		memcpy(&rib, &(pkm->sribbon4), 1);
		if (getbit(rib, bit) == 1)
		{
			ribbonnames.push_back(ribbon_names[bit + 16]);
		}
	}
	for (int bit = 0; bit < 16; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->hribbon1), 2);
		if (getbit(rib, bit) == 1)
		{
			ribbonnames.push_back(ribbon_names[bit + 4]);
		}
	}
	for (int bit = 0; bit < 16; bit++)
	{
		uint16 rib;
		memcpy(&rib, &(pkm->hribbon2), 2);
		if (getbit(rib, bit) == 1)
		{
			ribbonnames.push_back(ribbon_names[bit + 16]);
		}
	}
	return ribbonnames;
}
void deletemove(pokemon_obj * pkm, byte move)
{
	std::array<Moves::moves, 4> moves = pkm->moves;
	std::vector<Moves::moves> temp(4);
	std::copy(moves.begin(), moves.end(), temp.begin());
	temp.erase(temp.begin() + move);
	std::fill(moves.begin(), moves.end(), Moves::NOTHING);
	std::copy(temp.begin(), temp.end(), moves.begin());
	std::array<byte, 4> move_pp = pkm->pp;
	std::vector<byte> temppp(4);
	std::copy(move_pp.begin(), move_pp.end(), temppp.begin());
	temppp.erase(temppp.begin() + move);
	std::fill(move_pp.begin(), move_pp.end(), 0);
	std::copy(temppp.begin(), temppp.end(), move_pp.begin());
	std::array<byte, 4> move_ppups = pkm->ppup;
	std::vector<byte> tempppups(4);
	std::copy(move_ppups.begin(), move_ppups.end(), tempppups.begin());
	tempppups.erase(tempppups.begin() + move);
	std::fill(move_ppups.begin(), move_ppups.end(), 0);
	std::copy(tempppups.begin(), tempppups.end(), move_ppups.begin());
	for (int i = 0; i < 4; i++)
	{
		if (moves[i] == Moves::NOTHING)
		{
			pkm->pp[i] = 0;
			pkm->ppup[0] = 0;
		}
	}
	pkm->moves = moves;
	pkm->pp = move_pp;
	pkm->ppup = move_ppups;
	if (pkm->species == Species::keldeo)
	{
		for (int i = 0; i < 4; i++)
		{
			if (pkm->moves[i] != Moves::sacredsword)
			{
				pkm->form.keldeo_form = Forms::Keldeo::ordinary;
			}
		}
	}
}
void decryptparty(party_obj & party)
{
	std::for_each(party.pokemon.begin(), party.pokemon.end(), decryptpartypkm_it);
}
void decryptbox(box_obj & box)
{
	std::for_each(box.pokemon.begin(), box.pokemon.end(), decryptpkm_it);
}
void decryptpc(bw2savblock_obj & block)
{
	std::for_each(block.boxes.begin(), block.boxes.end(), decryptbox);
}
void encryptparty(party_obj & party)
{
	std::for_each(party.pokemon.begin(), party.pokemon.end(), encryptpartypkm_it);
}
void encryptbox(box_obj & box)
{
	std::for_each(box.pokemon.begin(), box.pokemon.end(), encryptpkm_it);
}
void encryptpc(bw2savblock_obj & block)
{
	std::for_each(block.boxes.begin(), block.boxes.end(), encryptbox);
}
uint32 getpkmcolorhex(int pkmcolor)
{
	switch (pkmcolor)
	{
	case 1:// 1 = black
		return 0x5A5A5A;
		break;
	case 2:// 2 = blue
		return 0x318CF7;
		break;
	case 3:// 3 = brown
		return 0xB57331;
		break;
	case 4:// 4 = gray
		return 0xA5A5A5;
		break;
	case 5:// 5 = green
		return 0x42BD6B;
		break;
	case 6:// 6 = pink
		return 0xFF94CE;
		break;
	case 7:// 7 = purple
		return 0xAD6BC6;
		break;
	case 8:// 8 = red
		return 0xF75A6B;
		break;
	case 9:// 9 = white
		return 0xF7F7F7;
		break;
	case 10:// 10 = yellow
		return 0xF7D64A;
		break;
	default:
		return 0;
		break;
	}
}
void deletehms(pokemon_obj * pkm)
{
	for (int move = 3; move >= 0; move--)
	{
		if (
			(pkm->moves[move] == Moves::cut) |
			(pkm->moves[move] == Moves::fly) |
			(pkm->moves[move] == Moves::surf) |
			(pkm->moves[move] == Moves::strength) |
			(pkm->moves[move] == Moves::waterfall) |
			(pkm->moves[move] == Moves::dive)
			)
		{
			deletemove(pkm, byte(move));
		}
	}
	if (pkm->moves[0] == Moves::NOTHING)
	{
		pkm->moves[0] = Moves::return_;
	}
}
