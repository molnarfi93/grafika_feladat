#ifndef ANIMATE_H
#define ANIMATE_H

#include "model.h"
#include "scene.h"

typedef struct Control{
	float top;
	float bottom;
	float left;
	float right;
}Control;

typedef struct Mouth{
	Control control;
	TextureVertex* inner_points;
	int* indexes;
}Mouth;

typedef struct Eyebrow{
	ControlPoint control_points;
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

void update_mimic(double time);

void animate(double mouth_move, double eyebrow_move, double time);

#endif