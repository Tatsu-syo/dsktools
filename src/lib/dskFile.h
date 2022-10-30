/*
dsktools (C) 2005,2022 Tatsuhiko Shoji
The sources for dsktools are distributed under the MIT open source license
*/
#ifndef SAVFILE_H
#define SAVFILE_H

#include <stdio.h>

#define SECTORS 1440
#define SECTORSIZE 512

/* セクタ番号テーブル初期化 */
int initialize(FILE *fpi);
/* ディスクイメージのセクタを読み込む */
int readSector(FILE *fpi,unsigned long sectorNo,void *buf);
/* ディスクイメージのセクタを書き込む */
int writeSector(FILE *fpo,unsigned long sectorNo,void *buf);

#endif
