#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_gba.h>;
#else
#include "../../include/pkmds/pkmds_gba.h";
#endif
using namespace std;
int main(int argc, char* argv[])
{
	gbasavefile * sav = new gbasavefile();
	gbapokemon * pkm = new gbapokemon();
	read("C:\\Users\\michaelbond\\Dropbox\\Saves\\pokemon_emerald_version.gsb",sav);
	sortsavefile(sav);
	gbasavehalf_unscrambled * unscrambled_sav = new gbasavehalf_unscrambled();
	unscrambled_sav = reinterpret_cast<gbasavehalf_unscrambled*>(&(sav->savefilea.blocks[5]));
	std::ofstream *out = new std::ofstream();
	std::ostringstream filename;
	for(int box = 0; box < 14; box++)
	{
		for(int slot = 0; slot < 30; slot++)
		{
			pkm = &(unscrambled_sav->pcstorage[box][slot]);
			decryptgbapkm(pkm);
			shufflegbapkm(pkm,true);
			if(pkm->encrypted.growth.species != 0)
			{
				filename.str("");
				filename.clear();
				filename << "C:\\Users\\michaelbond\\Downloads\\OUT\\box" << std::dec << box << "slot" << slot << "pid" << std::hex << pkm->pid << ".3gpkm";
				out = new std::ofstream(filename.str().c_str(),std::ios::binary);
				out->write(reinterpret_cast<char*>(pkm), sizeof(gbapokemon));
				out->close();
			}
		}
	}
	delete out;
	out = 0;
	return 0;
}
