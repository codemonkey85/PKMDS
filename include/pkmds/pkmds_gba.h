#pragma once
#ifdef PKMDS_CMAKE_USED
#include <pkmds/stdafx.h>
#else
#include "stdafx.h"
#endif
#include <vector>
struct gbapokemongrowth
{
	uint16 species;
	uint16 item;
	uint32 exp;
	byte ppup;
	byte tameness;
	uint16 unknown;
};
struct gbapokemonattacks
{
	uint16 moves[4];
	byte pp[4];
};
struct gbapokemoneffort
{
	byte evs[6];
	byte contest[6];
};
struct gbapokemonmisc
{
	byte pokerus;
	byte locationcaught;
	uint16 originsinfo;
	uint32 ivs;
	uint16 ribbons;
};
struct gbapokemonsubstruct
{
	gbapokemongrowth growth;
	gbapokemonattacks attacks;
	gbapokemoneffort effort;
	gbapokemonmisc misc;
};
struct gbapokemon
{
	uint32 pid;
	uint32 trainerid;
	byte nickname[10];
	uint16 language;
	byte otname[7];
	byte markings;
	uint16 checksum;
	uint16 unknown;
	gbapokemonsubstruct encrypted;
};
struct gbasavefooter
{
	uint16 blockid;
	uint16 checksum;
	uint32 validation;
	uint32 saveid;
};
struct gbasaveblock
{
	byte data[0xf80];
	byte unknown[0x74];
	gbasavefooter footer;
};
struct gbasavehalf
{
	gbasaveblock blocks[14];
};
struct gbasavefile
{
	gbasavehalf savefilea;
	gbasavehalf savefileb;
	byte unknown[0x4000];
};
void DllExport sortsaveblocks(gbasavehalf * savehalf);
bool DllExport compareblocks(gbasaveblock *a, gbasaveblock *b);
void DllExport sortblocks(std::vector<gbasaveblock*> * theblocks);
void DllExport decryptgbapkm(gbapokemon * pkm);
void DllExport shufflegbapkm(gbapokemon * pkm, bool un);
void DllExport sortsavefile(gbasavefile * sav);
void DllExport read(const char* file_name, gbasavefile *data);

//struct trainerinfostruct
//{
//    //byte trainername[8];
//    //byte playergender;
//    //uint16 trainerid;
//    //uint16 secretid;
//    //uint16 hoursplayed;
//    //byte minutesplayed;
//    //byte secondsplayed;
//    //byte framesplayed;
//    //uint32 gamecode;
//    //uint32 securitycode;
//	byte data[3884];
//};
//struct team_itemstruct
//{
//    byte data[3968];
//};
//struct unknown1struct
//{
//    byte data[3968];
//};
//struct unknown2struct
//{
//    byte data[3968];
//};
//struct rivalinfostruct
//{
//    byte data[3848];
//};
//struct pcbuffstruct
//{
//    byte data[3968];
//};
//struct pcbuffstructi
//{
//    byte data[2000];
//};
//enum sectionids : uint16
//{
//    trainerinfo,
//    team_items,
//    unknown1,
//    unknown2,
//    rivalinfo,
//    pcbuffa,
//    pcbuffb,
//    pcbuffc,
//    pcbuffd,
//    pcbuffe,
//    pcbufff,
//    pcbuffg,
//    pcbuffh,
//    pcbuffi
//};
//struct sectionfooter
//{
//    sectionids sectionid;
//    uint16 checksum;
//    uint32 saveindex;
//};
//struct datasection
//{
//    byte data[4080];
//    sectionfooter footer;
//	byte unknown[8];
//};
//struct shuffledgamesavesectionstruct
//{
//    datasection datasections[14];
//};
//struct shuffledgamesavestruct
//{
//    shuffledgamesavesectionstruct savea;
//	shuffledgamesavesectionstruct saveb;
//	byte unknown[16384];
//};
//struct gbaboxstruct
//{
//    byte data[30][80];
//};
//struct gamesavestruct
//{
//    trainerinfostruct trainerinfo_;
//    team_itemstruct team_items_;
//    unknown1struct unknown1_;
//    unknown2struct unknown2_;
//    rivalinfostruct rivalinfo_;
//    //uint32 curbox;
//    //gbaboxstruct boxes[14];
//    pcbuffstruct pcbuffa_;
//    pcbuffstruct pcbuffb_;
//    pcbuffstruct pcbuffc_;
//    pcbuffstruct pcbuffd_;
//    pcbuffstruct pcbuffe_;
//    pcbuffstruct pcbufff_;
//    pcbuffstruct pcbuffg_;
//    pcbuffstruct pcbuffh_;
//    pcbuffstructi pcbuffi_;
//};
//struct gba_sav
//{
//public:
//    gamesavestruct savea;
//    gamesavestruct saveb;
////private:
//    byte unused[16384];
//};
