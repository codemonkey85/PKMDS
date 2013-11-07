#include "main.h"
using namespace std;
int main(int argc, char* argv[])
{
	for(int i = 0; i < argc; i++){
		const char * filename = argv[i];
		cout << "Opening " << filename << "\n";
		string strfile = string(filename);
		pokemonx_obj * pkx = new pokemonx_obj;
		read(filename,pkx);
		string ext = getFileExtension(strfile);
		if(ext == "bin")
		{
			cout << "Decrypting " << strfile << "\n";
			decryptpkm(pkx);
			strReplace(strfile,".bin",".pkx");
		}
		if(ext == "pkx")
		{
			cout << "Encrypting " << strfile << "\n";
			encryptpkm(pkx);
			strReplace(strfile,".pkx",".bin");
		}
		pkx->isboxdatadecrypted = 0;
		pkx->ispartydatadecrypted = 0;
		cout << "Writing " << strfile << "\n";
		write(strfile.c_str(),pkx);
	}
	return 0;
}
void strReplace(std::string& str, const std::string& oldStr, const std::string& newStr)
{
	size_t pos = 0;
	while((pos = str.find(oldStr, pos)) != std::string::npos)
	{
		str.replace(pos, oldStr.length(), newStr);
		pos += newStr.length();
	}
}
std::string getFileExtension(std::string filename)
{
	std::string::size_type idx;
	idx = filename.rfind('.');
	if(idx != std::string::npos)
	{
		return filename.substr(idx+1);
	}
	else
	{
		// No extension found
		return "";
	}
}
