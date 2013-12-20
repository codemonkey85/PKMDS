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
	//gbasaveblock blocks[14];
	std::array<gbasaveblock,14> blocks;
};
struct gbasavehalf_unscrambled
{
	uint32 curbox;
	gbapokemon pcstorage[14][30];
	byte boxnames[126];
	byte boxwallpapers[14];
};
struct gbasavefile
{
	gbasavehalf savefilea;
	gbasavehalf savefileb;
	byte unknown[0x4000];
};
void DllExport sortsaveblocks(gbasavehalf * savehalf);
bool DllExport compareblocks(gbasaveblock a, gbasaveblock b);
void DllExport sortblocks(std::array<gbasaveblock,14> & theblocks);
void DllExport decryptgbapkm(gbapokemon * pkm);
void DllExport calcchecksum(gbapokemon * pkm);
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
/*
http://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_data_structure_in_Generation_III
Pokémon data structure in Generation III
From Bulbapedia, the community-driven Pokémon encyclopedia.
Pokémon in the Pokémon Ruby and Sapphire, FireRed and LeafGreen, and Emerald Versions are all stored the same way in a 100-byte structure.
Contents [hide] 
1 Notes
1.1 Personality value
1.2 OT ID
1.3 Nickname
1.4 Language
1.5 OT name
1.6 Mark
1.7 Checksum
1.8 Padding
1.9 Status ailment
2 Location
3 See also
4 Links
Notes

Pokémon
type	 offset
Personality	 dword	 0
OT ID	 dword	 4
Nickname	 10 bytes	 8
Language	 word	 18
OT name	 7 bytes	 20
Mark	 byte	 27
Checksum	 word	 28
 ????	 word	 30
Data	 48 bytes	 32
Status ailment	 dword	 80
Level	 byte	 84
Pokérus remaining	 byte	 85
Current HP	 word	 86
Total HP	 word	 88
Attack	 word	 90
Defense	 word	 92
Speed	 word	 94
Sp. Attack	 word	 96
Sp. Defense	 word	 98
Personality value
The personality value controls many things, including gender, Unown's letter, Spinda's dots, any Pokémon's Nature, and others.
OT ID
The Original Trainer's ID Number. Part of the XOR encryption key for the data section, also used in Shiny determination and the lottery.
Nickname
The Pokémon's nickname, limited to 10 characters.
Language
Determines the language of the game the Pokémon comes from. Valid values are:
0201 = Japanese
0202 = English
0203 = French
0204 = Italian
0205 = German
0206 = Korean (unused)
0207 = Spanish
OT name
The name of the original Trainer of the Pokémon.
Mark
The marks seen in the storage Box. These marks serve only to aid in organizing large collections of Pokémon.
Bit	Mark
0	 Circle
1	 Square
2	 Triangle
3	 Heart
Checksum
The checksum is of the 48-byte data section in the structure. It is computed by simply adding all the unencrypted values one word at a time.
If this value does not match the real checksum, the Pokémon is interpreted as a Bad Egg.
Padding
Any entry marked (Padding) is not used and usually set to either 0 or -1 of the respective data type.
Status ailment
The Pokémon's status ailments are stored as follows:
0-2: Sleep bits. Indicates turns of sleep, so 111b = 7 turns, 101b = 5 turns, etc.
3: Poison
4: Burned
5: Frozen
6: Paralysis
7: Bad poison
Location

A Trainer's team starts at the following addresses in the GBA's RAM (for US games?):
Ruby: 0x03004360
Sapphire: 0x03004360
Emerald: 0x02024190, 0x020244EC for US games
FireRed: 0x02024284
LeafGreen: 0x020241e4
Additionally, a wild Pokémon or an opponent's Pokémon will begin at:
Emerald: 0x02024744
FireRed: 0x0202402C

There are 6 Pokémon per team, so the whole team continues for 600 bytes afterward.
This structure is used to save data on Pokémon stored in the player's team. The structure for Pokémon saved in the PC stops after the data field, making it only 80 bytes long.
This explains why Pokémon injured by status ailment will cure themselves when put in the PC. It also applies to stats and level, which are recalculated based on Experience.
Thus, there are also 33600 (14*30*80) bytes stored somewhere else in the GBA's RAM to save data on Pokémon in the PC.
When the GBA's saved state (including memory contents) are unzipped into a 740,000+ byte file and viewed, the 14 Boxes of 420 Pokémon are stored in the general region of $038000 $040000.
*/
//=======================================================================================================================================
/*
http://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_data_substructures_in_the_GBA
Pokémon data substructures in Generation III
From Bulbapedia, the community-driven Pokémon encyclopedia.
(Redirected from Pokémon data substructures in the GBA)
This is the list of Pokémon data substructures in the Generation III Game Boy Advance games, Pokémon Ruby, Sapphire, FireRed, LeafGreen, and Emerald.
Contents [hide] 
1 Format
1.1 Order
1.2 Encryption
2 Notes
2.1 PP bonuses
2.2 Pokérus status
2.3 Origins
2.3.1 Level met
2.3.2 Game of origin
2.3.3 Poké Ball
2.3.4 Trainer gender
2.4 IVs
3 See also
Format

A Pokémon's data is slightly more complex than the rest of the structure. It is stored as four substructures, each 12 bytes in length:
Growth	Moves	EVs & Condition	 Miscellaneous
size
(bytes)	 offset
(bytes)		 size
(bytes)	 offset
(bytes)		 size
(bytes)	 offset
(bytes)		 size
(bytes)	 offset
(bytes)
Species	 2	 0	Move 1	 2	 0	HP EV	 1	 0	Pokérus status	 1	 0
Item held	 2	 0	 Move 2	 2	 2	Attack EV	 1	 1	 Met location	 1	 1
Experience	 4	 4	 Move 3	 2	 4	Defense EV	 1	 2	 Origins info	 2	 2
PP bonuses	 1	 8	 Move 4	 2	 6	Speed EV	 1	 3	IVs	 4	 4
Friendship	 1	 9	PP 1	 1	 8	Special Attack EV	 1	 4	Ribbons	 4	 8
Unknown	 2	 10	 PP 2	 1	 9	Special Defense EV	 1	 5
PP 3	 1	 10	 Coolness	 1	 6
PP 4	 1	 11	 Beauty	 1	 7
Cuteness	 1	 8
Smartness	 1	 9
Toughness	 1	 10
Feel	 1	 11
Order
The order of the structures is determined by the personality value of the Pokémon. The order is determined by the value modulo 24:
00. GAEM	 06. AGEM	 12. EGAM	 18. MGAE
01. GAME	 07. AGME	 13. EGMA	 19. MGEA
02. GEAM	 08. AEGM	 14. EAGM	 20. MAGE
03. GEMA	 09. AEMG	 15. EAMG	 21. MAEG
04. GMAE	 10. AMGE	 16. EMGA	 22. MEGA
05. GMEA	 11. AMEG	 17. EMAG	 23. MEAG
Where G, A, E, and M stand for the substructures: growth, moves, EVs and condition, and miscellaneous respectively.
Encryption
The four data substructures are stored in an encrypted form, decrypting the data is a two-step process.
To obtain the 32-bit decryption key, the entire original Trainer ID must be XORed with the personality value of the entry.
This key can then be used to decrypt the data by XORing it, 32 bits (or 4 bytes) at a time. To validate the checksum as
described in the Pokémon data structures, the entirety of the four unencrypted data substructures must be summed into a 16-bit value.
Notes

PP bonuses
The PP bonuses byte stores the number of PP Ups used for each move. Two bits per move, starting with the first move from the least significant bits upward to the last move.
Pokérus status
Pokérus status is stored in a single byte. The lower 4 bits represents the number of units of time left until the virus wears away.
If any bit in the upper 4 bits is set, the Pokémon is immune to Pokérus, indicated a small black dot appears on the Pokémon's status screen.
Both values are completely random when caught, leading to the fact that not all Pokémon contract the virus for the same amount of time and some are able to catch it again.
Origins
FBBBBGGGGLLLLLLL
This byte is sometimes divided into two bytes:
GLLLLLLL (Game/Level)
FBBBBGGG (Trainer gender/Ball/Game)
Level met
Level met (represented by L above) is a 7-bit value stored in the lowest seven bits of the origins-word. It is limited to the range of 1-127.
This value being zero represents being hatched from an Egg, so will display "Level 5 (egg)" instead of the regular "Level # (met)" message.
When examining the Level-byte on its own, the highest bit has to be cleared.
Game of origin
Game of origin (represented by G above) is contained in bits 7-10, when considering the origins-word as a whole word rather than two separate bytes.
0 = Pokémon Colosseum Bonus Disc
1 = Pokémon Sapphire
2 = Pokémon Ruby
3 = Pokémon Emerald
4 = Pokémon FireRed
5 = Pokémon LeafGreen
15 = Pokémon Colosseum or Pokémon XD
Poké Ball
The type of Poké Ball obtained in (represented by B above) is stored in bits 3-6 when considering offset 3 a single byte, and in bits 11-14 when considered a two-byte word.
1 = Master Ball
2 = Ultra Ball
3 = Great Ball
4 = Poké Ball
5 = Safari Ball
6 = Net Ball
7 = Dive Ball
8 = Nest Ball
9 = Repeat Ball
10 = Timer Ball
11 = Luxury Ball
12 = Premier Ball
Trainer gender
The most significant bit (represented by F above) stores whether the original Trainer is female. This is used to color the name in the status screen.
IVs
IVs are stored pretty logically. Starting from the least significant bit, each stat from HP to Special Defense takes up 5 bits.
The uppermost bit of this value stores which of its abilities the Pokémon has. If the bit is set to 0, the first ability is used.
If it is set to 1, the second ability is used. If the Pokémon can only have one ability, this bit can still be one.
The second-most significant bit of this value is a 1 if this entry is still an egg, 0 if not.
*/
//=======================================================================================================================================
/*
http://bulbapedia.bulbagarden.net/wiki/Save_data_structure_in_Generation_III
Save data structure in Generation III
From Bulbapedia, the community-driven Pokémon encyclopedia.
050Diglett.png	This article is incomplete.
Please feel free to edit this article to add missing information and complete it.
129Magikarp.png	This article does not yet meet the quality standards of Bulbapedia. Please feel free to edit this article to make it conform to Bulbapedia norms and conventions.
Contents [hide] 
1 Data types
2 Text data
3 File structure
3.1 Game save A, Game save B
4 Section format
4.1 Data
4.2 Section ID
4.2.1 Checksum
4.2.2 Save index
5 Section 0 - trainer info
5.1 Player name
5.2 Player gender
5.3 Trainer ID
5.4 Time played
5.5 Game Code
5.6 Security key
6 Section 1 - team / items
6.1 Team size
6.2 Team Pokémon list
6.3 Money
6.4 Item pockets
6.5 Item entry
6.5.1 Item index
6.5.2 Item quantity
7 Section 4 - rival info
7.1 Rival name
8 Sections 5-13 - PC buffer
8.1 Current PC Box
8.2 PC Boxes Pokémon list
8.3 Box names
8.4 Box wallpapers
The save data structure for Generation III is stored in the cartridge's battery-backed RAM chip (SRAM), or as a ".sav" file from most emulators. The structure consists of 128 KB of data, though not every byte is used. Emulators may append additional data for the purposes of maintaining real-time clock operations.
The integrity of most of the file is validated by checksums.
Data types

Unless otherwise noted, integer values occupy the specified number of bytes, and are little-endian and either unsigned or two's complement.
Text data

Text data for Generation III is stored in a proprietary character set. The text characters available for use by players in the game have the following byte values:
 	-0	-1	-2	-3	-4	-5	-6	-7	-8	-9	-A	-B	-C	-D	-E	-F
0-
1-
2-
3-
4-
5-
6-
7-
8-
9-	Unused, except for 0x00 (space)
A-	 	0	1	2	3	4	5	6	7	8	9	!	?	.	-	 
B-	…	“	”	‘	’	♂	♀	 	,	 	/	A	B	C	D	E
C-	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U
D-	V	W	X	Y	Z	a	b	c	d	e	f	g	h	i	j	k
E-	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z	 
F-	Unused, except for 0xFF, 0xFE, and 0xFB (terminator, line break, arrow)
F1 to F6 are used for the umlaute in the german game (Ä, Ö, Ü, ä, ö, ü).
In the Japanese version, significantly more of the table is used, owing to the need to store both Japanese kana and English characters:
 	-0	-1	-2	-3	-4	-5	-6	-7	-8	-9	-A	-B	-C	-D	-E	-F
0-	 	あ	い	う	え	お	か	き	く	け	こ	さ	し	す	せ	そ
1-	た	ち	つ	て	と	な	に	ぬ	ね	の	は	ひ	ふ	へ	ほ	ま
2-	み	む	め	も	や	ゆ	よ	ら	り	る	れ	ろ	わ	を	ん	ぁ
3-	ぃ	ぅ	ぇ	ぉ	ゃ	ゅ	ょ	が	ぎ	ぐ	げ	ご	ざ	じ	ず	ぜ
4-	ぞ	だ	ぢ	づ	で	ど	ば	び	ぶ	べ	ぼ	ぱ	ぴ	ぷ	ぺ	ぽ
5-	 	ア	イ	ウ	エ	オ	カ	キ	ク	ケ	コ	サ	シ	ス	セ	ソ
6-	タ	チ	ツ	テ	ト	ナ	ニ	ヌ	ネ	ノ	ハ	ヒ	フ	ヘ	ホ	マ
7-	ミ	ム	メ	モ	ヤ	ユ	ヨ	ラ	リ	ル	レ	ロ	ワ	ヲ	ン	ァ
8-	ィ	ゥ	ェ	ォ	ャ	ュ	ョ	ガ	ギ	グ	ゲ	ゴ	ザ	ジ	ズ	ゼ
9-	ゾ	ダ	ヂ	ヅ	デ	ド	バ	ビ	ブ	ベ	ボ	パ	ピ	プ	ペ	ポ
A-	 	0	1	2	3	4	5	6	7	8	9	!	?	.	-	 
B-	…	“	”	‘	’	♂	♀	 	,	 	/	A	B	C	D	E
C-	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U
D-	V	W	X	Y	Z	a	b	c	d	e	f	g	h	i	j	k
E-	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z	 
F-	Unused, except for 0xFF (terminator)
String fields can take up all of the bytes in which they are allotted. If a string is shorter than the maximum length for its field, it can be terminated with 0xFF.
In the name field for Eggs, the game places the bytes 0x60 0x6F 0x8B corresponding to タマゴ (tamago), the Japanese word for egg). This remains in the English version even though the characters have been replaced.
File structure

The Generation III save file is broken up into two game save blocks, each of which is broken up into 4 KB sections. Each 4 KB section is independently validated by checksum.
One block of game save data represents the most recent game save, and the other block represents the previous game save.
If any checksum for the most recent game save fails, the game will use the previous game save instead.
If any checksum for the previous game save fails, the player will be forced to start a new game.

Offset	 Size	 Contents
0x000000	 57344	Game save A
0x00E000	 57344	Game save B
0x01C000	 16384	Unknown
Game save A, Game save B
14 sections representing a game save.
Exactly which game save is the most recent and which one is the previous depends on the relative values of the save index field.
The game will alternate which region of the save file it writes to each time the game is saved. For example, if the most recent save was Game Save A, then the next time the game is saved, it will be written to Game Save B.
Section format

All sections contain the same general format: they contain however many bytes of data, followed by a header.
Offset	 Size	 Contents
0x0000	 4080	Data
0x0FF4	 2	Section ID
0x0FF6	 2	Checksum
0x0FFC	 4	Save index
Data
The checksum-able data within the section. The actual number of bytes checked is determined by Section ID.
Section ID
Specifies the save data being represented, as well as how many bytes to validate for the checksum. This is a 16-bit unsigned field and must have one of the following values:
ID	 Size	 Contents
0	 3884	Trainer info
1	 3968	Team / items
2	 3968	Unknown
3	 3968	Unknown
4	 3848	Rival info
5	 3968	PC buffer A
6	 3968	PC buffer B
7	 3968	PC buffer C
8	 3968	PC buffer D
9	 3968	PC buffer E
10	 3968	PC buffer F
11	 3968	PC buffer G
12	 3968	PC buffer H
13	 2000	PC buffer I
All 14 sections must be present exactly once in each game save block.
Checksum
Used to validate the integrity of saved data.
A 16-bit checksum generated by adding up bytes from the section. The algorithm is as follows:
Initialize a 32-bit checksum variable to zero.
Read 4 bytes at a time as 32-bit word (little-endian) and add it to the variable. The number of bytes to process in this manner is determined by Section ID.
Take the upper 16 bits of the result, and add them to the lower 16 bits of the result.
This new 16-bit value is the checksum.
Save index
Every time the game is saved, its Save Index value goes up by one. This is true even when starting a new game: it continues to count up from the previous save.
All 14 sections within a game save must have the same Save Index value. The most recent game save will have a greater Save Index value than the previous save.
Section 0 - trainer info

This section contains information regarding the player character.
Fields documented below simply list known values; there may be additional significant data in this section:
RS	E	FRLG	  
Offset	 Byte	 Offset	 Byte	 Offset	 Byte	 Contents
0x0000	 7	 0x0000	 7	 0x0000	 7	Player name
0x0008	 1	 0x0008	 1	 0x0008	 1	Player gender
0x000A	 4	 0x000A	 4	 0x000A	 4	Trainer ID
0x000E	 5	 0x000E	 5	 0x000E	 5	Time played
0x00AC	 4	N/A	 0x00AC	 4	Game Code
N/A	 0x00AC	 4	 0x0AF8	 4	Security key
Player name
The name of the player. Represented as a string that can be from 1 to 7 characters in length.
Player gender
Specifies the gender of the player character:
For boy characters, this is set to 0x00
For girl characters, this is set to 0x01
Note that changing this value will, for an unknown reason, not be reflected immediately on the character sprite when first loading the game. To update the sprite, the player must load into a new map first, such as entering or exiting a building.
Trainer ID
The player's internal Trainer ID.
The lower 16 bits represent the visible, public ID.
The upper 16 bits represent the hidden, Secret ID.
Time played
Specifies how much time has elapsed during gameplay.
This value is actually 4 values representing, in this order: the hours, minutes, seconds and "frames" that have elapsed. A frame is 1/60th of a second.
The hours field is 16-bit. The other three fields are 8-bit.
Game Code
Identifies which game this save data applies to.
For Ruby and Sapphire, this value will be 0x00000000.
For FireRed and LeafGreen, this value will be 0x00000001.
For Emerald, this is the location of the Security Key field, so any value other than 0 or 1 can be used to identify Emerald.
Security key
Used to encrypt sensitive data, such as money or item quantities. Applied to data via a simple exclusive or operation.
Important Note: The ultimate origin of this value is not well understood. It may be derived from other data, or it may just be a random number. The offsets listed in the table above are not known to be 100% guaranteed, but a copy of the value appears at offset 0x01F4 in Emerald and 0x0F20 in Fire Red/Leaf Green.
Ruby and Sapphire either do not utilize this masking operation, or the mask is always zero. Editor's Note: This could use some further investigation. If the mask does exist, it would be located at the same spots as in Emerald. In all of my testing, Ruby/Sapphire data has not been protected by a security key.
Section 1 - team / items

This section contains information regarding the player's team of Pokémon as well as their item inventory.
Fields documented below simply list known values; there may be additional significant data in this section:
RS	E	FRLG	  
Offset	 Size	 Offset	 Size	 Offset	 Size	 Contents
0x0234	 4	 0x0234	 4	 0x0034	 4	Team size
0x0238	 600	 0x0238	 600	 0x0038	 600	Team Pokémon list
0x0490	 4	 0x0490	 4	 0x0290	 4	Money
0x0498	 200	 0x0498	 200	 0x0298	 120	PC items
0x0560	 120	 0x0560	 120	 0x0310	 168	Item pocket
0x05B0	 80	 0x05D8	 120	 0x0310	 120	Key item pocket
0x0600	 64	 0x0650	 64	 0x0430	 52	Ball item pocket
0x0640	 256	 0x0690	 256	 0x0464	 232	TM Case
0x0740	 184	 0x0790	 184	 0x054C	 172	Berry pocket
Team size
The number of Pokémon currently on the team.
Team Pokémon list
Data representing information for up to 6 Pokémon, as an array. For the format, please refer to: Pokémon data structure in Generation III.
All 100 bytes of the Pokémon record are used.
Data representing Pokémon beyond the team size are dummied out with byte value 0x00.
Money
The amount of money held by the player. Must be XORed with the security key to yield the true value.
Item pockets
Lists of item entries representing the player's item inventory for the various Bag pockets.
The number of item entries available per pocket in each game can be calculated by taking the number of bytes from the table above, and dividing by 4, which is the size of the item entry structure. The inventory limits are as follows:
 	 PC	 Pocket	 Key Item	 Ball	 TM/HM	 Berry
RS	50	20	20	16	64	46
E	50	30	30	16	64	46
FRLG	30	42	30	13	58	43
Item entry
Item entries are defined using the following structure:
Offset	 Size	 Contents
0x00	 2	Item index
0x02	 2	Item quantity
Item index
The item's index.
Item quantity
The number of this item available in the Bag. Must be XORed with the lower 16 bits of the security key to yield the true value.
The security key does NOT apply to items stored in the PC.
Section 4 - rival info

This section contains information regarding the rival character.
Fields documented below simply list known values; there may be additional significant data in this section:
RSE	FRLG	  
Offset	 Size	 Offset	 Size	 Contents
N/A	 0x0BCC	 8	Rival name
Rival name
The name of the rival. Represented as a string that can be from 1 to 7 characters in length.
Sections 5-13 - PC buffer

These sections contain information regarding the contents of the Pokémon Storage System.
Although the PC buffer occupies 9 sections within the game save, it still functions like a single section in and of itself:
it's like one big section that was split apart across multiple sections.
The bytes within the PC buffer's component sections are contiguous within it. That is to say, the 3968 bytes occupied by
section 5 represent bytes 0 to 3967 in the PC buffer, the 3968 bytes in section 6 represent bytes 3968 to 7935 in the PC buffer, and so-on.
Altogether, the PC buffer contains 3968 bytes from each of 8 sections and 2000 bytes from 1 section, for a total of 33744 bytes.
RSEFRLG	  
Offset	 Size	 Contents
0x0000	 4	Current PC Box
0x0004	 33600	PC Boxes Pokémon list
0x8344	 126	Box names
0x83C2	 14	Box wallpapers
Current PC Box
The most recently viewed PC box, minus 1. That is to say, 0 represents Box 1 and 13 represents Box 14.
PC Boxes Pokémon list
A list of 420 Pokémon records. For the format, please refer to: Pokémon data structure in Generation III.
Only 80 bytes of the Pokémon record are used, meaning everything after the substructures is not included. Instead, those values are regenerated upon withdrawing a Pokémon from the PC. This is the basis of the Box trick.
Records are ordered as left-to right, top-to-bottom, per box. That is to say, the first 6 records represent the top row of Box 1 (boxes are 5 rows by 6 columns), and the first 30 records represent Box 1.
Empty cells within boxes simply dummy records containing nothing but byte value 0x00.
Box names
The 14 box names, 9 bytes apart. Represent strings that can be from 1 to 8 characters in length.
Box wallpapers
The 14 box wallpapers, 1 byte each.
*/