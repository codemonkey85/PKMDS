#pragma once
#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5.h>
#else
#include "pkmds_g5.h"
#endif
struct wcrib1
{
public:
    bool Country_Ribbon : 1;
	bool National_Ribbon : 1;
	bool Earth_Ribbon : 1;
	bool World_Ribbon : 1;
	bool Classic_Ribbon : 1;
	bool Premiere_Ribbon : 1;
	bool Event_Ribbon : 1;
	bool Birthday_Ribbon : 1;
};
struct wcrib2
{
public:
	bool Special_Ribbon : 1;
	bool Memorial_Ribbon : 1;
	bool Wish_Ribbon : 1;
	bool Battle_Champ_Ribbon : 1;
	bool Regional_Champ_Ribbon : 1;
	bool National_Champ_Ribbon : 1;
	bool World_Champ_Ribbon : 1;
private:
byte : 1;
};
/*
Ribbon Sets

These are the values for each ribbon byte:

Flag Value	wcrib1				wcrib2
0x01		Country Ribbon		Special Ribbon
0x02		National Ribbon		Memorial Ribbon
0x04		Earth Ribbon		Wish Ribbon
0x08		World Ribbon		Battle Champ Ribbon
0x10		Classic Ribbon		Regional Champ Ribbon
0x20		Premiere Ribbon		National Champ Ribbon
0x40		Event Ribbon		World Champ Ribbon
0x80		Birthday Ribbon		No Ribbon(Empty)
*/
struct gift_data
{
public:
	uint16 trainer_id;
	uint16 secret_id;
	byte hometown;
private:
	byte unused[3];
public:
	uint32 pid;
	wcrib1 rib1;
	wcrib2 rib2;
	Balls::balls ball;
private:
byte : 8;
public:
	Items::items item;
	Moves::moves moves[4];
	Species::species species;
private:
byte : 8;
public:
	byte language_flag;
	wchar_t nickname[11];
	byte nature_flag;
	byte gender_flag;
	byte ability_flag;
	byte shiny_flag;
	Locations::locations eggmetloc;
	Locations::locations metloc;
private:
	byte level_;
public:
	byte conteststats[6];
	byte ivs_flags[6];
private:
byte : 8;
public:
	wchar_t trainer_name[8];
	byte trainer_gender_flag;
	byte level_flag;
	byte egg_flag;
private:
	byte unused2[3];
	/*
	0x00-0x01	 Trainer ID Number, Item Number, Power Type
	0x02-0x03	 Secret ID Number
	0x04	 Hometown
	00 - Game Received In
	01 - Hoenn(Sapphire)
	Values follow in standard order through 21

	0x05-0x07	Unused
	0x08-0x0B	 PID
	Unset = 00000000

	0x0C	 Primary Ribbons
	Ribbon data available below.

	0x0D	 Secondary Ribbons
	Ribbon data available below.

	0x0E	 PokéBall
	0x0F	Unused
	0x10-0x11	 Held Item
	0x12-0x13	 Move ID #1
	0x14-0x15	 Move ID #2
	0x16-0x17	 Move ID #3
	0x18-0x19	 Move ID #4
	0x1A-0x1B	 PokéDex Number
	0x1C	Unused
	0x1D	 Language
	00 for Game Received In

	0x1E-0x33	 Pokémon Nickname
	(0x32-0x33 FF FF terminated)
	If no nickname, all FF.

	0x34	 Nature
	FF - Unset

	0x35	 Pokémon Gender
	00 - Male
	01 - Female
	02 - Random

	0x36	 Pokémon Ability
	00 - Ability 1
	01 - Ability 2
	02 - Dream World Ability
	03 - RND(Abil1, Abil2)
	04 - RND(Abil1, Abil2, AbilDW)
	0x37	 Shiny Toggle
	00 - Not Shiny
	01 - Allow Shiny
	02 - Generate Shiny PID
	Shows Shiny Pokemon on Card

	0x38-0x39	 Egg Met Location
	0x3A-0x3B	 Met Location of Pokémon
	0x3C	 Level - unused(?)
	0x3D-0x42	 Contest Stats
	Last byte is Sheen

	0x43-0x48	 IVs
	FFs for unset IVs

	0x49	Unused
	0x4A-0x59	 OT Name
	0x5A	 OT Gender
	00 - Male
	01 - Female
	03 - Recipient's Gender

	0x5B	 Level(random if set to 0)
	0x5C	 Egg Flag
	00 - Is Not Egg
	01 - Is Egg

	0x5D-0x5F	Unused
	*/
};
struct card_data
{
public:
	wchar_t card_title[37];
private:
uint16 : 16;
public:
	byte card_received_date[4];
	uint16 card_id;
	byte card_from_loc;
	byte card_type;
	byte gift_status;
private:
	byte unused[23];
	/*
	0x60-0xA9	 Card Title
	0xAA-0xAB	Unknown
	0xAC-0xAF	 Date Card Received
	0xB0-0xB1	 Card ID
	0xB2	 "Card From" Location
	0xB3	 Card Type [Color]
		01 - Pokémon [Blue]
		02 - (Key) Item [Pink]
		03 - Power [Yellow]
	0xB4	 Gift Status: Used / Unused
		00 - Repeatable gift
		01 - Unused
		03 - Used
	0xB5-0xCB	Unused
	*/
};
struct wondercard : gift_data, card_data{};
