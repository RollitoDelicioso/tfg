##-----------------------------LICENSE NOTICE------------------------------------
##  This file is part of CPCtelera: An Amstrad CPC Game Engine 
##  Copyright (C) 2018 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
##
##  This program is free software: you can redistribute it and/or modify
##  it under the terms of the GNU Lesser General Public License as published by
##  the Free Software Foundation, either version 3 of the License, or
##  (at your option) any later version.
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU Lesser General Public License for more details.
##
##  You should have received a copy of the GNU Lesser General Public License
##  along with this program.  If not, see <http://www.gnu.org/licenses/>.
##------------------------------------------------------------------------------
############################################################################
##                        CPCTELERA ENGINE                                ##
##                 Automatic image conversion file                        ##
##------------------------------------------------------------------------##
## This file is intended for users to automate tilemap conversion from    ##
## original files (like Tiled .tmx) into C-arrays.                        ##
############################################################################

## TILEMAP CONVERSION EXAMPLES (Uncomment EVAL lines to use)
##

## Convert img/tilemap.tmx to src/tilemap.c and src/tilemap.h
##		This file contains a tilemap created with Tiled that uses tiles
## in img/tiles.png. This macro will convert the tilemap into a C-array
## named g_tilemap, containing all the IDs of the tiles that are located 
## at each given location of the C-array. 
##

#$(eval $(call TMX2C,img/maps/map_1.tmx,tilemap_map_1,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/map_2.tmx,tilemap_map_2,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/map_peque.tmx,tilemap_map_2,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/test.tmx,tilemap_map_2,src/tilemap/,))

#$(eval $(call TMX2C,img/maps/Maps_game/0.tmx,map_0,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/1.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/2.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/3.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/4.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/5.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/6.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/7.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/8.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/9.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/10.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/11.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/12.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/13.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/14.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/15.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/16.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/17.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/18.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/19.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/20.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/21.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/22.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/23.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/24.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/25.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/26.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/27.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/28.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/29.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/30.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/31.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/32.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/33.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/34.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/35.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/36.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/37.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/38.tmx,map_,src/tilemap/,))

#$(eval $(call TMX2C,img/maps/Maps_game/39.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/40.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/41.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/42.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/43.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/44.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/45.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/46.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/47.tmx,map_,src/tilemap/,))

#$(eval $(call TMX2C,img/maps/Maps_game/48.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/49.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/50.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/51.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/52.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/53.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/54.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/55.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/56.tmx,map_,src/tilemap/,))

#$(eval $(call TMX2C,img/maps/Maps_game/57.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/58.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/59.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/60.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/61.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/62.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/63.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/64.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/65.tmx,map_,src/tilemap/,))

#$(eval $(call TMX2C,img/maps/Maps_game/66.tmx,map_,src/tilemap/,))
#$(eval $(call TMX2C,img/maps/Maps_game/67.tmx,map_,src/tilemap/,))



#$(eval $(call TMX2C,img/tilemap.tmx,g_tilemap,src/,4))

## Convert img/level0b.tmx to src/levels/level0b.c and src/levels/level0b.h
##		This file contains another tilemap created with Tiled. This macro 
## will convert the tilemap into a C bitarray of 4-bits per item. The array
## will be named g_level0_4bit. For each tile ID included into the final 
## bitarray, only 4 bits will be used. Therefore, each byte of the array 
## will contain 2 tile IDs.
##

#$(eval $(call TMX2C,img/level0b.tmx,g_level0_4bit,src/levels/,4))




############################################################################
##              DETAILED INSTRUCTIONS AND PARAMETERS                      ##
##------------------------------------------------------------------------##
##                                                                        ##
## Macro used for conversion is TMX2C, which has up to 4 parameters:      ##
##  (1): TMX file to be converted to C array                              ##
##  (2): C identifier for the generated C array                           ##
##  (3): Output folder for C and H files generated (Default same folder)  ##
##  (4): Bits per item (1,2,4 or 6 to codify tilemap into a bitarray).    ##
##       Blanck for normal integer tilemap array (8 bits per item)        ##
##  (5): Aditional options (aditional modifiers for cpct_tmx2csv)         ##
##                                                                        ##
## Macro is used in this way (one line for each image to be converted):   ##
##  $(eval $(call TMX2C,(1),(2),(3),(4),(5)))                             ##
##                                                                        ##
## Important:                                                             ##
##  * Do NOT separate macro parameters with spaces, blanks or other chars.##
##    ANY character you put into a macro parameter will be passed to the  ##
##    macro. Therefore ...,src/sprites,... will represent "src/sprites"   ##
##    folder, whereas ...,  src/sprites,... means "  src/sprites" folder. ##
##  * You can omit parameters by leaving them empty.                      ##
##  * Parameters (4) and (5) are optional and generally not required.     ##
############################################################################
