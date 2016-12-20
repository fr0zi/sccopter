#include "CSC2MapLoader.hpp"

#include "utils.hpp"

CSC2MapLoader::CSC2MapLoader(vbcString sc2filename)
: _file(0), _tileHeight(0)
{
    #ifdef DEBUG_MODE
		fprintf(stdout, "Creating SC2 Map Loader\n");
	#endif

    _file = fopen(sc2filename.c_str(), "rb");

    if (_file)
        readMapData();
    else
        fprintf(stderr, "Could not open sc2 file!\n");
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

    if (_tileHeight)
        delete [] _tileHeight;

}

int* CSC2MapLoader::getTilesData()
{
    return _tileHeight;
}


Tile* CSC2MapLoader::getTiles()
{
    return _tiles;
}


// PRIVATE

void CSC2MapLoader::readMapData()
{
    _tiles = new Tile[TILES_COUNT];

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
    while (ftell (_file) < filelength (fileno (_file)))
    {
        //printf("Current file pos: %d\n", ftell(_file));

        fread(&_segHeader, sizeof(_segHeader), 1, _file);
        //printf("Chunk: %x\n", segHeader.name);
        //printf("Size: %d\n", ByteConversion(segHeader.length));


        switch (_segHeader.name)
        {
            case CNAM:
                printf("*** CNAM segment found\n");
                //printf("Size: %d\n", ByteConversion(segHeader.length));
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case MISC:
                printf("*** MISC segment found\n");
                //printf("Size: %d\n", ByteConversion(segHeader.length));
                fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case ALTM:
                printf("*** ALTM segment found\n");
                printf("Chunk size: %d\n", ByteConversion(_segHeader.length));

                WORD terHeight;
                //WORD second;

                _tileHeight = new int[TILES_COUNT];


                for (int i = 0; i < 32768 / 2; i++)
                {
                    //if (i % 128 == 0)
                    //    printf("\nROW %d\n", i/128);

                    //fseek(_file, 1, SEEK_CUR);
                    fread(&terHeight, 1, sizeof(terHeight), _file);
                    //fread(&second, 1, sizeof(WORD), _file);

                    //printf("%d:\t", i);
                    //printf("%d\t",ByteConversion(terHeight));

                    std::bitset<4> foo (ByteConversion(terHeight));
                    //printf("%d\t", foo.to_ulong());

                    // =============================

                    switch (foo.to_ulong())
                    {
                        case 0:
                            //printf("-350\t");
                            _tileHeight[i] = -350;
                            _tiles[i].height = -350;
                            break;

                        case 1:
                            //printf("-250\t");
                            _tileHeight[i] = -250;
                            _tiles[i].height = -250;
                            break;

                        case 2:
                            //printf("-150\t");
                            _tileHeight[i] = -150;
                            _tiles[i].height = -150;
                            break;

                        case 3:
                            //printf("-50\t");
                            _tileHeight[i] = -50;
                            _tiles[i].height = -50;
                            //printf("%d\t", *(_tileHeight+i));
                            //printf("%x\t",ByteConversion(terHeight));
                            break;

                        case 4:
                            //printf("50\t");
                            _tileHeight[i] = 50;
                            _tiles[i].height = 50;
                            break;

                        case 5:
                            //printf("150\t");
                            _tileHeight[i] = 150;
                            _tiles[i].height = 150;
                            //printf("%x\t",ByteConversion(terHeight));
                            break;

                        case 6:
                            //printf("250\t");
                            _tileHeight[i] = 250;
                            _tiles[i].height = 250;
                            break;

                        case 7:
                            //printf("350\t");
                            _tileHeight[i] = 350;
                            _tiles[i].height = 350;
                            break;

                        case 8:
                            //printf("450\t");
                            _tileHeight[i] = 450;
                            _tiles[i].height = 450;
                            break;

                        case 9:
                            //printf("550\t");
                            _tileHeight[i] = 550;
                            _tiles[i].height = 550;
                            break;

                        case 10:
                            //printf("650\t");
                            _tileHeight[i] = 650;
                            _tiles[i].height = 650;
                            break;

                        case 11:
                            //printf("750\t");
                            _tileHeight[i] = 750;
                            _tiles[i].height = 750;
                            break;

                        case 12:
                            //printf("850\t");
                            _tileHeight[i] = 850;
                            _tiles[i].height = 850;
                            break;

                        case 13:
                            //printf("950\t");
                            _tileHeight[i] = 950;
                            _tiles[i].height = 950;
                            break;

                        case 14:
                            //printf("1050\t");
                            _tileHeight[i] = 1050;
                            _tiles[i].height = 1050;
                            break;

                        case 15:
                            //printf("1150\t");
                            _tileHeight[i] = 1150;
                            _tiles[i].height = 1150;
                            break;

                        case 16:
                            //printf("1250\t");
                            _tileHeight[i] = 1250;
                            _tiles[i].height = 1250;
                            break;

                        case 17:
                            //printf("1350\t");
                            _tileHeight[i] = 1350;
                            _tiles[i].height = 1350;
                            break;

                        case 18:
                            //printf("1450\t");
                            _tileHeight[i] = 1450;
                            _tiles[i].height = 1450;
                            break;

                        case 19:
                            //printf("1550\t");
                            _tileHeight[i] = 1550;
                            _tiles[i].height = 1550;
                            break;

                        case 20:
                            //printf("1650\t");
                            _tileHeight[i] = 1650;
                            _tiles[i].height = 1650;
                            break;

                        case 21:
                            //printf("1750\t");
                            _tileHeight[i] = 1750;
                            _tiles[i].height = 1750;
                            break;

                        case 22:
                            //printf("1850\t");
                            _tileHeight[i] = 1850;
                            _tiles[i].height = 1850;
                            break;

                        case 23:
                            //printf("1950\t");
                            _tileHeight[i] = 1950;
                            _tiles[i].height = 1950;
                            break;

                        case 24:
                            //printf("2050\t");
                            _tileHeight[i] = 2050;
                            _tiles[i].height = 2050;
                            break;

                        case 25:
                            //printf("2150\t");
                            _tileHeight[i] = 2150;
                            _tiles[i].height = 2150;
                            break;

                        case 26:
                            //printf("2250\t");
                            _tileHeight[i] = 2250;
                            _tiles[i].height = 2250;
                            break;

                        case 27:
                            //printf("2350\t");
                            _tileHeight[i] = 2350;
                            _tiles[i].height = 2350;
                            break;

                        case 28:
                            //printf("2450\t");
                            _tileHeight[i] = 2450;
                            _tiles[i].height = 2450;
                            break;

                        case 29:
                            //printf("2550\t");
                            _tileHeight[i] = 2550;
                            _tiles[i].height = 2550;
                            break;

                        case 30:
                            //printf("2650\t");
                            _tileHeight[i] = 2650;
                            _tiles[i].height = 2650;
                            break;

                        case 31:
                            //printf("2750\t");
                            _tileHeight[i] = 2750;
                            _tiles[i].height = 2750;
                            break;
                    }
                    //*/
                }

                printf("\n");
                //fseek(_file, ByteConversion(segHeader.length), SEEK_CUR);
                break;

            case XTER:
                printf("*** XTER segment found\n");
                printf("Chunk size: %d\n", ByteConversion(_segHeader.length));

                BYTE terSurface;

                for (int i = 0; i < ByteConversion(_segHeader.length); i++)
                {
                    fread(&terSurface, 1, sizeof(terSurface), _file);
                    printf("S: %x\t", terSurface);
                }

                //fseek(_file, ByteConversion(_segHeader.length), SEEK_CUR);
                break;

            case XBLD:
                printf("*** XBLD segment found\n");
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
}
