#pragma once
class Memo
{
public:
	Memo(char* ,char*);
	Memo(CString, CString);
	~Memo();

	CString date;
	CString str;
};

