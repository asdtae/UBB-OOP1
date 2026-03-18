#pragma once

struct inter{};

// inicializál, beállít; függvényparaméterek:
// 2 db. valós; ha az első paraméter nagyobb
// mint a második, cseréljük fel a két értéket!
inter* init(int, int);

// a lefoglalt memóriaterületet felszabadítja
void felsz(inter*);

// az intervallum méretét a intervallum
// közepére nézve megduplázza; pl. [1,3]-ból [0,4] lesz
inter* duplaz(inter*);

// kiírja az intervallumot
void kiir(const inter*);

// set value
// void set(const inter*, double);