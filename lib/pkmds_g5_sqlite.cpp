#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_sql.h>
#else
#include "../../PKMDS/include/pkmds/pkmds_sql.h"
#endif
using namespace std;
#ifndef __cplusplus_cli
sqlite3 *database;
sqlite3_stmt *statement;
void opendb(const char db_file[])
{
//#if (defined __APPLE__)
//    CFURLRef appUrlRef = CFBundleCopyBundleURL(CFBundleGetMainBundle());
//    CFStringRef macPath = CFURLCopyFileSystemPath(appUrlRef,
//                                           kCFURLPOSIXPathStyle);
//    const char *pathPtr = CFStringGetCStringPtr(macPath,
//                                           CFStringGetSystemEncoding());
//    qDebug("Path = %s", pathPtr);
//    CFRelease(appUrlRef);
//    CFRelease(macPath);
//#endif
	sqlite3_open(db_file, &database);
}
void closedb()
{
	sqlite3_close(database);
}
sqlite3 *imgdatabase;
sqlite3_stmt *imgstatement;
void openimgdb(const char db_file[])
{
	sqlite3_open(db_file, &imgdatabase);
}
void closeimgdb()
{
	sqlite3_close(imgdatabase);
}
void getapic(const ostringstream &o, byte ** picdata, int * size)
{
	const void * blob;
	size_t thesize = 0;
	char cmd[BUFF_SIZE];
	strcpy__(cmd, o.str().c_str());
	if (sqlite3_prepare_v2(imgdatabase, cmd, -1, &imgstatement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(imgstatement);
		int result = 0;
		result = sqlite3_step(imgstatement);
		if ((result == SQLITE_ROW) | (result == SQLITE_DONE))
		{
			for (int col = 0; col < cols; col++)
			{
				blob = sqlite3_column_blob(imgstatement, col);
				thesize = sqlite3_column_bytes(imgstatement, col);
				*picdata = new byte[thesize];
				memcpy(*picdata, blob, thesize);
				*size = thesize;
			}
		}
		sqlite3_finalize(imgstatement);
	}
}
void getapic(const string &str, byte ** picdata, int * size)
{
	const void * blob;
	size_t thesize = 0;
	char cmd[BUFF_SIZE];
#if defined (__linux__) || defined (__APPLE__) || defined (__CYGWIN__)
	strcpy(cmd, str.c_str());
#else
	strcpy_s(cmd, str.c_str());
#endif
	if (sqlite3_prepare_v2(imgdatabase, cmd, -1, &imgstatement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(imgstatement);
		int result = 0;
		result = sqlite3_step(imgstatement);
		if ((result == SQLITE_ROW) | (result == SQLITE_DONE))
		{
			for (int col = 0; col < cols; col++)
			{
				blob = sqlite3_column_blob(imgstatement, col);
				thesize = sqlite3_column_bytes(imgstatement, col);
				*picdata = new byte[thesize];
				memcpy(*picdata, blob, thesize);
				*size = thesize;
			}
		}
		sqlite3_finalize(imgstatement);
	}
}
string getastring(const ostringstream &o)
{
	string s = "";
	char cmd[BUFF_SIZE];
#if defined (__linux__) || defined (__APPLE__) || defined(__CYGWIN__)
	strcpy(cmd,o.str().c_str());
#else
	strcpy_s(cmd, o.str().c_str());
#endif
	if (sqlite3_prepare_v2(database, cmd, -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		result = sqlite3_step(statement);
		if ((result == SQLITE_ROW) | (result == SQLITE_DONE))
		{
			for (int col = 0; col < cols; col++)
			{
				const unsigned char* test;
				test = sqlite3_column_text(statement, col);
				if (sqlite3_column_text(statement, col) != 0)
				{
					s = (char*)test;
				}
			}
		}
		sqlite3_finalize(statement);
	}
	return s;
}
wstring getawstring(const ostringstream &o)
{
	wchar_t s[] = L"\0\0\0\0\0\0\0\0\0\0\0";
	char cmd[BUFF_SIZE];
#if defined (__linux__) || defined (__APPLE__) || defined(__CYGWIN__)
	strcpy(cmd,o.str().c_str());
#else
	strcpy_s(cmd, o.str().c_str());
#endif
	if (sqlite3_prepare_v2(database, cmd, -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		result = sqlite3_step(statement);
		if ((result == SQLITE_ROW) | (result == SQLITE_DONE))
		{
			for (int col = 0; col < cols; col++)
			{
				const unsigned char* test;
				test = sqlite3_column_text(statement, col);
				if (sqlite3_column_text(statement, col) != 0)
				{
					std::copy(test, test + NICKLENGTH, s);
				}
			}
		}
		sqlite3_finalize(statement);
	}
	return s;
}
int getanint(const ostringstream &o)
{
	int i = 0;
	char cmd[BUFF_SIZE];
#if defined (__linux__) || defined (__APPLE__) || defined(__CYGWIN__)
	strcpy(cmd,o.str().c_str());
#else
	strcpy_s(cmd,o.str().c_str());
#endif
	if(sqlite3_prepare_v2(database,cmd,-1,&statement,0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		result = sqlite3_step(statement);
		if((result == SQLITE_ROW) | (result == SQLITE_DONE))
		{
			for(int col = 0; col < cols; col++)
			{
				i = sqlite3_column_int(statement, col);
			}
		}
		sqlite3_finalize(statement);
	}
	return i;
}
string getastring(const string &str)
{
	string s = "";
	char cmd[BUFF_SIZE];
#if defined (__linux__) || defined (__APPLE__) || defined (__CYGWIN__)
	strcpy(cmd,str.c_str());
#else
	strcpy_s(cmd, str.c_str());
#endif
	if (sqlite3_prepare_v2(database, cmd, -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		result = sqlite3_step(statement);
		if ((result == SQLITE_ROW) | (result == SQLITE_DONE))
		{
			for (int col = 0; col < cols; col++)
			{
				const unsigned char* test;
				test = sqlite3_column_text(statement, col);
				if (sqlite3_column_text(statement, col) != 0)
				{
					s = (char*)test;
				}
			}
		}
		sqlite3_finalize(statement);
	}
	return s;
}
//wstring getawstring(const wstring &str)
//{
//
//	wstring test = str;
//
//	wstring s = L"";
//	char cmd[BUFF_SIZE];
//#if defined (__linux__) || defined (__APPLE__) || defined (__CYGWIN__)
//	strcpy(cmd, str.c_str());
//#else
//	strcpy_s(cmd, str.c_str());
//#endif
//	if (sqlite3_prepare_v2(database, cmd, -1, &statement, 0) == SQLITE_OK)
//	{
//		int cols = sqlite3_column_count(statement);
//		int result = 0;
//		result = sqlite3_step(statement);
//		if ((result == SQLITE_ROW) | (result == SQLITE_DONE))
//		{
//			for (int col = 0; col < cols; col++)
//			{
//				const unsigned char* test;
//				test = sqlite3_column_text(statement, col);
//				if (sqlite3_column_text(statement, col) != 0)
//				{
//					s = (wchar_t*)test;
//				}
//			}
//		}
//		sqlite3_finalize(statement);
//	}
//	return s;
//}
int getanint(const string &str)
{
	int i = 0;
	char cmd[BUFF_SIZE];
#if defined (__linux__) || defined (__APPLE__) || defined (__CYGWIN__)
	strcpy(cmd,str.c_str());
#else
	strcpy_s(cmd,str.c_str());
#endif
	if(sqlite3_prepare_v2(database,cmd,-1,&statement,0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		result = sqlite3_step(statement);
		if((result == SQLITE_ROW) | (result == SQLITE_DONE))
		{
			for(int col = 0; col < cols; col++)
			{
				i = sqlite3_column_int(statement, col);
			}
		}
		sqlite3_finalize(statement);
	}
	return i;
}
void dostatement(const string &cmd)
{
	sqlite3_prepare_v2(database,cmd.c_str(),-1,&statement,0);
	sqlite3_step(statement);
}
#else
string getastring(const ostringstream &o)
{
	VS_SQLite ^ vsqlite = gcnew VS_SQLite();
	return vsqlite->getSQLTextstd(o.str());
	//free(vsqlite);
}
int getanint(const ostringstream &o)
{
	VS_SQLite ^ vsqlite = gcnew VS_SQLite();
	return vsqlite->getSQLInt(o.str());
	//free(vsqlite);
}
string getastring(const string &str)
{
	VS_SQLite ^ vsqlite = gcnew VS_SQLite();
	return vsqlite->getSQLTextstd(str);
	//free(vsqlite);
}
int getanint(const string &str)
{
	VS_SQLite ^ vsqlite = gcnew VS_SQLite();
	return vsqlite->getSQLInt(str);
	//free(vsqlite);
}
void dostatement(const string &cmd)
{}
#endif
int getpkmlevel(const int id, const int exp)
{
	return getanint(getpkmlevelsql(id,exp));
}
int getpkmlevel(const pokemon_obj &pkm)
{
	return getpkmlevel(pkm.species,pkm.exp);
}
int getpkmlevel(const pokemon_obj *pkm)
{
	return getpkmlevel(pkm->species_int,pkm->exp);
}
int getpkmexptonext(const int id, const int exp)
{
	if(getpkmlevel(id,exp) == 100)
	{
		return 0;
	};
	int expatnext = getanint(getpkmexptonextsql(id,exp));
	return expatnext - exp;
}
int getpkmexptonext(const pokemon_obj &pkm)
{
	return getpkmexptonext(pkm.species, pkm.exp);
}
int getpkmexpatcur(const int id, const int exp)
{
	return getanint(getpkmexpatcursql(id,exp));
}
uint32 getpkmexpatlevel(const int id, const int level)
{
	return getanint(getpkmexpatlevelsql(id,level));
}
uint32 getpkmexpatlevel(const Species::species id, const int level)
{
	return getanint(getpkmexpatlevelsql(id,level));
}
int getpkmexpatcur(const pokemon_obj &pkm)
{
	return getpkmexpatcur(pkm.species,pkm.exp);
}
int getnatureincrease(const int natureid)
{
	return getanint(getnatureincreasesql(natureid));
}
int getnatureincrease(const pokemon_obj &pkm)
{
	if(pkm.nature_int == 0 && pkm.hometown != Hometowns::black && pkm.hometown != Hometowns::white)
	{
		return getnatureincrease(pkm.pid % 25);
	}
	else
	{
		return getnatureincrease(pkm.nature_int);
	}
}
int getnatureincrease(const pokemon_obj *pkm)
{
	if(pkm->nature_int == 0 && pkm->hometown != Hometowns::black && pkm->hometown != Hometowns::white)
	{
		return getnatureincrease(pkm->pid % 25);
	}
	else
	{
		return getnatureincrease(pkm->nature_int);
	}
}
int getnaturedecrease(const int natureid)
{
	return getanint(getnaturedecreasesql(natureid));
}
int getnaturedecrease(const pokemon_obj &pkm)
{
	if((pkm.nature_int == 0) && (pkm.hometown != Hometowns::black) && (pkm.hometown != Hometowns::white))
	{
		return getnaturedecrease(pkm.pid % 25);
	}
	else
	{
		return getnaturedecrease(pkm.nature_int);
	}
}
int getnaturedecrease(const pokemon_obj *pkm)
{
	if((pkm->nature_int == 0) && (pkm->hometown != Hometowns::black) && (pkm->hometown != Hometowns::white))
	{
		return getnaturedecrease(pkm->pid % 25);
	}
	else
	{
		return getnaturedecrease(pkm->nature_int);
	}
}
// TODO: Optimize stat calculation
/*
Perhaps the best way to accomplish this is to query the database for all of the values needed for this formula in one row, and then reference that row
as needed. As of this time, this function queries the database 2 - 4 times.
*/
int getpkmstat(const pokemon_obj &pkm, const Stat_IDs::stat_ids stat_id)
{
	int basestat = getanint(getpkmstatsql(pkm,stat_id));
	int level = getpkmlevel(pkm);
	int iv = 0;
	int ev = 0;
	switch(stat_id)
	{
	case Stat_IDs::hp:
		iv = pkm.ivs.hp;
		ev = pkm.evs.hp;
		return (int)((floor((double)(floor((double)(((iv + (2 * basestat) + floor((double)(ev/4))+100) * level) / 100)) + 10))));
		break;
	case Stat_IDs::attack:
		iv = pkm.ivs.attack;
		ev = pkm.evs.attack;
		break;
	case Stat_IDs::defense:
		iv = pkm.ivs.defense;
		ev = pkm.evs.defense;
		break;
	case Stat_IDs::spatk:
		iv = pkm.ivs.spatk;
		ev = pkm.evs.spatk;
		break;
	case Stat_IDs::spdef:
		iv = pkm.ivs.spdef;
		ev = pkm.evs.spdef;
		break;
	case Stat_IDs::speed:
		iv = pkm.ivs.speed;
		ev = pkm.evs.speed;
		break;
	};
	double naturemod = 1.0;
	int natureincrease = getnatureincrease(pkm);
	int naturedecrease = getnaturedecrease(pkm);
	if (natureincrease != naturedecrease) {
		if (int(stat_id) == natureincrease){
			naturemod = 1.1;
		};
		if (int(stat_id) == naturedecrease){
			naturemod = 0.9;
		};
	};
	return (int)((floor((double)(floor((double)(((iv + (2 * basestat) + floor((double)(ev/4))) * level) / 100)) + 5)) * naturemod));
	return 0;
}
int getpkmstat(const pokemon_obj *pkm, const Stat_IDs::stat_ids stat_id)
{
	int basestat = getanint(getpkmstatsql(pkm,stat_id));
	int level = getpkmlevel(pkm);
	int iv = 0;
	int ev = 0;
	switch(stat_id)
	{
	case Stat_IDs::hp:
		iv = pkm->ivs.hp;
		ev = pkm->evs.hp;
		return (int)((floor((double)(floor((double)(((iv + (2 * basestat) + floor((double)(ev/4))+100) * level) / 100)) + 10))));
		break;
	case Stat_IDs::attack:
		iv = pkm->ivs.attack;
		ev = pkm->evs.attack;
		break;
	case Stat_IDs::defense:
		iv = pkm->ivs.defense;
		ev = pkm->evs.defense;
		break;
	case Stat_IDs::spatk:
		iv = pkm->ivs.spatk;
		ev = pkm->evs.spatk;
		break;
	case Stat_IDs::spdef:
		iv = pkm->ivs.spdef;
		ev = pkm->evs.spdef;
		break;
	case Stat_IDs::speed:
		iv = pkm->ivs.speed;
		ev = pkm->evs.speed;
		break;
	};
	double naturemod = 1.0;
	int natureincrease = getnatureincrease(pkm);
	int naturedecrease = getnaturedecrease(pkm);
	if (natureincrease != naturedecrease) {
		if (int(stat_id) == natureincrease){
			naturemod = 1.1;
		};
		if (int(stat_id) == naturedecrease){
			naturemod = 0.9;
		};
	};
	return (int)((floor((double)(floor((double)(((iv + (2 * basestat) + floor((double)(ev/4))) * level) / 100)) + 5)) * naturemod));
	return 0;
}
bool pkmhasgenddiff(const int species)
{
	int h = getanint(pkmhasgenddiffsql(species));
	return (h == 1);
}
bool pkmhasgenddiff(const pokemon_obj &pkm)
{
	return pkmhasgenddiff(pkm.species);
}
int lookuppkmcolorid(const int species)
{
	return getanint(lookuppkmcoloridsql(species));
}
int lookuppkmcolorid(const pokemon_obj &pkm)
{
	return lookuppkmcolorid(pkm.species);
}
bool compareivbyval(const ivtest &a, const ivtest &b)
{
	return a.val > b.val;
}
bool compareivbyid(const ivtest &a, const ivtest &b)
{
	return a.id < b.id;
}
bool compareivbyorder(const ivtest &a, const ivtest &b)
{
	return a.order < b.order;
}
int lookuppkmtype(const int species, const int form, const int slot, const int generation)
{
	switch((Species::species)species)
	{
	case Species::arceus:
		if(slot == 2)
		{
			return -1;
		}
		return int(getarceustype(form));
		break;
	default:
		ostringstream o;
		o << ""
			<< "SELECT pokemon_types.type_id "
			<< "FROM pokemon_types "
			<< "INNER JOIN pokemon_forms "
			<< "ON pokemon_types.pokemon_id = pokemon_forms.pokemon_id "
			<< "INNER JOIN pokemon "
			<< "ON pokemon_types.pokemon_id = pokemon.id "
			<< "AND pokemon_forms.pokemon_id = pokemon.id "
			<< "INNER JOIN pokemon_form_generations "
			<< "ON pokemon_forms.id = pokemon_form_generations.pokemon_form_id "
			<< "WHERE (pokemon.species_id = " << species << ") "
			<< "AND (pokemon_types.slot = " << slot << ") "
			<< "AND (pokemon_form_generations.game_index = " << form << ") "
			<< "AND (pokemon_form_generations.generation_id = " << generation << ")";
		//		<< "SELECT pokemon_types.type_id "
		//        << "FROM pokemon_types "
		//        << "INNER JOIN pokemon_forms "
		//        << "ON pokemon_types.pokemon_id = pokemon_forms.pokemon_id "
		//        << "INNER JOIN pokemon "
		//        << "ON pokemon_types.pokemon_id = pokemon.id "
		//        << "AND pokemon_forms.pokemon_id = pokemon.id "
		//        << "INNER JOIN pokemon_species "
		//        << "ON pokemon.species_id = pokemon_species.id "
		//        << "INNER JOIN pokemon_species_names "
		//        << "ON pokemon_species.id = pokemon_species_names.pokemon_species_id "
		//        << "WHERE (pokemon_species_names.local_language_id = " << langid << ") "
		//        << "AND (pokemon_forms.form_order = " << form << " + 1) "
		//        << "AND (pokemon_species.id = " << species << ") "
		//        << "AND (pokemon_types.slot = " << slot << ")";
		return getanint(o) - 1;
	}
}
int lookuppkmtype(const pokemon_obj &pkm, const int slot, const int generation)
{
	return lookuppkmtype(pkm.species_int,pkm.form_int,slot,generation);
}
void setlevel(pokemon_obj &pkm, int level)
{
	pkm.exp = getanint(getsetlevelsql(pkm,level));
}
int getpkmexptonext(const pokemon_obj *pkm)
{
	return getpkmexptonext(pkm->species_int, pkm->exp);
}
int getpkmexpatcur(const pokemon_obj *pkm)
{
	return getpkmexpatcur(pkm->species_int,pkm->exp);
}
bool pkmhasgenddiff(const pokemon_obj *pkm)
{
	return pkmhasgenddiff(pkm->species_int);
}
int lookuppkmcolorid(const pokemon_obj *pkm)
{
	return lookuppkmcolorid(pkm->species_int);
}
void setlevel(pokemon_obj *pkm, int level)
{
	pkm->exp = getanint(getsetlevelsql(pkm,level));
}
int lookuppkmtype(const pokemon_obj *pkm, const int slot, const int generation)
{
	return lookuppkmtype(pkm->species_int,pkm->form_int,slot,generation);
}
int lookuppkmevolvedspecies(int speciesid)
{
	return getanint(lookuppkmevolvedspeciessql(speciesid));
}
void pctoparty(party_pkm *ppkm, const pokemon_obj *pkm)
{
	memcpy(ppkm,pkm,sizeof(pokemon_obj));
	ppkm->party_data.maxhp = getpkmstat(pkm,Stat_IDs::hp);
	ppkm->party_data.hp = ppkm->party_data.maxhp;
	ppkm->party_data.attack = getpkmstat(pkm,Stat_IDs::attack);
	ppkm->party_data.defense = getpkmstat(pkm,Stat_IDs::defense);
	ppkm->party_data.speed = getpkmstat(pkm,Stat_IDs::speed);
	ppkm->party_data.spatk = getpkmstat(pkm,Stat_IDs::spatk);
	ppkm->party_data.spdef = getpkmstat(pkm,Stat_IDs::spdef);
	ppkm->party_data.level = getpkmlevel(pkm);
}
void pctoparty(party_pkm &ppkm, const pokemon_obj *pkm)
{
	memcpy(&ppkm,pkm,sizeof(pokemon_obj));
	ppkm.party_data.maxhp = getpkmstat(pkm,Stat_IDs::hp);
	ppkm.party_data.hp = ppkm.party_data.maxhp;
	ppkm.party_data.attack = getpkmstat(pkm,Stat_IDs::attack);
	ppkm.party_data.defense = getpkmstat(pkm,Stat_IDs::defense);
	ppkm.party_data.speed = getpkmstat(pkm,Stat_IDs::speed);
	ppkm.party_data.spatk = getpkmstat(pkm,Stat_IDs::spatk);
	ppkm.party_data.spdef = getpkmstat(pkm,Stat_IDs::spdef);
	ppkm.party_data.level = getpkmlevel(pkm);
}
void pctoparty(party_pkm *ppkm, const pokemon_obj &pkm)
{
	memcpy(ppkm,&pkm,sizeof(pokemon_obj));
	ppkm->party_data.maxhp = getpkmstat(pkm,Stat_IDs::hp);
	ppkm->party_data.hp = ppkm->party_data.maxhp;
	ppkm->party_data.attack = getpkmstat(pkm,Stat_IDs::attack);
	ppkm->party_data.defense = getpkmstat(pkm,Stat_IDs::defense);
	ppkm->party_data.speed = getpkmstat(pkm,Stat_IDs::speed);
	ppkm->party_data.spatk = getpkmstat(pkm,Stat_IDs::spatk);
	ppkm->party_data.spdef = getpkmstat(pkm,Stat_IDs::spdef);
	ppkm->party_data.level = getpkmlevel(pkm);
}
void pctoparty(party_pkm &ppkm, const pokemon_obj &pkm)
{
	memcpy(&ppkm,&pkm,sizeof(pokemon_obj));
	ppkm.party_data.maxhp = getpkmstat(pkm,Stat_IDs::hp);
	ppkm.party_data.hp = ppkm.party_data.maxhp;
	ppkm.party_data.attack = getpkmstat(pkm,Stat_IDs::attack);
	ppkm.party_data.defense = getpkmstat(pkm,Stat_IDs::defense);
	ppkm.party_data.speed = getpkmstat(pkm,Stat_IDs::speed);
	ppkm.party_data.spatk = getpkmstat(pkm,Stat_IDs::spatk);
	ppkm.party_data.spdef = getpkmstat(pkm,Stat_IDs::spdef);
	ppkm.party_data.level = getpkmlevel(pkm);
}
//void displaypkminconsole(pokemon_obj * pkm)
//{
//    cin.ignore();
//    string linebreak = "\n==========================\n";
//    cout << endl;
//    if(int(pkm->species) <= 0 || int(pkm->species) > 649)
//    {
//        cout << "This is not a valid Pokemon!" << endl;
//    }
//    else
//    {
//#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
//        system("cls");
//#else
//        system("clear");
//#endif
//        // Basic Information
//        cout << "Basic Information" << linebreak;
//        cout << "Pokemon species: " << lookuppkmname(pkm) << endl;
//        cout << "Level: " << getpkmlevel(pkm) << endl;
//        cout << "Gender: " << getpkmgendername(pkm) << endl;
//        cout << "Held item: ";
//        if(pkm->item == Items::NOTHING)
//        {
//            cout << "None" << endl;
//        }
//        else
//        {
//            cout << lookupitemname(pkm) << endl;
//        }
//        cout << "Type: " << lookuptypename(lookuppkmtype(pkm,1));
//        if(lookuppkmtype(pkm,2) != -1)
//        {
//            cout << "/" << lookuptypename(lookuppkmtype(pkm,2)) << endl;
//        }
//        else
//        {
//            cout << endl;
//        }
//        // Moves and Ability
//        cout << "\nMoves and Ability" << linebreak;
//        cout << "Move[s]:" << endl;
//        for(int i = 0; i < 4; i++)
//        {
//            if(pkm->moves[i] != Moves::NOTHING)
//            {
//                cout << lookupmovename(pkm,i) << endl;
//            }
//        }
//        cout << "Ability: " << lookupabilityname(pkm) << endl;
//        // Stats
//        cout << "\nStats" << linebreak;
//        cout << "Nature: " << getnaturename(pkm) << endl;
//        cout << "IVs: " << endl;
//        cout << "HP: " << (int)(pkm->ivs.hp) << endl;
//        cout << "Attack: " << (int)(pkm->ivs.attack) << endl;
//        cout << "Defense: " << (int)(pkm->ivs.defense) << endl;
//        cout << "Special Attack: " << (int)(pkm->ivs.spatk) << endl;
//        cout << "Special Defense: " << (int)(pkm->ivs.spdef) << endl;
//        cout << "Speed: " << (int)(pkm->ivs.speed) << endl;
//        cout << "EVs: " << endl;
//        cout << "HP: " << (int)(pkm->evs.hp) << endl;
//        cout << "Attack: " << (int)(pkm->evs.attack) << endl;
//        cout << "Defense: " << (int)(pkm->evs.defense) << endl;
//        cout << "Special Attack: " << (int)(pkm->evs.spatk) << endl;
//        cout << "Special Defense: " << (int)(pkm->evs.spdef) << endl;
//        cout << "Speed: " << (int)(pkm->evs.speed) << endl;
//        cout << "Stats: " << endl;
//        cout << "HP: " << getpkmstat(pkm,Stat_IDs::hp) << endl;
//        cout << "Attack: " << getpkmstat(pkm,Stat_IDs::attack) << endl;
//        cout << "Defense: " << getpkmstat(pkm,Stat_IDs::defense) << endl;
//        cout << "Special Attack: " << getpkmstat(pkm,Stat_IDs::spatk) << endl;
//        cout << "Special Defense: " << getpkmstat(pkm,Stat_IDs::spdef) << endl;
//        cout << "Speed: " << getpkmstat(pkm,Stat_IDs::speed) << endl;
//        if(pkm->ivs.isegg)
//        {
//            cout << "This is an egg." << endl;
//            cout << "Steps to hatch: " << getpkmhatchsteps(pkm) << endl;
//        }
//        else
//        {
//            cout << "Tameness: " << (int)((getpkmhappiness(pkm)) * 100) << "%" << endl;
//        }
//        // Origins
//        cout << "\nOrigins:" << linebreak;
//        cout << "Ball: ";
//        if(pkm->ball == Balls::pokeball || pkm->ball == Balls::pokeball_)
//        {
//            cout << "Poke Ball" << endl;
//        }
//        else
//        {
//            cout << ballnames[pkm->ball] << endl;
//        }
//        cout << "Met date (Y/M/D): " << (int)(pkm->metdate.year + 2000) << "/" << (int)(pkm->metdate.month) << "/" << (int)(pkm->metdate.day) << endl;
//        cout << "Met location: " << getpkmmetlocname(pkm) << endl;
//        if(pkm->eggmet != Locations::mysteryzone_)
//        {
//            cout << "Egg date (Y/M/D): " << (int)(pkm->eggdate.year + 2000) << "/" << (int)(pkm->eggdate.month) << "/" << (int)(pkm->eggdate.day) << endl;
//            cout << "Egg location: " << getpkmegglocname(pkm) << endl;
//        }
//        cout << "Fateful encounter: ";
//        if(pkm->forms.fencounter)
//        {
//            cout << "Yes" << endl;
//        }
//        else
//        {
//            cout << "No" << endl;
//        }
//        cout << "Shiny: ";
//        if(getpkmshiny(pkm))
//        {
//            cout << "Yes" << endl;
//        }
//        else
//        {
//            cout << "No" << endl;
//        }
//        cout << "Infected with PokeRus: ";
//        if(pkm->pkrs.strain != 0)
//        {
//            cout << "Yes" << endl;
//        }
//        else
//        {
//            cout << "No" << endl;
//        }
//    }
//    cout << endl;
//}
int getmovepp(const Moves::moves moveid)
{
	return getanint(getmoveppsql(moveid));
}
int getmovepp(const pokemon_obj * pkm, const int movenum)
{
	return getmovepp(pkm->moves[movenum]);
}
int getmovetotalpp(const pokemon_obj * pkm, const int movenum)
{
	int curpp = getmovepp(pkm,movenum);
	double multiplier = pkm->ppup[movenum] * 20;
	multiplier = (multiplier + 100) / 100;
	return (int)(curpp * multiplier);
}
int getpkmgenderrate(Species::species speciesid)
{
	ostringstream o;
	o << ""
		<< "SELECT gender_rate "
		<< "FROM   pokemon_species "
		<< "WHERE  ( id = " << (int)speciesid << " ) ";    return getanint(o);
}
Genders::genders calcpkmgender(const pokemon_obj * pkm)
{
	int genderrate = getpkmgenderrate(pkm->species);
	int ratiobin = 0;
	switch(genderrate)
	{
	case -1:
		return Genders::genderless;
		break;
	case 0:
		return Genders::male;
		break;
	case 1:
		ratiobin = 31;
		break;
	case 2:
		ratiobin = 63;
		break;
	case 4:
		ratiobin = 127;
		break;
	case 6:
		ratiobin = 191;
		break;
	case 8:
		return Genders::female;
		break;
	default:
		return Genders::male;
		break;
	}
	int pidbin = (pkm->pid) % 256;
	if(pidbin >= ratiobin)
	{
		return Genders::male;
	}
	return Genders::female;
}
Genders::genders calcpkmgender(const pokemon_obj & pkm)
{
	int genderrate = getpkmgenderrate(pkm.species);
	int ratiobin = 0;
	switch(genderrate)
	{
	case -1:
		return Genders::genderless;
		break;
	case 0:
		return Genders::male;
		break;
	case 1:
		ratiobin = 31;
		break;
	case 2:
		ratiobin = 63;
		break;
	case 4:
		ratiobin = 127;
		break;
	case 6:
		ratiobin = 191;
		break;
	case 8:
		return Genders::female;
		break;
	default:
		return Genders::male;
		break;
	}
	int pidbin = (pkm.pid) % 256;
	if(pidbin >= ratiobin)
	{
		return Genders::male;
	}
	return Genders::female;
}
int getmovecategory(const Moves::moves moveid)
{
	ostringstream o;
	o << ""
		<< "SELECT damage_class_id "
		<< "FROM   moves "
		<< "WHERE  ( id = " << (int)moveid << " ) ";
	return getanint(o);
}
int getmovepower(const Moves::moves moveid)
{
	ostringstream o;
	o << ""
		<< "SELECT power "
		<< "FROM   moves "
		<< "WHERE  ( id = " << (int)moveid << " ) ";
	return getanint(o);
}
int getmoveaccuracy(const Moves::moves moveid)
{
	ostringstream o;
	o << ""
		<< "SELECT accuracy "
		<< "FROM   moves "
		<< "WHERE  ( id = " << (int)moveid << " ) ";
	return getanint(o);
}
Types::types getmovetype(Moves::moves moveid)
{
	ostringstream o;
	o << ""
		<< "SELECT type_id "
		<< "FROM   moves "
		<< "WHERE  ( id = " << (int)moveid << " ) ";
	return (Types::types)(getanint(o)-1);
}
string lookuptypename(const Types::types type, const int langid)
{
	return getastring(lookuptypenamesql((int)type,langid));
}
string lookuptypename(const int type, const int langid)
{
	return getastring(lookuptypenamesql(type,langid));
}

string DllExport lookupmovetypename(const int moveid, const int langid)
{
	return lookuptypename(getmovetype(Moves::moves(moveid)),langid);
}
string DllExport lookupmovetypename(const pokemon_obj &pkm, const int movenum, const int langid)
{
	return lookuptypename(getmovetype(pkm.moves[movenum]),langid);
}
string DllExport lookupmovetypename(const pokemon_obj *pkm, const int movenum, const int langid)
{
	return lookuptypename(getmovetype(pkm->moves[movenum]),langid);
}
string lookupmoveflavortext(const uint16 moveid, const int langid, const int versiongroup)
{
	string ret = getastring(getmoveflavortextsql(moveid,langid,versiongroup));
	replace(ret.begin(),ret.end(),'\n',' ');
	return ret;
}
string lookupmoveflavortext(const pokemon_obj &pkm, const int movenum, const int langid, const int versiongroup)
{
	return lookupmoveflavortext((uint16)pkm.moves[movenum],langid,versiongroup);
}
string lookupmoveflavortext(const pokemon_obj *pkm, const int movenum, const int langid, const int versiongroup)
{
	return lookupmoveflavortext((uint16)pkm->moves[movenum],langid,versiongroup);
}
string lookupabilityflavortext(const pokemon_obj *pkm, const int version_group, const int langid)
{
	return getastring(lookupabilityflavortext(pkm->ability,version_group,langid));
}
string lookupabilityflavortext(const int abilityid, const int version_group, const int langid)
{
	string ret = getastring(lookupabilityflavortextsql(abilityid,version_group,langid));
	replace(ret.begin(),ret.end(),'\n',' ');
	return ret;
}
string lookupabilityflavortext(const pokemon_obj &pkm, const int version_group, const int langid)
{
	return getastring(lookupabilityflavortext(pkm.ability,version_group,langid));
}
/*
# PokeTools
# Some useful calculatios for RNGing in Pokemon Gen V
# by Kai Seward, April 2011
# Gen V RNG Breeding Guide: http://www.smogon.com/forums/showthread.php?t=3446600
def pidtodec(pid):
""" return the decimal form of the personality value """
return int(pid,16)
def characteristic(pid):
""" in the case of a tie, the stat that rules the characteristic """
characteristic = pidtodec(pid) % 6
if characteristic == 0:
return 'HP'
elif characteristic == 1:
return 'Attack'
elif characteristic == 2:
return 'Defense'
elif characteristic == 3:
return 'Speed'
elif characteristic == 4:
return 'Special Attack'
elif characteristic == 5:
return 'Special Defense'
def characteristicint(pid):
""" in the case of a tie, the stat that rules the characteristic """
characteristic = pidtodec(pid) % 6
if characteristic == 0:
return 0
print ('HP')
elif characteristic == 1:
return 1
print ('Attack')
elif characteristic == 2:
return 2
print ('Defense')
elif characteristic == 3:
return 3
print ('Speed')
elif characteristic == 4:
return 4
print ('Special Attack')
elif characteristic == 5:
return 5
print ('Special Defense')
def ivmax(IVs):
""" (HP, Attack Defense, Speeed, Special Attack, Special Defense) """
for x in range(len(IVs)):
if IVs[x] == 'X':
IVs[x] = 0
maxiv = max(IVs)
return maxiv
def list_ivtie(IVs):
maxiv = ivmax(IVs)
for x in range(len(IVs)):
if IVs[x] == 'X':
IVs[x] = 0
indices = [i for i in range(len(IVs)) if IVs[i] == maxiv]
return indices
def iv_pid_char_index(IVs,pid):
""" determine the characteristic stat of given a set of IVs and a pid.
(HP, Attack, Defense,Speed,Special Attack, Special Defense)
You may enter X in the place of an IV as long as there are
known greater values """
index = characteristicint(pid)
maxivs = list_ivtie(IVs)
while 1:
if index in maxivs:
return index
else:
index = (index + 1) % 6
def characteristic_determine(IVs,pid):
""" Given a set of IVs and a PID, determines what the characteristic should be.
IVs must be formatted as a list in this order HP, Attack, Defense, Speed, Special Attack, Special Defense.
If you don't know a particular IV, you can enter 'X'.
Example If I know HP, Defense, Special Attack, Special Defense, and Speed are all 31 and attack is not 31,
You can enter [31,'X',31,31,31,31] in the IV field.  PID must be entered as a string e.g. 'AAAAAA' """
govstat = iv_pid_char_index(IVs,pid)
ref = ivmax(IVs) % 5
HP = ['Loves to eat','Often dozes off','Often scatters things','Scatters things often','Likes to relax']
Attack = ['Proud of its power','Likes to thrash about','A little quick tempered','Likes to fight','Quick tempered']
Defense = ['Sturdy body','Capable of taking hits','Highly persistent','Good endurance','Good perseverance']
SpecialAttack = ['Highly curious','Mischievous','Thoroughly cunning','Often lost in thought','Very finicky']
SpecialDefense = ['Strong willed','Somewhat vain','Strongly defiant','Hates to lose','Somewht stubborn']
Speed = ['Likes to run','Alert to sounds','Impetuous and silly','Somewhat of a clown','Quick to flee']
if govstat == 0:
return HP[ref]
elif govstat == 1:
return Attack[ref]
elif govstat == 2:
return Defense[ref]
elif govstat == 3:
return Speed[ref]
elif govstat == 4:
return SpecialAttack[ref]
elif govstat == 5:
return SpecialDefense[ref]
*/
string lookupcharacteristic(const int statid, const int iv, const int langid)
{
	return getastring(lookupcharacteristicsql(statid,iv,langid));
}
string lookupcharacteristic(const pokemon_obj &pkm, const int langid)
{
	int statid = 0;
	int highval = 0;
	ivtest ivbuf = {};
	vector<ivtest> ivs;
	ivbuf.id = Stat_IDs::hp;
	ivbuf.val = pkm.ivs.hp;
	ivbuf.order = 0;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::attack;
	ivbuf.val = pkm.ivs.attack;
	ivbuf.order = 1;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::defense;
	ivbuf.val = pkm.ivs.defense;
	ivbuf.order = 2;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::speed;
	ivbuf.val = pkm.ivs.speed;
	ivbuf.order = 3;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::spatk;
	ivbuf.val = pkm.ivs.spatk;
	ivbuf.order = 4;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::spdef;
	ivbuf.val = pkm.ivs.spdef;
	ivbuf.order = 5;
	ivs.push_back(ivbuf);
	sort(ivs.begin(),ivs.end(),compareivbyval);
	highval = ivs[0].val;
	sort(ivs.begin(),ivs.end(),compareivbyorder);
	int highcount = 0;
	for(int i=0;i<6;i++)
	{
		if(ivs[i].val == highval)
		{
			statid = i+1;
			highcount++;
		}
	}
	if(highcount == 1)
	{
		return lookupcharacteristic(statid,highval,langid);
	}
	int startindex = pkm.pid % 6;

	for(int i=0; i<6; i++)
	{
		if(ivs[startindex].val == highval)
		{
			return lookupcharacteristic(ivs[startindex].id,highval,langid);
		}
		startindex++;
		if(startindex ==6)
		{
			startindex = 0;
		}
	}
	return lookupcharacteristic(statid,highval,langid);
}
string lookupcharacteristic(const pokemon_obj *pkm, const int langid)
{
	int statid = 0;
	int highval = 0;
	ivtest ivbuf = {};
	vector<ivtest> ivs;
	ivbuf.id = Stat_IDs::hp;
	ivbuf.val = pkm->ivs.hp;
	ivbuf.order = 0;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::attack;
	ivbuf.val = pkm->ivs.attack;
	ivbuf.order = 1;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::defense;
	ivbuf.val = pkm->ivs.defense;
	ivbuf.order = 2;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::speed;
	ivbuf.val = pkm->ivs.speed;
	ivbuf.order = 3;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::spatk;
	ivbuf.val = pkm->ivs.spatk;
	ivbuf.order = 4;
	ivs.push_back(ivbuf);
	ivbuf.id = Stat_IDs::spdef;
	ivbuf.val = pkm->ivs.spdef;
	ivbuf.order = 5;
	ivs.push_back(ivbuf);
	sort(ivs.begin(),ivs.end(),compareivbyval);
	highval = ivs[0].val;
	sort(ivs.begin(),ivs.end(),compareivbyorder);
	int highcount = 0;
	for(int i=0;i<6;i++)
	{
		if(ivs[i].val == highval)
		{
			statid = (int)(ivs[i].id); //i+1;
			highcount++;
		}
	}
	if(highcount == 1)
	{
		return lookupcharacteristic(statid,highval,langid);
	}
	int startindex = pkm->pid % 6;

	for(int i=0; i<6; i++)
	{
		if(ivs[startindex].val == highval)
		{
			return lookupcharacteristic(ivs[startindex].id,highval,langid);
		}
		startindex++;
		if(startindex ==6)
		{
			startindex = 0;
		}
	}
	return lookupcharacteristic(statid,highval,langid);
}
string lookuppkmname(const int speciesid, const int langid)
{
	return getastring(getspeciesnamesql(speciesid,langid));
}
string lookuppkmname(const pokemon_obj &pkm, const int langid)
{
	return getastring(getspeciesnamesql(pkm.species,langid));
}
string lookuppkmname(const pokemon_obj *pkm, const int langid)
{
	return getastring(getspeciesnamesql(pkm->species, langid));
}
wstring lookuppkmnamewstring(const pokemon_obj *pkm, const int langid)
{
	ostringstream o;
	o << getspeciesnamesql(pkm->species, langid);
	return getawstring(o);
}
string lookupmovename(const int moveid, const int langid)
{
	return getastring(getmovenamesql(moveid,langid));
}
string lookupmovename(const pokemon_obj &pkm, const int movenum, const int langid)
{
	return getastring(getmovenamesql(pkm.moves[movenum],langid));
}
string lookupmovename(const pokemon_obj *pkm, const int movenum, const int langid)
{
	return getastring(getmovenamesql(pkm->moves[movenum],langid));
}
string getnaturename(const int natureid, const int langid)
{
	return getastring(getnaturenamesql(natureid,langid));
}
string getnaturename(const pokemon_obj &pkm, const int langid)
{
	if((pkm.nature_int == 0) && (pkm.hometown != Hometowns::black) && (pkm.hometown != Hometowns::white))
	{
		return getastring(getnaturenamesql(pkm.pid % 25,langid));
	}
	else
	{
		return getastring(getnaturenamesql(pkm.nature_int,langid));
	}
}
string getnaturename(const pokemon_obj *pkm, const int langid)
{
	if((pkm->nature == 0) && (pkm->hometown != Hometowns::black) && (pkm->hometown != Hometowns::white))
	{
		return getastring(getnaturenamesql(pkm->pid % 25,langid));
	}
	else
	{
		return getastring(getnaturenamesql(pkm->nature_int,langid));
	}
}
string lookupitemname(const int itemid, const int generation, const int langid)
{
	if(itemid == int(Items::godstone)){return "God Stone";}
	if(itemid == int(Items::xtransceiver2)){return lookupitemname(Items::xtransceiver,generation,langid);}
	if(itemid == int(Items::droppeditem2)){return lookupitemname(Items::droppeditem,generation,langid);}
	return getastring(lookupitemnamesql(itemid,generation,langid));
}
string lookupitemname(const pokemon_obj &pkm, const int generation, const int langid)
{
	if(pkm.item == Items::godstone){return "God Stone";}
	if(pkm.item == Items::xtransceiver2){return lookupitemname(Items::xtransceiver,generation,langid);}
	if(pkm.item == Items::droppeditem2){return lookupitemname(Items::droppeditem,generation,langid);}
	return getastring(lookupitemnamesql(pkm.item,generation,langid));
}
string lookupitemname(const pokemon_obj *pkm, const int generation, const int langid)
{
	if(pkm->item == Items::godstone){return "God Stone";}
	if(pkm->item == Items::xtransceiver2){return lookupitemname(Items::xtransceiver,generation,langid);}
	if(pkm->item == Items::droppeditem2){return lookupitemname(Items::droppeditem,generation,langid);}
	return getastring(lookupitemnamesql(pkm->item,generation,langid));
}
string lookupabilityname(const int abilityid, const int langid)
{
	return getastring(lookupabilitynamesql(abilityid,langid));
}
string lookupabilityname(const pokemon_obj &pkm, const int langid)
{
	return getastring(lookupabilitynamesql(pkm.ability,langid));
}
string lookupabilityname(const pokemon_obj *pkm, const int langid)
{
	return getastring(lookupabilitynamesql(pkm->ability,langid));
}
string getpkmgendername(const pokemon_obj &pkm)
{
	return getgendername(getpkmgender(pkm));
}
string getpkmgendername(const pokemon_obj *pkm)
{
	return getgendername(getpkmgender(pkm));
}
string getpkmmetlocname(const pokemon_obj &pkm, const int gen, const int langid)
{
	return lookuplocname(pkm.met,gen,langid);
}
string getpkmmetlocname(const pokemon_obj *pkm, const int gen, const int langid)
{
	return lookuplocname(pkm->met,gen,langid);
}
string getpkmegglocname(const pokemon_obj &pkm, const int gen, const int langid)
{
	return lookuplocname(pkm.eggmet,gen,langid);
}
string getpkmegglocname(const pokemon_obj *pkm, const int gen, const int langid)
{
	return lookuplocname(pkm->eggmet,gen,langid);
}
string lookuplocname(const int locid, const int gen, const int langid)
{
	if(locid == (int)Locations::unovavictoryroad2)
	{
		return "Victory Road (2)";
	}
	else
	{
		return getastring(lookuplocnamesql(locid,gen,langid));
	}
}
string getpkmformname(const pokemon_obj &pkm, const int generation, const int langid)
{
	return getastring(getpkmformnamesql(pkm,generation,langid));
}
string getpkmformname(const pokemon_obj *pkm, const int generation, const int langid)
{
	return getastring(getpkmformnamesql(pkm,generation,langid));
}
string getpkmformname(const int speciesid, const int formid, const int generation, const int langid)
{
	return getastring(getpkmformnamesql(speciesid,formid,generation,langid));
}
string getmachinetypename(const Items::items itemid, const int generation, const int version_group)
{
	return getastring(getmachinetypesql(itemid,generation,version_group));
}
string getpokemoncolorstring(const Species::species speciesid)
{
	return getastring(getpokemoncolorsql(speciesid));
}
int getpokemoncolor(const Species::species speciesid)
{
	return getanint(getpokemoncolorsql(speciesid));
}
uint32 getpkmcolor(const Species::species species)
{
	uint32 pkmcolor = getpkmcolorhex(getpokemoncolor(species));
	if(pkmcolor == 0)
	{
		return 0xF0F0F0;
	}
	return pkmcolor;
}
string getmachinemovename(const Items::items itemid, const int generation, const int version_group, const int langid)
{
	return getastring(getmachinemovenamesql(itemid,generation,version_group,langid));
}
int getitempocket(const Items::items itemid, const int generation)
{
	//if(itemid == int(Items::godstone)){return "God Stone";}
	if(itemid == Items::xtransceiver2){return getitempocket(Items::xtransceiver,generation);}
	if(itemid == Items::droppeditem2){return getitempocket(Items::droppeditem,generation);}
	return getanint(getitempocketsql(itemid,generation));
}
string getitempocketname(const Items::items itemid, const int generation, const int langid)
{
	if(itemid == Items::xtransceiver2){return getitempocketname(Items::xtransceiver,generation,langid);}
	if(itemid == Items::droppeditem2){return getitempocketname(Items::droppeditem,generation,langid);}
	return getastring(getitempocketnamesql(itemid,generation,langid));
}
item_obj * finditeminbag(bw2sav_obj * sav, Items::items itemid, int & slot)
{
	item_obj * itemp = new item_obj();
	slot = -1;
	switch(ItemPockets::itempockets(getitempocket(itemid)))
	{
	case ItemPockets::battle:
		for(int i = 0; i < sav->cur.bag.items_pocket.size(); i++)
		{
			if(sav->cur.bag.items_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.items_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::berries:
		for(int i = 0; i < sav->cur.bag.berries_pocket.size(); i++)
		{
			if(sav->cur.bag.berries_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.berries_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::key:
		for(int i = 0; i < sav->cur.bag.keyitems_pocket.size(); i++)
		{
			if(sav->cur.bag.keyitems_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.keyitems_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::machines:
		for(int i = 0; i < sav->cur.bag.tms_pocket.size(); i++)
		{
			if(sav->cur.bag.tms_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.tms_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::medicine:
		for(int i = 0; i < sav->cur.bag.medicine_pocket.size(); i++)
		{
			if(sav->cur.bag.medicine_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.medicine_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::misc:
		for(int i = 0; i < sav->cur.bag.items_pocket.size(); i++)
		{
			if(sav->cur.bag.items_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.items_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::pokeballs:
		for(int i = 0; i < sav->cur.bag.items_pocket.size(); i++)
		{
			if(sav->cur.bag.items_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.items_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	default:
		break;
		return itemp;
	}
}
item_obj * getavailablebagslot(bw2sav_obj * sav, ItemPockets::itempockets pocket, int & slot)
{
	item_obj * itemp = new item_obj();
	Items::items itemid = Items::NOTHING;
	slot = -1;
	switch(pocket)
	{
	case ItemPockets::battle:
		for(int i = 0; i < sav->cur.bag.items_pocket.size(); i++)
		{
			if(sav->cur.bag.items_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.items_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::berries:
		for(int i = 0; i < sav->cur.bag.berries_pocket.size(); i++)
		{
			if(sav->cur.bag.berries_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.berries_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::key:
		for(int i = 0; i < sav->cur.bag.keyitems_pocket.size(); i++)
		{
			if(sav->cur.bag.keyitems_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.keyitems_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::machines:
		for(int i = 0; i < sav->cur.bag.tms_pocket.size(); i++)
		{
			if(sav->cur.bag.tms_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.tms_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::medicine:
		for(int i = 0; i < sav->cur.bag.medicine_pocket.size(); i++)
		{
			if(sav->cur.bag.medicine_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.medicine_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::misc:
		for(int i = 0; i < sav->cur.bag.items_pocket.size(); i++)
		{
			if(sav->cur.bag.items_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.items_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	case ItemPockets::pokeballs:
		for(int i = 0; i < sav->cur.bag.items_pocket.size(); i++)
		{
			if(sav->cur.bag.items_pocket[i].id == itemid)
			{
				itemp = &(sav->cur.bag.items_pocket[i]);
				slot = i;
				return itemp;
			}
		}
		return itemp;
		break;
	default:
		return itemp;
		break;
	}
}
void removeitem(bw2sav_obj * sav, pokemon_obj * pkm)
{
	if(pkm->species != Species::NOTHING)
	{
		if(pkm->item != Items::NOTHING)
		{
			int itemslot = 0;
			item_obj * itemp = finditeminbag(sav,pkm->item,itemslot);
			if(itemslot == -1)
			{
				itemp = getavailablebagslot(sav,ItemPockets::itempockets(getitempocket(pkm->item)),itemslot);
				if(itemslot != -1)
				{
					itemp->id = pkm->item;
					itemp->quantity = 1;
					pkm->item = Items::NOTHING;
				}
			}
			else
			{
				itemp->quantity++;
				pkm->item = Items::NOTHING;
			}
			switch(pkm->species)
			{
			case Species::giratina:
				pkm->form.giratina_form = Forms::Giratina::altered;
				break;
			}
		}
	}
}
item_obj * getpocket(bw2sav_obj * sav, ItemPockets::itempockets pocket)
{
	item_obj * itemp = new item_obj();
	switch(pocket)
	{
	case ItemPockets::battle:
		itemp = &(sav->cur.bag.items_pocket[0]);
		break;
	case ItemPockets::berries:
		itemp = &(sav->cur.bag.berries_pocket[0]);
		break;
	case ItemPockets::key:
		itemp = &(sav->cur.bag.keyitems_pocket[0]);
		break;
	case ItemPockets::machines:
		itemp = &(sav->cur.bag.tms_pocket[0]);
		break;
	case ItemPockets::medicine:
		itemp = &(sav->cur.bag.medicine_pocket[0]);
		break;
	case ItemPockets::misc:
		itemp = &(sav->cur.bag.items_pocket[0]);
		break;
	case ItemPockets::pokeballs:
		itemp = &(sav->cur.bag.items_pocket[0]);
		break;
	default:
		break;
	}
	return itemp;
}
void tossitem(bw2sav_obj * sav, item_obj * item)
{
	int slot = 0;
	int bagsize = 0;
	item_obj blankitem;
	item_obj * bag = new item_obj();
	item_obj * testitem = finditeminbag(sav,item->id,slot);
	if((slot != -1) & (testitem == item))
	{
		bag = getpocket(sav,ItemPockets::itempockets(getitempocket(item->id)));
		switch(ItemPockets::itempockets(getitempocket(item->id)))
		{
		case ItemPockets::battle:
			bagsize = sav->cur.bag.items_pocket.size();
			break;
		case ItemPockets::berries:
			bagsize = sav->cur.bag.berries_pocket.size();
			break;
		case ItemPockets::key:
			bagsize = sav->cur.bag.keyitems_pocket.size();
			break;
		case ItemPockets::machines:
			bagsize = sav->cur.bag.tms_pocket.size();
			break;
		case ItemPockets::medicine:
			bagsize = sav->cur.bag.medicine_pocket.size();
			break;
		case ItemPockets::misc:
			bagsize = sav->cur.bag.items_pocket.size();
			break;
		case ItemPockets::pokeballs:
			bagsize = sav->cur.bag.items_pocket.size();
			break;
		default:
			break;
		}
		if(slot >= bagsize-1)
		{
			bag[bagsize-1] = blankitem;
		}
		else
		{
			memcpy(&(bag[slot]),&(bag[slot+1]),sizeof(item_obj)*(bagsize-slot));
			bag[bagsize-1] = blankitem;
		}
	}
}
void giveitem(bw2sav_obj * sav, item_obj * item, pokemon_obj * pkm)
{
	pkm->item = item->id;
	item->quantity--;
	if(item->quantity == 0)
	{
		tossitem(sav,item);
	}
	switch(pkm->species)
	{
	case Species::giratina:
		if(item->id == Items::griseousorb)
		{
			pkm->form.giratina_form = Forms::Giratina::origin;
		}
		break;
	}
}
void insertitem(bw2sav_obj * sav, item_obj * item, int slot)
{
	int test = 0;
	getavailablebagslot(sav,ItemPockets::itempockets(getitempocket(item->id)),test);
	item_obj * bag = getpocket(sav,ItemPockets::itempockets(getitempocket(item->id)));
	if(test != -1)
	{
		int bagsize = 0;
		switch(ItemPockets::itempockets(getitempocket(item->id)))
		{
		case ItemPockets::battle:
			bagsize = sav->cur.bag.items_pocket.size();
			break;
		case ItemPockets::berries:
			bagsize = sav->cur.bag.berries_pocket.size();
			break;
		case ItemPockets::key:
			bagsize = sav->cur.bag.keyitems_pocket.size();
			break;
		case ItemPockets::machines:
			bagsize = sav->cur.bag.tms_pocket.size();
			break;
		case ItemPockets::medicine:
			bagsize = sav->cur.bag.medicine_pocket.size();
			break;
		case ItemPockets::misc:
			bagsize = sav->cur.bag.items_pocket.size();
			break;
		case ItemPockets::pokeballs:
			bagsize = sav->cur.bag.items_pocket.size();
			break;
		default:
			break;
		}
		if(slot >= bagsize)
		{
			bag[bagsize-1] = *item;
		}
		else
		{
			memcpy(bag+slot,bag+slot-1,sizeof(item_obj) * (bagsize-slot-1));
			bag[slot] = *item;
		}
	}
}
string lookupitemflavortext(const int itemid, const int generation, const int langid, const int versiongroup)
{
	return getastring(lookupitemflavortextsql(itemid, generation,langid,versiongroup));
}