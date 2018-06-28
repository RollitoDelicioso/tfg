typedef struct {
	u8 x;
	u8 y;
	u8 ldf; // L.D.F (Last Direcction Faced) To know witch direction should face the bullet.
			// 0: up, 1: down, 2: left, 3: right
	const u8* sprite;
	i8 lives;
} THero;

typedef enum {
   es_dead,       // Entity dead
   es_stop,       // Entity stopped, not moving
   es_walk_right, // Entity walking
   es_walk_left,  // Entity walking
   es_fist,       // Entity fisting
   es_kick,       // Entity kicking
   es_win,        // Entity Winning
   es_hit         // Entity is being hit
} TEntityStatus;

typedef struct {
	u8 x;
	u8 y;
	u8 ldf;	
	void (*perform_action)(u8*);
	u8 ctpa; // count_to_perform_action
	u8 stpa; // steps_to_perform_action
	u8 lives;
	u8* sprite;
} TEnemy;

