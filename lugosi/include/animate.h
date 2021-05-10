#ifndef ANIMATE_H
#define ANIMATE_H

#include "model.h"
#include "scene.h"

typedef struct Mouth{
	TextureVertex* control_points[4];
	TextureVertex* inner_points;
	int* indexes;
}Mouth;

typedef struct Eyebrow{
	TextureVertex* control_points[5];
	TextureVertex* inner_points;
	int* indexes;
}Eyebrow;

typedef enum{
	CLOUDY,
	NERVOUS, 
	PEEVED, 
	SURPRISED, 
	NORMALIZED
}Mimic;

Mouth mouth;
Eyebrow left_eyebrow;
Eyebrow right_eyebrow;
Mimic mimic;

void init_mouth();

void init_left_eyebrow();

void init_right_eyebrow();

TextureVertex* get_texture_coords(double x, double y);

int find_vertex(double wanted_x, double wanted_y);

int is_tolerated(double coords, double wanted);

int find_triangle(int wanted_index);

void update_mimic(double time);

void animate(double mouth_move, double eyebrow_move, double time);

#endif