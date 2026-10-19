#include "ini.h"
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

IniManager::IniManager(const std::string& fileName)
{
	m_fileName = fileName;
}

int IniManager::ReadInteger(const char* section, const char* key, int defaultValue)
{
	return static_cast<int>(GetPrivateProfileIntA(section, key, defaultValue, m_fileName.c_str()));
}

double IniManager::ReadDouble(const char* section, const char* key, double defaultValue)
{
	char result[MAX_PATH] = "";
	char defaultString[MAX_PATH] = "";

	sprintf_s(defaultString, sizeof(defaultString), "%f", defaultValue);
	GetPrivateProfileStringA(section, key, defaultString, result, MAX_PATH, m_fileName.c_str());
	return std::atof(result);
}

bool IniManager::ReadBoolean(const char* section, const char* key, bool defaultValue)
{
	char result[10] = "";
	const char* defaultString = defaultValue ? "true" : "false";

	GetPrivateProfileStringA(
		section, key, defaultString, result, static_cast<DWORD>(sizeof(result)), m_fileName.c_str());
	return std::strcmp(result, "true") == 0;
}

std::string IniManager::ReadString(const char* section, const char* key, const char* defaultValue)
{
	char result[32768] = "";
	const DWORD length = GetPrivateProfileStringA(
		section, key, defaultValue, result, static_cast<DWORD>(sizeof(result)), m_fileName.c_str());
	return std::string(result, length);
}

void IniManager::WriteInteger(const char* section, const char* key, int value)
{
	char stringValue[MAX_PATH] = "";
	sprintf_s(stringValue, sizeof(stringValue), "%d", value);
	WritePrivateProfileStringA(section, key, stringValue, m_fileName.c_str());
}

void IniManager::WriteDouble(const char* section, const char* key, double value)
{
	char stringValue[MAX_PATH] = "";
	sprintf_s(stringValue, sizeof(stringValue), "%lf", value);
	WritePrivateProfileStringA(section, key, stringValue, m_fileName.c_str());
}

void IniManager::WriteBoolean(const char* section, const char* key, bool value)
{
	WritePrivateProfileStringA(section, key, value ? "true" : "false", m_fileName.c_str());
}

void IniManager::WriteString(const char* section, const char* key, const char* value)
{
	WritePrivateProfileStringA(section, key, value, m_fileName.c_str());
}