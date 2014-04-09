#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g6.h>
#else
#include "../include/pkmds/pkmds_g6.h"
#endif
const byte t_shuffle[24][4] = {
    {0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1},
    {0,3,1,2}, {0,3,2,1}, {1,0,2,3}, {1,0,3,2},
    {1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
    {2,0,1,3}, {2,0,3,1}, {2,1,0,3}, {2,1,3,0},
    {2,3,0,1}, {2,3,1,0}, {3,0,1,2}, {3,0,2,1},
    {3,1,0,2}, {3,1,2,0}, {3,2,0,1}, {3,2,1,0}
};
void shuffle(pokemonx_obj * pkx, bool un)
{
    byte * raw = reinterpret_cast<byte*>(pkx);
    byte temp[224];
    byte mode = (((((uint32*) raw)[0] >> 0xD) & 0x1F) % 24);

    if (un)
    {
        memcpy(&(temp[t_shuffle[mode][0] * 56]), &raw[8 + 0 * 56], 56);
        memcpy(&(temp[t_shuffle[mode][1] * 56]), &raw[8 + 1 * 56], 56);
        memcpy(&(temp[t_shuffle[mode][2] * 56]), &raw[8 + 2 * 56], 56);
        memcpy(&(temp[t_shuffle[mode][3] * 56]), &raw[8 + 3 * 56], 56);
    }
    else
    {
        memcpy(&(temp[0 * 56]), &raw[8 + t_shuffle[mode][0] * 56], 56);
        memcpy(&(temp[1 * 56]), &raw[8 + t_shuffle[mode][1] * 56], 56);
        memcpy(&(temp[2 * 56]), &raw[8 + t_shuffle[mode][2] * 56], 56);
        memcpy(&(temp[3 * 56]), &raw[8 + t_shuffle[mode][3] * 56], 56);
    }
    memcpy(&raw[8], &temp, 224);
}
void unshufflepkm(pokemonx_obj *pkx)
{
    shuffle(pkx,true);
}
void shufflepkm(pokemonx_obj *pkx)
{
    shuffle(pkx,false);
}
void pkmcrypt(partyx_field* pkx, uint32 key)
{
    pkmprng prng;
    prng.mseed = key;
    uint16 * words = reinterpret_cast<uint16*>(pkx);
    for(int i = 0x0; i < 0x2a; i++)
    {
        words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
    }
}
void encryptpkm(party_pkx* pkx)
{
    shufflepkm(pkx);
    pkmcrypt(pkx);
    pkmcrypt(&(pkx->party_data),pkx->key);
    pkx->ispartydatadecrypted = false;
    pkx->isboxdatadecrypted = false;
}
void decryptpkm(party_pkx* pkx)
{
    pkmcrypt(pkx);
    pkmcrypt(&(pkx->party_data),pkx->key);
    unshufflepkm(pkx);
    pkx->ispartydatadecrypted = true;
    pkx->isboxdatadecrypted = true;
}
void pkmcrypt(pokemonx_obj* pkx)
{
    pkmprng prng;
    prng.mseed = pkx->key; // pkx->checksum;
    uint16 * words = reinterpret_cast<uint16*>(pkx);
    for(int i = 0x04; i < 0x74; i++)
    {
        words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
    }
}
void encryptpkm(pokemonx_obj* pkx)
{
    shufflepkm(pkx);
    pkmcrypt(pkx);
    pkx->ispartydatadecrypted = false;
    pkx->isboxdatadecrypted = false;
}
void decryptpkm(pokemonx_obj* pkx)
{
    pkmcrypt(pkx);
    unshufflepkm(pkx);
    pkx->ispartydatadecrypted = true;
    pkx->isboxdatadecrypted = true;
}
int getchecksum(pokemonx_obj* pkx) // Calculates the checksum for the given Pokemon object.
{
    uint32 chk = 0;
    uint16* p = (uint16*)pkx;
    for (uint16* i = p + 0x04; i < p + 0x74; i++)
    {
        chk += *i;
    }
    chk = chk & 0xffff;
    return chk;
}
void calcchecksum(pokemonx_obj* pkx) // Calculates and assigns the checksum for the given Pokemon object.
{
    pkx->checksum = getchecksum(pkx);
}
void read(const char* file_name, pokemonx_obj *data) // Reads the given file and assigns the data to the given save file object.
{
    std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
    in->read(reinterpret_cast<char*>(data), sizeof(pokemonx_obj));
    in->close();
    delete in;
    in = 0;
}
void read(const char* file_name, xysavefile *data) // Reads the given file and assigns the data to the given save file object.
{
    std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
    in->read(reinterpret_cast<char*>(data), sizeof(xysavefile));
    in->close();
    delete in;
    in = 0;
}
#ifdef _MSC_VER
void read(const wchar_t * file_name, pokemonx_obj *data) // Reads the given file and assigns the data to the given save file object.
{
    std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
    in->read(reinterpret_cast<char*>(data), sizeof(pokemonx_obj));
    in->close();
    delete in;
    in = 0;
}
void write(const wchar_t * file_name, pokemonx_obj* data) // Writes the given Pokemon data to the given file name.
{
    bool encryptstatus[2] = {data->ispartydatadecrypted,data->isboxdatadecrypted};
    data->ispartydatadecrypted = false;
    data->isboxdatadecrypted = false;
    std::ofstream *out = new std::ofstream(file_name,std::ios::binary);
    out->write(reinterpret_cast<char*>(data), sizeof(pokemonx_obj));
    out->close();
    delete out;
    out = 0;
    data->ispartydatadecrypted = encryptstatus[0];
    data->isboxdatadecrypted = encryptstatus[1];
}
#endif /* _MSC_VER */
void write(const char* file_name, pokemonx_obj* data) // Writes the given Pokemon data to the given file name.
{
    bool encryptstatus[2] = {data->ispartydatadecrypted,data->isboxdatadecrypted};
    data->ispartydatadecrypted = false;
    data->isboxdatadecrypted = false;
    std::ofstream *out = new std::ofstream(file_name,std::ios::binary);
    out->write(reinterpret_cast<char*>(data), sizeof(pokemonx_obj));
    out->close();
    delete out;
    out = 0;
    data->ispartydatadecrypted = encryptstatus[0];
    data->isboxdatadecrypted = encryptstatus[1];
}
bool getpkmshiny(const pokemonx_obj *pkx){
    uint32 p1, p2, E, F;

    p1 = (pkx->pid & 0xFFFF0000) >> 16;
    p2 = pkx->pid & 0xFFFF;
    E = pkx->tid ^ pkx->sid;
    F = p1 ^ p2;
    return (E ^ F) < 16; // 8;
}
