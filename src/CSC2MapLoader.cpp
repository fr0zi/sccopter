#include "CSC2MapLoader.hpp"

#include "utils.hpp"

CSC2MapLoader::CSC2MapLoader(vbcString sc2filename)
: _file(0), _tiles(0)
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

                //_tileHeight = new int[TILES_COUNT];


                for (int i = 0; i < 32768 / 2; i++)
                {
                    //if (i % 128 == 0)
                    //    printf("\nROW %d\n", i/128);

                    //fseek(_file, 1, SEEK_CUR);
                    fread(&terHeight, 1, sizeof(terHeight), _file);
                    //fread(&second, 1, sizeof(WORD), _file);

                    //printf("%d:\t", i);
                    //printf("| 0x%x - %d\t",ByteConversion(terHeight), ByteConversion(terHeight));

                    std::bitset<5> foo (ByteConversion(terHeight));
                    //printf("%d: ", foo.to_ulong());

                    // =============================

                    switch (foo.to_ulong())
                    {
                        case 0:
                            //printf("-350\t");
                            //_tileHeight[i] = -350;
                            _tiles[i].height = -350;
                            break;

                        case 1:
                            //printf("-250\t");
                            //_tileHeight[i] = -250;
                            _tiles[i].height = -250;
                            break;

                        case 2:
                            //printf("-150\t");
                            //_tileHeight[i] = -150;
                            _tiles[i].height = -150;
                            break;

                        case 3:
                            //printf("-50\t");
                            //_tileHeight[i] = -50;
                            _tiles[i].height = -50;
                            //printf("%d\t", *(_tileHeight+i));
                            //printf("%x\t",ByteConversion(terHeight));
                            break;

                        case 4:
                            //printf("50\t");
                            //_tileHeight[i] = 50;
                            _tiles[i].height = 50;
                            break;

                        case 5:
                            //printf("150\t");
                            //_tileHeight[i] = 150;
                            _tiles[i].height = 150;
                            //printf("%x\t",ByteConversion(terHeight));
                            break;

                        case 6:
                            //printf("250\t");
                            //_tileHeight[i] = 250;
                            _tiles[i].height = 250;
                            break;

                        case 7:
                            //printf("350\t");
                            //_tileHeight[i] = 350;
                            _tiles[i].height = 350;
                            break;

                        case 8:
                            //printf("450\t");
                            //_tileHeight[i] = 450;
                            _tiles[i].height = 450;
                            break;

                        case 9:
                            //printf("550\t");
                            //_tileHeight[i] = 550;
                            _tiles[i].height = 550;
                            break;

                        case 10:
                            //printf("650\t");
                            //_tileHeight[i] = 650;
                            _tiles[i].height = 650;
                            break;

                        case 11:
                            //printf("750\t");
                            //_tileHeight[i] = 750;
                            _tiles[i].height = 750;
                            break;

                        case 12:
                            //printf("850\t");
                            //_tileHeight[i] = 850;
                            _tiles[i].height = 850;
                            break;

                        case 13:
                            //printf("950\t");
                            //_tileHeight[i] = 950;
                            _tiles[i].height = 950;
                            break;

                        case 14:
                            //printf("1050\t");
                            //_tileHeight[i] = 1050;
                            _tiles[i].height = 1050;
                            break;

                        case 15:
                            //printf("1150\t");
                            //_tileHeight[i] = 1150;
                            _tiles[i].height = 1150;
                            break;

                        case 16:
                            //printf("1250\t");
                            //_tileHeight[i] = 1250;
                            _tiles[i].height = 1250;
                            break;

                        case 17:
                            //printf("1350\t");
                            //_tileHeight[i] = 1350;
                            _tiles[i].height = 1350;
                            break;

                        case 18:
                            //printf("1450\t");
                            //_tileHeight[i] = 1450;
                            _tiles[i].height = 1450;
                            break;

                        case 19:
                            //printf("1550\t");
                            //_tileHeight[i] = 1550;
                            _tiles[i].height = 1550;
                            break;

                        case 20:
                            //printf("1650\t");
                            //_tileHeight[i] = 1650;
                            _tiles[i].height = 1650;
                            break;

                        case 21:
                            //printf("1750\t");
                            //_tileHeight[i] = 1750;
                            _tiles[i].height = 1750;
                            break;

                        case 22:
                            //printf("1850\t");
                            //_tileHeight[i] = 1850;
                            _tiles[i].height = 1850;
                            break;

                        case 23:
                            //printf("1950\t");
                            //_tileHeight[i] = 1950;
                            _tiles[i].height = 1950;
                            break;

                        case 24:
                            //printf("2050\t");
                            //_tileHeight[i] = 2050;
                            _tiles[i].height = 2050;
                            break;

                        case 25:
                            //printf("2150\t");
                            //_tileHeight[i] = 2150;
                            _tiles[i].height = 2150;
                            break;

                        case 26:
                            //printf("2250\t");
                            //_tileHeight[i] = 2250;
                            _tiles[i].height = 2250;
                            break;

                        case 27:
                            //printf("2350\t");
                            //_tileHeight[i] = 2350;
                            _tiles[i].height = 2350;
                            break;

                        case 28:
                            //printf("2450\t");
                            //_tileHeight[i] = 2450;
                            _tiles[i].height = 2450;
                            break;

                        case 29:
                            //printf("2550\t");
                            //_tileHeight[i] = 2550;
                            _tiles[i].height = 2550;
                            break;

                        case 30:
                            //printf("2650\t");
                            //_tileHeight[i] = 2650;
                            _tiles[i].height = 2650;
                            break;

                        case 31:
                            //printf("2750\t");
                            //_tileHeight[i] = 2750;
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


                BYTE data;

                int loop, totalTile;
                loop = 0;
                totalTile = 0;
                //int len;
                //len = ByteConversion(_segHeader.length);
                //for (int i = 0; i < ByteConversion(_segHeader.length); i++)
                do
                {
                    //printf("LOOP: %d\n", loop);

                    fread(&data, 1, sizeof(data), _file);
                    loop++;

                    if (data <= 127)
                    {
                        printf("Type 1: %d\n", data);

                        BYTE data2;

                        for (int c = 0; c < data; c++)
                        {
                            fread(&data2, 1, sizeof(data2), _file);
                            loop++;

                            printf("Data: %x - ", data2);

                            if (data2 == 0x00)
                            {
                                printf("Flat terrain\n");
                                _tiles[totalTile].type = ETT_FLAT;
                            }
                            else if (data2 == 0x01)
                            {
                                printf("Slope N\n");
                                _tiles[totalTile].type = ETT_SLOPE_N;
                            }
                            else if (data2 == 0x02)
                            {
                                printf("Slope E\n");
                                _tiles[totalTile].type = ETT_SLOPE_E;
                            }
                            else if (data2 == 0x03)
                            {
                                printf("Slope S\n");
                                _tiles[totalTile].type = ETT_SLOPE_S;
                            }
                            else if (data2 == 0x04)
                            {
                                printf("Slope W\n");
                                _tiles[totalTile].type = ETT_SLOPE_W;
                            }
                            else if (data2 == 0x05)
                            {
                                printf("Slope N-E\n");
                                _tiles[totalTile].type = ETT_SLOPE_NE;
                            }
                            else if (data2 == 0x06)
                            {
                                printf("Slope S-E\n");
                                _tiles[totalTile].type = ETT_SLOPE_SE;
                            }
                            else if (data2 == 0x07)
                            {
                                printf("Slope S-W\n");
                                _tiles[totalTile].type = ETT_SLOPE_SW;
                            }
                            else if (data2 == 0x08)
                            {
                                printf("Slope N-W\n");
                                _tiles[totalTile].type = ETT_SLOPE_NW;
                            }
                            else if (data2 == 0x09)
                            {
                                printf("Corner N-E\n");
                                _tiles[totalTile].type = ETT_CORNER_NE;
                            }
                            else if (data2 == 0x0a)
                            {
                                printf("Corner S-E\n");
                                _tiles[totalTile].type = ETT_CORNER_SE;
                            }
                            else if (data2 == 0x0b)
                            {
                                printf("Corner S-W\n");
                                _tiles[totalTile].type = ETT_CORNER_SW;
                            }
                            else if (data2 == 0x0c)
                            {
                                printf("Corner N-W\n");
                                _tiles[totalTile].type = ETT_CORNER_NW;
                            }
                            else if (data2 == 0x0d)
                            {
                                printf("High ground\n");
                                _tiles[totalTile].type = ETT_HIGHGROUND;
                            }
                            else if (data2 == 0x10)
                            {
                                printf("Water covered flat terrain\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_FLAT;
                            }
                            else if (data2 == 0x11)
                            {
                                printf("Water covered slope N\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_SLOPE_N;
                            }
                            else if (data2 == 0x12)
                            {
                                printf("Water covered slope E\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_SLOPE_E;
                            }
                            else if (data2 == 0x13)
                            {
                                printf("Water covered slope S\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_SLOPE_S;
                            }
                            else if (data2 == 0x14)
                            {
                                printf("Water covered slope W\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_SLOPE_W;
                            }
                            else if (data2 == 0x15)
                            {
                                printf("Water covered slope N-E\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_SLOPE_NE;
                            }
                            else if (data2 == 0x16)
                            {
                                printf("Water covered slope S-E\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_SLOPE_SE;
                            }
                            else if (data2 == 0x17)
                            {
                                printf("Water covered slope S-W\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_SLOPE_SW;
                            }
                            else if (data2 == 0x18)
                            {
                                printf("Water covered slope N-W\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_SLOPE_NW;
                            }
                            else if (data2 == 0x19)
                            {
                                printf("Water covered corner N-E\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_CORNER_NE;
                            }
                            else if (data2 == 0x1a)
                            {
                                printf("Water covered corner S-E\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_CORNER_SE;
                            }
                            else if (data2 == 0x1b)
                            {
                                printf("Water covered corner S-W\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_CORNER_SW;
                            }
                            else if (data2 == 0x1c)
                            {
                                printf("Water covered corner N-W\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_CORNER_NW;
                            }
                            else if (data2 == 0x1d)
                            {
                                printf("Water covered high ground N-E\n");
                                _tiles[totalTile].type = ETT_WATER_COVERED_HIGHGROUND;
                            }
                            else if (data2 == 0x20)
                            {
                                printf("Water submerged flat terrain\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_FLAT;
                            }
                            else if (data2 == 0x21)
                            {
                                printf("Water submerged slope N\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_SLOPE_N;
                            }
                            else if (data2 == 0x22)
                            {
                                printf("Water submerged slope E\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_SLOPE_E;
                            }
                            else if (data2 == 0x23)
                            {
                                printf("Water submerged slope S\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_SLOPE_S;
                            }
                            else if (data2 == 0x24)
                            {
                                printf("Water submerged slope W\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_SLOPE_W;
                            }
                            else if (data2 == 0x25)
                            {
                                printf("Water submerged slope N-E\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_SLOPE_NE;
                            }
                            else if (data2 == 0x26)
                            {
                                printf("Water submerged slope S-E\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_SLOPE_SE;
                            }
                            else if (data2 == 0x27)
                            {
                                printf("Water submerged slope S-W\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_SLOPE_SW;
                            }
                            else if (data2 == 0x28)
                            {
                                printf("Water submerged slope N-W\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_SLOPE_NW;
                            }
                            else if (data2 == 0x29)
                            {
                                printf("Water submerged corner N-E\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_CORNER_NE;
                            }
                            else if (data2 == 0x2a)
                            {
                                printf("Water submerged corner S-E\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_CORNER_SE;
                            }
                            else if (data2 == 0x2b)
                            {
                                printf("Water submerged corner S-W\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_CORNER_SW;
                            }
                            else if (data2 == 0x2c)
                            {
                                printf("Water submerged corner N-W\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_CORNER_NW;
                            }
                            else if (data2 == 0x2d)
                            {
                                printf("Water submerged high ground N-E\n");
                                _tiles[totalTile].type = ETT_WATER_SUBMERGED_HIGHGROUND;
                            }
                            else if (data2 == 0x30)
                            {
                                printf("Terrain with water on the surface\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_FLAT;
                            }
                            else if (data2 == 0x31)
                            {
                                printf("Terrain with water on the surface, slope N\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_SLOPE_N;
                            }
                            else if (data2 == 0x32)
                            {
                                printf("Terrain with water on the surface, slope E\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_SLOPE_E;
                            }
                            else if (data2 == 0x33)
                            {
                                printf("Terrain with water on the surface, slope S\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_SLOPE_S;
                            }
                            else if (data2 == 0x34)
                            {
                                printf("Terrain with water on the surface, slope W\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_SLOPE_W;
                            }
                            else if (data2 == 0x35)
                            {
                                printf("Terrain with water on the surface, slope N-E\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_SLOPE_NE;
                            }
                            else if (data2 == 0x36)
                            {
                                printf("Terrain with water on the surface, slope S-E\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_SLOPE_SE;
                            }
                            else if (data2 == 0x37)
                            {
                                printf("Terrain with water on the surface, slope S-W\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_SLOPE_SW;
                            }
                            else if (data2 == 0x38)
                            {
                                printf("Terrain with water on the surface, slope N-W\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_SLOPE_NW;
                            }
                            else if (data2 == 0x39)
                            {
                                printf("Terrain with water on the surface, corner N-E\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_CORNER_NE;
                            }
                            else if (data2 == 0x3a)
                            {
                                printf("Terrain with water on the surface, corner S-E\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_CORNER_SE;
                            }
                            else if (data2 == 0x3b)
                            {
                                printf("Terrain with water on the surface, corner S-W\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_CORNER_SW;
                            }
                            else if (data2 == 0x3c)
                            {
                                printf("Terrain with water on the surface, corner N-W\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_CORNER_NW;
                            }
                            else if (data2 == 0x3d)
                            {
                                printf("Terrain with water on the surface\n");
                                _tiles[totalTile].type = ETT_SURFACE_WATER_HIGHGROUND;
                            }
                            else
                                printf("??\n");

                            totalTile++;

                        }

                        printf("\n");
                    }
                    else if (data >= 129)
                    {
                        printf("Type 2: %d\t", data);

                        int dataCount = data - 127;
                        printf("Data count: %d\t", dataCount);
                        //totalTile += dataCount;

                        BYTE data2;

                        fread(&data2, 1, sizeof(data2), _file);
                        loop++;
                        printf("Data: %x - ", data2);

                        TileType tileType;
                        tileType = ETT_FLAT;


                            if (data2 == 0x00)
                            {
                                printf("Flat terrain\n");
                                tileType = ETT_FLAT;
                            }
                            else if (data2 == 0x01)
                            {
                                printf("Slope N\n");
                                tileType = ETT_SLOPE_N;
                            }
                            else if (data2 == 0x02)
                            {
                                printf("Slope E\n");
                                tileType = ETT_SLOPE_E;
                            }
                            else if (data2 == 0x03)
                            {
                                printf("Slope S\n");
                                tileType = ETT_SLOPE_S;
                            }
                            else if (data2 == 0x04)
                            {
                                printf("Slope W\n");
                                tileType = ETT_SLOPE_W;
                            }
                            else if (data2 == 0x05)
                            {
                                printf("Slope N-E\n");
                                tileType = ETT_SLOPE_NE;
                            }
                            else if (data2 == 0x06)
                            {
                                printf("Slope S-E\n");
                                tileType = ETT_SLOPE_SE;
                            }
                            else if (data2 == 0x07)
                            {
                                printf("Slope S-W\n");
                                tileType = ETT_SLOPE_SW;
                            }
                            else if (data2 == 0x08)
                            {
                                printf("Slope N-W\n");
                                tileType = ETT_SLOPE_NW;
                            }
                            else if (data2 == 0x09)
                            {
                                printf("Corner N-E\n");
                                tileType = ETT_CORNER_NE;
                            }
                            else if (data2 == 0x0a)
                            {
                                printf("Corner S-E\n");
                                tileType = ETT_CORNER_SE;
                            }
                            else if (data2 == 0x0b)
                            {
                                printf("Corner S-W\n");
                                tileType = ETT_CORNER_SW;
                            }
                            else if (data2 == 0x0c)
                            {
                                printf("Corner N-W\n");
                                tileType = ETT_CORNER_NW;
                            }
                            else if (data2 == 0x0d)
                            {
                                printf("High ground\n");
                                tileType = ETT_HIGHGROUND;
                            }
                            else if (data2 == 0x10)
                            {
                                printf("Water covered flat terrain\n");
                                tileType = ETT_WATER_COVERED_FLAT;
                            }
                            else if (data2 == 0x11)
                            {
                                printf("Water covered slope N\n");
                                tileType = ETT_WATER_COVERED_SLOPE_N;
                            }
                            else if (data2 == 0x12)
                            {
                                printf("Water covered slope E\n");
                                tileType = ETT_WATER_COVERED_SLOPE_E;
                            }
                            else if (data2 == 0x13)
                            {
                                printf("Water covered slope S\n");
                                tileType = ETT_WATER_COVERED_SLOPE_S;
                            }
                            else if (data2 == 0x14)
                            {
                                printf("Water covered slope W\n");
                                tileType = ETT_WATER_COVERED_SLOPE_W;
                            }
                            else if (data2 == 0x15)
                            {
                                printf("Water covered slope N-E\n");
                                tileType = ETT_WATER_COVERED_SLOPE_NE;
                            }
                            else if (data2 == 0x16)
                            {
                                printf("Water covered slope S-E\n");
                                tileType = ETT_WATER_COVERED_SLOPE_SE;
                            }
                            else if (data2 == 0x17)
                            {
                                printf("Water covered slope S-W\n");
                                tileType = ETT_WATER_COVERED_SLOPE_SW;
                            }
                            else if (data2 == 0x18)
                            {
                                printf("Water covered slope N-W\n");
                                tileType = ETT_WATER_COVERED_SLOPE_NW;
                            }
                            else if (data2 == 0x19)
                            {
                                printf("Water covered corner N-E\n");
                                tileType = ETT_WATER_COVERED_CORNER_NE;
                            }
                            else if (data2 == 0x1a)
                            {
                                printf("Water covered corner S-E\n");
                                tileType = ETT_WATER_COVERED_CORNER_SE;
                            }
                            else if (data2 == 0x1b)
                            {
                                printf("Water covered corner S-W\n");
                                tileType = ETT_WATER_COVERED_CORNER_SW;
                            }
                            else if (data2 == 0x1c)
                            {
                                printf("Water covered corner N-W\n");
                                tileType = ETT_WATER_COVERED_CORNER_NW;
                            }
                            else if (data2 == 0x1d)
                            {
                                printf("Water covered high ground N-E\n");
                                tileType = ETT_WATER_COVERED_HIGHGROUND;
                            }
                            else if (data2 == 0x20)
                            {
                                printf("Water submerged flat terrain\n");
                                tileType = ETT_WATER_SUBMERGED_FLAT;
                            }
                            else if (data2 == 0x21)
                            {
                                printf("Water submerged slope N\n");
                                tileType = ETT_WATER_SUBMERGED_SLOPE_N;
                            }
                            else if (data2 == 0x22)
                            {
                                printf("Water submerged slope E\n");
                                tileType = ETT_WATER_SUBMERGED_SLOPE_E;
                            }
                            else if (data2 == 0x23)
                            {
                                printf("Water submerged slope S\n");
                                tileType = ETT_WATER_SUBMERGED_SLOPE_S;
                            }
                            else if (data2 == 0x24)
                            {
                                printf("Water submerged slope W\n");
                                tileType = ETT_WATER_SUBMERGED_SLOPE_W;
                            }
                            else if (data2 == 0x25)
                            {
                                printf("Water submerged slope N-E\n");
                                tileType = ETT_WATER_SUBMERGED_SLOPE_NE;
                            }
                            else if (data2 == 0x26)
                            {
                                printf("Water submerged slope S-E\n");
                                tileType = ETT_WATER_SUBMERGED_SLOPE_SE;
                            }
                            else if (data2 == 0x27)
                            {
                                printf("Water submerged slope S-W\n");
                                tileType = ETT_WATER_SUBMERGED_SLOPE_SW;
                            }
                            else if (data2 == 0x28)
                            {
                                printf("Water submerged slope N-W\n");
                                tileType = ETT_WATER_SUBMERGED_SLOPE_NW;
                            }
                            else if (data2 == 0x29)
                            {
                                printf("Water submerged corner N-E\n");
                                tileType = ETT_WATER_SUBMERGED_CORNER_NE;
                            }
                            else if (data2 == 0x2a)
                            {
                                printf("Water submerged corner S-E\n");
                                tileType = ETT_WATER_SUBMERGED_CORNER_SE;
                            }
                            else if (data2 == 0x2b)
                            {
                                printf("Water submerged corner S-W\n");
                                tileType = ETT_WATER_SUBMERGED_CORNER_SW;
                            }
                            else if (data2 == 0x2c)
                            {
                                printf("Water submerged corner N-W\n");
                                tileType = ETT_WATER_SUBMERGED_CORNER_NW;
                            }
                            else if (data2 == 0x2d)
                            {
                                printf("Water submerged high ground N-E\n");
                                tileType = ETT_WATER_SUBMERGED_HIGHGROUND;
                            }
                            else if (data2 == 0x30)
                            {
                                printf("Terrain with water on the surface\n");
                                tileType = ETT_SURFACE_WATER_FLAT;
                            }
                            else if (data2 == 0x31)
                            {
                                printf("Terrain with water on the surface, slope N\n");
                                tileType = ETT_SURFACE_WATER_SLOPE_N;
                            }
                            else if (data2 == 0x32)
                            {
                                printf("Terrain with water on the surface, slope E\n");
                                tileType = ETT_SURFACE_WATER_SLOPE_E;
                            }
                            else if (data2 == 0x33)
                            {
                                printf("Terrain with water on the surface, slope S\n");
                                tileType = ETT_SURFACE_WATER_SLOPE_S;
                            }
                            else if (data2 == 0x34)
                            {
                                printf("Terrain with water on the surface, slope W\n");
                                tileType = ETT_SURFACE_WATER_SLOPE_W;
                            }
                            else if (data2 == 0x35)
                            {
                                printf("Terrain with water on the surface, slope N-E\n");
                                tileType = ETT_SURFACE_WATER_SLOPE_NE;
                            }
                            else if (data2 == 0x36)
                            {
                                printf("Terrain with water on the surface, slope S-E\n");
                                tileType = ETT_SURFACE_WATER_SLOPE_SE;
                            }
                            else if (data2 == 0x37)
                            {
                                printf("Terrain with water on the surface, slope S-W\n");
                                tileType = ETT_SURFACE_WATER_SLOPE_SW;
                            }
                            else if (data2 == 0x38)
                            {
                                printf("Terrain with water on the surface, slope N-W\n");
                                tileType = ETT_SURFACE_WATER_SLOPE_NW;
                            }
                            else if (data2 == 0x39)
                            {
                                printf("Terrain with water on the surface, corner N-E\n");
                                tileType = ETT_SURFACE_WATER_CORNER_NE;
                            }
                            else if (data2 == 0x3a)
                            {
                                printf("Terrain with water on the surface, corner S-E\n");
                                tileType = ETT_SURFACE_WATER_CORNER_SE;
                            }
                            else if (data2 == 0x3b)
                            {
                                printf("Terrain with water on the surface, corner S-W\n");
                                tileType = ETT_SURFACE_WATER_CORNER_SW;
                            }
                            else if (data2 == 0x3c)
                            {
                                printf("Terrain with water on the surface, corner N-W\n");
                                tileType = ETT_SURFACE_WATER_CORNER_NW;
                            }
                            else if (data2 == 0x3d)
                            {
                                printf("Terrain with water on the surface\n");
                                tileType = ETT_SURFACE_WATER_HIGHGROUND;
                            }
                            else
                                printf("??\n");


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

                printf("Total tiles: %d\n", totalTile);
                printf("\n");

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
}
