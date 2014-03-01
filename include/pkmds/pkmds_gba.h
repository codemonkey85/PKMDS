#pragma once
//#ifdef PKMDS_CMAKE_USED
//#include <pkmds/stdafx.h>
//#else
//#include "stdafx.h"
//#endif

#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_sql.h>
#else
#include "pkmds_sql.h"
#endif
#include <string>
#include <locale>

#include <vector>
namespace GBASpecies
{
	enum gbaspecies : uint16 
	{
		NOTHING=0,
		bulbasaur=1,
		ivysaur=2,
		venusaur=3,
		charmander=4,
		charmeleon=5,
		charizard=6,
		squirtle=7,
		wartortle=8,
		blastoise=9,
		caterpie=10,
		metapod=11,
		butterfree=12,
		weedle=13,
		kakuna=14,
		beedrill=15,
		pidgey=16,
		pidgeotto=17,
		pidgeot=18,
		rattata=19,
		raticate=20,
		spearow=21,
		fearow=22,
		ekans=23,
		arbok=24,
		pikachu=25,
		raichu=26,
		sandshrew=27,
		sandslash=28,
		nidoran_f=29,
		nidorina=30,
		nidoqueen=31,
		nidoran_m=32,
		nidorino=33,
		nidoking=34,
		clefairy=35,
		clefable=36,
		vulpix=37,
		ninetales=38,
		jigglypuff=39,
		wigglytuff=40,
		zubat=41,
		golbat=42,
		oddish=43,
		gloom=44,
		vileplume=45,
		paras=46,
		parasect=47,
		venonat=48,
		venomoth=49,
		diglett=50,
		dugtrio=51,
		meowth=52,
		persian=53,
		psyduck=54,
		golduck=55,
		mankey=56,
		primeape=57,
		growlithe=58,
		arcanine=59,
		poliwag=60,
		poliwhirl=61,
		poliwrath=62,
		abra=63,
		kadabra=64,
		alakazam=65,
		machop=66,
		machoke=67,
		machamp=68,
		bellsprout=69,
		weepinbell=70,
		victreebel=71,
		tentacool=72,
		tentacruel=73,
		geodude=74,
		graveler=75,
		golem=76,
		ponyta=77,
		rapidash=78,
		slowpoke=79,
		slowbro=80,
		magnemite=81,
		magneton=82,
		farfetchd=83,
		doduo=84,
		dodrio=85,
		seel=86,
		dewgong=87,
		grimer=88,
		muk=89,
		shellder=90,
		cloyster=91,
		gastly=92,
		haunter=93,
		gengar=94,
		onix=95,
		drowzee=96,
		hypno=97,
		krabby=98,
		kingler=99,
		voltorb=100,
		electrode=101,
		exeggcute=102,
		exeggutor=103,
		cubone=104,
		marowak=105,
		hitmonlee=106,
		hitmonchan=107,
		lickitung=108,
		koffing=109,
		weezing=110,
		rhyhorn=111,
		rhydon=112,
		chansey=113,
		tangela=114,
		kangaskhan=115,
		horsea=116,
		seadra=117,
		goldeen=118,
		seaking=119,
		staryu=120,
		starmie=121,
		mr_mime=122,
		scyther=123,
		jynx=124,
		electabuzz=125,
		magmar=126,
		pinsir=127,
		tauros=128,
		magikarp=129,
		gyarados=130,
		lapras=131,
		ditto=132,
		eevee=133,
		vaporeon=134,
		jolteon=135,
		flareon=136,
		porygon=137,
		omanyte=138,
		omastar=139,
		kabuto=140,
		kabutops=141,
		aerodactyl=142,
		snorlax=143,
		articuno=144,
		zapdos=145,
		moltres=146,
		dratini=147,
		dragonair=148,
		dragonite=149,
		mewtwo=150,
		mew=151,
		chikorita=152,
		bayleef=153,
		meganium=154,
		cyndaquil=155,
		quilava=156,
		typhlosion=157,
		totodile=158,
		croconaw=159,
		feraligatr=160,
		sentret=161,
		furret=162,
		hoothoot=163,
		noctowl=164,
		ledyba=165,
		ledian=166,
		spinarak=167,
		ariados=168,
		crobat=169,
		chinchou=170,
		lanturn=171,
		pichu=172,
		cleffa=173,
		igglybuff=174,
		togepi=175,
		togetic=176,
		natu=177,
		xatu=178,
		mareep=179,
		flaaffy=180,
		ampharos=181,
		bellossom=182,
		marill=183,
		azumarill=184,
		sudowoodo=185,
		politoed=186,
		hoppip=187,
		skiploom=188,
		jumpluff=189,
		aipom=190,
		sunkern=191,
		sunflora=192,
		yanma=193,
		wooper=194,
		quagsire=195,
		espeon=196,
		umbreon=197,
		murkrow=198,
		slowking=199,
		misdreavus=200,
		unown=201,
		wobbuffet=202,
		girafarig=203,
		pineco=204,
		forretress=205,
		dunsparce=206,
		gligar=207,
		steelix=208,
		snubbull=209,
		granbull=210,
		qwilfish=211,
		scizor=212,
		shuckle=213,
		heracross=214,
		sneasel=215,
		teddiursa=216,
		ursaring=217,
		slugma=218,
		magcargo=219,
		swinub=220,
		piloswine=221,
		corsola=222,
		remoraid=223,
		octillery=224,
		delibird=225,
		mantine=226,
		skarmory=227,
		houndour=228,
		houndoom=229,
		kingdra=230,
		phanpy=231,
		donphan=232,
		porygon2=233,
		stantler=234,
		smeargle=235,
		tyrogue=236,
		hitmontop=237,
		smoochum=238,
		elekid=239,
		magby=240,
		miltank=241,
		blissey=242,
		raikou=243,
		entei=244,
		suicune=245,
		larvitar=246,
		pupitar=247,
		tyranitar=248,
		lugia=249,
		ho_oh=250,
		celebi=251,
		treecko=277,
		grovyle=278,
		sceptile=279,
		torchic=280,
		combusken=281,
		blaziken=282,
		mudkip=283,
		marshtomp=284,
		swampert=285,
		poochyena=286,
		mightyena=287,
		zigzagoon=288,
		linoone=289,
		wurmple=290,
		silcoon=291,
		beautifly=292,
		cascoon=293,
		dustox=294,
		lotad=295,
		lombre=296,
		ludicolo=297,
		seedot=298,
		nuzleaf=299,
		shiftry=300,
		taillow=304,
		swellow=305,
		wingull=309,
		pelipper=310,
		ralts=392,
		kirlia=393,
		gardevoir=394,
		surskit=311,
		masquerain=312,
		shroomish=306,
		breloom=307,
		slakoth=364,
		vigoroth=365,
		slaking=366,
		nincada=301,
		ninjask=302,
		shedinja=303,
		whismur=370,
		loudred=371,
		exploud=372,
		makuhita=335,
		hariyama=336,
		azurill=350,
		nosepass=320,
		skitty=315,
		delcatty=316,
		sableye=322,
		mawile=355,
		aron=382,
		lairon=383,
		aggron=384,
		meditite=356,
		medicham=357,
		electrike=337,
		manectric=338,
		plusle=353,
		minun=354,
		volbeat=386,
		illumise=387,
		roselia=363,
		gulpin=367,
		swalot=368,
		carvanha=330,
		sharpedo=331,
		wailmer=313,
		wailord=314,
		numel=339,
		camerupt=340,
		torkoal=321,
		spoink=351,
		grumpig=352,
		spinda=308,
		trapinch=332,
		vibrava=333,
		flygon=334,
		cacnea=344,
		cacturne=345,
		swablu=358,
		altaria=359,
		zangoose=380,
		seviper=379,
		lunatone=348,
		solrock=349,
		barboach=323,
		whiscash=324,
		corphish=326,
		crawdaunt=327,
		baltoy=318,
		claydol=319,
		lileep=388,
		cradily=389,
		anorith=390,
		armaldo=391,
		feebas=328,
		milotic=329,
		castform=385,
		kecleon=317,
		shuppet=377,
		banette=378,
		duskull=361,
		dusclops=362,
		tropius=369,
		chimecho=411,
		absol=376,
		wynaut=360,
		snorunt=346,
		glalie=347,
		spheal=341,
		sealeo=342,
		walrein=343,
		clamperl=373,
		huntail=374,
		gorebyss=375,
		relicanth=381,
		luvdisc=325,
		bagon=395,
		shelgon=396,
		salamence=397,
		beldum=398,
		metang=399,
		metagross=400,
		regirock=401,
		regice=402,
		registeel=403,
		latias=407,
		latios=408,
		kyogre=404,
		groudon=405,
		rayquaza=406,
		jirachi=409,
		deoxys=410
	};
}
namespace GBAGames
{
	enum gbagames : uint16
	{
		colosseum_bonus_disc,
		sapphire,
		ruby,
		emerald,
		firered,
		leafgreen,
		colosseum_xd=15
	};
}
namespace GBABalls
{
	enum gbaballs : uint16
	{
		masterball=1,
		ultraball,
		greatball,
		pokeball,
		safariball,
		netball,
		diveball,
		nestball,
		repeatball,
		timerball,
		luxuryball,
		premierball
	};
}
struct gbapkrs
{
	byte days : 4;
	byte strain : 4;
	gbapkrs()
	{
		memset(this,0,sizeof(gbapkrs));
	};
};
struct gbaribbons
{
	uint32 cool : 3;
	uint32 beauty : 3;
	uint32 cute : 3;
	uint32 smart : 3;
	uint32 tough : 3;
	uint32 champion : 1;
uint32 : 2;
	uint32 artist : 1;
	uint32 effort : 1;
uint32 : 4;
	uint32 national : 1;
uint32 : 6;
	uint32 fencounter : 1;
	gbaribbons()
	{
		memset(this,0,sizeof(gbaribbons));
	};
};
struct gbamarks
{
	byte circle : 1;
	byte square : 1;
	byte triangle : 1;
	byte heart : 1;
byte : 4;
	gbamarks()
	{
		memset(this,0,sizeof(gbamarks));
	};
};
struct ppbonuses_struct
{
	byte move1 : 2;
	byte move2 : 2;
	byte move3 : 2;
	byte move4 : 2;
	ppbonuses_struct()
	{
		memset(this,0,sizeof(ppbonuses_struct));
	};
};
struct gbaevsfield {
	byte hp; // HP EVs
	byte attack; // Attack EVs
	byte defense; // Defense EVs
	byte speed; // Speed EVs
	byte spatk; // Special Attack EVs
	byte spdef; // Special Defnse EVs
	gbaevsfield()
	{
		memset(this,0,sizeof(gbaevsfield));
	}
};
struct gbacontestfield {
	byte cool; // Cool
	byte beauty; // Beauty; used for Feebas evolution (to Milotic)
	byte cute; // Cute
	byte smart; // Smart
	byte tough; // Tough
	byte sheen; // Sheen
	gbacontestfield()
	{
		memset(this,0,sizeof(gbacontestfield));
	}
};
struct origins_struct
{
	uint16 metlevel : 7;
	GBAGames::gbagames game : 4;
	GBABalls::gbaballs ball : 4;
	uint16 trainergender : 1;
	origins_struct()
	{
		memset(this,0,sizeof(origins_struct));
	};
};
struct ivs_struct 
{
public:
	uint32 hp : 5;
	uint32 attack : 5;
	uint32 defense : 5;
	uint32 speed : 5;
	uint32 spatk : 5;
	uint32 spdef : 5;
	uint32 isegg : 1;
	uint32 ability_flag : 1;
	ivs_struct()
	{
		memset(this,0,sizeof(ivs_struct));
	}
};
struct growth_block
{
	GBASpecies::gbaspecies species;
	uint16 item;
	uint32 exp;
	ppbonuses_struct ppbonuses;
	byte friendship;
uint16 : 16;
	growth_block()
	{
		memset(this,0,sizeof(growth_block));
	};
};
struct moves_block
{
	uint16 moves[4];
	byte movepp[4];
	moves_block()
	{
		memset(this,0,sizeof(moves_block));
	};
};
struct evscondition_block
{
	gbaevsfield evs;
	gbacontestfield contest;
	evscondition_block()
	{
		memset(this,0,sizeof(evscondition_block));
	};
};
struct misc_block
{
	gbapkrs pkrs;
	byte metloc;
	origins_struct origins;
	ivs_struct ivs;
	gbaribbons ribbons;
	misc_block()
	{
		memset(this,0,sizeof(misc_block));
	};
};
struct pkmdata : growth_block, moves_block, evscondition_block, misc_block
{
	pkmdata()
	{
		memset(this,0,sizeof(pkmdata));
	};
};
struct pokemon_gen3
{
	uint32 pid;
	uint16 tid;
	uint16 sid;
	byte nickname[10];
	uint16 lang;
	byte otname[7];
	gbamarks mark;
	uint16 checksum;
uint16 : 16;
	pkmdata data;
	pokemon_gen3()
	{
		memset(this,0,sizeof(pokemon_gen3));
	};
};
struct pokemon_gen3_party : pokemon_gen3
{
	uint32 status;
	byte level;
	byte pkrs_remaining;
	uint16 curhp;
	uint16 totalhp;
	uint16 atk;
	uint16 def;
	uint16 speed;
	uint16 spatk;
	uint16 spdef;
	pokemon_gen3_party()
	{
		memset(this,0,sizeof(pokemon_gen3_party));
	};
};
struct gbasavefooter
{
	byte sectionid;
byte : 8;
	uint16 checksum;
	uint32 validation;
	uint32 saveindex;
};
struct gbasaveblockpacked
{
	byte data[4084];
	//byte padding[116];
	gbasavefooter footer;
};
struct gbasavehalfpacked
{
	std::array<gbasaveblockpacked,16> blocks;
};
struct gbasavefilepacked
{
	gbasavehalfpacked savea;
	gbasavehalfpacked saveb;
	//byte unknown[16384];
};

