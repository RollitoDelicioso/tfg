#include "animation.h"
#include "sprites.h"


const TAnimation attack_animation_up[2] = {{sprite_sword_up_2,4,8}, {sprite_sword_up_1,2,8}};
const TAnimation attack_animation_down[2] = {{sprite_sword_down_2,4,8}, {sprite_sword_down_1,2,8}};
const TAnimation attack_animation_left[2] = {{sprite_sword_left_2,3,14}, {sprite_sword_left_1,3,6}};
const TAnimation attack_animation_right[2] = {{sprite_sword_right_2,3,14}, {sprite_sword_right_1,3,6}};

// Type, direction, state
const u8* const duck_sprites[4][2] = {
										{
											{sprite_duck_back_1},{sprite_duck_back_2}
										},
										{
											{sprite_duck_front_1},{sprite_duck_front_2}
										},
										{
											{sprite_duck_left_1},{sprite_duck_left_2}
										},
										{
											{sprite_duck_right_1},{sprite_duck_right_2}
										}
									};

const u8* const girador_sprites[2] = { sprite_girador_1, sprite_girador_2 };

const u8* const gusano_sprites[4] = { sprite_gusano_out, sprite_gusano_hidding_1, sprite_gusano_hidding_2, sprite_gusano_moving_to_hero };

// Direction, state
const u8* const hero_sprites[4][2] = 	{
											{
												{sprite_hero_back_1},{sprite_hero_back_2}
											},
											{
												{sprite_hero_front_1},{sprite_hero_front_2}
											},
											{
												{sprite_hero_left_1},{sprite_hero_left_2}
											},
											{
												{sprite_hero_right_1},{sprite_hero_right_2}
											}
										};
const u8* const disparador_sprites[4] = { sprite_disparador_back, sprite_disparador_front, sprite_disparador_left, sprite_disparador_right };
const u8* const disparador_sprites_attacking[4] = { sprite_disparador_back, sprite_disparador_front_a, sprite_disparador_left_a, sprite_disparador_right_a };



const u8* const hero_attack_sword[4] = { sprite_hero_attack_back,sprite_hero_attack_front,sprite_hero_attack_left,sprite_hero_attack_right };