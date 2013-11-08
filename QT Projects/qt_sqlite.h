#pragma once
#include <QMainWindow>
#include <QGraphicsView>
#include <../../include/pkmds/pkmds_sql.h>
QPixmap getpkmsprite(const pokemon_obj &pkm);
QPixmap getpkmsprite(const pokemon_obj *pkm);
QPixmap getpkmicon(const pokemon_obj &pkm);
QPixmap getpkmicon(const pokemon_obj *pkm);
QPixmap gettypepic(const Types::types type);
QPixmap gettypepic(const int type);
QPixmap getshinystar();
QPixmap getgenderpic(const Genders::genders gender);
QPixmap getwallpaperimage(const Wallpapers::wallpapers wallpaper);
QPixmap getitemimage(const int itemid);
QPixmap getmarkingimage(const Markings::markings mark, const bool marked);
QPixmap getballpic(const Balls::balls ball);
QPixmap getmovecatimage(const Moves::moves themove);
QPixmap getpkrsimage(const pokerus & pkrs);
QPixmap getribbonimg(const std::string ribbon, const bool hoenn);
