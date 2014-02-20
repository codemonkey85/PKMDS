#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_gba.h>
#else
#include "../../PKMDS/include/pkmds/pkmds_gba.h"
#endif

int blocksizes[] = {
	3884, // Trainer info
	3968, // Team / items
	3968, // Unknown
	3968, // Unknown
	3848, // Rival info
	3968, // PC buffer A
	3968, // PC buffer B
	3968, // PC buffer C
	3968, // PC buffer D
	3968, // PC buffer E
	3968, // PC buffer F
	3968, // PC buffer G
	3968, // PC buffer H
	2000, // PC buffer I
};
int blocklocations[] = {
	0,     // Trainer info
	3884,  // Team / items
	7852,  // Unknown
	11820, // Unknown
	15788, // Rival info
	19636, // PC buffer A
	23604, // PC buffer B
	27572, // PC buffer C
	31540, // PC buffer D
	35508, // PC buffer E
	39476, // PC buffer F
	43444, // PC buffer G
	47412, // PC buffer H
	51380, // PC buffer I
};

void read(const char* file_name, gbasavefilepacked *data)
{
	std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(gbasavefilepacked));
	in->close();
	delete in;
	in = 0;
}
void read(const char* file_name, pokemon_gen3 *data)
{
	std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(pokemon_gen3));
	in->close();
	delete in;
	in = 0;
}

void buildgbasave(gbasavefilepacked * savin, gbasavefile * savout)
{
	int icount = 0;
	gbasaveblockpacked * block = new gbasaveblockpacked();
	byte * rawdata = reinterpret_cast<byte*>(savout);
	int cursave = 0;
	for(int i = 0; i < 16; i++)
	{
		block = reinterpret_cast<gbasaveblockpacked*>(&(savin->savea.blocks[i]));
		if(block->footer.validation == 0x08012025)
		{
			if(block->footer.saveindex > cursave)
			{
				cursave = block->footer.saveindex;
			}
		}
	}
	for(int i = 0; i < 16; i++)
	{
		block = reinterpret_cast<gbasaveblockpacked*>(&(savin->saveb.blocks[i]));
		if(block->footer.validation == 0x08012025)
		{
			if(block->footer.saveindex > cursave)
			{
				cursave = block->footer.saveindex;
			}
		}
	}
	for(int i = 0; i < 16; i++)
	{
		block = reinterpret_cast<gbasaveblockpacked*>(&(savin->savea.blocks[i]));
		if(block->footer.validation == 0x08012025)
		{
			if(block->footer.saveindex == cursave)
			{
				memcpy(&(rawdata[blocklocations[block->footer.sectionid]]),&(block->data), blocksizes[block->footer.sectionid]);
				icount++;
			}
		}
	}
	icount = 0;
	for(int i = 0; i < 16; i++)
	{
		block = reinterpret_cast<gbasaveblockpacked*>(&(savin->saveb.blocks[i]));
		if(block->footer.validation == 0x08012025)
		{
			if(block->footer.saveindex == cursave)
			{
				memcpy(&(rawdata[blocklocations[block->footer.sectionid]]),&(block->data), blocksizes[block->footer.sectionid]);
				icount++;
			}
		}
	}
	icount = 0;
}


