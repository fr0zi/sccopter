#include "CSC2MapLoader.hpp"

#include "utils.hpp"
#include <stdio.h>
#include <sys/stat.h>

CSC2MapLoader::CSC2MapLoader(vbcString sc2filename)
: _file(0), _tiles(0), _seaLevel(0)
{
    #ifdef DEBUG_MODE
		fprintf(stdout, "Creating SC2 Map Loader\n");
	#endif

    _file = fopen(sc2filename.c_str(), "rb");

    if (_file)
    {
        fprintf(stderr, "Reading sc2 file: %s\n", sc2filename.c_str());
        readMapData();
    }
    else
        fprintf(stderr, "Could not open sc2 file: %s!\n", sc2filename.c_str());
}

CSC2MapLoader::~CSC2MapLoader()
{
    #ifdef DEBUG_MODE
		fprintf(stdout, "Destroying SC2 Map Loader\n");
	#endif

    if (_file)
        fclose(_file);

    if (_tiles)
        delete [] _tiles;

    //if (_tileHeight)
    //    delete [] _tileHeight;

}

//int* CSC2MapLoader::getTilesData()
//{
//    //return _tileHeight;
//    return 0;
//}


Tile* CSC2MapLoader::getTiles()
{
    return _tiles;
}


// PRIVATE

void CSC2MapLoader::readMapData()
{
    _tiles = new Tile[TILES_COUNT];

    WORD sea_level = 0;

    fread(&_segHeader, sizeof(_segHeader), 1, _file);

    printf("Chunk: %x\n", _segHeader.name);
    printf("Chunk length: %x\n", ByteConversion(_segHeader.length));


    if(_segHeader.name == FORM) // Chunk: FORM
    {
        printf("*** FORM segment found\n");
    }

    fread(&_segHeader.name, sizeof(_segHeader.name), 1, _file);

    // ISCD chunk has only a name - no length data, so we read only one DWORD
    printf("Chunk: %x\n", _segHeader.name);

    if (_segHeader.name == ISCD)
        printf("It is correct SC2000 save game file!\n");
    else
        printf("It is NOT correct SC2000 save game file!\n");

    // reading data chunks
    long int currPos = ftell(_file);
    fseek(_file, 0L, SEEK_END);
    long int fileSize = ftell(_file);
    fseek(_file, currPos, SEEK_SET);

    printf("File size: %d\n", fileSize);

    while (ftell (_file) < fileSize )
    {
        fread(&_segHeader, sizeof(_segHeader), 1, _file);


        switch (_segHeader.name)
        {
            case CNAM:
                printf("*** CNAM segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case MISC:
                printf("*** MISC segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case ALTM:
                printf("*** ALTM segment found\n");
                printf("Chunk size: %d\n", ByteConversion(_segHeader.length));

                WORD terHeight;

                for (int i = 0; i < 32768 / 2; i++)
                {
                    //if (i % 128 == 0)
                    //    printf("\nROW %d\n", i/128);

                    fread(&terHeight, 1, sizeof(terHeight), _file);

                    std::bitset<5> blockHeight (ByteConversion(terHeight));
                    std::bitset<8> water (ByteConversion(terHeight));

                    // =============================

                    _tiles[i].height = (blockHeight.to_ulong() * 100) + 50;
                }

                printf("\n");
                //fseek(_file, ByteConversion(segHeader.length), SEEK_CUR);
                break;

            case XTER:
                printf("*** XTER segment found\n");
                printf("Chunk size: %d\n", ByteConversion(_segHeader.length));


                BYTE data;

                unsigned int loop, totalTile;
                loop = 0;
                totalTile = 0;

                do
                {
                    //printf("LOOP: %d\n", loop);

                    fread(&data, 1, sizeof(data), _file);
                    loop++;

                    if (data <= 127)
                    {
                        //printf("Type 1: %d\n", data);

                        BYTE data2;

                        for (int c = 0; c < data; c++)
                        {
                            fread(&data2, 1, sizeof(data2), _file);
                            loop++;

                            _tiles[totalTile].type = (TileType)data2;

                            totalTile++;

                        }

                        printf("\n");
                    }
                    else if (data >= 129)
                    {
                        //printf("Type 2: %d\t", data);

                        int dataCount = data - 127;
                        //printf("Data count: %d\t", dataCount);
                        //totalTile += dataCount;

                        BYTE data2;

                        fread(&data2, 1, sizeof(data2), _file);
                        loop++;
                        //printf("Data: %x - ", data2);

                        // assign tile type according to ENUM code
                        TileType tileType = (TileType)data2;


                        for (int l = 0; l < dataCount; l++)
                        {
                            _tiles[totalTile].type = tileType;
                            //printf("%d\t", _tiles[totalTile].type);
                            totalTile++;
                        }

                        //printf("\n");
                    }
                    else
                        printf("Unknown: %d\t", data);
                } while ( loop < ByteConversion(_segHeader.length));

                //}

                //printf("Total tiles: %d\n", totalTile);
                //printf("\n");

                //fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XBLD:
                printf("*** XBLD segment found\n");
                printf("Chunk size: %d\n", ByteConversion(_segHeader.length));

                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XZON:
                printf("*** XZON segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XUND:
                printf("*** XUND segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XTXT:
                printf("*** XTXT segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XLAB:
                printf("*** XLAB segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XMIC:
                printf("*** XMIC segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XTHG:
                printf("*** XTHG segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XBIT:
                printf("*** XBIT segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XTRF:
                printf("*** XTRF segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XPLT:
                printf("*** XPLT segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XVAL:
                printf("*** XVAL segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XCRM:
                printf("*** XCRM segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XPLC:
                printf("*** XPLC segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XFIR:
                printf("*** XFIR segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XPOP:
                printf("*** XPOP segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XROG:
                printf("*** XROG segment found\n");
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XGRP:
                printf("*** XGRP segment found\n");
                //printf("Size: %d\n", ByteConversion(_segHeader.length));
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            default:
                printf("Going to the next chunk...\n");
            fseek(_file, _segHeader.length, SEEK_CUR);
        }
    }

    calculateSeaLevel();
}

void CSC2MapLoader::calculateSeaLevel()
{
    for (int i = 0; i < TILES_COUNT; i++)
    {
        if ((_tiles[i].type >= 0x10) && (_tiles[i].type < 0x2d))
        {
            if (_tiles[i].height > _seaLevel)
            {
                _seaLevel = _tiles[i].height;
            }
        }
    }

    _seaLevel += 100;
}
