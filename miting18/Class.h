#pragma once
#include <string.h>
#include <stdlib.h>
#ifndef _STRING
#define _STRING
class STRING {
protected:
	char* str;
	int len;
public:
	STRING() { str = NULL; };
	STRING(char* s);
	STRING(char c);
	STRING(const STRING& str2);
	int GetLength();
	void 	Clear();
	char* GetString()
	{
		if (str) return str; else return "";
	}
	~STRING();
};