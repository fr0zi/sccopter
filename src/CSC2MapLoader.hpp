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

enum TileType {
    ETT_FLAT, // 0x00
    ETT_SLOPE_N, // 0x01
    ETT_SLOPE_E, // 0x02
    ETT_SLOPE_S, // 0x03
    ETT_SLOPE_W, // 0x04
    ETT_SLOPE_NE, // 0x05
    ETT_SLOPE_SE, // 0x06
    ETT_SLOPE_SW, // 0x07
    ETT_SLOPE_NW, // 0x08
    ETT_CORNER_NE, // 0x09
    ETT_CORNER_SE, // 0x10
    ETT_CORNER_SW, // 0x0
    ETT_CORNER_NW, // 0x05
    ETT_HIGHGROUND,
    ETT_UNUSED_0E,
    ETT_UNUSED_0F,
    ETT_UNDERWATER_FLAT,
    ETT_UNDERWATER_SLOPE_N,
    ETT_UNDERWATER_SLOPE_E,
    ETT_UNDERWATER_SLOPE_S,
    ETT_UNDERWATER_SLOPE_W,
    ETT_UNDERWATER_SLOPE_NE,
    ETT_UNDERWATER_SLOPE_SE,
    ETT_UNDERWATER_SLOPE_SW,
    ETT_UNDERWATER_SLOPE_NW,
    ETT_UNDERWATER_CORNER_NE,
    ETT_UNDERWATER_CORNER_SE,
    ETT_UNDERWATER_CORNER_SW,
    ETT_UNDERWATER_CORNER_NW,
    ETT_UNDERWATER_HIGHGROUND,
    ETT_UNUSED_1E,
    ETT_UNUSED_1F,
    ETT_WATER_SUBMERGED_FLAT,
    ETT_WATER_SUBMERGED_SLOPE_N,
    ETT_WATER_SUBMERGED_SLOPE_E,
    ETT_WATER_SUBMERGED_SLOPE_S,
    ETT_WATER_SUBMERGED_SLOPE_W,
    ETT_WATER_SUBMERGED_SLOPE_NE,
    ETT_WATER_SUBMERGED_SLOPE_SE,
    ETT_WATER_SUBMERGED_SLOPE_SW,
    ETT_WATER_SUBMERGED_SLOPE_NW,
    ETT_WATER_SUBMERGED_CORNER_NE,
    ETT_WATER_SUBMERGED_CORNER_SE,
    ETT_WATER_SUBMERGED_CORNER_SW,
    ETT_WATER_SUBMERGED_CORNER_NW,
    ETT_WATER_SUBMERGED_HIGHGROUND,
    ETT_UNUSED_2E,
    ETT_UNUSED_2F,
    ETT_SURFACE_WATER_FLAT,
    ETT_SURFACE_WATER_SLOPE_N,
    ETT_SURFACE_WATER_SLOPE_E,
    ETT_SURFACE_WATER_SLOPE_S,
    ETT_SURFACE_WATER_SLOPE_W,
    ETT_SURFACE_WATER_SLOPE_NE,
    ETT_SURFACE_WATER_SLOPE_SE,
    ETT_SURFACE_WATER_SLOPE_SW,
    ETT_SURFACE_WATER_SLOPE_NW,
    ETT_SURFACE_WATER_CORNER_NE,
    ETT_SURFACE_WATER_CORNER_SE,
    ETT_SURFACE_WATER_CORNER_SW,
    ETT_SURFACE_WATER_CORNER_NW,
    ETT_SURFACE_WATER_HIGHGROUND,
    ETT_SURFACE_WATER_CANAL_WE,
    ETT_SURFACE_WATER_CANAL_NS,
    ETT_SURFACE_WATER_BAY_OPEN_S,
    ETT_SURFACE_WATER_BAY_OPEN_W,
    ETT_SURFACE_WATER_BAY_OPEN_N,
    ETT_SURFACE_WATER_BAY_OPEN_E,
    ETT_WATERFALL,
    ETT_UNUSED_3F
};

struct segHeader {
    DWORD name;
    DWORD length;
};

struct Tile
{
    int height;
    TileType type;
};

class CSC2MapLoader : public CRefCounter
{
    public:
        CSC2MapLoader(vbcString sc2filename);
        ~CSC2MapLoader();

        //int* getTilesData();

        Tile* getTiles();

    private:
        FILE*       _file;
        segHeader   _segHeader;
        //int*        _tileHeight;
        Tile*        _tiles;

        void readMapData();
};



#endif // CSC2MAPLOADER_HPP_INCLUDED
