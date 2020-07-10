//
// toolbox.h: 
// 
// Tools header for obj_demo
// 
// (20060211-20060924, cearn)
//
// === NOTES ===
// * This is a _small_ set of typedefs, #defines and inlines that can 
//   be found in tonclib, and might not represent the 
//   final forms.


#ifndef TOOLBOX_H
#define TOOLBOX_H

#include "libtonc/tonc_types.h"        // (tonc_types.h)
#include "libtonc/tonc_memmap.h"        // (tonc_memmap.h)
#include "libtonc/tonc_memdef.h"        // (tonc_memdef.h)
#include "libtonc/tonc_input.h"        // (tonc_input.h)
#include "libtonc/tonc_video.h"

// --- Objects  ---

void oam_init(OBJ_ATTR *obj, u32 count);
void oam_copy(OBJ_ATTR *dst, const OBJ_ATTR *src, u32 count);
void obj_copy(OBJ_ATTR *dst, const OBJ_ATTR *src, u32 count);


// --- Objects ---


//! Set the attributes of an object.
INLINE OBJ_ATTR *obj_set_attr(OBJ_ATTR *obj, u16 a0, u16 a1, u16 a2)
{
	obj->attr0= a0; obj->attr1= a1; obj->attr2= a2;
	return obj;
}

//! Set the position of \a obj
INLINE void obj_set_pos(OBJ_ATTR *obj, int x, int y)
{
	BFN_SET(obj->attr0, y, ATTR0_Y);
	BFN_SET(obj->attr1, x, ATTR1_X);
}


#endif // TOOLBOX_H