//void sortsavefile(gbasavefile * sav)
//{
//	sortsaveblocks(&(sav->savefilea));
//	sortsaveblocks(&(sav->savefileb));
//}
//void sortsaveblocks(gbasavehalf * savehalf)
//{
//	sortblocks(savehalf->blocks);
//}
//bool compareblocks(gbasaveblock a, gbasaveblock b)
//{
//	return a.footer.sectionid < b.footer.sectionid;
//}
//void sortblocks(std::array<gbasaveblock,14> & theblocks)
//{
//	std::sort(theblocks.begin(),theblocks.end(),compareblocks);
//}
void decryptgbapkm(pokemon_gen3 * pkm)
{
	uint32 * TID = reinterpret_cast<uint32*>(&(pkm->tid));
	uint32 key = ((*TID)  ^ pkm->pid);
	uint32 * pkmpnt = new uint32;
	pkmpnt = reinterpret_cast<uint32*>(&(pkm->data));
	for(int i = 0; i < 12; i++)
	{
		pkmpnt[i] = (pkmpnt[i] ^ key);
	}
}
const byte t_shuffle[24][4] = {
	{0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1},
	{0,3,1,2}, {0,3,2,1}, {1,0,2,3}, {1,0,3,2},
	{1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
	{2,0,1,3}, {2,0,3,1}, {2,1,0,3}, {2,1,3,0},
	{2,3,0,1}, {2,3,1,0}, {3,0,1,2}, {3,0,2,1},
	{3,1,0,2}, {3,1,2,0}, {3,2,0,1}, {3,2,1,0}
};
void shufflegbapkm(pokemon_gen3 * pkm, bool un)
{
	byte * pkmpnt = new byte();
	pkmpnt = reinterpret_cast<byte*>(&(pkm->data));
	byte temp[48];
	//byte mode = (((((uint32*) pkmpnt)[0] >> 0xD) & 0x1F) % 24);
	byte mode = pkm->pid % 24;
	if (un) {
		memcpy(&(temp[t_shuffle[mode][0] * 12]), &pkmpnt[0 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][1] * 12]), &pkmpnt[1 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][2] * 12]), &pkmpnt[2 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][3] * 12]), &pkmpnt[3 * 12], 12);
	} else {
		memcpy(&(temp[0 * 12]), &pkmpnt[t_shuffle[mode][0] * 12], 12);
		memcpy(&(temp[1 * 12]), &pkmpnt[t_shuffle[mode][1] * 12], 12);
		memcpy(&(temp[2 * 12]), &pkmpnt[t_shuffle[mode][2] * 12], 12);
		memcpy(&(temp[3 * 12]), &pkmpnt[t_shuffle[mode][3] * 12], 12);
	}
	memcpy(pkmpnt, &temp, 48);
}

/*

void shuffle(pokemon_obj * pkm, bool un)
{
byte * raw = reinterpret_cast<byte*>(pkm);
byte temp[128];
byte mode = (((((uint32*) raw)[0] >> 0xD) & 0x1F) % 24);

if (un)
{
memcpy(&(temp[t_shuffle[mode][0] * 32]), &raw[8 + 0 * 32], 32);
memcpy(&(temp[t_shuffle[mode][1] * 32]), &raw[8 + 1 * 32], 32);
memcpy(&(temp[t_shuffle[mode][2] * 32]), &raw[8 + 2 * 32], 32);
memcpy(&(temp[t_shuffle[mode][3] * 32]), &raw[8 + 3 * 32], 32);
}
else
{
memcpy(&(temp[0 * 32]), &raw[8 + t_shuffle[mode][0] * 32], 32);
memcpy(&(temp[1 * 32]), &raw[8 + t_shuffle[mode][1] * 32], 32);
memcpy(&(temp[2 * 32]), &raw[8 + t_shuffle[mode][2] * 32], 32);
memcpy(&(temp[3 * 32]), &raw[8 + t_shuffle[mode][3] * 32], 32);
}
memcpy(&raw[8], &temp, 128);
}


*/

