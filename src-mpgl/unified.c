// TODO: replace all tabs with spaces, fix any obvious grammar/spelling issues
// TODO: see about appropriateness of Black Book fns: https://www.phatcode.net/res/224/files/html/index.html

typedef void TODOTYPE;  // TODO

/**
 * MicroProse Graphics Library
 *
 * The MicroProse Graphics Library is intended to be a collection of high quality routines
 * to perform the primitive graphic functions normally required in our games.
 *
 * The routines are combined together to form a consistent interface between the applications.
 *
 * As much as possible, graphics adapter specific logic has been hidden
 * to make the underlying hardware transparent to the user.
 *
 * Each game will of necessity embellish the library with custom features.
 *
 * Hopefully the library will at least provide the required primitives.
 */

NULL;  // TODO


/**
 * RastPort
 *
 * Many of the C-callable graphics routines get their parameters from a RastPort.
 * A RastPort is a definition of a window into a screen.
 * It defines the boundaries of that window for clipping and relative addressing
 * as well as maintaining current pen colors and font info for text drawing.
 *
 * The file RastPort (TODO) contains a definition of the structure.
 */
struct RastPort {
    struct  Layer *Layer;
    struct  BitMap *BitMap;
    UWORD *AreaPtrn;  /* Ptr to areafill pattern */
    struct  TmpRas *TmpRas;
    struct  AreaInfo *AreaInfo;
    struct  GelsInfo *GelsInfo;
    UBYTE Mask;  /* Write mask for this raster */
    BYTE FgPen;  /* Foreground pen for this raster */
    BYTE BgPen;  /* Background pen  */
    BYTE AOlPen;  /* Areafill outline pen */
    BYTE DrawMode;  /* Drawing mode for fill, lines, and text */
    BYTE AreaPtSz;  /* 2^n words for areafill pattern */
    BYTE linpatcnt;  /* Current line drawing pattern preshift */
    BYTE dummy;
    UWORD Flags;  /* Miscellaneous control bits */
    UWORD LinePtrn;  /* 16 bits for textured lines */
    WORD cp_x, cp_y;  /* Current pen position */
    UBYTE minterms[8];
    WORD PenWidth;
    WORD PenHeight;
    struct  TextFont *Font;  /* Current font address */
    UBYTE AlgoStyle;  /* The algorithmically generated style */
    UBYTE TxFlags;  /* Text specific flags */
    UWORD TxHeight;  /* Text height */
    UWORD TxWidth;  /* Text nominal width */
    UWORD TxBaseline;  /* Text baseline */
    WORD TxSpacing;  /* Text spacing (per character) */
    APTR *RP_User;
    ULONG longreserved[2];
#ifndef GFX_RASTPORT_1_2
    UWORD wordreserved[7];  /* Used to be a node */
    UBYTE reserved[8];  /* For future use */
#endif
};
// TODO: see http://www.kaiiv.de/retrocoding/1/ and https://wiki.amigaos.net/wiki/Graphics_Primitives and http://amigadev.elowar.com/read/ADCD_2.1/Includes_and_Autodocs_2._guide/node00AF.html


/**
 * Map a graphic page to a memory segment.
 */
void map_page_to_seg(TODOTYPE page, TODOTYPE seg)
{
  // TODO
}


/**
 * Returns library-specific data parameters one at a time.
 * Programs would have an include file with defines for the indexes.
 * Conceptually, this facility should be for static data only.
 */
void dump_params()
{
  // TODO
}

/**
 * Load in the selected overlay and setup vector table.
 *
 * This is a software only function. (TODO: did this line belong to a different routine?)
 */
void TODO_1()
{
  // TODO
}


/**
 * To load the new palette into the hardware registers, a SetPalette is required.
 */
void TODO_2()
{
  // TODO
}


/**
 * Set video mode for this library plus any other library specific initialization
 *
 * The mode argument is the same value used for LibCanDo.
 * And is unused in libraries supporting a single video mode.
 */
void set_video_mode(TODOTYPE mode)
{
  // TODO
}


/**
 * Determine what graphics modes are supported in the hardware.
 * \return The code for the highest performance video system found
 * It would be nice if this code was used system-wide.
 */
void get_best_gfx_mode()
{
  // TODO
}


/// This group of functions operate on entire graphic pages.

/**
 * Display the selected graphics page on the CRT.
 * Otherwise a blast is performed, overwriting the data previously in video memory.
 */
void TODO_4()
{
  // TODO
}


/**
 * Display the selected graphics page on the CRT.
 * Otherwise a non-destructive ShowPage is performed, swapping the data with the video buffer.
 */
void TODO_5()
{
  // TODO
}


/**
 * A random dissolve is performed from page to the current video page.
 * This is a destructive copy in all video modes.
 */
void dissolve(TODOTYPE page)
{
  // TODO
}


/// This group of functions operate on windows of graphic pages.

/**
 * Copy a window from one graphics page to another.
 */
void TODO_6()
{
  // TODO
}


/**
 * Fill a window in a RastPort with a color.
 */
void TODO_1()
{
  // TODO
}


/// These routines read a picture from a disk file into a graphics page.
/// Any conversion or decompression is performed automatically.
/// Currently two file formats are supported: IFF for development and CRUNCHED for production.
/// The picture file contains color palette data that is loaded as well.
/// For color pictures, the palette is 16 color values stored in bytes.
/// With the upper nibble being blank.

// TODO


/// The following are used internally by LoadPicture.

// TODO


/// The following code illustrates the intended usage.

// TODO


/**
 * Sprites
 *
 * Sprites are defined by a structure and are passed as arguments with pointers to that structure.
 *
 * The header of the structure defines the size of the sprite and other parameter data.
 * Following the header is the compressed picture data.
 * Each scan line is defined by two size bytes and the variable length data.
 * The first size byte gives the relative offset to the first non-blank pixel.
 * The second size byte gives the length of data following.
 *
 * There was a conceptual problem with building sprites offline, but I can't remember what it is.
 *
 * Sprites can be built online or offline.
 * An offline sprite compiler will allow sprites to be extracted from graphic images,
 * formed into structures, and saved in disk files.
 * An online facility will exist to perform the same function at the expense of longer load times.
 * Sprites contain the destination page for writing and display.
 * Sprites ALWAYS exist in real memory and are in pixel format.
 * It is still an open issue as to whether or not a separate mask plane is required.
 */
