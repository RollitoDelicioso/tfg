#include "c_map_data.h"
#include "entities/enemy.h"
#include "entities/object.h"
#include "constants.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////         ENEMIES        /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define CREATE_ENEMY(X,Y,LIVES,TYPE,ON_DEAD)	{\
													.x = X,\
													.y = Y,\
													.lives = LIVES,\
													.type = TYPE,\
													.on_dead = ON_DEAD\
												}

const struct TEnemyData enemies_map_1[] = {
	CREATE_ENEMY(8,16,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_2[] = {
	CREATE_ENEMY(7,11,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(14,10,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_3[] = {
	CREATE_ENEMY(9,8,2,duck,enemy_generic_drop),
	CREATE_ENEMY(22,16,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_4[] = {
	CREATE_ENEMY(8,15,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(20,9,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_5[] = {
	CREATE_ENEMY(7,6,1,duck,enemy_generic_drop),
	CREATE_ENEMY(18,6,2,duck,enemy_generic_drop),
	CREATE_ENEMY(19,13,1,duck,enemy_generic_drop),
	CREATE_ENEMY(24,9,1,duck,enemy_generic_drop),
	CREATE_ENEMY(7,13,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_6[] = {
	CREATE_ENEMY(4,5,2,duck,enemy_generic_drop),
	CREATE_ENEMY(8,13,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_7[] = {
	CREATE_ENEMY(8,5,2,duck,enemy_generic_drop),
	CREATE_ENEMY(8,17,1,duck,enemy_generic_drop),
	CREATE_ENEMY(15,11,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_8[] = {
	CREATE_ENEMY(5,7,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(21,11,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(10,16,1,disparador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_12[] = {
	CREATE_ENEMY(7,4,1,girador,enemy_generic_drop),
	CREATE_ENEMY(16,11,2,girador,enemy_generic_drop),
	CREATE_ENEMY(19,3,1,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_13[] = {
	CREATE_ENEMY(8,4,1,duck,enemy_generic_drop),
	CREATE_ENEMY(8,11,2,duck,enemy_generic_drop),
	CREATE_ENEMY(23,4,2,duck,enemy_generic_drop),
	CREATE_ENEMY(23,11,1,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_14[] = {
	CREATE_ENEMY(6,11,3,duck,enemy_generic_drop),
	CREATE_ENEMY(8,4,1,disparador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_15[] = {
	CREATE_ENEMY(5,11,2,duck,enemy_generic_drop),
	CREATE_ENEMY(14,7,1,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_16[] = {
	CREATE_ENEMY(21,1,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(7,6,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(18,11,1,disparador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_19[] = {
	CREATE_ENEMY(4,8,2,duck,enemy_generic_drop),
	CREATE_ENEMY(20,5,3,duck,enemy_generic_drop),
	CREATE_ENEMY(5,11,3,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_22[] = {
	CREATE_ENEMY(9,5,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(10,14,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(21,10,1,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_23[] = {
	CREATE_ENEMY(4,4,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(4,10,1,gusano,enemy_generic_drop),
	CREATE_ENEMY(20,5,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(22,11,3,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_26[] = {
	CREATE_ENEMY(5,6,1,duck,enemy_generic_drop),
	CREATE_ENEMY(6,16,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_27[] = {
	CREATE_ENEMY(17,4,1,duck,enemy_generic_drop),
	CREATE_ENEMY(8,9,2,duck,enemy_generic_drop),
	CREATE_ENEMY(9,16,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_28[] = {
	CREATE_ENEMY(5,5,1,gusano,enemy_generic_drop),
	CREATE_ENEMY(13,13,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(16,4,1,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_29[] = {
	CREATE_ENEMY(4,4,1,gusano,enemy_generic_drop),
	CREATE_ENEMY(4,13,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(18,3,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(28,15,3,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_32[] = {
	CREATE_ENEMY(12,5,2,duck,enemy_generic_drop),
	CREATE_ENEMY(12,12,2,duck,enemy_generic_drop),
	CREATE_ENEMY(22,9,1,duck,enemy_generic_drop)
};


const struct TEnemyData enemies_map_33[] = {
	CREATE_ENEMY(9,5,2,duck,enemy_generic_drop),
	CREATE_ENEMY(19,6,2,duck,enemy_generic_drop),
	CREATE_ENEMY(3,8,2,duck,enemy_generic_drop),
	CREATE_ENEMY(19,11,1,duck,enemy_generic_drop)
};


const struct TEnemyData enemies_map_34[] = {
	CREATE_ENEMY(10,9,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_35[] = {
	CREATE_ENEMY(4,8,1,gusano,enemy_generic_drop),
	CREATE_ENEMY(14,4,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(15,11,1,gusano,enemy_generic_drop),
	CREATE_ENEMY(27,8,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_36[] = {
	CREATE_ENEMY(18,1,2,girador,enemy_generic_drop),
	CREATE_ENEMY(18,7,2,girador,enemy_generic_drop),
	CREATE_ENEMY(17,11,2,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_38[] = {
	CREATE_ENEMY(7,11,1,gusano,enemy_drop_white_key)
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////      LOCAL PORTALS     /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const struct TLocalPortalData portal_map_1 = {1,11,17,1};
const struct TLocalPortalData portal_map_27 = {2,9,24,15};
const struct TLocalPortalData portal_map_29 = {27,3,11,9};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////    EXTERNAL PORTALs    /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//const struct TExternalPortalData external_portal_map_0 = {10,10,1};
const struct TExternalPortalData external_portal_map_2 = {24,6,8};
const struct TExternalPortalData external_portal_map_8 = {15,22,2};
const struct TExternalPortalData external_portal_map_11 = {7,4,38};
//const struct TExternalPortalData external_portal_map_16 = {10,10,1};
const struct TExternalPortalData external_portal_map_18 = {7,17,37};
//const struct TExternalPortalData external_portal_map_26 = {10,10,1};
//const struct TExternalPortalData external_portal_map_29 = {10,10,1};
//const struct TExternalPortalData external_portal_map_31 = {10,10,1};
const struct TExternalPortalData external_portal_map_37 = {9,11,18};
const struct TExternalPortalData external_portal_map_38 = {11,12,11};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////          DOORS         /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const struct TDoorData door_map_1 = {5,15,0,0};
const struct TDoorData door_map_2 = {15,20,0,0};
const struct TDoorData door_map_18 = {6,18,0,1};
const struct TDoorData door_map_19 = {16,15,0,2};
const struct TDoorData door_map_20 = {11,8,0,3};
const struct TDoorData door_map_29 = {23,2,0,4};
