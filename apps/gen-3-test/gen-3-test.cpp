#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_sql.h>
#include <pkmds/pkmds_gba.h>
#else
#include "..\\..\\include\\pkmds\\pkmds_sql.h"
#include "..\\..\\include\\pkmds\\pkmds_gba.h"
#endif
using namespace std;
string outputpath = "C:\\Users\\Michael Bond\\Downloads\\GBA PKM DUMPED\\";
void dostuff(pokemon_gen3 * gbapkm);
int main(int argc, char* argv[])
{
	string savefile;
	savefile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\Pokemon - Fire Red GBA_MODIFIED.sav";
	gbasavefilepacked* savin = new gbasavefilepacked();
	gbasavefile* sav = new gbasavefile();
	pokemon_gen3* pkm = new pokemon_gen3();
	read(savefile.c_str(),savin);
	buildgbasave(savin,sav);
	opendb("C:\\Users\\Michael Bond\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite");
	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			pkm = &(sav->pcstorage.pcstorage[box][slot]);
			decryptgbapkm(pkm);
			shufflegbapkm(pkm,true);
			if(pkm->data.species != GBASpecies::NOTHING)
			{
				dostuff(pkm);
			}
		}
	}
	closedb();
	cout << "\nEND\n";
	string test;
	cin >> test;
	return 0;
}
void dostuff(pokemon_gen3 * gbapkm)
{
	pokemon_obj * pkm = new pokemon_obj();
	std::ostringstream o;
	o 
		<< "SELECT abilities.id FROM abilities INNER JOIN ability_names ON abilities.id =  "
		<< "ability_names.ability_id INNER JOIN pokemon_abilities ON abilities.id =  "
		<< "pokemon_abilities.ability_id INNER JOIN pokemon ON pokemon_abilities.pokemon_id "
		<< " = pokemon.id WHERE ( ability_names.local_language_id = 9 ) AND ( pokemon.species_id "
		<< " = " << int(gbapkm->data.species) << " ) AND ( abilities.generation_id = 3 ) AND ( pokemon_abilities.slot "
		<< " = " << int(gbapkm->data.ivs.ability_flag) << " + 1 ) ";
	int ability = getanint(o);
	if(ability == 0)
	{
		o.str("");
		o.clear();
		o 
			<< "SELECT abilities.id FROM abilities INNER JOIN ability_names ON abilities.id =  "
			<< "ability_names.ability_id INNER JOIN pokemon_abilities ON abilities.id =  "
			<< "pokemon_abilities.ability_id INNER JOIN pokemon ON pokemon_abilities.pokemon_id "
			<< " = pokemon.id WHERE ( ability_names.local_language_id = 9 ) AND ( pokemon.species_id "
			<< " = " << int(gbapkm->data.species) << " ) AND ( abilities.generation_id = 3 ) AND ( pokemon_abilities.slot "
			<< " = 1) ";
		ability = getanint(o);
	}
	pkm->ability = Abilities::abilities(ability);
	pkm->contest.beauty = gbapkm->data.contest.beauty;
	pkm->contest.cool = gbapkm->data.contest.cool;
	pkm->contest.cute = gbapkm->data.contest.cute;
	pkm->contest.sheen = gbapkm->data.contest.sheen;
	pkm->contest.smart = gbapkm->data.contest.smart;
	pkm->contest.tough = gbapkm->data.contest.tough;
	switch(gbapkm->lang)
	{
	case 0201:
		pkm->country = Countries::japanese;
		break;
	case 0202:
		pkm->country = Countries::english;
		break;
	case 0203:
		pkm->country = Countries::french;
		break;
	case 0204:
		pkm->country = Countries::italian;
		break;
	case 0205:
		pkm->country = Countries::german;
		break;
	case 0206:
		pkm->country = Countries::southkorean;
		break;
	case 0207:
		pkm->country = Countries::spanish;
		break;
	default:
		pkm->country = Countries::english;
	}
	pkm->encounter = Encounters::palpark_egg_hatched_specialevent;
	pkm->evs.attack = gbapkm->data.evs.attack;
	pkm->evs.defense = gbapkm->data.evs.defense;
	pkm->evs.hp = gbapkm->data.evs.hp;
	pkm->evs.spatk = gbapkm->data.evs.spatk;
	pkm->evs.spdef = gbapkm->data.evs.spdef;
	pkm->evs.speed = gbapkm->data.evs.speed;
	pkm->exp = gbapkm->data.exp;
	pkm->ivs.attack = gbapkm->data.ivs.attack;
	pkm->ivs.defense = gbapkm->data.ivs.defense;
	pkm->ivs.hp = gbapkm->data.ivs.hp;
	pkm->ivs.spatk = gbapkm->data.ivs.spatk;
	pkm->ivs.spdef = gbapkm->data.ivs.spdef;
	pkm->ivs.speed = gbapkm->data.ivs.speed;
	pkm->ivs.isegg = gbapkm->data.ivs.isegg;
	pkm->met = Locations::poketransfer;
	pkm->metlevel_otgender.metlevel = gbapkm->data.origins.metlevel;
	pkm->metlevel_otgender.otgender = Genders::genders(int(gbapkm->data.origins.trainergender));
	pkm->nature = Natures::natures(gbapkm->pid % 25);
	pkm->pid = gbapkm->pid;
	pkm->ppup[0] = gbapkm->data.ppbonuses.move1;
	pkm->ppup[1] = gbapkm->data.ppbonuses.move2;
	pkm->ppup[2] = gbapkm->data.ppbonuses.move3;
	pkm->ppup[3] = gbapkm->data.ppbonuses.move4;
	pkm->sid = gbapkm->sid;
	pkm->species = Species::pkmspecies(convertgbaspecies(gbapkm->data.species));
	pkm->tameness = gbapkm->data.friendship;
	pkm->tid = gbapkm->tid;
	for(int i = 0; i < 4; i++)
	{
		pkm->pp[i] = gbapkm->data.movepp[i];
		//pkm->moves[0] = 
	}
	//pkm->forms.female = 
	// 3gpkm[0x4F] >> 7 retrieves the true/false of FE flag
	//pkm->forms.fencounter = 
	//pkm->forms.genderless = 
	//pkm->hometown = 
	//pkm->item = 
	//pkm->metdate.day = 
	//pkm->metdate.month = 
	//pkm->metdate.year = 
	//pkm->nickname = 
	//pkm->otname = 
	//pkm->ivs.isnicknamed = 
	//pkm->pkrs.days = 
	//pkm->markings.circle = 
	//pkm->ball = 
	/*
	Other

	Ribbons aren't really documented anywhere else so I'd probably better cover them here.

	In the 'Misc' data block of each pokemon, there is a single Word value that stores the ribbons attached to that pokemon. It's a bit odd as there are significantly more that 32 ribbons so I'll try to break it down here.

	Contest Ribbons
	The first 15 bits tell us what contest ribbons the pokemon holds, but it's not a case of it being 1 bit per ribbon. Instead, what he have is 3 bits per ribbon, each showing a value representing the number of ranks that pokemon has achieved per contest type:

	0 - 2 -> Cool Rank
	3 - 5 -> Beauty Rank
	6 - 7 -> Cute Rank
	9 -11 -> Smart Rank
	12-14 -> Tough Rank
	Each value gives us from 0 - 4, 0 being no rank, 4 being master rank. When a pokemon is any rank higher than 1, they will have all the ribbons for earlier ranks as well.

	Other Ribbons
	The next few bits give specific ribbons:

	Bit 15 -> Champion Ribbon
	Bit 18 -> Artist Ribbon
	Bit 19 -> Effort Ribbon
	Bit 24 -> Cleared All Difficulties Ribbon (Purified on Colusseum)
	*/
	//pkm->hribbon1.beauty_ribbon = 
	//pkm->hribbon2.artist_ribbon = 
	//pkm->sribbon1.ability_ribbon = 
	//pkm->sribbon2.blue_ribbon = 
	//pkm->sribbon3.beauty_ribbon = 
	//pkm->sribbon4.tough_ribbon = 
	cout << lookuppkmname(pkm);
}