void calcchecksum(pokemon_gen3 * pkm)
{
	uint32 sum = 0;
	uint16 * word = new uint16();
	word = reinterpret_cast<uint16*>(&(pkm->data));
	for(int i = 0; i < 24; i++)
	{
		sum += word[i];
	}
	pkm->checksum = sum;
}
int gbatods[386][2] = {
	{1,1},
	{2,2},
	{3,3},
	{4,4},
	{5,5},
	{6,6},
	{7,7},
	{8,8},
	{9,9},
	{10,10},
	{11,11},
	{12,12},
	{13,13},
	{14,14},
	{15,15},
	{16,16},
	{17,17},
	{18,18},
	{19,19},
	{20,20},
	{21,21},
	{22,22},
	{23,23},
	{24,24},
	{25,25},
	{26,26},
	{27,27},
	{28,28},
	{29,29},
	{30,30},
	{31,31},
	{32,32},
	{33,33},
	{34,34},
	{35,35},
	{36,36},
	{37,37},
	{38,38},
	{39,39},
	{40,40},
	{41,41},
	{42,42},
	{43,43},
	{44,44},
	{45,45},
	{46,46},
	{47,47},
	{48,48},
	{49,49},
	{50,50},
	{51,51},
	{52,52},
	{53,53},
	{54,54},
	{55,55},
	{56,56},
	{57,57},
	{58,58},
	{59,59},
	{60,60},
	{61,61},
	{62,62},
	{63,63},
	{64,64},
	{65,65},
	{66,66},
	{67,67},
	{68,68},
	{69,69},
	{70,70},
	{71,71},
	{72,72},
	{73,73},
	{74,74},
	{75,75},
	{76,76},
	{77,77},
	{78,78},
	{79,79},
	{80,80},
	{81,81},
	{82,82},
	{83,83},
	{84,84},
	{85,85},
	{86,86},
	{87,87},
	{88,88},
	{89,89},
	{90,90},
	{91,91},
	{92,92},
	{93,93},
	{94,94},
	{95,95},
	{96,96},
	{97,97},
	{98,98},
	{99,99},
	{100,100},
	{101,101},
	{102,102},
	{103,103},
	{104,104},
	{105,105},
	{106,106},
	{107,107},
	{108,108},
	{109,109},
	{110,110},
	{111,111},
	{112,112},
	{113,113},
	{114,114},
	{115,115},
	{116,116},
	{117,117},
	{118,118},
	{119,119},
	{120,120},
	{121,121},
	{122,122},
	{123,123},
	{124,124},
	{125,125},
	{126,126},
	{127,127},
	{128,128},
	{129,129},
	{130,130},
	{131,131},
	{132,132},
	{133,133},
	{134,134},
	{135,135},
	{136,136},
	{137,137},
	{138,138},
	{139,139},
	{140,140},
	{141,141},
	{142,142},
	{143,143},
	{144,144},
	{145,145},
	{146,146},
	{147,147},
	{148,148},
	{149,149},
	{150,150},
	{151,151},
	{152,152},
	{153,153},
	{154,154},
	{155,155},
	{156,156},
	{157,157},
	{158,158},
	{159,159},
	{160,160},
	{161,161},
	{162,162},
	{163,163},
	{164,164},
	{165,165},
	{166,166},
	{167,167},
	{168,168},
	{169,169},
	{170,170},
	{171,171},
	{172,172},
	{173,173},
	{174,174},
	{175,175},
	{176,176},
	{177,177},
	{178,178},
	{179,179},
	{180,180},
	{181,181},
	{182,182},
	{183,183},
	{184,184},
	{185,185},
	{186,186},
	{187,187},
	{188,188},
	{189,189},
	{190,190},
	{191,191},
	{192,192},
	{193,193},
	{194,194},
	{195,195},
	{196,196},
	{197,197},
	{198,198},
	{199,199},
	{200,200},
	{201,201},
	{202,202},
	{203,203},
	{204,204},
	{205,205},
	{206,206},
	{207,207},
	{208,208},
	{209,209},
	{210,210},
	{211,211},
	{212,212},
	{213,213},
	{214,214},
	{215,215},
	{216,216},
	{217,217},
	{218,218},
	{219,219},
	{220,220},
	{221,221},
	{222,222},
	{223,223},
	{224,224},
	{225,225},
	{226,226},
	{227,227},
	{228,228},
	{229,229},
	{230,230},
	{231,231},
	{232,232},
	{233,233},
	{234,234},
	{235,235},
	{236,236},
	{237,237},
	{238,238},
	{239,239},
	{240,240},
	{241,241},
	{242,242},
	{243,243},
	{244,244},
	{245,245},
	{246,246},
	{247,247},
	{248,248},
	{249,249},
	{250,250},
	{251,251},
	{277,252},
	{278,253},
	{279,254},
	{280,255},
	{281,256},
	{282,257},
	{283,258},
	{284,259},
	{285,260},
	{286,261},
	{287,262},
	{288,263},
	{289,264},
	{290,265},
	{291,266},
	{292,267},
	{293,268},
	{294,269},
	{295,270},
	{296,271},
	{297,272},
	{298,273},
	{299,274},
	{300,275},
	{304,276},
	{305,277},
	{309,278},
	{310,279},
	{392,280},
	{393,281},
	{394,282},
	{311,283},
	{312,284},
	{306,285},
	{307,286},
	{364,287},
	{365,288},
	{366,289},
	{301,290},
	{302,291},
	{303,292},
	{370,293},
	{371,294},
	{372,295},
	{335,296},
	{336,297},
	{350,298},
	{320,299},
	{315,300},
	{316,301},
	{322,302},
	{355,303},
	{382,304},
	{383,305},
	{384,306},
	{356,307},
	{357,308},
	{337,309},
	{338,310},
	{353,311},
	{354,312},
	{386,313},
	{387,314},
	{363,315},
	{367,316},
	{368,317},
	{330,318},
	{331,319},
	{313,320},
	{314,321},
	{339,322},
	{340,323},
	{321,324},
	{351,325},
	{352,326},
	{308,327},
	{332,328},
	{333,329},
	{334,330},
	{344,331},
	{345,332},
	{358,333},
	{359,334},
	{380,335},
	{379,336},
	{348,337},
	{349,338},
	{323,339},
	{324,340},
	{326,341},
	{327,342},
	{318,343},
	{319,344},
	{388,345},
	{389,346},
	{390,347},
	{391,348},
	{328,349},
	{329,350},
	{385,351},
	{317,352},
	{377,353},
	{378,354},
	{361,355},
	{362,356},
	{369,357},
	{411,358},
	{376,359},
	{360,360},
	{346,361},
	{347,362},
	{341,363},
	{342,364},
	{343,365},
	{373,366},
	{374,367},
	{375,368},
	{381,369},
	{325,370},
	{395,371},
	{396,372},
	{397,373},
	{398,374},
	{399,375},
	{400,376},
	{401,377},
	{402,378},
	{403,379},
	{407,380},
	{408,381},
	{404,382},
	{405,383},
	{406,384},
	{409,385},
	{410,386}
};
int convertgbaspecies(GBASpecies::gbaspecies in)
{
	for(int i = 0; i < 386; i++)
	{
		if(int(in) == gbatods[i][0])
		{
			return gbatods[i][1];
		}
	}
	return 0;
}

