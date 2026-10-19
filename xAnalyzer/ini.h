#ifndef INI_H
#define INI_H

#include <string>

class IniManager
{
public:
	IniManager(const std::string& fileName);

	int ReadInteger(const char* section, const char* key, int defaultValue);
	double ReadDouble(const char* section, const char* key, double defaultValue);
	bool ReadBoolean(const char* section, const char* key, bool defaultValue);
	std::string ReadString(const char* section, const char* key, const char* defaultValue);

	void WriteInteger(const char* section, const char* key, int value);
	void WriteDouble(const char* section, const char* key, double value);
	void WriteBoolean(const char* section, const char* key, bool value);
	void WriteString(const char* section, const char* key, const char* value);
private:
	std::string m_fileName;
};

#endif // INI_H