#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#else
#include "pkmds_g5_sqlite.h"
#endif
party_pkm * ppkm;
pokemon_obj * pkm;
sqlite3 *db;
sqlite3_stmt *stmt;
std::string TableName;
vector<std::string> POSValues;
vector<std::string> positions;
int frmCurBoxNum;
bw2savblock_obj * cursavblock;
int frmCurSlotNum;
void createtable();
void dosearch(vector<std::string> columns, string where, string order, int limit);
