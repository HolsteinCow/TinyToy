#ifndef __DISPLAY_H__
#define __DISPLAY_H__

typedef struct{
	int x, y, life;
	bool alive;
}line;

typedef struct{
	int x, tick;
	bool on;
}rem;

void active_m_init(void);
double gen_rand(void);
char gen_char(void);
void gen_line(void);
void matrix_effect_cycle(void);
void urand_effect_cycle(void);
void pack_matrix(void);

#endif
