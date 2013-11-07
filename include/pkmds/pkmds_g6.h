#include "../../include/pkmds/pkmds_g5.h"
// http://projectpokemon.org/wiki/Pokemon_X/Y_3DS_Structure
//Unencrypted Data
struct pkxunencryptblock { // The unencrypted block of the Pokemon data, featuring such important things as the PID and checksum.
	uint32 key; // Used for encryption / decryption.
	uint16 ispartydatadecrypted : 1;
	uint16 isboxdatadecrypted : 1;
	uint16 isspeciesegg : 1;
uint16 : 13;
	uint16 checksum; // The checksum for the Pokemon data; used to validate data.
	pkxunencryptblock()
	{
		memset(this,0,sizeof(pkxunencryptblock));
	}
};
struct pkxblocka { //
	Species::pkmspecies species;
	Items::items item;
	uint16 tid;
	uint16 sid;
	uint32 exp;
	Abilities::abilities ability;
	byte abilitynum;
uint16 : 16;
	uint32 pid;
	Natures::natures nature;
	formsfield forms;
	evsfield evs;
uint32 : 32;
	byte unknown[3];
	pokerus pkrs;
uint32 : 32;
	uint32 kalosribbons;
	byte unknown2[12];
	pkxblocka()
	{
		memset(this,0,sizeof(pkxblocka));
	}
};
struct pkxblockb { //
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
	char nickname[24];
#else
	wchar_t nickname[12];
#endif
#endif
uint16 : 16;
	Moves::moves moves[4];
	byte pp[4];
	byte ppups[4];
	Moves::moves eggmoves[4];
uint16 : 16;
	ivsfield ivs;
	pkxblockb()
	{
		memset(this,0,sizeof(pkxblockb));
	}
};
struct pkxblockc { //
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
	char otname_to[24];
#else
	wchar_t otname_to[12];
#endif
#endif
	byte unknown[32];
	pkxblockc()
	{
		memset(this,0,sizeof(pkxblockc));
	}
};
struct pkxblockd { // 
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
	char otname[24];
#else
	wchar_t otname[12];
#endif
#endif
	byte unknown[9]; // Unknown / unused
	datefield eggdate;
	datefield metdate;
byte : 8; // Unknown / unused
	Locations::locations eggmet;
	Locations::locations met;
	Balls::balls ball;
	metlevelfield metlevel_otgender;
byte : 8; // Unknown / unused
	Hometowns::hometowns hometown;
	Countries::countries country;
	byte regionid;
	byte regionid3ds;
	byte otlang;
uint32 : 32; // Unknown / unused
	pkxblockd()
	{
		memset(this,0,sizeof(pkxblockd));
	}
};
struct pokemonx_obj : pkxunencryptblock,pkxblocka,pkxblockb,pkxblockc,pkxblockd { // The Pokemon object, containing 232 bytes of data (as stored in the PC storage system)
	pokemonx_obj()
	{
		memset(this,0,sizeof(pokemonx_obj));
	}
};
struct partyx_field { // Size: 
	status_field status;
byte : 8;
uint16 : 16;
	byte level;
uint16 : 16;
byte : 8;
	uint16 hp;
	uint16 maxhp;
	uint16 attack;
	uint16 defense;
	uint16 speed;
	uint16 spatk;
	uint16 spdef;
uint16 : 16;
uint32 : 32;
	partyx_field()
	{
		memset(this,0,sizeof(partyx_field));
	}
};
struct party_pkx { // Size: 
	pokemonx_obj pkx_data;
	partyx_field partyx_data;
	party_pkx()
	{
		memset(this,0,sizeof(party_pkx));
	}
};
void DllExport pkmcrypt(partyx_field* pkx, uint32 pid);
void DllExport encryptpkm(party_pkx* pkx);
void DllExport decryptpkm(party_pkx* pkx);
byte DllExport getpkmshuffleindex(const pokemonx_obj *pkx);
void DllExport unshufflepkm(pokemonx_obj *pkx);
void DllExport shufflepkm(pokemonx_obj *pkx);
void DllExport pkmcrypt(pokemonx_obj* pkx);
void DllExport encryptpkm(pokemonx_obj* pkx);
void DllExport decryptpkm(pokemonx_obj* pkx);
void DllExport calcchecksum(pokemonx_obj* pkx);
void DllExport read(const char* file_name, pokemonx_obj *data);
void DllExport read(const wchar_t * file_name, pokemonx_obj *data);
void DllExport write(const char* file_name, pokemonx_obj* data);
void DllExport write(const wchar_t * file_name, pokemonx_obj* data);
bool DllExport getpkmshiny(const pokemonx_obj *pkx);
