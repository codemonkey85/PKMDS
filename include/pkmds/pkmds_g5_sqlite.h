#pragma once
// Set theDB to be the full path of the SQLITE database (provided by Veekun)
#if (defined __linux__) || (defined __APPLE__) || (defined __CYGWIN__)
#if (defined __APPLE__)
// Mac OS
#if (!defined QT_NO_DEBUG)
static const char theDB[] = "../../../../../../Dropbox/PKMDS Databases/veekun-pokedex.sqlite";
static const char theimgDB[] = "../../../../../../Dropbox/PKMDS Databases/images.sqlite";
#else
static const char theDB[] = "../../veekun-pokedex.sqlite";
static const char theimgDB[] = "../../images.sqlite";
#endif
#else
// Linux (Ubuntu)
#if (!defined QT_NO_DEBUG)
static const char theDB[] = "../../../Dropbox/PKMDS Databases/veekun-pokedex.sqlite";
static const char theimgDB[] = "../../../Dropbox/PKMDS Databases/images.sqlite";
#else
static const char theDB[] = "veekun-pokedex.sqlite";
static const char theimgDB[] = "images.sqlite";
#endif
#endif
#else
// Windows
#if (!defined QT_NO_DEBUG)
static const char theDB[] = "..\\..\\..\\..\\..\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite";
static const char theimgDB[] = "..\\..\\..\\..\\..\\Dropbox\\PKMDS Databases\\images.sqlite";
#else
static const char theDB[] = "veekun-pokedex.sqlite";
static const char theimgDB[] = "images.sqlite";
#endif
#endif
#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5.h>
#include <sqlite3.h>
#else
#include "pkmds_g5.h"
#include "../../Visual_Studio/vs_sqlite.h"
#include "../../include/sqlite3.h"
#endif
#ifndef __cplusplus_cli
extern DllExport sqlite3 *imgdatabase;
extern DllExport sqlite3_stmt *imgstatement;
void DllExport opendb(const char db_file[] = theDB);
void DllExport closedb();
void DllExport openimgdb(const char db_file[] = theimgDB);
void DllExport closeimgdb();
#endif
using namespace std;
void DllExport getapic(const ostringstream &o, byte ** picdata, int * size);
void DllExport getapic(const string &str, byte ** picdata, int * size);
string DllExport getastring(const ostringstream &o);
wstring DllExport getawstring(const ostringstream &o);
int DllExport getanint(const ostringstream &o);
string DllExport getastring(const string &str);
//wstring DllExport getawstring(const wstring &str);
int DllExport getanint(const string &str);
void DllExport dostatement(const string &cmd);
struct ivtest{
	byte id;
	byte val;
	byte order;
};
int DllExport getpkmlevel(const int id, const int exp);
int DllExport getpkmlevel(const pokemon_obj &pkm);
int DllExport getpkmlevel(const pokemon_obj *pkm);
int DllExport getpkmexptonext(const int id, const int exp);
int DllExport getpkmexptonext(const pokemon_obj &pkm);
int DllExport getpkmexptonext(const pokemon_obj *pkm);
int DllExport getpkmexpatcur(const int id, const int exp);
int DllExport getpkmexpatcur(const pokemon_obj &pkm);
int DllExport getpkmexpatcur(const pokemon_obj *pkm);
int DllExport getnatureincrease(const int natureid);
int DllExport getnatureincrease(const pokemon_obj &pkm);
int DllExport getnatureincrease(const pokemon_obj *pkm);
int DllExport getnaturedecrease(const int natureid);
int DllExport getnaturedecrease(const pokemon_obj &pkm);
int DllExport getnaturedecrease(const pokemon_obj *pkm);
int DllExport getpkmstat(const pokemon_obj &pkm, const Stat_IDs::stat_ids stat_id);
int DllExport getpkmstat(const pokemon_obj *pkm, const Stat_IDs::stat_ids stat_id);
bool DllExport pkmhasgenddiff(const int species);
bool DllExport pkmhasgenddiff(const pokemon_obj &pkm);
bool DllExport pkmhasgenddiff(const pokemon_obj *pkm);
int DllExport lookuppkmcolorid(const int species);
int DllExport lookuppkmcolorid(const pokemon_obj &pkm);
int DllExport lookuppkmcolorid(const pokemon_obj *pkm);
bool DllExport compareivbyval(const ivtest &a, const ivtest &b);
bool DllExport compareivbyid(const ivtest &a, const ivtest &b);
bool DllExport compareivbyorder(const ivtest &a, const ivtest &b);
void DllExport setlevel(pokemon_obj &pkm, int level);
void DllExport setlevel(pokemon_obj *pkm, int level);
int DllExport lookuppkmtype(const int species, const int form, const int slot, const int generation = GENERATION);
int DllExport lookuppkmtype(const pokemon_obj &pkm, const int slot, const int generation = GENERATION);
int DllExport lookuppkmtype(const pokemon_obj *pkm, const int slot, const int generation = GENERATION);
int DllExport lookuppkmevolvedspecies(int speciesid);
void DllExport pctoparty(party_pkm *ppkm, const pokemon_obj *pkm);
void DllExport pctoparty(party_pkm &ppkm, const pokemon_obj *pkm);
void DllExport pctoparty(party_pkm *ppkm, const pokemon_obj &pkm);
void DllExport pctoparty(party_pkm &ppkm, const pokemon_obj &pkm);
//void DllExport displaypkminconsole(pokemon_obj * pkm);
uint32 DllExport getpkmexpatlevel(const int id, const int level);
uint32 DllExport getpkmexpatlevel(const Species::species id, const int level);
int DllExport getmovepp(const Moves::moves moveid);
int DllExport getmovepp(const pokemon_obj * pkm, const int movenum);
int DllExport getmovetotalpp(const pokemon_obj * pkm, const int movenum);
Genders::genders DllExport calcpkmgender(const pokemon_obj * pkm);
int DllExport getpkmgenderrate(Species::species speciesid);
Genders::genders DllExport calcpkmgender(const pokemon_obj & pkm);
int DllExport getmovecategory(const Moves::moves moveid);
Types::types DllExport getmovetype(Moves::moves moveid);
int DllExport getmovepower(const Moves::moves moveid);
int DllExport getmoveaccuracy(const Moves::moves moveid);
string DllExport lookuppkmname(const int speciesid, const int langid = LANG_ID);
string DllExport lookuppkmname(const pokemon_obj &pkm, const int langid = LANG_ID);
string DllExport lookuppkmname(const pokemon_obj *pkm, const int langid = LANG_ID);
wstring DllExport lookuppkmnamewstring(const pokemon_obj *pkm, const int langid = LANG_ID);
string DllExport lookupmovename(const int moveid, const int langid = LANG_ID);
string DllExport lookupmovename(const pokemon_obj &pkm, const int movenum, const int langid = LANG_ID);
string DllExport lookupmovename(const pokemon_obj *pkm, const int movenum, const int langid = LANG_ID);
string DllExport lookupmoveflavortext(const uint16 moveid, const int langid = LANG_ID, const int versiongroup = VERSION_GROUP);
string DllExport lookupmoveflavortext(const pokemon_obj &pkm, const int movenum, const int langid = LANG_ID, const int versiongroup = VERSION_GROUP);
string DllExport lookupmoveflavortext(const pokemon_obj *pkm, const int movenum, const int langid = LANG_ID, const int versiongroup = VERSION_GROUP);
string DllExport lookupmovetypename(const int moveid, const int langid = LANG_ID);
string DllExport lookupmovetypename(const pokemon_obj &pkm, const int movenum, const int langid=LANG_ID);
string DllExport lookupmovetypename(const pokemon_obj *pkm, const int movenum, const int langid=LANG_ID);
string DllExport lookupmovedamagetypename(const uint16 moveid, const int langid = LANG_ID);
string DllExport lookupmovedamagetypename(const pokemon_obj &pkm, const int movenum, const int langid = LANG_ID);
string DllExport lookupmovedamagetypename(const pokemon_obj *pkm, const int movenum, const int langid = LANG_ID);
string DllExport getnaturename(const int natureid, const int langid = LANG_ID);
string DllExport getnaturename(const pokemon_obj &pkm, const int langid = LANG_ID);
string DllExport getnaturename(const pokemon_obj *pkm, const int langid = LANG_ID);
string DllExport lookupitemname(const int itemid, const int generation = GENERATION, const int langid = LANG_ID);
string DllExport lookupitemname(const pokemon_obj &pkm, const int generation = GENERATION, const int langid = LANG_ID);
string DllExport lookupitemname(const pokemon_obj *pkm, const int generation = GENERATION, const int langid = LANG_ID);
string DllExport getpkmgendername(const pokemon_obj &pkm);
string DllExport getpkmgendername(const pokemon_obj *pkm);
string DllExport lookupabilityname(const int abilityid, const int langid = LANG_ID);
string DllExport lookupabilityname(const pokemon_obj &pkm, const int langid = LANG_ID);
string DllExport lookupabilityname(const pokemon_obj *pkm, const int langid = LANG_ID);
string DllExport getpkmformname(const pokemon_obj &pkm, const int generation = GENERATION, const int langid = LANG_ID);
string DllExport getpkmformname(const pokemon_obj *pkm, const int generation = GENERATION, const int langid = LANG_ID);
string DllExport getpkmformname(const int speciesid, const int formid, const int generation = GENERATION, const int langid = LANG_ID);
string DllExport lookuplocname(const int locid, const int gen = GENERATION, const int langid = LANG_ID);
string DllExport getpkmmetlocname(const pokemon_obj &pkm, const int gen = GENERATION, const int langid = LANG_ID);
string DllExport getpkmmetlocname(const pokemon_obj *pkm, const int gen = GENERATION, const int langid = LANG_ID);
string DllExport getpkmegglocname(const pokemon_obj &pkm, const int gen = GENERATION, const int langid = LANG_ID);
string DllExport getpkmegglocname(const pokemon_obj *pkm, const int gen = GENERATION, const int langid = LANG_ID);
string DllExport lookupitemflavortext(const int itemid, const int generation = GENERATION, const int langid = LANG_ID, const int versiongroup = VERSION_GROUP);
string DllExport lookupitemflavortext(const pokemon_obj &pkm, const int generation = GENERATION, const int langid = LANG_ID, const int versiongroup = VERSION_GROUP);
string DllExport lookupitemflavortext(const pokemon_obj *pkm, const int generation = GENERATION, const int langid = LANG_ID, const int versiongroup = VERSION_GROUP);
string DllExport lookuppkmcolorname(const int species, const int langid = LANG_ID);
string DllExport lookuppkmcolorname(const pokemon_obj &pkm, const int langid = LANG_ID);
string DllExport lookuppkmcolorname(const pokemon_obj *pkm, const int langid = LANG_ID);
string DllExport lookupabilityflavortext(const int abilityid, const int version_group = VERSION_GROUP, const int langid = LANG_ID);
string DllExport lookupabilityflavortext(const pokemon_obj &pkm, const int version_group = VERSION_GROUP, const int langid = LANG_ID);
string DllExport lookupabilityflavortext(const pokemon_obj *pkm, const int version_group = VERSION_GROUP, const int langid = LANG_ID);
string DllExport lookupcharacteristic(const int statid, const int iv, const int langid = LANG_ID);
string DllExport lookupcharacteristic(const pokemon_obj &pkm, const int langid = LANG_ID);
string DllExport lookupcharacteristic(const pokemon_obj *pkm, const int langid = LANG_ID);
string DllExport lookuptypename(const Types::types type, const int langid = LANG_ID);
string DllExport lookuptypename(const int type, const int langid = LANG_ID);
string DllExport getmachinetypename(const Items::items itemid, const int generation = GENERATION, const int version_group = VERSION_GROUP);
string DllExport getpokemoncolorstring(const Species::species speciesid);
int DllExport getpokemoncolor(const Species::species speciesid);
uint32 DllExport getpkmcolor(const Species::species species);
string DllExport getmachinemovename(const Items::items itemid, const int generation = GENERATION, const int version_group = VERSION_GROUP, const int langid = LANG_ID);
int DllExport getitempocket(const Items::items itemid, const int generation = GENERATION);
string DllExport getitempocketname(const Items::items itemid, const int generation = GENERATION, const int langid = LANG_ID);
DllExport item_obj * finditeminbag(bw2sav_obj * sav, Items::items itemid, int & slot);
DllExport item_obj * getavailablebagslot(bw2sav_obj * sav, ItemPockets::itempockets pocket, int & slot);
void DllExport removeitem(bw2sav_obj * sav, pokemon_obj * pkm);
DllExport item_obj * getpocket(bw2sav_obj * sav, ItemPockets::itempockets pocket);
void DllExport tossitem(bw2sav_obj * sav, item_obj * item);
void DllExport giveitem(bw2sav_obj * sav, item_obj * item, pokemon_obj * pkm);
void DllExport insertitem(bw2sav_obj * sav, item_obj * item, int slot);
