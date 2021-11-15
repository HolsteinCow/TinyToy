#ifndef __DISPLAY_H__
#define __DISPLAY_H__

typedef struct{
	int x, y;
	bool alive;
	int height;
}line;

void active_m_init(void);
double gen_rand(void);
char gen_char(void);
void gen_line(void);
void matrix_effect_cycle(void);
void urand_effect_cycle(void);
void pack_matrix(void);

#endif
