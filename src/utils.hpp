#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED



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

#endif // UTILS_HPP_INCLUDED
