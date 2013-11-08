#pragma once
#include "qt_sqlite.h"
QPixmap getpkmsprite(const pokemon_obj &pkm)
{
    QPixmap pixmap;
    std::ostringstream o;
    getspritesql(o,pkm);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getpkmsprite(const pokemon_obj *pkm)
{
    QPixmap pixmap;
    std::ostringstream o;
    getspritesql(o,pkm);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getpkmicon(const pokemon_obj &pkm)
{
    QPixmap pixmap;
    std::ostringstream o;
    geticonsql(o,pkm);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getpkmicon(const pokemon_obj *pkm)
{
    QPixmap pixmap;
    std::ostringstream o;
    geticonsql(o,pkm);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap gettypepic(const Types::types type)
{
    QPixmap pixmap;
    std::ostringstream o;
    gettypesql(o,type);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap gettypepic(const int type)
{
    QPixmap pixmap;
    std::ostringstream o;
    gettypesql(o,type);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getshinystar()
{
    QPixmap pixmap;
    std::ostringstream o;
    o << "select image from misc where identifier = \"shiny\"";
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getgenderpic(const Genders::genders gender)
{
    std::string strgender = "male";
    if(gender == Genders::female)
    {
        strgender = "female";
    }
    QPixmap pixmap;
    std::ostringstream o;
    o << "select image from misc where identifier = \"" + strgender + "\"";
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getwallpaperimage(const Wallpapers::wallpapers wallpaper)
{
    QPixmap pixmap;
    std::ostringstream o;
    getwallpapersql(o,wallpaper);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getitemimage(const int itemid)
{
    QPixmap pixmap;
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    if(((itemid >= (int)Items::tm01) & (itemid <= (int)Items::tm92)) | ((itemid >= (int)Items::tm93) & (itemid <= (int)Items::tm95)) | ((itemid >= (int)Items::hm01) & (itemid <= (int)Items::hm06)))
    {
        std::string mprefix = "tm-";
        if((itemid >= (int)Items::hm01) & (itemid <= (int)Items::hm06)){mprefix = "hm-";}
        std::string sql = "select image from items where (identifier = \"" + mprefix + getmachinetypename(Items::items(itemid)) + "\")"; // ,generation,version_group);
        strcpy__(cmd,sql.c_str());
    }
    else if((itemid >= (int)Items::datacard01) & (itemid <= (int)Items::datacard27))
    {
        std::string sql = "select image from items where (identifier = \"data-card\")";
        strcpy__(cmd,sql.c_str());
    }
    else
    {
        std::ostringstream o;
        getitemsql(o,itemid);
        strcpy__(cmd,o.str().c_str());
    }
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getmarkingimage(const Markings::markings mark, const bool marked)
{
    QPixmap pixmap;
    std::ostringstream o;
    getmarkingsql(o,mark,marked);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getballpic(const Balls::balls ball)
{
    QPixmap pixmap;
    std::ostringstream o;
    getballsql(o,ball);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getmovecatimage(const Moves::moves themove)
{
    QPixmap pixmap;
    std::ostringstream o;
    getmovecatsql(o,themove);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
QPixmap getpkrsimage(const pokerus & pkrs)
{
    QPixmap pixmap;
    if(pkrs.strain != 0)
    {
        const void * blob;
        size_t thesize = 0;
        char cmd[BUFF_SIZE];
        std::string sql = "";
        if(pkrs.days > 0)
        {
            sql = "select image from misc where identifier = \"pokerus_infected\"";
        }
        else
        {
            sql = "select image from misc where identifier = \"pokerus_cured\"";
        }
        strcpy__(cmd,sql.c_str());
        if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
        {
            int cols = sqlite3_column_count(imgstatement);
            int result = 0;
            result = sqlite3_step(imgstatement);
            if((result == SQLITE_ROW) | (result == SQLITE_DONE))
            {
                for(int col = 0; col < cols; col++)
                {
                    blob = sqlite3_column_blob(imgstatement,col);
                    thesize = sqlite3_column_bytes(imgstatement,col);
                    QByteArray array;
                    array = QByteArray::fromRawData((const char*)blob,thesize);
                    pixmap.loadFromData(array);
                }
            }
            sqlite3_finalize(imgstatement);
        }
    }
    return pixmap;
}
QPixmap getribbonimg(const std::string ribbon, const bool hoenn)
{
    QPixmap pixmap;
    std::ostringstream o;
    o << getribbonsql(ribbon,hoenn);
    const void * blob;
    size_t thesize = 0;
    char cmd[BUFF_SIZE];
    strcpy__(cmd,o.str().c_str());
    if(sqlite3_prepare_v2(imgdatabase,cmd,-1,&imgstatement,0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(imgstatement);
        int result = 0;
        result = sqlite3_step(imgstatement);
        if((result == SQLITE_ROW) | (result == SQLITE_DONE))
        {
            for(int col = 0; col < cols; col++)
            {
                blob = sqlite3_column_blob(imgstatement,col);
                thesize = sqlite3_column_bytes(imgstatement,col);
                QByteArray array;
                array = QByteArray::fromRawData((const char*)blob,thesize);
                pixmap.loadFromData(array);
            }
        }
        sqlite3_finalize(imgstatement);
    }
    return pixmap;
}