int gbatodsitems[310][2] = {
	{0,0},
	{1,1},
	{2,2},
	{3,3},
	{4,4},
	{5,5},
	{6,6},
	{7,7},
	{8,8},
	{9,9},
	{10,10},
	{11,11},
	{12,12},
	{13,17},
	{14,18},
	{15,19},
	{16,20},
	{17,21},
	{18,22},
	{19,23},
	{20,24},
	{21,25},
	{22,26},
	{23,27},
	{24,28},
	{25,29},
	{26,30},
	{27,31},
	{28,32},
	{29,33},
	{30,34},
	{31,35},
	{32,36},
	{33,37},
	{34,38},
	{35,39},
	{36,40},
	{37,41},
	{38,42},
	{39,65},
	{40,66},
	{41,67},
	{42,68},
	{43,69},
	{44,43},
	{45,44},
	{46,70},
	{47,71},
	{48,72},
	{49,73},
	{50,74},
	{51,75},
	{63,45},
	{64,46},
	{65,47},
	{66,48},
	{67,49},
	{68,50},
	{69,51},
	{70,52},
	{71,53},
	{73,55},
	{74,56},
	{75,57},
	{76,58},
	{77,59},
	{78,60},
	{79,61},
	{80,63},
	{81,64},
	{83,76},
	{84,77},
	{85,78},
	{86,79},
	{93,80},
	{94,81},
	{95,82},
	{96,83},
	{97,84},
	{98,85},
	{103,86},
	{104,87},
	{106,88},
	{107,89},
	{108,90},
	{109,91},
	{110,92},
	{111,93},
	{121,0},
	{122,0},
	{123,0},
	{124,0},
	{125,0},
	{126,0},
	{127,0},
	{128,0},
	{129,0},
	{130,0},
	{131,0},
	{132,0},
	{133,149},
	{134,150},
	{135,151},
	{136,152},
	{137,153},
	{138,154},
	{139,155},
	{140,156},
	{141,157},
	{142,158},
	{143,159},
	{144,160},
	{145,161},
	{146,162},
	{147,163},
	{148,164},
	{149,165},
	{150,166},
	{151,167},
	{152,168},
	{153,169},
	{154,170},
	{155,171},
	{156,172},
	{157,173},
	{158,174},
	{159,175},
	{160,176},
	{161,177},
	{162,178},
	{163,179},
	{164,180},
	{165,181},
	{166,182},
	{167,183},
	{168,201},
	{169,202},
	{170,203},
	{171,204},
	{172,205},
	{173,206},
	{174,207},
	{175,208},
	{179,213},
	{180,214},
	{181,215},
	{182,216},
	{183,217},
	{184,218},
	{185,219},
	{186,220},
	{187,221},
	{188,222},
	{189,223},
	{190,224},
	{191,225},
	{192,226},
	{193,227},
	{194,228},
	{195,229},
	{196,230},
	{197,231},
	{198,232},
	{199,233},
	{200,234},
	{201,235},
	{202,236},
	{203,237},
	{204,238},
	{205,239},
	{206,240},
	{207,241},
	{208,242},
	{209,243},
	{210,244},
	{211,245},
	{212,246},
	{213,247},
	{214,248},
	{215,249},
	{216,250},
	{217,251},
	{218,252},
	{219,253},
	{220,254},
	{221,255},
	{222,256},
	{223,257},
	{224,258},
	{225,259},
	{254,260},
	{255,261},
	{256,262},
	{257,263},
	{258,264},
	{259,0},
	{260,444},
	{261,471},
	{262,445},
	{263,446},
	{264,447},
	{265,456},
	{266,457},
	{268,0},
	{269,0},
	{270,0},
	{271,476},
	{272,0},
	{273,0},
	{274,0},
	{275,0},
	{276,534},
	{277,535},
	{278,0},
	{279,0},
	{280,0},
	{281,0},
	{282,0},
	{283,0},
	{284,0},
	{285,463},
	{286,99},
	{287,100},
	{288,0},
	{289,328},
	{290,329},
	{291,330},
	{292,331},
	{293,332},
	{294,333},
	{295,334},
	{296,335},
	{297,336},
	{298,337},
	{299,338},
	{300,339},
	{301,340},
	{302,341},
	{303,342},
	{304,343},
	{305,344},
	{306,345},
	{307,346},
	{308,347},
	{309,348},
	{310,349},
	{311,350},
	{312,351},
	{313,352},
	{314,353},
	{315,354},
	{316,355},
	{317,356},
	{318,357},
	{319,358},
	{320,359},
	{321,360},
	{322,361},
	{323,362},
	{324,363},
	{325,364},
	{326,365},
	{327,366},
	{328,367},
	{329,368},
	{330,369},
	{331,370},
	{332,371},
	{333,372},
	{334,373},
	{335,374},
	{336,375},
	{337,376},
	{338,377},
	{339,420},
	{340,421},
	{341,422},
	{342,423},
	{343,424},
	{344,0},
	{345,0},
	{346,0},
	{349,0},
	{350,0},
	{351,467},
	{352,0},
	{353,0},
	{354,103},
	{355,475},
	{356,0},
	{357,101},
	{358,102},
	{359,0},
	{360,450},
	{361,442},
	{362,443},
	{363,0},
	{364,0},
	{365,0},
	{366,0},
	{367,0},
	{368,0},
	{369,0},
	{370,0},
	{371,0},
	{372,0},
	{373,0},
	{374,0},
	{375,0},
	{376,0}
};

