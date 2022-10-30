/*
dsktools (C) 2005,2022 Tatsuhiko Shoji
The sources for dsktools are distributed under the MIT open source license
*/
#include	<stdio.h>
#include	<stdlib.h>
#include	"dskFile.h"

/* 添え字が実際のセクタ番号、値は0から始まる(4+SECTORSIZE)バイトブロックの番号 */
static unsigned long sectorTable[SECTORS];
/* 最大ブロック番号 */
static unsigned long maxBlock;

/* セクタ番号テーブルに仮想フロッピーファイルの内容を読み込む。 */
int initialize(FILE *fpi)
{
	return 0;
}

/* 仮想フロッピーディスクファイルのセクタを読み込む */
int readSector(FILE *fpi,unsigned long sectorNo,void *buf)
{
	long sectorPos;
	size_t ioCount;

	/* 存在しないセクタ番号を指定した場合、エラーとする。 */
	if (sectorNo >= SECTORS){
		return 1;
	}

	/* ファイル上の位置に直す。 */
	sectorPos = (long)(sectorNo * SECTORSIZE);

	fseek(fpi,sectorPos,SEEK_SET);
	ioCount = fread(buf,SECTORSIZE,1,fpi);
	if (ioCount < 1){
		return 1;
	}
	return 0;
}

/* 仮想フロッピーディスクファイルのセクタに書き込む */
int writeSector(FILE *fpo,unsigned long sectorNo,void *buf)
{
	long sectorPos;
	size_t ioCount;
	unsigned char secNoBuf[4];
	
	/* 存在しないセクタ番号を指定した場合、エラーとする。 */
	if (sectorNo >= SECTORS){
		return 1;
	}

		/* ファイル上の位置に直す。 */
		sectorPos = (long)(sectorNo * (SECTORSIZE));

		fseek(fpo,sectorPos,SEEK_SET);

	ioCount = fwrite(buf,SECTORSIZE,1,fpo);
	if (ioCount < 1){
		return 1;
	}
	return 0;
}
