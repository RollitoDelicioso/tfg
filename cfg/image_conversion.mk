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
## This file is intended for users to automate image conversion from JPG, ##
## PNG, GIF, etc. into C-arrays.                                          ##
############################################################################

## Example firmware palette definition as variable in cpct_img2tileset format

PALETTE={24 0 26 3 6 9 10 12 11 22 15 14 16 23 4 13}

## AUTOMATED IMAGE CONVERSION EXAMPLE (Uncomment EVAL line to use)
##
##    This example would convert img/example.png into src/example.{c|h} files.
##    A C-array called pre_example[24*12*2] would be generated with the definition
##    of the image example.png in mode 0 screen pixel format, with interlaced mask.
##    The palette used for conversion is given through the PALETTE variable and
##    a pre_palette[16] array will be generated with the 16 palette colours as 
##	  hardware colour values.

#$(eval $(call IMG2SPRITES,img/example.png,0,pre,24,12,$(PALETTE),mask,src/,hwpalette))




############################################################################
##              DETAILED INSTRUCTIONS AND PARAMETERS                      ##
##------------------------------------------------------------------------##
##                                                                        ##
## Macro used for conversion is IMG2SPRITES, which has up to 9 parameters:##
##  (1): Image file to be converted into C sprite (PNG, JPG, GIF, etc)    ##
##  (2): Graphics mode (0,1,2) for the generated C sprite                 ##
##  (3): Prefix to add to all C-identifiers generated                     ##
##  (4): Width in pixels of each sprite/tile/etc that will be generated   ##
##  (5): Height in pixels of each sprite/tile/etc that will be generated  ##
##  (6): Firmware palette used to convert the image file into C values    ##
##  (7): (mask / tileset / zgtiles)                                       ##
##     - "mask":    generate interlaced mask for all sprites converted    ##
##     - "tileset": generate a tileset array with pointers to all sprites ##
##     - "zgtiles": generate tiles/sprites in Zig-Zag pixel order and     ##
##                  Gray Code row order                                   ##
##  (8): Output subfolder for generated .C/.H files (in project folder)   ##
##  (9): (hwpalette)                                                      ##
##     - "hwpalette": output palette array with hardware colour values    ##
## (10): Aditional options (you can use this to pass aditional modifiers  ##
##       to cpct_img2tileset)                                             ##
##                                                                        ##
## Macro is used in this way (one line for each image to be converted):   ##
##  $(eval $(call IMG2SPRITES,(1),(2),(3),(4),(5),(6),(7),(8),(9), (10))) ##
##                                                                        ##
## Important:                                                             ##
##  * Do NOT separate macro parameters with spaces, blanks or other chars.##
##    ANY character you put into a macro parameter will be passed to the  ##
##    macro. Therefore ...,src/sprites,... will represent "src/sprites"   ##
##    folder, whereas ...,  src/sprites,... means "  src/sprites" folder. ##
##                                                                        ##
##  * You can omit parameters but leaving them empty. Therefore, if you   ##
##  wanted to specify an output folder but do not want your sprites to    ##
##  have mask and/or tileset, you may omit parameter (7) leaving it empty ##
##     $(eval $(call IMG2SPRITES,imgs/1.png,0,g,4,8,$(PAL),,src/))        ##
############################################################################

## TILESET ###########################################################################################

$(eval $(call IMG2SPRITES,img/tiles.png,0,tileset,8,8,$(PALETTE),zgtiles,src/tilemap/,hwpalette,))


## HERO ##############################################################################################

## Hero sprites
$(eval $(call IMG2SPRITES,img/Hero/hero_front_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_front_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_back_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_back_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_left_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_left_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_right_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_right_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))

## Attacking
$(eval $(call IMG2SPRITES,img/Hero/hero_attack_front.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_attack_left.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_attack_right.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Hero/hero_attack_back.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))

## Attack Sprite
$(eval $(call IMG2SPRITES,img/Sword/sword_down_1.png,0,sprite,4,8,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Sword/sword_down_2.png,0,sprite,8,8,$(PALETTE),mask,src/sprites,))

$(eval $(call IMG2SPRITES,img/Sword/sword_up_1.png,0,sprite,4,8,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Sword/sword_up_2.png,0,sprite,8,8,$(PALETTE),mask,src/sprites,))

$(eval $(call IMG2SPRITES,img/Sword/sword_left_1.png,0,sprite,6,6,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Sword/sword_left_2.png,0,sprite,6,14,$(PALETTE),mask,src/sprites,))

$(eval $(call IMG2SPRITES,img/Sword/sword_right_1.png,0,sprite,6,6,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Sword/sword_right_2.png,0,sprite,6,14,$(PALETTE),mask,src/sprites,))

#######################################################################################################

## ENEMIES ############################################################################################

## DUCK

$(eval $(call IMG2SPRITES,img/Enemies/Duck/duck_back_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Duck/duck_back_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Duck/duck_front_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Duck/duck_front_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Duck/duck_left_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Duck/duck_left_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Duck/duck_right_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Duck/duck_right_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))

## GIRADOR

$(eval $(call IMG2SPRITES,img/Enemies/Girador/girador_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Girador/girador_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))

## GUSANO

$(eval $(call IMG2SPRITES,img/Enemies/Gusano/gusano_out.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Gusano/gusano_hidding_1.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Gusano/gusano_hidding_2.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Gusano/gusano_moving_to_hero.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))

## DISPARADOR

$(eval $(call IMG2SPRITES,img/Enemies/Disparador/disparador_back.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Disparador/disparador_front.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Disparador/disparador_front_a.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Disparador/disparador_left.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Disparador/disparador_left_a.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Disparador/disparador_right.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Disparador/disparador_right_a.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Enemies/Disparador/disparador_bullet.png,0,sprite,2,4,$(PALETTE),mask,src/sprites,))


#######################################################################################################


## OBJECTS ############################################################################################

## Hearth

$(eval $(call IMG2SPRITES,img/Objects/Hearth/full_hearth.png,0,sprite,8,8,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Objects/Hearth/half_hearth.png,0,sprite,8,8,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Objects/Hearth/empty_hearth.png,0,sprite,8,8,$(PALETTE),mask,src/sprites,))

## Key

$(eval $(call IMG2SPRITES,img/Objects/Key/white_key.png,0,sprite,4,8,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Objects/Key/green_key.png,0,sprite,4,8,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Objects/Key/red_key.png,0,sprite,4,8,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Objects/Key/blue_key.png,0,sprite,4,8,$(PALETTE),mask,src/sprites,))

#######################################################################################################

## Door

$(eval $(call IMG2SPRITES,img/Objects/Doors/white_door.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Objects/Doors/green_door.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Objects/Doors/red_door.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))
$(eval $(call IMG2SPRITES,img/Objects/Doors/blue_door.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))

#######################################################################################################

## Princess

$(eval $(call IMG2SPRITES,img/Princess/princess.png,0,sprite,8,16,$(PALETTE),mask,src/sprites,))

#######################################################################################################

## Logo

$(eval $(call IMG2SPRITES,img/Logo/logo.png,0,sprite,40,20,$(PALETTE),mask,src/sprites,))

#######################################################################################################
