#include "bullet.h"
#include "sprites.h"
#include "video/video.h"
#include "entities/hero.h"
#include "entities/enemy.h"
#include "entities/entity.h"

#define INIT_BULLET {0xFF,0,0,0}

const TBullet bullets[MAX_BULLETS] = {INIT_BULLET,INIT_BULLET,INIT_BULLET,INIT_BULLET,INIT_BULLET,INIT_BULLET};

u8 find_index()
{
	for(u8 i=0;i<MAX_BULLETS;++i)
	{
		if(bullets[i].x == 0xFF)
		{
			return i;
		}
	}
	return 0xFF;
}

void bullet_hit_by_hero(u8 index)
{
	u8 *p_bullet = &bullets[index].direction;
	(*p_bullet++) = hero.ldf;
	(*p_bullet) = 1;
}

void bullet_fill(u8 x, u8 y, u8 direction)
{
	u8 *p_bullet;
	u8 index = find_index();
	if(index != 0xFF)
	{
		p_bullet = &bullets[index].x;
		(*p_bullet++) = x;
		(*p_bullet++) = y;
		(*p_bullet++) = direction;
		(*p_bullet) = 0;
	}	
}

void delete_bullet(u8 index)
{
	u8* p_bullet = &bullets[index].x;
	(*p_bullet) = 0xFF;
}

void bullet_collision_with_enemies(u8 index)
{
	for(u8 i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i].lives > 0 && entity_x_collision(bullets[index].x,BULLET_WIDTH,enemies[i].x,ENTITY_WIDTH) && entity_y_collision(bullets[index].y,BULLET_HEIGHT,enemies[i].y,ENTITY_HEIGHT))
		{
			enemy_decrease_heal(i);
			delete_bullet(index);
		}
	}
}

void bullet_collision_with_hero(u8 index)
{
	if(entity_x_collision(bullets[index].x,BULLET_WIDTH,hero.x,ENTITY_WIDTH) && entity_y_collision(bullets[index].y,BULLET_HEIGHT,hero.y,ENTITY_HEIGHT))
	{
		hero_decrease_heal(1);
		delete_bullet(index);
	}
}

void bullet_update()
{

u8 *p_bullet;

for(u8 i=0;i<MAX_BULLETS;++i)
	{
		if(bullets[i].x != 0xFF)
		{
			p_bullet = &bullets[i].x;
			if(video_isInsideViewport(bullets[i].x, bullets[i].y, BULLET_WIDTH, BULLET_HEIGHT))
			{
				switch(bullets[i].direction)
				{
					case up:
						(*(p_bullet+1)) -= BULLET_SPEED_Y;
						break;
					case down:
						(*(p_bullet+1)) += BULLET_SPEED_Y;
						break;
					case left:
						(*p_bullet) -= BULLET_SPEED_X;
						break;
					case right:
						(*p_bullet) += BULLET_SPEED_X;
						break;
				}

				if(!bullets[i].hit_by_hero)
				{
					bullet_collision_with_hero(i);
				}
				else
				{
					bullet_collision_with_enemies(i);
				}
			}
			else
			{
				delete_bullet(i);
			}
		}
	}	
}

void bullet_draw()
{
	for(u8 i=0;i<MAX_BULLETS;++i)
	{
		if(bullets[i].x != 0xFF && video_isInsideViewport(bullets[i].x, bullets[i].y, BULLET_WIDTH, BULLET_HEIGHT))
		{
			cpct_drawSpriteMasked(sprite_disparador_bullet, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(bullets[i].x), RELATIVE_POSITION_Y(bullets[i].y)), BULLET_WIDTH, BULLET_HEIGHT);
		}
	}
}