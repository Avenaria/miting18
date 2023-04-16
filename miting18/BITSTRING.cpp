#include "BITSTRING.h"
int BITSTRING::VerifyString(char* s)
{
	if (!s) return 0;
	for (int n = 0; n < strlen(s); n++)
	{
		if ((s[n] != '0') && (s[n] != '1')) return 0;
	}
	return 1;
}
BITSTRING::BITSTRING()
{
	str = NULL;
	len = 0;
}

BITSTRING::BITSTRING(char* s)
{
	if (VerifyString(s)) STRING::STRING(s); else
	{
		str = NULL;
		len = 0;
	}
}

BITSTRING::BITSTRING(const BITSTRING& b)
{
	if (VerifyString(b.str)) STRING::STRING(b);
}

BITSTRING::~BITSTRING()
{
	STRING::~STRING();
}

/*const BITSTRING& BITSTRING::operator=(const BITSTRING &b);
{
	if (str) free(str);
	if (b.str)
	{
	 str=strdup(b.str);
	 len=b.len;
	}
	else
	{
		str=NULL;
		len=0;
	}

} */
