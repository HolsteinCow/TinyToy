#ifndef __UI_H__
#define __UI_H__

#define X_BOUND 200
#define Y_BOUND 100

typedef struct{
    char char_val;
    int brightness;
    bool highlight;
    bool bold;
    bool blink;
    short int color;
    short int bg_color;
} attr;

extern attr char_matrix[X_BOUND][Y_BOUND]

bool init_ui();
void teardown_ui();

#endif
