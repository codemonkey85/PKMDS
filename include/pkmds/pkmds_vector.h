#pragma once
#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5_sqlite.h>
#else
#include "pkmds_sql.h"
#endif
#ifndef __cplusplus_cli
bool DllExport comparebyspeciesasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbyspeciesasc(std::vector<pokemon_obj>& pkm);
bool DllExport comparebygenderasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbygenderasc(std::vector<pokemon_obj>& pkm);
bool DllExport comparebyformasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbyformasc(std::vector<pokemon_obj>& pkm);
bool DllExport comparebyattackasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbyattackasc(std::vector<pokemon_obj>& pkm);
bool DllExport comparebydefenseasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbydefenseasc(std::vector<pokemon_obj>& pkm);
bool DllExport comparebyspeedasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbyspeedasc(std::vector<pokemon_obj>& pkm);
bool DllExport comparebyspatkasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbyspatkasc(std::vector<pokemon_obj>& pkm);
bool DllExport comparebyspdefasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbyspdefasc(std::vector<pokemon_obj>& pkm);
bool DllExport comparebyhpasc(const pokemon_obj &a, const pokemon_obj &b);
void DllExport sortbyhpasc(std::vector<pokemon_obj>& pkm);
bool comparebyitemidasc(const item_obj & a, const item_obj & b);
void sortbyitemidasc(std::array<item_obj,310> &items);
bool comparebyitemiddesc(const item_obj & a, const item_obj & b);
void sortbyitemiddesc(std::array<item_obj,310> &items);
//TODO: Create a vector of pointers to pokemon_obj that can be manipulated for the purpose of inserting and deleting pokemon in the pc storage system.
std::vector<pokemon_obj> DllExport *getpcvector(bw2savblock_obj * block, const bool encrypted = true);
std::vector<pokemon_obj*> DllExport *getpcvectorp(bw2savblock_obj * block, const bool encrypted = true);
bool DllExport comparebyspeciesascp(pokemon_obj *a, pokemon_obj *b);
void DllExport sortbyspeciesascp(std::vector<pokemon_obj*>* pkm);
bool DllExport comparebygenderascp(const pokemon_obj *a, const pokemon_obj *b);
//void DllExport sortbygenderascp(std::vector<pokemon_obj>* pkm);
bool DllExport comparebyformascp(const pokemon_obj *a, const pokemon_obj *b);
//void DllExport sortbyformascp(std::vector<pokemon_obj>* pkm);
bool DllExport comparebyattackascp(const pokemon_obj *a, const pokemon_obj *b);
//void DllExport sortbyattackascp(std::vector<pokemon_obj>* pkm);
bool DllExport comparebydefenseascp(const pokemon_obj *a, const pokemon_obj *b);
//void DllExport sortbydefenseascp(std::vector<pokemon_obj>* pkm);
bool DllExport comparebyspeedascp(const pokemon_obj *a, const pokemon_obj *b);
//void DllExport sortbyspeedascp(std::vector<pokemon_obj>* pkm);
bool DllExport comparebyspatkascp(const pokemon_obj *a, const pokemon_obj *b);
//void DllExport sortbyspatkascp(std::vector<pokemon_obj>* pkm);
bool DllExport comparebyspdefascp(const pokemon_obj *a, const pokemon_obj *b);
//void DllExport sortbyspdefascp(std::vector<pokemon_obj>* pkm);
bool DllExport comparebyhpascp(const pokemon_obj *a, const pokemon_obj *b);
//void DllExport sortbyhpascp(std::vector<pokemon_obj>* pkm);
#endif
