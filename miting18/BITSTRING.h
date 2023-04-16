#pragma once
#include "string.h"
#ifndef _BITSTR
#define _BITSTR
class BITSTRING : public STRING {
protected:
	int VerifyString(char* s);
public:
	BITSTRING();
	BITSTRING(char* s);
	BITSTRING(const BITSTRING& b);
	~BITSTRING();
	const BITSTRING& operator = (const BITSTRING& b)
	{
		if (str) free(str);
		if (b.str)
		{
			str = strdup(b.str);
			len = b.len;
		}
		else
		{
			str = NULL;
			len = 0;
		}

	}
	const BITSTRING  operator +(const BITSTRING& b)
	{
		int m, p = 0, a1, a2;
		if (len > b.len) m = len; else m = b.len;
		char* r = new char[m + 1];
		memset(r, '0', m);
		r[m] = 0;
		int n1 = len - 1, n2 = b.len - 1;
		for (int n = m - 1; n >= 0; n--)
		{
			if (n1 >= 0) a1 = str[n1] - '0';
			else a1 = 0;
			if (n2 >= 0) a2 = b.str[n2] - '0';
			else a2 = 0;
			switch (a1 + a2 + p)
			{
			case 3:
				r[n] = 1;
				p = 2;
				break;
			case 2:
				r[n] = '0';
				p = 1;
				break;
			case 1:
				r[n] = '1';
				p = 0;
				break;
			case 0:
				r[n] = '0';
				p = 0;
				break;
			}
			n1--;
			n2--;
		}
		return BITSTRING(r);
	}
	int operator ==(const BITSTRING& b)
	{
		int l;
		if (len > b.len) l = len; else l = b.len;
		int r = 1;;
		int n1 = len - 1, n2 = b.len - 1, k;
		k = l - 1;
		while (k >= 0)
		{

			if ((n1 >= 0) && (n2 >= 0) && (str[n1] != b.str[n2])) return 0;
			if ((n1 < 0) && (b.str[n2] != '0')) return 0;
			if ((n2 < 0) && (str[n1] != '0')) return 0;
			k--; n1--; n2--;
		}
		return 1;
	}
};