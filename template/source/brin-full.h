
//{{BLOCK(brin_full)

//======================================================================
//
//	brin_full, 512x256@4, 
//	+ palette 256 entries, not compressed
//	+ 170 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 8x8 
//	Metatiled by 8x4
//	Total size: 512 + 5440 + 3648 + 128 = 9728
//
//	Time-stamp: 2020-07-11, 05:56:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BRIN_FULL_H
#define GRIT_BRIN_FULL_H

#define brin_fullTilesLen 5440
extern const unsigned int brin_fullTiles[1360];

#define brin_fullMetaTilesLen 3648
extern const unsigned int brin_fullMetaTiles[912];

#define brin_fullMetaMapLen 128
extern const unsigned int brin_fullMetaMap[32];

#define brin_fullPalLen 512
extern const unsigned int brin_fullPal[128];

#endif // GRIT_BRIN_FULL_H

//}}BLOCK(brin_full)
