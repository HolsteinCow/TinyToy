#ifndef __UI_H__
#define __UI_H__

#define MAX_BRIGHTNESS 14
#define MIN_BRIGHTNESS 4

#define X_BOUND 200
#define Y_BOUND 100

typedef enum{ 
	MATRIX,
	SPIRAL,
	SNOW,
}display_m;

typedef struct{
    char char_val;
    bool color;
	bool highlight;
    //bool blink;
}attr;

extern attr matrix[X_BOUND][Y_BOUND];

bool init_ui();
void teardown_ui();
void update_ui();

#endif