int convertgbaitems(uint16 in)
{
	for(int i = 0; i < 310; i++)
	{
		if(int(in) == gbatodsitems[i][0])
		{
			return gbatodsitems[i][1];
		}
	}
	return 0;
}
int dstogba[386][2] = {
	{1,1},
	{2,2},
	{3,3},
	{4,4},
	{5,5},
	{6,6},
	{7,7},
	{8,8},
	{9,9},
	{10,10},
	{11,11},
	{12,12},
	{13,13},
	{14,14},
	{15,15},
	{16,16},
	{17,17},
	{18,18},
	{19,19},
	{20,20},
	{21,21},
	{22,22},
	{23,23},
	{24,24},
	{25,25},
	{26,26},
	{27,27},
	{28,28},
	{29,29},
	{30,30},
	{31,31},
	{32,32},
	{33,33},
	{34,34},
	{35,35},
	{36,36},
	{37,37},
	{38,38},
	{39,39},
	{40,40},
	{41,41},
	{42,42},
	{43,43},
	{44,44},
	{45,45},
	{46,46},
	{47,47},
	{48,48},
	{49,49},
	{50,50},
	{51,51},
	{52,52},
	{53,53},
	{54,54},
	{55,55},
	{56,56},
	{57,57},
	{58,58},
	{59,59},
	{60,60},
	{61,61},
	{62,62},
	{63,63},
	{64,64},
	{65,65},
	{66,66},
	{67,67},
	{68,68},
	{69,69},
	{70,70},
	{71,71},
	{72,72},
	{73,73},
	{74,74},
	{75,75},
	{76,76},
	{77,77},
	{78,78},
	{79,79},
	{80,80},
	{81,81},
	{82,82},
	{83,83},
	{84,84},
	{85,85},
	{86,86},
	{87,87},
	{88,88},
	{89,89},
	{90,90},
	{91,91},
	{92,92},
	{93,93},
	{94,94},
	{95,95},
	{96,96},
	{97,97},
	{98,98},
	{99,99},
	{100,100},
	{101,101},
	{102,102},
	{103,103},
	{104,104},
	{105,105},
	{106,106},
	{107,107},
	{108,108},
	{109,109},
	{110,110},
	{111,111},
	{112,112},
	{113,113},
	{114,114},
	{115,115},
	{116,116},
	{117,117},
	{118,118},
	{119,119},
	{120,120},
	{121,121},
	{122,122},
	{123,123},
	{124,124},
	{125,125},
	{126,126},
	{127,127},
	{128,128},
	{129,129},
	{130,130},
	{131,131},
	{132,132},
	{133,133},
	{134,134},
	{135,135},
	{136,136},
	{137,137},
	{138,138},
	{139,139},
	{140,140},
	{141,141},
	{142,142},
	{143,143},
	{144,144},
	{145,145},
	{146,146},
	{147,147},
	{148,148},
	{149,149},
	{150,150},
	{151,151},
	{152,152},
	{153,153},
	{154,154},
	{155,155},
	{156,156},
	{157,157},
	{158,158},
	{159,159},
	{160,160},
	{161,161},
	{162,162},
	{163,163},
	{164,164},
	{165,165},
	{166,166},
	{167,167},
	{168,168},
	{169,169},
	{170,170},
	{171,171},
	{172,172},
	{173,173},
	{174,174},
	{175,175},
	{176,176},
	{177,177},
	{178,178},
	{179,179},
	{180,180},
	{181,181},
	{182,182},
	{183,183},
	{184,184},
	{185,185},
	{186,186},
	{187,187},
	{188,188},
	{189,189},
	{190,190},
	{191,191},
	{192,192},
	{193,193},
	{194,194},
	{195,195},
	{196,196},
	{197,197},
	{198,198},
	{199,199},
	{200,200},
	{201,201},
	{202,202},
	{203,203},
	{204,204},
	{205,205},
	{206,206},
	{207,207},
	{208,208},
	{209,209},
	{210,210},
	{211,211},
	{212,212},
	{213,213},
	{214,214},
	{215,215},
	{216,216},
	{217,217},
	{218,218},
	{219,219},
	{220,220},
	{221,221},
	{222,222},
	{223,223},
	{224,224},
	{225,225},
	{226,226},
	{227,227},
	{228,228},
	{229,229},
	{230,230},
	{231,231},
	{232,232},
	{233,233},
	{234,234},
	{235,235},
	{236,236},
	{237,237},
	{238,238},
	{239,239},
	{240,240},
	{241,241},
	{242,242},
	{243,243},
	{244,244},
	{245,245},
	{246,246},
	{247,247},
	{248,248},
	{249,249},
	{250,250},
	{251,251},
	{252,277},
	{253,278},
	{254,279},
	{255,280},
	{256,281},
	{257,282},
	{258,283},
	{259,284},
	{260,285},
	{261,286},
	{262,287},
	{263,288},
	{264,289},
	{265,290},
	{266,291},
	{267,292},
	{268,293},
	{269,294},
	{270,295},
	{271,296},
	{272,297},
	{273,298},
	{274,299},
	{275,300},
	{276,304},
	{277,305},
	{278,309},
	{279,310},
	{280,392},
	{281,393},
	{282,394},
	{283,311},
	{284,312},
	{285,306},
	{286,307},
	{287,364},
	{288,365},
	{289,366},
	{290,301},
	{291,302},
	{292,303},
	{293,370},
	{294,371},
	{295,372},
	{296,335},
	{297,336},
	{298,350},
	{299,320},
	{300,315},
	{301,316},
	{302,322},
	{303,355},
	{304,382},
	{305,383},
	{306,384},
	{307,356},
	{308,357},
	{309,337},
	{310,338},
	{311,353},
	{312,354},
	{313,386},
	{314,387},
	{315,363},
	{316,367},
	{317,368},
	{318,330},
	{319,331},
	{320,313},
	{321,314},
	{322,339},
	{323,340},
	{324,321},
	{325,351},
	{326,352},
	{327,308},
	{328,332},
	{329,333},
	{330,334},
	{331,344},
	{332,345},
	{333,358},
	{334,359},
	{335,380},
	{336,379},
	{337,348},
	{338,349},
	{339,323},
	{340,324},
	{341,326},
	{342,327},
	{343,318},
	{344,319},
	{345,388},
	{346,389},
	{347,390},
	{348,391},
	{349,328},
	{350,329},
	{351,385},
	{352,317},
	{353,377},
	{354,378},
	{355,361},
	{356,362},
	{357,369},
	{358,411},
	{359,376},
	{360,360},
	{361,346},
	{362,347},
	{363,341},
	{364,342},
	{365,343},
	{366,373},
	{367,374},
	{368,375},
	{369,381},
	{370,325},
	{371,395},
	{372,396},
	{373,397},
	{374,398},
	{375,399},
	{376,400},
	{377,401},
	{378,402},
	{379,403},
	{380,407},
	{381,408},
	{382,404},
	{383,405},
	{384,406},
	{385,409},
	{386,410}
};
GBASpecies::gbaspecies convertgbaspecies(int in)
{
	for(int i = 0; i < 386; i++)
	{
		if(in == int(dstogba[i][0]))
		{
			return GBASpecies::gbaspecies(dstogba[i][1]);
		}
	}
	return GBASpecies::NOTHING;
}

