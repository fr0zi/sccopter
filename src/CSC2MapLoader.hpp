#ifndef CSC2MAPLOADER_HPP_INCLUDED
#define CSC2MAPLOADER_HPP_INCLUDED


#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <bitset>
#include <sys/stat.h>



#include "Includes.hpp"
#include "CRefCounter.hpp"

typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef unsigned int    DWORD;

#define FORM 0x4d524f46
#define ISCD 0x48444353
#define CNAM 0x4d414e43
#define MISC 0x4353494d
#define ALTM 0x4d544c41
#define XTER 0x52455458
#define XBLD 0x444c4258
#define XZON 0x4e4f5a58
#define XUND 0x444e5558
#define XTXT 0x54585458
#define XLAB 0x42414c58
#define XMIC 0x43494d58
#define XTHG 0x47485458
#define XBIT 0x54494258
#define XTRF 0x46525458
#define XPLT 0x544c5058
#define XVAL 0x4c415658
#define XCRM 0x4d524358
#define XPLC 0x434c5058
#define XFIR 0x52494658
#define XPOP 0x504f5058
#define XROG 0x474f5258
#define XGRP 0x50524758


/*
bits 4-0    Decimal     Terrain height
00000000      0          -350 feet
00000001      1          -250 feet
00000010      2          -150 feet
00000011      3           -50 feet
00000100      4            50 feet
00000101      5           150 feet
00000110      6           250 feet
00000111      7           350 feet
00001000      8           450 feet
00001001      9           550 feet
00001010     10           650 feet
00001011     11           750 feet
00001100     12           850 feet
00001101     13           950 feet
00001110     14          1050 feet
00001111     15          1150 feet
00010000     16          1250 feet
00010001     17          1350 feet
00010010     18          1450 feet
00010011     19          1550 feet
00010100     20          1650 feet
00010101     21          1750 feet
00010110     22          1850 feet
00010111     23          1950 feet
00011000     24          2050 feet
00011001     25          2150 feet
00011010     26          2250 feet
00011011     27          2350 feet
00011100     28          2450 feet
00011101     29          2550 feet
00011110     30          2650 feet
00011111     31          2750 feet
*/
/*
long filelength(int f)
{
    struct stat buf;

    fstat(f, &buf);

    return(buf.st_size);
}

unsigned int ByteConversion(unsigned int dword)
{
   return ((dword>>24)&0x000000FF) | ((dword>>8)&0x0000FF00) | ((dword<<8)&0x00FF0000) | ((dword<<24)&0xFF000000);
}

unsigned short ByteConversion(unsigned short word)
{
   return ((word & 0xff) << 8) | ((word & 0xff00) >> 8);
}
*/

// 128x128 = 16384

const int TILES_COUNT = 16384;

struct segHeader {
    DWORD name;
    DWORD length;
};

struct Tile
{
    int height;

};

class CSC2MapLoader : public CRefCounter
{
    public:
        CSC2MapLoader(vbcString sc2filename);
        ~CSC2MapLoader();

        int* getTilesData();

        Tile* getTiles();

    private:
        FILE*       _file;
        segHeader   _segHeader;
        int*        _tileHeight;
        Tile*        _tiles;

        void readMapData();
};



#endif // CSC2MAPLOADER_HPP_INCLUDED
