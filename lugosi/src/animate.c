#include "animate.h"
#include "model.h"
#include "scene.h"
#include "callbacks.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int n_mouth_points = 0;
int n_left_eyebrow_points = 0;
int n_right_eyebrow_points = 0;

void init_mouth(){
	
	//* init control_points
	mouth.control.left = 764 / 1024;
	mouth.control.right = 884 / 1024;
	mouth.control.top = 285 / 1024;
	mouth.control.bottom = 317 / 1024;
	
	mouth.inner_points = (TextureVertex*)malloc(5000 * sizeof(TextureVertex));
    mouth.indexes = (int*)malloc(5000 * sizeof(int));
	//* init inner_points
	int i;
	for(i=1; i<scene.lugosi.n_texture_vertices; i++){
		if(scene.lugosi.texture_vertices[i] >= mouth.control.left && scene.lugosi.texture_vertices[i] <= mouth.control.right 
		   && scene.lugosi.texture_vertices[i] >= mouth.control.bottom && scene.lugosi.texture_vertices[i] <= mouth.control.top){
			mouth.inner_points[n_mouth_points].u = scene.lugosi.texture_vertices[i].u;
			mouth.inner_points[n_mouth_points].v = scene.lugosi.texture_vertices[i].v;
			mouth.indexes[n_mouth_points] = i;
			n_mouth_points += 1;
		}
	}
}

void init_left_eyebrow(){
	
	//* init control_points
	left_eyebrow.control.left = 836 / 1024;
	right_eyebrow.control.right = 916 / 1024;
	left_eyebrow.control.top = 198 / 1024;
	left_eyebrow.control.bottom = 232 / 1024;
	
	left_eyebrow.inner_points = (TextureVertex*)malloc(5000 * sizeof(TextureVertex));
	left_eyebrow.indexes = (int*)malloc(5000 * sizeof(int));
	//* init inner_points
	int num_points = 0;
	int i;
	for(i=1;i<scene.lugosi.n_texture_vertices;i++){
		if(scene.lugosi.texture_vertices[i] >= left_eyebrow.control.left && scene.lugosi.texture_vertices[i] <= left_eyebrow.control.right 
		   && scene.lugosi.texture_vertices[i] >= left_eyebrow.control.bottom && scene.lugosi.texture_vertices[i] <= left_eyebrow.control.top){
			left_eyebrow.inner_points[n_left_eyebrow_points].u = scene.lugosi.texture_vertices[i].u;
			left_eyebrow.inner_points[n_left_eyebrow_points].v = scene.lugosi.texture_vertices[i].v;
			left_eyebrow.indexes[n_left_eyebrow_points] = i;
			n_left_eyebrow_points += 1;
		}
	}
}

void init_right_eyebrow(){
	
	//* init control_points
	right_eyebrow.control.left = 720 / 1024;
	right_eyebrow.control.right = 798 / 1024;
	right_eyebrow.control.top = 220 / 1024;
	right_eyebrow.control.bottom = 203 / 1024;
	
	right_eyebrow.inner_points = (TextureVertex*)malloc(5000 * sizeof(TextureVertex));
	right_eyebrow.indexes = (int*)malloc(5000 * sizeof(int));
	//* init inner_points
	int num_points = 0;
	int i;
	for(i=1;i<scene.lugosi.n_texture_vertices;i++){
		if(scene.lugosi.texture_vertices[i] >= right_eyebrow.control.left && scene.lugosi.texture_vertices[i] <= right_eyebrow.control.right 
		   && scene.lugosi.texture_vertices[i] >= right_eyebrow.control.bottom && scene.lugosi.texture_vertices[i] <= right_eyebrow.control.top){
			right_eyebrow.inner_points[n_right_eyebrow_points].u = scene.lugosi.texture_vertices[i].u;
			right_eyebrow.inner_points[n_right_eyebrow_points].v = scene.lugosi.texture_vertices[i].v;
			right_eyebrow.indexes[n_right_eyebrow_points] = i;
			n_right_eyebrow_points += 1;
		}
	}
}

void update_mimic(double time){
	switch (mimic) {
		case CLOUDY:
			animate(0, -0.02, time);
			break;
		case NERVOUS:
			animate(0.02, -0.02, time);
			break;
		case PEEVED:
			animate(0.02, 0, time);
			break;
		case SURPRISED:
			animate(0, 0.02, time);
			break;
		case NORMALIZED:
			animate(0, 0, time);
			break;
	}
}

void animate(double mouth_move, double eyebrow_move, double time){ 
	if(mouth_move != 0){
		if(mouth_move > 0){
			if (scene.lugosi.texture_vertices[mouth.indexes[0]].v >= mouth.inner_points[0].v + mouth_move){
				return;
			}
			for(i=0; i<n_mouth_points; i++){ 
				scene.lugosi.texture_vertices[mouth.indexes[i]].v += (time / 20);
			}
		else if(mouth_move < 0){
			if (scene.lugosi.texture_vertices[mouth.indexes[0]].v <= mouth.inner_points[0].v + mouth_move){
				return;
			}
			for(i=0; i<n_mouth_points; i++){ 
				scene.lugosi.texture_vertices[mouth.indexes[i]].v -= (time / 20);
			}
		}
	} 
	if(eyebrow_move != 0){
		if(eyebrow_move > 0){
			if (scene.lugosi.texture_vertices[left_eyebrow.indexes[0]].v >= left_eyebrow.inner_points[0].v + eyebrow_move){
				return;
			}
			for(i=0; i<n_left_eyebrow_points; i++){
				scene.lugosi.texture_vertices[left_eyebrow.indexes[i]].v += (time / 20);
			}
			for(i=0; i<n_right_eyebrow_points; i++){
				scene.lugosi.texture_vertices[right_eyebrow.indexes[i]].v += (time / 20);
			}
		}
		else if(eyebrow_move < 0){
			if (scene.lugosi.texture_vertices[left_eyebrow.indexes[0]].v <= left_eyebrow.inner_points[0].v + eyebrow_move){
				return;
			}
			for(i=0; i<n_left_eyebrow_points; i++){
				scene.lugosi.texture_vertices[left_eyebrow.indexes[i]].v -= (time / 20);
			}
			for(i=0; i<n_right_eyebrow_points; i++){
				scene.lugosi.texture_vertices[right_eyebrow.indexes[i]].v -= (time / 20);
			}
		}
	}
}