//struct gbasaveblockpacked
//{
//	byte data[3968];
//	byte padding[116];
//	gbasavefooter footer;
//};
//struct gbasavehalfpacked
//{
//	std::array<gbasaveblockpacked,14> blocks;
//};
//struct gbasavefilepacked
//{
//	gbasavehalfpacked savea;
//	gbasavehalfpacked saveb;
//	byte unknown[16384];
//};

struct gbapcstorage
{
	uint32 curbox;
	pokemon_gen3 pcstorage[14][30];
	byte boxnames[126];
	byte boxwallpapers[14];
};
struct gbasavefile
{
	byte data[19636];
	gbapcstorage pcstorage;
};

void buildgbasave(gbasavefilepacked * savin, gbasavefile * savout);


//struct gbasaveblock
//{
//	//byte data[0xf80];
//	//byte unknown[0x74];
//	byte data[0xf80];
//	gbasavefooter footer;
//};
//struct gbasavehalf
//{
//	//gbasaveblock blocks[14];
//	std::array<gbasaveblock,14> blocks;
//};
//struct gbasavehalf_unscrambled
//{
//	uint32 curbox;
//	pokemon_gen3 pcstorage[14][30];
//	byte boxnames[126];
//	byte boxwallpapers[14];
//};
//struct gbasavefile
//{
//	gbasavehalf savefilea;
//	gbasavehalf savefileb;
//	byte unknown[0x4000];
//};
//void DllExport sortsaveblocks(gbasavehalf * savehalf);
//bool DllExport compareblocks(gbasaveblock a, gbasaveblock b);
//void DllExport sortblocks(std::array<gbasaveblock,14> & theblocks);
void DllExport decryptgbapkm(pokemon_gen3 * pkm);
void DllExport calcchecksum(pokemon_gen3 * pkm);
void DllExport shufflegbapkm(pokemon_gen3 * pkm, bool un);
//void DllExport sortsavefile(gbasavefile * sav);
void DllExport read(const char* file_name, gbasavefilepacked *data);
void DllExport read(const char* file_name, pokemon_gen3 *data);
DllExport int convertgbaspecies(GBASpecies::gbaspecies in);
DllExport int convertgbaitems(uint16 in);
DllExport GBASpecies::gbaspecies convertgbaspecies(int in);
DllExport int convertgbatext(int in);
void DllExport convertgen3pkmtogen5(pokemon_gen3 * gbapkm, pokemon_obj * pkm);
void DllExport write(const char* file_name, pokemon_gen3* data);
