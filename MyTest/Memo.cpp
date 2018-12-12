#include "stdafx.h"
#include "Memo.h"


Memo::Memo(char *date, char* str)
{
	this->date = date;
	this->str = str;
}

Memo::Memo(CString date, CString str)
{
	this->date = date;
	this->str = str;
}

Memo::~Memo()
{
}