byte gbatounicode[240][2] = 
{
	{0x00,'\0'},{0x01,'あ'},{0x02,'い'},{0x03,'う'},{0x04,'え'},{0x05,'お'},{0x06,'か'},{0x07,'き'},{0x08,'く'},{0x09,'け'},{0x0A,'こ'},{0x0B,'さ'},{0x0C,'し'},{0x0D,'す'},{0x0E,'せ'},{0x0F,'そ'},
	{0x10,'た'},{0x11,'ち'},{0x12,'つ'},{0x13,'て'},{0x14,'と'},{0x15,'な'},{0x16,'に'},{0x17,'ぬ'},{0x18,'ね'},{0x19,'の'},{0x1A,'は'},{0x1B,'ひ'},{0x1C,'ふ'},{0x1D,'へ'},{0x1E,'ほ'},{0x1F,'ま'},
	{0x20,'み'},{0x21,'む'},{0x22,'め'},{0x23,'も'},{0x24,'や'},{0x25,'ゆ'},{0x26,'よ'},{0x27,'ら'},{0x28,'り'},{0x29,'る'},{0x2A,'れ'},{0x2B,'ろ'},{0x2C,'わ'},{0x2D,'を'},{0x2E,'ん'},{0x2F,'ぁ'},
	{0x30,'ぃ'},{0x31,'ぅ'},{0x32,'ぇ'},{0x33,'ぉ'},{0x34,'ゃ'},{0x35,'ゅ'},{0x36,'ょ'},{0x37,'が'},{0x38,'ぎ'},{0x39,'ぐ'},{0x3A,'げ'},{0x3B,'ご'},{0x3C,'ざ'},{0x3D,'じ'},{0x3E,'ず'},{0x3F,'ぜ'},
	{0x40,'ぞ'},{0x41,'だ'},{0x42,'ぢ'},{0x43,'づ'},{0x44,'で'},{0x45,'ど'},{0x46,'ば'},{0x47,'び'},{0x48,'ぶ'},{0x49,'べ'},{0x4A,'ぼ'},{0x4B,'ぱ'},{0x4C,'ぴ'},{0x4D,'ぷ'},{0x4E,'ぺ'},{0x4F,'ぽ'},
	{0x50,'\0'},{0x51,'ア'},{0x52,'イ'},{0x53,'ウ'},{0x54,'エ'},{0x55,'オ'},{0x56,'カ'},{0x57,'キ'},{0x58,'ク'},{0x59,'ケ'},{0x5A,'コ'},{0x5B,'サ'},{0x5C,'シ'},{0x5D,'ス'},{0x5E,'セ'},{0x5F,'ソ'},
	{0x60,'タ'},{0x61,'チ'},{0x62,'ツ'},{0x63,'テ'},{0x64,'ト'},{0x65,'ナ'},{0x66,'ニ'},{0x67,'ヌ'},{0x68,'ネ'},{0x69,'ノ'},{0x6A,'ハ'},{0x6B,'ヒ'},{0x6C,'フ'},{0x6D,'ヘ'},{0x6E,'ホ'},{0x6F,'マ'},
	{0x70,'ミ'},{0x71,'ム'},{0x72,'メ'},{0x73,'モ'},{0x74,'ヤ'},{0x75,'ユ'},{0x76,'ヨ'},{0x77,'ラ'},{0x78,'リ'},{0x79,'ル'},{0x7A,'レ'},{0x7B,'ロ'},{0x7C,'ワ'},{0x7D,'ヲ'},{0x7E,'ン'},{0x7F,'ァ'},
	{0x80,'ィ'},{0x81,'ゥ'},{0x82,'ェ'},{0x83,'ォ'},{0x84,'ャ'},{0x85,'ュ'},{0x86,'ョ'},{0x87,'ガ'},{0x88,'ギ'},{0x89,'グ'},{0x8A,'ゲ'},{0x8B,'ゴ'},{0x8C,'ザ'},{0x8D,'ジ'},{0x8E,'ズ'},{0x8F,'ゼ'},
	{0x90,'ゾ'},{0x91,'ダ'},{0x92,'ヂ'},{0x93,'ヅ'},{0x94,'デ'},{0x95,'ド'},{0x96,'バ'},{0x97,'ビ'},{0x98,'ブ'},{0x99,'ベ'},{0x9A,'ボ'},{0x9B,'パ'},{0x9C,'ピ'},{0x9D,'プ'},{0x9E,'ペ'},{0x9F,'ポ'},
	{0xA0,'\0'},{0xA1,'0'},{0xA2,'1'},{0xA3,'2'},{0xA4,'3'},{0xA5,'4'},{0xA6,'5'},{0xA7,'6'},{0xA8,'7'},{0xA9,'8'},{0xAA,'9'},{0xAB,'!'},{0xAC,'?'},{0xAD,'.'},{0xAE,'-'},{0xAF,'\0'},
	{0xB0,'…'},{0xB1,'“'},{0xB2,'”'},{0xB3,'‘'},{0xB4,'’'},{0xB5,'♂'},{0xB6,'♀'},{0xB7,'\0'},{0xB8,','},{0xB9,'\0'},{0xBA,'/'},{0xBB,'A'},{0xBC,'B'},{0xBD,'C'},{0xBE,'D'},{0xBF,'E'},
	{0xC0,'F'},{0xC1,'G'},{0xC2,'H'},{0xC3,'I'},{0xC4,'J'},{0xC5,'K'},{0xC6,'L'},{0xC7,'M'},{0xC8,'N'},{0xC9,'O'},{0xCA,'P'},{0xCB,'Q'},{0xCC,'R'},{0xCD,'S'},{0xCE,'T'},{0xCF,'U'},
	{0xD0,'V'},{0xD1,'W'},{0xD2,'X'},{0xD3,'Y'},{0xD4,'Z'},{0xD5,'a'},{0xD6,'b'},{0xD7,'c'},{0xD8,'d'},{0xD9,'e'},{0xDA,'f'},{0xDB,'g'},{0xDC,'h'},{0xDD,'i'},{0xDE,'j'},{0xDF,'k'},
	{0xE0,'l'},{0xE1,'m'},{0xE2,'n'},{0xE3,'o'},{0xE4,'p'},{0xE5,'q'},{0xE6,'r'},{0xE7,'s'},{0xE8,'t'},{0xE9,'u'},{0xEA,'v'},{0xEB,'w'},{0xEC,'x'},{0xED,'y'},{0xEE,'z'},{0xEF,'\0'},
};
byte convertgbatext(byte in)
{
	for(int i = 0; i < 240; i++)
	{
		if(in == int(gbatounicode[i][0]))
		{
			return gbatounicode[i][1];
		}
	}
	return '\0';
}
void convertgen3pkmtogen5(pokemon_gen3 * gbapkm, pokemon_obj * pkm)
{
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
		pkm->moves[i] = Moves::moves(gbapkm->data.moves[i]);
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
	pkm->item = Items::items(convertgbaitems(gbapkm->data.item));
	std::string nickname = "";
	std::string otname = "";
	for(int i = 0; i < 10; i++)
	{
		nickname += convertgbatext(gbapkm->nickname[i]);
	}
	cout << "\n";
	for(int i = 0; i < 7; i++)
	{
		otname += convertgbatext(gbapkm->otname[i]);
	}
	cout << "\n";
	string speciesname = lookuppkmname(pkm);
	std::locale loc;
	for(int i = 0; i < speciesname.length(); i++)
	{
		if(nickname[i] != std::toupper(speciesname[i],loc))
		{
			pkm->ivs.isnicknamed = true;
		}
	}
	for(int i = 0; i < nickname.length(); i++)
	{
		pkm->nickname[i] = nickname[i];
	}
	for(int i = 0; i < otname.length(); i++)
	{
		pkm->otname[i] = otname[i];
	}
	calcchecksum(pkm);
}
