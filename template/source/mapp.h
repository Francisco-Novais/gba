
//{{BLOCK(mapp)

//======================================================================
//
//	mapp, 512x256@4, 
//	+ palette 256 entries, not compressed
//	+ 31 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 992 + 4096 = 5600
//
//	Time-stamp: 2020-07-12, 19:21:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAPP_H
#define GRIT_MAPP_H

#define mappTilesLen 992
extern const unsigned int mappTiles[248];

#define mappMapLen 4096
extern const unsigned int mappMap[1024];

#define mappPalLen 512
extern const unsigned int mappPal[128];

#endif // GRIT_MAPP_H

//}}BLOCK(mapp)
