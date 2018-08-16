#include <cpctelera.h>

typedef struct {
	const u8* const sprite;
	u8 width;
	u8 height;
} TAnimation;

extern const TAnimation attack_animation_up[2];
extern const TAnimation attack_animation_down[2];
extern const TAnimation attack_animation_left[2];
extern const TAnimation attack_animation_right[2];

extern const u8* const duck_sprites[4][2];
extern const u8* const girador_sprites[2];
extern const u8* const gusano_sprites[4];
extern const u8* const disparador_sprites[4];
extern const u8* const disparador_sprites_attacking[4];
extern const u8* const hero_sprites[4][2];
extern const u8* const hero_attack_sword[4];
