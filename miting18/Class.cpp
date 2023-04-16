#include "Class.h"
STRING::STRING(char* s)
{
	str = strdup(s);
	len = strlen(s);
}

STRING::STRING(char c)
{
	str = new char[2];
	if (str)
	{
		str[0] = c;
		str[1] = 0;
		len = 1;
	}
}

STRING::STRING(const STRING& str2)
{
	str = strdup(str2.str);
	len = str2.len;
}

int  STRING::GetLength()
{
	return len;
}

void STRING::Clear()
{
	if (str)
	{
		len = 0;
		free(str);
		str = NULL;
	}
}

STRING::~STRING()
{
	if (str) { free(str); str = NULL; }

}