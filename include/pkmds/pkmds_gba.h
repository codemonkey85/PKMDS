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
namespace GBAMoves
{
	enum gbamoves : uint16
	{
		NOTHING,
		pound,
		karatechop,
		doubleslap,
		cometpunch,
		megapunch,
		payday,
		firepunch,
		icepunch,
		thunderpunch,
		scratch,
		vicegrip,
		guillotine,
		razorwind,
		swordsdance,
		cut,
		gust,
		wingattack,
		whirlwind,
		fly,
		bind,
		slam,
		vinewhip,
		stomp,
		doublekick,
		megakick,
		jumpkick,
		rollingkick,
		sandattack,
		headbutt,
		hornattack,
		furyattack,
		horndrill,
		tackle,
		bodyslam,
		wrap,
		takedown,
		thrash,
		doubleedge,
		tailwhip,
		poisonsting,
		twineedle,
		pinmissile,
		leer,
		bite,
		growl,
		roar,
		sing,
		supersonic,
		sonicboom,
		disable,
		acid,
		ember,
		flamethrower,
		mist,
		watergun,
		hydropump,
		surf,
		icebeam,
		blizzard,
		psybeam,
		bubblebeam,
		aurorabeam,
		hyperbeam,
		peck,
		drillpeck,
		submission,
		lowkick,
		counter,
		seismictoss,
		strength,
		absorb,
		megadrain,
		leechseed,
		growth,
		razorleaf,
		solarbeam,
		poisonpowder,
		stunspore,
		sleeppowder,
		petaldance,
		stringshot,
		dragonrage,
		firespin,
		thundershock,
		thunderbolt,
		thunderwave,
		thunder,
		rockthrow,
		earthquake,
		fissure,
		dig,
		toxic,
		confusion,
		psychic,
		hypnosis,
		meditate,
		agility,
		quickattack,
		rage,
		teleport,
		nightshade,
		mimic,
		screech,
		doubleteam,
		recover,
		harden,
		minimize,
		smokescreen,
		confuseray,
		withdraw,
		defensecurl,
		barrier,
		lightscreen,
		haze,
		reflect,
		focusenergy,
		bide,
		metronome,
		mirrormove,
		selfdestruct,
		eggbomb,
		lick,
		smog,
		sludge,
		boneclub,
		fireblast,
		waterfall,
		clamp,
		swift,
		skullbash,
		spikecannon,
		constrict,
		amnesia,
		kinesis,
		softboiled,
		hijumpkick,
		glare,
		dreameater,
		poisongas,
		barrage,
		leechlife,
		lovelykiss,
		skyattack,
		transform,
		bubble,
		dizzypunch,
		spore,
		flash,
		psywave,
		splash,
		acidarmor,
		crabhammer,
		explosion,
		furyswipes,
		bonemerang,
		rest,
		rockslide,
		hyperfang,
		sharpen,
		conversion,
		triattack,
		superfang,
		slash,
		substitute,
		struggle,
		sketch,
		triplekick,
		thief,
		spiderweb,
		mindreader,
		nightmare,
		flamewheel,
		snore,
		curse,
		flail,
		conversion2,
		aeroblast,
		cottonspore,
		reversal,
		spite,
		powdersnow,
		protect,
		machpunch,
		scaryface,
		faintattack,
		sweetkiss,
		bellydrum,
		sludgebomb,
		mudslap,
		octazooka,
		spikes,
		zapcannon,
		foresight,
		destinybond,
		perishsong,
		icywind,
		detect,
		bonerush,
		lockon,
		outrage,
		sandstorm,
		gigadrain,
		endure,
		charm,
		rollout,
		falseswipe,
		swagger,
		milkdrink,
		spark,
		furycutter,
		steelwing,
		meanlook,
		attract,
		sleeptalk,
		healbell,
		return_,
		present,
		frustration,
		safeguard,
		painsplit,
		sacredfire,
		magnitude,
		dynamicpunch,
		megahorn,
		dragonbreath,
		batonpass,
		encore,
		pursuit,
		rapidspin,
		sweetscent,
		irontail,
		metalclaw,
		vitalthrow,
		morningsun,
		synthesis,
		moonlight,
		hiddenpower,
		crosschop,
		twister,
		raindance,
		sunnyday,
		crunch,
		mirrorcoat,
		psychup,
		extremespeed,
		ancientpower,
		shadowball,
		futuresight,
		rocksmash,
		whirlpool,
		beatup,
		fakeout,
		uproar,
		stockpile,
		spitup,
		swallow,
		heatwave,
		hail,
		torment,
		flatter,
		willowisp,
		memento,
		facade,
		focuspunch,
		smellingsalt,
		followme,
		naturepower,
		charge,
		taunt,
		helpinghand,
		trick,
		roleplay,
		wish,
		assist,
		ingrain,
		superpower,
		magiccoat,
		recycle,
		revenge,
		brickbreak,
		yawn,
		knockoff,
		endeavor,
		eruption,
		skillswap,
		imprison,
		refresh,
		grudge,
		snatch,
		secretpower,
		dive,
		armthrust,
		camouflage,
		tailglow,
		lusterpurge,
		mistball,
		featherdance,
		teeterdance,
		blazekick,
		mudsport,
		iceball,
		needlearm,
		slackoff,
		hypervoice,
		poisonfang,
		crushclaw,
		blastburn,
		hydrocannon,
		meteormash,
		astonish,
		weatherball,
		aromatherapy,
		faketears,
		aircutter,
		overheat,
		odorsleuth,
		rocktomb,
		silverwind,
		metalsound,
		grasswhistle,
		tickle,
		cosmicpower,
		waterspout,
		signalbeam,
		shadowpunch,
		extrasensory,
		skyuppercut,
		sandtomb,
		sheercold,
		muddywater,
		bulletseed,
		aerialace,
		iciclespear,
		irondefense,
		block,
		howl,
		dragonclaw,
		frenzyplant,
		bulkup,
		bounce,
		mudshot,
		poisontail,
		covet,
		volttackle,
		magicalleaf,
		watersport,
		calmmind,
		leafblade,
		dragondance,
		rockblast,
		shockwave,
		waterpulse,
		doomdesire,
		psychoboost
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
namespace GBAItems
{
	enum gbaitems : uint16
	{
		NOTHING=0x0000,
		masterball=0x0001,
		ultraball=0x0002,
		greatball=0x0003,
		pokeball=0x0004,
		safariball=0x0005,
		netball=0x0006,
		diveball=0x0007,
		nestball=0x0008,
		repeatball=0x0009,
		timerball=0x000A,
		luxuryball=0x000B,
		premierball=0x000C,
		potion=0x000D,
		antidote=0x000E,
		burnheal=0x000F,
		iceheal=0x0010,
		awakening=0x0011,
		parlyzheal=0x0012,
		fullrestore=0x0013,
		maxpotion=0x0014,
		hyperpotion=0x0015,
		superpotion=0x0016,
		fullheal=0x0017,
		revive=0x0018,
		maxrevive=0x0019,
		freshwater=0x001A,
		sodapop=0x001B,
		lemonade=0x001C,
		moomoomilk=0x001D,
		energypowder=0x001E,
		energyroot=0x001F,
		healpowder=0x0020,
		revivalherb=0x0021,
		ether=0x0022,
		maxether=0x0023,
		elixir=0x0024,
		maxelixir=0x0025,
		lavacookie=0x0026,
		blueflute=0x0027,
		yellowflute=0x0028,
		redflute=0x0029,
		blackflute=0x002A,
		whiteflute=0x002B,
		berryjuice=0x002C,
		sacredash=0x002D,
		shoalsalt=0x002E,
		shoalshell=0x002F,
		redshard=0x0030,
		blueshard=0x0031,
		yellowshard=0x0032,
		greenshard=0x0033,
		hpup=0x003F,
		protein=0x0040,
		iron=0x0041,
		carbos=0x0042,
		calcium=0x0043,
		rarecandy=0x0044,
		ppup=0x0045,
		zinc=0x0046,
		ppmax=0x0047,
		guardspec=0x0049,
		direhit=0x004A,
		xattack=0x004B,
		xdefend=0x004C,
		xspeed=0x004D,
		xaccuracy=0x004E,
		xspecial=0x004F,
		pokedoll=0x0050,
		fluffytail=0x0051,
		superrepel=0x0053,
		maxrepel=0x0054,
		escaperope=0x0055,
		repel=0x0056,
		sunstone=0x005D,
		moonstone=0x005E,
		firestone=0x005F,
		thunderstone=0x0060,
		waterstone=0x0061,
		leafstone=0x0062,
		tinymushroom=0x0067,
		bigmushroom=0x0068,
		pearl=0x006A,
		bigpearl=0x006B,
		stardust=0x006C,
		starpiece=0x006D,
		nugget=0x006E,
		heartscale=0x006F,
		orangemail=0x0079,
		harbormail=0x007A,
		glittermail=0x007B,
		mechmail=0x007C,
		woodmail=0x007D,
		wavemail=0x007E,
		beadmail=0x007F,
		shadowmail=0x0080,
		tropicmail=0x0081,
		dreammail=0x0082,
		fabmail=0x0083,
		retromail=0x0084,
		cheriberry=0x0085,
		chestoberry=0x0086,
		pechaberry=0x0087,
		rawstberry=0x0088,
		aspearberry=0x0089,
		leppaberry=0x008A,
		oranberry=0x008B,
		persimberry=0x008C,
		lumberry=0x008D,
		sitrusberry=0x008E,
		figyberry=0x008F,
		wikiberry=0x0090,
		magoberry=0x0091,
		aguavberry=0x0092,
		iapapaberry=0x0093,
		razzberry=0x0094,
		blukberry=0x0095,
		nanabberry=0x0096,
		wepearberry=0x0097,
		pinapberry=0x0098,
		pomegberry=0x0099,
		kelpsyberry=0x009A,
		qualotberry=0x009B,
		hondewberry=0x009C,
		grepaberry=0x009D,
		tamatoberry=0x009E,
		cornnberry=0x009F,
		magostberry=0x00A0,
		rabutaberry=0x00A1,
		nomelberry=0x00A2,
		spelonberry=0x00A3,
		pamtreberry=0x00A4,
		watmelberry=0x00A5,
		durinberry=0x00A6,
		belueberry=0x00A7,
		liechiberry=0x00A8,
		ganlonberry=0x00A9,
		salacberry=0x00AA,
		petayaberry=0x00AB,
		apicotberry=0x00AC,
		lansatberry=0x00AD,
		starfberry=0x00AE,
		enigmaberry=0x00AF,
		brightpowder=0x00B3,
		whiteherb=0x00B4,
		machobrace=0x00B5,
		expshare=0x00B6,
		quickclaw=0x00B7,
		soothebell=0x00B8,
		mentalherb=0x00B9,
		choiceband=0x00BA,
		kingsrock=0x00BB,
		silverpowder=0x00BC,
		amuletcoin=0x00BD,
		cleansetag=0x00BE,
		souldew=0x00BF,
		deepseatooth=0x00C0,
		deepseascale=0x00C1,
		smokeball=0x00C2,
		everstone=0x00C3,
		focusband=0x00C4,
		luckyegg=0x00C5,
		scopelens=0x00C6,
		metalcoat=0x00C7,
		leftovers=0x00C8,
		dragonscale=0x00C9,
		lightball=0x00CA,
		softsand=0x00CB,
		hardstone=0x00CC,
		miracleseed=0x00CD,
		blackglasses=0x00CE,
		blackbelt=0x00CF,
		magnet=0x00D0,
		mysticwater=0x00D1,
		sharpbeak=0x00D2,
		poisonbarb=0x00D3,
		nevermeltice=0x00D4,
		spelltag=0x00D5,
		twistedspoon=0x00D6,
		charcoal=0x00D7,
		dragonfang=0x00D8,
		silkscarf=0x00D9,
		upgrade=0x00DA,
		shellbell=0x00DB,
		seaincense=0x00DC,
		laxincense=0x00DD,
		luckypunch=0x00DE,
		metalpowder=0x00DF,
		thickclub=0x00E0,
		stick=0x00E1,
		redscarf=0x00FE,
		bluescarf=0x00FF,
		pinkscarf=0x0100,
		greenscarf=0x0101,
		yellowscarf=0x0102,
		machbike=0x0103,
		coincase=0x0104,
		itemfinder=0x0105,
		oldrod=0x0106,
		goodrod=0x0107,
		superrod=0x0108,
		ssticket=0x0109,
		contestpass=0x010A,
		wailmerpail=0x010C,
		devongoods=0x010D,
		sootsack=0x010E,
		basementkey=0x010F,
		acrobike=0x0110,
		pokeblockcase=0x0111,
		letter=0x0112,
		eonticket=0x0113,
		redorb=0x0114,
		blueorb=0x0115,
		scanner=0x0116,
		gogoggles=0x0117,
		meteorite=0x0118,
		rm1key=0x0119,
		rm2key=0x011A,
		rm4key=0x011B,
		rm6key=0x011C,
		storagekey=0x011D,
		rootfossil=0x011E,
		clawfossil=0x011F,
		devonscope=0x0120,
		tm01=0x0121,
		tm02=0x0122,
		tm03=0x0123,
		tm04=0x0124,
		tm05=0x0125,
		tm06=0x0126,
		tm07=0x0127,
		tm08=0x0128,
		tm09=0x0129,
		tm10=0x012A,
		tm11=0x012B,
		tm12=0x012C,
		tm13=0x012D,
		tm14=0x012E,
		tm15=0x012F,
		tm16=0x0130,
		tm17=0x0131,
		tm18=0x0132,
		tm19=0x0133,
		tm20=0x0134,
		tm21=0x0135,
		tm22=0x0136,
		tm23=0x0137,
		tm24=0x0138,
		tm25=0x0139,
		tm26=0x013A,
		tm27=0x013B,
		tm28=0x013C,
		tm29=0x013D,
		tm30=0x013E,
		tm31=0x013F,
		tm32=0x0140,
		tm33=0x0141,
		tm34=0x0142,
		tm35=0x0143,
		tm36=0x0144,
		tm37=0x0145,
		tm38=0x0146,
		tm39=0x0147,
		tm40=0x0148,
		tm41=0x0149,
		tm42=0x014A,
		tm43=0x014B,
		tm44=0x014C,
		tm45=0x014D,
		tm46=0x014E,
		tm47=0x014F,
		tm48=0x0150,
		tm49=0x0151,
		tm50=0x0152,
		hm01=0x0153,
		hm02=0x0154,
		hm03=0x0155,
		hm04=0x0156,
		hm05=0x0157,
		hm06=0x0158,
		hm07=0x0159,
		hm08=0x015A,
		oaksparcel=0x015D,
		pokeflute=0x015E,
		secretkey=0x015F,
		bikevoucher=0x0160,
		goldteeth=0x0161,
		oldamber=0x0162,
		cardkey=0x0163,
		liftkey=0x0164,
		domefossil=0x0165,
		helixfossil=0x0166,
		silphscope=0x0167,
		bicycle=0x0168,
		townmap=0x0169,
		vsseeker=0x016A,
		famechecker=0x016B,
		tmcase=0x016C,
		berrypouch=0x016D,
		teachytv=0x016E,
		tripass=0x016F,
		rainbowpass=0x0170,
		tea=0x0171,
		mysticticket=0x0172,
		auroraticket=0x0173,
		powderjar=0x0174,
		ruby=0x0175,
		sapphire=0x0176,
		magmaemblem=0x0177,
		oldseamap=0x0178,
	};
}
namespace GBALang
{
	enum gbalang : uint16
	{
		japanese=0x0201,
		english=0x0202,
		french=0x0203,
		italian=0x0204,
		german=0x0205,
		korean=0x0206,
		spanish=0x0207,
	};
}
struct gbaribbons
{
	union
	{
		struct
		{
			uint16 cool : 3;
			uint16 beauty : 3;
			uint16 cute : 3;
			uint16 smart : 3;
			uint16 tough : 3;
			uint16 /*champion*/ : 1;
			bool : 2;
			bool artist : 1;
			bool effort : 1;
			bool : 4;
			bool national : 1;
			bool : 6;
			bool fencounter : 1;
		};
		struct
		{
			bool : 8;
			bool : 7;
			bool champion : 1;
			bool : 8;
			bool : 8;
		};
	};
};
struct gbamarks
{
	bool circle : 1;
	bool square : 1;
	bool triangle : 1;
	bool heart : 1;
	bool : 4;
};
struct ppbonuses_struct
{
	byte move1 : 2;
	byte move2 : 2;
	byte move3 : 2;
	byte move4 : 2;
};
struct pokemon_gen3
{
	union
	{
		struct
		{
			union
			{
				uint32 pid; // The Pokemon's personality value (PID).
				spindaspots_struct spinda_spots;
			};
			union
			{
				uint32 id;
				struct
				{
					uint16 tid;
					uint16 sid;
				};
			};
			byte nickname[10];
			union
			{
				GBALang::gbalang lang;
				uint16 lang_int;
			};
			byte otname[7];
			union
			{
				gbamarks markings;
				byte markings_int;
			};
			uint16 checksum;
uint16 : 16;
			union
			{
				struct
				{
					union
					{
						GBASpecies::gbaspecies species;
						uint16 species_int;
					};
					union
					{
						GBAItems::gbaitems item;
						uint16 item_int;
					};
					uint32 exp;
					ppbonuses_struct ppbonuses;
					byte friendship;
uint16 : 16;
					union
					{
						std::array<GBAMoves::gbamoves,4> moves;
						std::array<uint16,4> move_ints;
					};
					std::array<byte,4> movepp;
					union
					{
						evsfield evs;
						std::array<byte,6> ev_ints;
					};
					union
					{
						contestfield contest;
						std::array<byte,6> contest_ints;
					};
					union
					{
						pokerus pkrs;
						byte pkrs_int;
					};
					byte metloc;
					union
					{
						struct
						{
							uint16 metlevel : 7;
							GBAGames::gbagames game : 4;
							GBABalls::gbaballs ball : 4;
uint16 : 1;
						};
						struct
						{
byte : 8;
byte : 7;
#if (defined __linux__) || (defined __APPLE__) || (defined __CYGWIN__)
							byte trainergender: 1; //To stop GCC from throwing a warning
#else
							Genders::genders trainergender : 1;
#endif
						};
					};
					union
					{
						ivsfield ivs; // Individual Values
						struct
						{
uint16 : 16;
byte : 8;
byte : 6;
							bool isegg : 1;
							byte ability_flag : 1;
						};
					};
					gbaribbons ribbons;
				};
				byte encrypted_data[48];
			};
		};
		byte _raw_data_u8[80];
		uint16 _raw_data_u16[40];
		uint32 _raw_data_u32[20];
	};
	pokemon_gen3()
	{
		memset(this,0,sizeof(pokemon_gen3));
	}
};
struct pokemon_gen3_party : pokemon_gen3
{
	union
	{
		struct
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
		};
		byte _raw_party_data_u8[20];
		uint16 _raw_party_data_u16[10];
		uint32 _raw_party_data_u32[5];
	};
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
	gbasavefooter()
	{
		memset(this,0,sizeof(gbasavefooter));
	};
};
struct gbasaveblockpacked
{
	byte data[0xFF4];
	gbasavefooter footer;
	gbasaveblockpacked()
	{
		memset(this,0,sizeof(gbasaveblockpacked));
	};
};
struct gbasavehalfpacked
{
	std::array<gbasaveblockpacked,16> blocks;
	gbasavehalfpacked()
	{
		memset(this,0,sizeof(gbasavehalfpacked));
	};
};
struct gbasavefilepacked
{
	gbasavehalfpacked savea;
	gbasavehalfpacked saveb;
	gbasavefilepacked()
	{
		memset(this,0,sizeof(gbasavefilepacked));
	};
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
	gbapcstorage()
	{
		memset(this,0,sizeof(gbapcstorage));
	};
};
struct gbasavefile
{
	byte data[19636];
	gbapcstorage pcstorage;
	gbasavefile()
	{
		memset(this,0,sizeof(gbasavefile));
	};
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
void DllExport write(const char* file_name, gbasavefilepacked* data);
void DllExport write(const char* file_name, gbasavefile* savin, gbasavefilepacked* prevsav);
