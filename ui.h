#ifndef __UI_H__
#define __UI_H__

#define MAX_BRIGHTNESS 14
#define MIN_BRIGHTNESS 4

#define X_BOUND 80
#define Y_BOUND 40

#define TICK_DELAY 20000L

typedef struct{
    char char_val;
    bool color;
	bool highlight;
    //bool blink;
}attr;

bool init_ui(void);
void update_ui(void);
void gen_color_pairs(void);
int ui_loop(void (*)(void), void (*)(void), bool);

#endif
