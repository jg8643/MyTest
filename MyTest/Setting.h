#pragma once
#include "stdafx.h"

class Memo;
class Setting {
public:
	Setting();

	int count;
	Memo *memo[50];
	CString temp_memo;
	int SearchFile(CString);
	void ReadDataFile();
	void WriteDataFile();
	void ReadMemoFile();
	void WriteMemoFile();
};