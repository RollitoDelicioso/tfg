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
	CREATE_ENEMY(7,6,1,disparador,enemy_drop_red_key),
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
	CREATE_ENEMY(18,7,2,girador,enemy_drop_green_key),
	CREATE_ENEMY(17,11,2,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_38[] = {
	CREATE_ENEMY(7,11,1,gusano,enemy_drop_white_key)
};

const struct TEnemyData enemies_map_40[] = {
	CREATE_ENEMY(4,5,2,duck,enemy_generic_drop),
	CREATE_ENEMY(4,14,3,duck,enemy_generic_drop),
	CREATE_ENEMY(11,5,2,duck,enemy_generic_drop),
	CREATE_ENEMY(11,14,3,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_41[] = {
	CREATE_ENEMY(11,10,2,disparador,enemy_drop_white_key),
	CREATE_ENEMY(7,5,3,girador,enemy_generic_drop),
	CREATE_ENEMY(7,14,3,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_42[] = {
	CREATE_ENEMY(6,9,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(3,4,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(1,14,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_43[] = {
	CREATE_ENEMY(3,6,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(10,6,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(3,14,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(10,14,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_44[] = {
	CREATE_ENEMY(10,9,4,disparador,enemy_drop_white_key)
	
};

const struct TEnemyData enemies_map_45[] = {
	CREATE_ENEMY(7,5,3,gusano,enemy_generic_drop),
	CREATE_ENEMY(4,9,2,duck,enemy_generic_drop),
	CREATE_ENEMY(10,9,3,gusano,enemy_generic_drop),
	CREATE_ENEMY(7,14,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_46[] = {
	CREATE_ENEMY(6,10,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(9,10,2,disparador,enemy_drop_white_key)
};

const struct TEnemyData enemies_map_47[] = {
	CREATE_ENEMY(3,4,3,girador,enemy_generic_drop),
	CREATE_ENEMY(8,10,2,disparador,enemy_drop_white_key),
	CREATE_ENEMY(5,14,3,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_48[] = {
	CREATE_ENEMY(13,2,2,disparador,enemy_drop_white_key),
	CREATE_ENEMY(24,6,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(2,7,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(2,11,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(14,11,2,disparador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_49[] = {
	CREATE_ENEMY(4,3,2,girador,enemy_generic_drop),
	CREATE_ENEMY(8,4,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(16,3,2,girador,enemy_generic_drop),
	CREATE_ENEMY(9,11,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_50[] = {
	CREATE_ENEMY(8,16,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(19,16,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(12,11,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(18,6,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(13,2,2,disparador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_51[] = {
	CREATE_ENEMY(18,7,2,girador,enemy_drop_white_key),
	CREATE_ENEMY(20,1,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(9,11,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(7,16,2,disparador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_52[] = {
	CREATE_ENEMY(7,8,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(2,13,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(15,16,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(14,3,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_53[] = {
	CREATE_ENEMY(7,4,2,girador,enemy_generic_drop),
	CREATE_ENEMY(9,14,2,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_54[] = {
	CREATE_ENEMY(3,14,1,disparador,enemy_drop_white_key),
	CREATE_ENEMY(5,14,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(7,14,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(1,14,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(13,9,2,duck,enemy_generic_drop)
};

const struct TEnemyData enemies_map_55[] = {
	CREATE_ENEMY(12,12,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(5,9,2,disparador,enemy_drop_white_key),
	CREATE_ENEMY(8,18,1,disparador,enemy_generic_drop),
	CREATE_ENEMY(16,2,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_56[] = {
	CREATE_ENEMY(9,8,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(13,8,2,disparador,enemy_drop_white_key),
	CREATE_ENEMY(9,12,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(13,12,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(11,8,3,girador,enemy_generic_drop),
	CREATE_ENEMY(11,15,3,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_57[] = {
	CREATE_ENEMY(10,2,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(9,9,2,girador,enemy_generic_drop),
	CREATE_ENEMY(9,16,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(17,10,2,gusano,enemy_drop_green_key)
};

const struct TEnemyData enemies_map_58[] = {
	CREATE_ENEMY(3,13,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(7,5,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(12,13,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(19,11,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_59[] = {
	CREATE_ENEMY(16,3,2,gusano,enemy_drop_green_key),
	CREATE_ENEMY(4,3,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(5,14,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(15,14,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_60[] = {
	CREATE_ENEMY(16,2,2,disparador,enemy_drop_green_key),
	CREATE_ENEMY(7,16,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(2,9,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_61[] = {
	CREATE_ENEMY(4,2,2,disparador,enemy_drop_green_key),
	CREATE_ENEMY(8,2,2,girador,enemy_generic_drop),
	CREATE_ENEMY(9,16,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_62[] = {
	CREATE_ENEMY(8,7,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(13,13,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_63[] = {
	CREATE_ENEMY(14,16,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(3,16,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(3,10,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(10,2,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(2,5,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(14,10,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_64[] = {
	CREATE_ENEMY(6,2,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(14,2,2,disparador,enemy_drop_green_key),
	CREATE_ENEMY(14,8,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(3,8,2,gusano,enemy_generic_drop)
};

const struct TEnemyData enemies_map_65[] = {
	CREATE_ENEMY(14,16,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(4,16,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(4,10,2,gusano,enemy_generic_drop),
	CREATE_ENEMY(9,8,2,gusano,enemy_drop_blue_key),
	CREATE_ENEMY(16,11,2,disparador,enemy_generic_drop),
	CREATE_ENEMY(9,13,2,girador,enemy_generic_drop)
};

const struct TEnemyData enemies_map_66[] = {
	CREATE_ENEMY(7,12,5,disparador,enemy_drop_red_key)
};

const struct TEnemyData enemies_map_67[] = {
	CREATE_ENEMY(7,6,1,princess,enemy_generic_drop)
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
const struct TLocalPortalData portal_map_39 = {7,6,7,10};
const struct TLocalPortalData portal_map_49 = {3,8,15,14};
const struct TLocalPortalData portal_map_51 = {6,12,20,12};
const struct TLocalPortalData portal_map_53 = {15,1,1,15};
const struct TLocalPortalData portal_map_54 = {15,11,11,15};
const struct TLocalPortalData portal_map_55 = {9,13,14,7};

const struct TLocalPortalData portal_map_58 = {14,1,14,7};
const struct TLocalPortalData portal_map_60 = {1,1,7,7};
const struct TLocalPortalData portal_map_63 = {7,3,18,17};




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////    EXTERNAL PORTALs    /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


const struct TExternalPortalData external_portal_map_0 = {7,4,66};
//const struct TExternalPortalData external_portal_map_9 = {10,10,1};
//const struct TExternalPortalData external_portal_map_10 = {10,10,1};
const struct TExternalPortalData external_portal_map_2 = {24,6,8};
const struct TExternalPortalData external_portal_map_8 = {15,22,2};
const struct TExternalPortalData external_portal_map_11 = {7,5,38};
const struct TExternalPortalData external_portal_map_16 = {11,4,20};
const struct TExternalPortalData external_portal_map_18 = {7,17,37};
const struct TExternalPortalData external_portal_map_20 = {24,12,16};
const struct TExternalPortalData external_portal_map_26 = {7,3,39};
const struct TExternalPortalData external_portal_map_29 = {2,2,57};
const struct TExternalPortalData external_portal_map_31 = {2,1,48};
const struct TExternalPortalData external_portal_map_37 = {9,12,18};
const struct TExternalPortalData external_portal_map_38 = {11,12,11};
const struct TExternalPortalData external_portal_map_39 = {16,6,26};
const struct TExternalPortalData external_portal_map_47 = {16,6,26};
const struct TExternalPortalData external_portal_map_50 = {2,2,51};
const struct TExternalPortalData external_portal_map_53 = {4,19,54};
const struct TExternalPortalData external_portal_map_56 = {7,11,67}; //Enviar a fin
const struct TExternalPortalData external_portal_map_65 = {11,3,23};
const struct TExternalPortalData external_portal_map_66 = {6,11,0};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////          DOORS         /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const struct TDoorData door_map_2 = {15,20,red,0};
const struct TDoorData door_map_18 = {6,18,white,1};
const struct TDoorData door_map_19 = {16,15,blue,2};
const struct TDoorData door_map_20 = {11,8,red,3};
const struct TDoorData door_map_29 = {23,2,green,4};
const struct TDoorData door_map_33 = {24,8,red,5};

const struct TDoorData door_map_40 = {7,18,white,6};
const struct TDoorData door_map_42 = {7,18,white,7};
const struct TDoorData door_map_47 = {11,9,white,8};

const struct TDoorData door_map_48 = {16,16,white,9};
const struct TDoorData door_map_51 = {26,16,white,10};
const struct TDoorData door_map_54 = {16,18,white,11};
const struct TDoorData door_map_55 = {19,1,white,12};
const struct TDoorData door_map_56 = {11,18,white,13};

const struct TDoorData door_map_57 = {19,15,green,14};
const struct TDoorData door_map_59 = {17,18,green,15};
const struct TDoorData door_map_60 = {1,18,green,16};
const struct TDoorData door_map_62 = {0,8,green,17};
const struct TDoorData door_map_65 = {16,4,green,18};

