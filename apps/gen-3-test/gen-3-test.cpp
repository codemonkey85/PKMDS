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
	//savefile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\pokemon_emerald_version - Copy2.sav";
	savefile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\Pokemon - Fire Red GBA_MODIFIED.sav";
	const char * pkmfile = "C:\\Users\\Michael Bond\\Dropbox\\Saves\\Gengar_heart.3gpkm";
	gbasavefilepacked* savin = new gbasavefilepacked();
	gbasavefile* sav = new gbasavefile();
	pokemon_gen3* pkm = new pokemon_gen3();
	read(savefile.c_str(),savin);
	buildgbasave(savin,sav);
	opendb("C:\\Users\\Michael Bond\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite");

	//read(pkmfile,pkm);
	//dostuff(pkm);

	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			pkm = &(sav->pcstorage.pcstorage[box][slot]);
			decryptgbapkm(pkm);
			shufflegbapkm(pkm,true);
			if(pkm->data.species != GBASpecies::NOTHING)
			{
				//if(pkm->data.species == GBASpecies::squirtle)
				//{
				//uint32 * ribbons = reinterpret_cast<uint32*>(&(pkm->data.ribbons));
				//if(*ribbons != 0)
				//{
				dostuff(pkm);
				//}
				//}
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
	switch(gbapkm->data.ribbons.beauty)
	{
	case 4:
		pkm->hribbon1.beauty_ribbon_master = true;
		pkm->hribbon1.beauty_ribbon_hyper = true;
		pkm->hribbon1.beauty_ribbon_super = true;
		pkm->hribbon1.beauty_ribbon = true;
		break;
	case 3:
		pkm->hribbon1.beauty_ribbon_hyper = true;
		pkm->hribbon1.beauty_ribbon_super = true;
		pkm->hribbon1.beauty_ribbon = true;
		break;
	case 2:
		pkm->hribbon1.beauty_ribbon_super = true;
		pkm->hribbon1.beauty_ribbon = true;
		break;
	case 1:
		pkm->hribbon1.beauty_ribbon = true;
		break;
	}
	switch(gbapkm->data.ribbons.cool)
	{
	case 4:
		pkm->hribbon1.cool_ribbon_master = true;
		pkm->hribbon1.cool_ribbon_hyper = true;
		pkm->hribbon1.cool_ribbon_super = true;
		pkm->hribbon1.cool_ribbon = true;
		break;
	case 3:
		pkm->hribbon1.cool_ribbon_hyper = true;
		pkm->hribbon1.cool_ribbon_super = true;
		pkm->hribbon1.cool_ribbon = true;
		break;
	case 2:
		pkm->hribbon1.cool_ribbon_super = true;
		pkm->hribbon1.cool_ribbon = true;
		break;
	case 1:
		pkm->hribbon1.cool_ribbon = true;
		break;
	}
	switch(gbapkm->data.ribbons.cute)
	{
	case 4:
		pkm->hribbon1.cute_ribbon_master = true;
		pkm->hribbon1.cute_ribbon_hyper = true;
		pkm->hribbon1.cute_ribbon_super = true;
		pkm->hribbon1.cute_ribbon = true;
		break;
	case 3:
		pkm->hribbon1.cute_ribbon_hyper = true;
		pkm->hribbon1.cute_ribbon_super = true;
		pkm->hribbon1.cute_ribbon = true;
		break;
	case 2:
		pkm->hribbon1.cute_ribbon_super = true;
		pkm->hribbon1.cute_ribbon = true;
		break;
	case 1:
		pkm->hribbon1.cute_ribbon = true;
		break;
	}
	switch(gbapkm->data.ribbons.smart)
	{
	case 4:
		pkm->hribbon1.smart_ribbon_master = true;
		pkm->hribbon1.smart_ribbon_hyper = true;
		pkm->hribbon1.smart_ribbon_super = true;
		pkm->hribbon1.smart_ribbon = true;
		break;
	case 3:
		pkm->hribbon1.smart_ribbon_hyper = true;
		pkm->hribbon1.smart_ribbon_super = true;
		pkm->hribbon1.smart_ribbon = true;
		break;
	case 2:
		pkm->hribbon1.smart_ribbon_super = true;
		pkm->hribbon1.smart_ribbon = true;
		break;
	case 1:
		pkm->hribbon1.smart_ribbon = true;
		break;
	}
	switch(gbapkm->data.ribbons.tough)
	{
	case 4:
		pkm->hribbon2.tough_ribbon_master = true;
		pkm->hribbon2.tough_ribbon_hyper = true;
		pkm->hribbon2.tough_ribbon_super = true;
		pkm->hribbon2.tough_ribbon = true;
		break;
	case 3:
		pkm->hribbon2.tough_ribbon_hyper = true;
		pkm->hribbon2.tough_ribbon_super = true;
		pkm->hribbon2.tough_ribbon = true;
		break;
	case 2:
		pkm->hribbon2.tough_ribbon_super = true;
		pkm->hribbon2.tough_ribbon = true;
		break;
	case 1:
		pkm->hribbon2.tough_ribbon = true;
		break;
	}
	pkm->hribbon2.artist_ribbon = bool(gbapkm->data.ribbons.artist);
	pkm->hribbon2.champion_ribbon = bool(gbapkm->data.ribbons.champion);
	pkm->hribbon2.effort_ribbon = bool(gbapkm->data.ribbons.effort);
	pkm->hribbon2.national_ribbon = bool(gbapkm->data.ribbons.national);
	pkm->forms.fencounter = gbapkm->data.ribbons.fencounter;
	Genders::genders gender = calcpkmgender(pkm);
	pkm->forms.female = (gender == Genders::female);
	pkm->forms.genderless = (gender == Genders::genderless);
	pkm->markings.circle = bool(gbapkm->mark.circle);
	pkm->markings.square = bool(gbapkm->mark.square);
	pkm->markings.heart = bool(gbapkm->mark.heart);
	pkm->markings.triangle = bool(gbapkm->mark.triangle);
	for(int i = 0; i < 4; i++)
	{
		pkm->pp[i] = gbapkm->data.movepp[i];
		//pkm->moves[0] = 
	}
	switch(gbapkm->data.origins.game)
	{
	case GBAGames::colosseum_bonus_disc:
		pkm->hometown = Hometowns::colosseum_bonus;
		break;
	case GBAGames::colosseum_xd:
		pkm->hometown = Hometowns::colosseum;
		break;
	case GBAGames::emerald:
		pkm->hometown = Hometowns::emerald;
		break;
	case GBAGames::firered:
		pkm->hometown = Hometowns::firered;
		break;
	case GBAGames::leafgreen:
		pkm->hometown = Hometowns::leafgreen;
		break;
	case GBAGames::ruby:
		pkm->hometown = Hometowns::ruby;
		break;
	case GBAGames::sapphire:
		pkm->hometown = Hometowns::sapphire;
		break;
	}
	switch(gbapkm->data.origins.ball)
	{
	case GBABalls::diveball:
		pkm->ball = Balls::diveball;
		break;
	case GBABalls::greatball:
		pkm->ball = Balls::greatball;
		break;
	case GBABalls::luxuryball:
		pkm->ball = Balls::luxuryball;
		break;
	case GBABalls::masterball:
		pkm->ball = Balls::masterball;
		break;
	case GBABalls::nestball:
		pkm->ball = Balls::nestball;
		break;
	case GBABalls::netball:
		pkm->ball = Balls::netball;
		break;
	case GBABalls::pokeball:
		pkm->ball = Balls::pokeball;
		break;
	case GBABalls::premierball:
		pkm->ball = Balls::premierball;
		break;
	case GBABalls::repeatball:
		pkm->ball = Balls::repeatball;
		break;
	case GBABalls::safariball:
		pkm->ball = Balls::safariball;
		break;
	case GBABalls::timerball:
		pkm->ball = Balls::timerball;
		break;
	case GBABalls::ultraball:
		pkm->ball = Balls::ultraball;
		break;
	}
	time_t t = time(0);
	struct tm * now = localtime( & t );
	pkm->metdate.day = now->tm_mday;
	pkm->metdate.month = now->tm_mon + 1;
	pkm->metdate.year = now->tm_year -100;
	pkm->pkrs.days = gbapkm->data.pkrs.days;
	pkm->pkrs.strain = gbapkm->data.pkrs.strain;
	//pkm->item = 
	//pkm->nickname = 
	//pkm->otname = 
	//pkm->ivs.isnicknamed = 
	cout << lookuppkmname(pkm);
}
