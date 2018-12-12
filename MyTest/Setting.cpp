#include "stdafx.h"
#include "Setting.h"
#include "Memo.h"
#include <string.h>
Setting::Setting()
{
	count = 0;
	temp_memo = L"";
	ReadDataFile();
	ReadMemoFile();
}

int Setting::SearchFile(CString str)
{
	int result = -1;
	for (int i = 0; i < count; i++) {
		if (str == memo[i]->date) {
			result = i;
		}
	}
	return result;
}

void Setting::ReadDataFile()
{
	char buf[50];
	char *temp[2];
	int i = 0;
	FILE *fin = fopen("data.txt", "rt");

	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		temp[0] = strtok(buf, "|");
		for (i = 1; i < 2; i++) {
			temp[i] = strtok(NULL, "+");
		}
		memo[count++] = new Memo(temp[0], temp[1]);
		if (memo[count -1]->str == L"") {
			memo[count - 1] = memo[count];
			count--;
		}
	}
	fclose(fin);
}

void Setting::WriteDataFile()
{
	FILE *fout = fopen("data.txt", "w+");
	for (int i = 0; i < count-1; i++) {
		CStringA charstr1(memo[i]->date);
		CStringA charstr2(memo[i]->str);
		fprintf(fout, "%s|%s+\n", charstr1, charstr2);
	}
	CStringA charstr1(memo[count - 1]->date);
	CStringA charstr2(memo[count - 1]->str);
	fprintf(fout, "%s|%s+\n", charstr1, charstr2);
	fclose(fout);
}

void Setting::ReadMemoFile()
{
	char buf[1024];
	char *temp[2];
	int i = 0;
	FILE *fin = fopen("memo.txt", "rt");

	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		temp_memo += buf;
	}
	fclose(fin);
}

void Setting::WriteMemoFile()
{
	FILE *fout = fopen("memo.txt", "w+");

	temp_memo.Replace(L"\r\n", L"¡Ù");
	CStringA charstr1(temp_memo);
	fprintf(fout, "%s", charstr1);
	
	fclose(fout);
}
