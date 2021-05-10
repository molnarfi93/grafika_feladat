#include "animate.h"
#include "model.h"
#include "scene.h"
#include "callbacks.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void init_mouth(){
	
	//* init control_points
	mouth.control_points[0] = get_texture_coords(-0.65, 0.97);
	mouth.control_points[1] = get_texture_coords(0.95, 1.08);
	mouth.control_points[2] = get_texture_coords(1.11, 0.53);
	mouth.control_points[3] = get_texture_coords(-0.42, 0.62);
	
	//* init inner_points
	int num_points = 0;
	int i;
	for(i=1;i<scene.lugosi.n_texture_vertices;i++){
		int u_ok = FALSE;
		int v_ok = FALSE;
		int j;
		for(j=1;j<4;j++){
			if((scene.lugosi.texture_vertices[i].u <= mouth.control_points[0]->u) && (scene.lugosi.texture_vertices[i].u >= mouth.control_points[j]->u)){
				u_ok = TRUE;
				break;
			}
			else if((scene.lugosi.texture_vertices[i].u >= mouth.control_points[0]->u) && (scene.lugosi.texture_vertices[i].u <= mouth.control_points[j]->u)){
				u_ok = TRUE;
				break;
			}
		}
		if(u_ok == TRUE){
			for(j=1;j<4;j++){
				if((scene.lugosi.texture_vertices[i].v <= mouth.control_points[0]->v) && (scene.lugosi.texture_vertices[i].v >= mouth.control_points[j]->v)){
					v_ok = TRUE;
					break;
				}
				else if((scene.lugosi.texture_vertices[i].v >= mouth.control_points[0]->v) && (scene.lugosi.texture_vertices[i].v <= mouth.control_points[j]->v)){
					v_ok = TRUE;
					break;
				}
			}
			if(v_ok == TRUE){
				mouth.inner_points = (TextureVertex*)malloc((num_points + 1) * sizeof(TextureVertex));
				mouth.inner_points[num_points].u = scene.lugosi.texture_vertices[i].u;
				mouth.inner_points[num_points].v = scene.lugosi.texture_vertices[i].v;
				mouth.indexes = (int*)malloc((num_points + 1) * sizeof(int));
				mouth.indexes[num_points] = i;
				num_points += 1;
			}
		}
	}
}

void init_left_eyebrow(){
	
	//* init control_points
	left_eyebrow.control_points[0] = get_texture_coords(-1.20, 3.00);
	left_eyebrow.control_points[1] = get_texture_coords(-0.92, 3.28);
	left_eyebrow.control_points[2] = get_texture_coords(-0.18, 3.18);
	left_eyebrow.control_points[3] = get_texture_coords(-0.12, 3.00);
	left_eyebrow.control_points[4] = get_texture_coords(-0.74, 3.16);
	
	//* init inner_points
	int num_points = 0;
	int i;
	for(i=1;i<scene.lugosi.n_texture_vertices;i++){
		int u_ok = FALSE;
		int v_ok = FALSE;
		int j;
		for(j=1;j<5;j++){
			if((scene.lugosi.texture_vertices[i].u <= left_eyebrow.control_points[0]->u) && (scene.lugosi.texture_vertices[i].u >= left_eyebrow.control_points[j]->u)){
				u_ok = TRUE;
				break;
			}
			else if((scene.lugosi.texture_vertices[i].u >= left_eyebrow.control_points[0]->u) && (scene.lugosi.texture_vertices[i].u <= left_eyebrow.control_points[j]->u)){
				u_ok = TRUE;
				break;
			}
		}
		if(u_ok == TRUE){
			for(j=1;j<5;j++){
				if((scene.lugosi.texture_vertices[i].v <= left_eyebrow.control_points[0]->v) && (scene.lugosi.texture_vertices[i].v >= left_eyebrow.control_points[j]->v)){
					v_ok = TRUE;
					break;
				}
				else if((scene.lugosi.texture_vertices[i].v >= left_eyebrow.control_points[0]->v) && (scene.lugosi.texture_vertices[i].v <= left_eyebrow.control_points[j]->v)){
					v_ok = TRUE;
					break;
				}
			}
			if(v_ok == TRUE){
				left_eyebrow.inner_points = (TextureVertex*)malloc((num_points + 1) * sizeof(TextureVertex));
				left_eyebrow.inner_points[num_points].u = scene.lugosi.texture_vertices[i].u;
				left_eyebrow.inner_points[num_points].v = scene.lugosi.texture_vertices[i].v;
				left_eyebrow.indexes = (int*)malloc((num_points + 1) * sizeof(int));
				left_eyebrow.indexes[num_points] = i;
				num_points += 1;
			}
		}
	}
}

void init_right_eyebrow(){
	
	//* init control_points
	right_eyebrow.control_points[0] = get_texture_coords(0.65, 2.86);
	right_eyebrow.control_points[1] = get_texture_coords(0.81, 3.16);
	right_eyebrow.control_points[2] = get_texture_coords(1.48, 3.41);
	right_eyebrow.control_points[3] = get_texture_coords(1.82, 3.18);
	right_eyebrow.control_points[4] = get_texture_coords(1.71, 3.23);
	
	//* init inner_points
	int num_points = 0;
	int i;
	for(i=1;i<scene.lugosi.n_texture_vertices;i++){
		int u_ok = FALSE;
		int v_ok = FALSE;
		int j;
		for(j=1;j<5;j++){
			if((scene.lugosi.texture_vertices[i].u <= right_eyebrow.control_points[0]->u) && (scene.lugosi.texture_vertices[i].u >= right_eyebrow.control_points[j]->u)){
				u_ok = TRUE;
				break;
			}
			else if((scene.lugosi.texture_vertices[i].u >= right_eyebrow.control_points[0]->u) && (scene.lugosi.texture_vertices[i].u <= right_eyebrow.control_points[j]->u)){
				u_ok = TRUE;
				break;
			}
		}
		if(u_ok == TRUE){
			for(j=1;j<5;j++){
				if((scene.lugosi.texture_vertices[i].v <= right_eyebrow.control_points[0]->v) && (scene.lugosi.texture_vertices[i].v >= right_eyebrow.control_points[j]->v)){
					v_ok = TRUE;
					break;
				}
				else if((scene.lugosi.texture_vertices[i].v >= right_eyebrow.control_points[0]->v) && (scene.lugosi.texture_vertices[i].v <= right_eyebrow.control_points[j]->v)){
					v_ok = TRUE;
					break;
				}
			}
			if(v_ok == TRUE){
				right_eyebrow.inner_points = (TextureVertex*)malloc((num_points + 1) * sizeof(TextureVertex));
				right_eyebrow.inner_points[num_points].u = scene.lugosi.texture_vertices[i].u;
				right_eyebrow.inner_points[num_points].v = scene.lugosi.texture_vertices[i].v;
				right_eyebrow.indexes = (int*)malloc((num_points + 1) * sizeof(int));
				right_eyebrow.indexes[num_points] = i;
				num_points += 1;
			}
		}
	}
}

TextureVertex* get_texture_coords(double x, double y){
	int i = find_vertex(x, y);
	int texture_index = find_triangle(i);
	return &(scene.lugosi.texture_vertices[texture_index]);	
}

int find_vertex(double wanted_x, double wanted_y){
	int i;
	for(i=1;i<scene.lugosi.n_vertices;i++){
		int x_tol = is_tolerated(scene.lugosi.vertices[i].x, wanted_x);
		int y_tol = is_tolerated(scene.lugosi.vertices[i].y, wanted_y);
		if(x_tol == TRUE && y_tol == TRUE && scene.lugosi.vertices[i].z > 0){
			return i + 3;
		}
	}
}

int is_tolerated(double coord, double wanted){
	double diff = (double)fabs(coord - wanted);
	if (diff < 0.05){
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int find_triangle(int wanted_index){
	int i;
	for(i=1;i<scene.lugosi.n_triangles;i++){
		if(scene.lugosi.triangles[i].points[0].vertex_index == wanted_index){
			return scene.lugosi.triangles[i].points[0].texture_index;
		}
		else if(scene.lugosi.triangles[i].points[1].vertex_index == wanted_index){
			return scene.lugosi.triangles[i].points[1].texture_index;
		}
		else if(scene.lugosi.triangles[i].points[2].vertex_index == wanted_index){
			return scene.lugosi.triangles[i].points[2].texture_index;
		}
	}
}

void update_mimic(double time){
	switch (mimic) {
		case CLOUDY:
			animate(0, -0.05, time);
			break;
		case NERVOUS:
			animate(0.05, -0.05, time);
			break;
		case PEEVED:
			animate(0.05, 0, time);
			break;
		case SURPRISED:
			animate(0, 0.05, time);
			break;
		case NORMALIZED:
			animate(0, 0, time);
			break;
	}
}

void animate(double mouth_move, double eyebrow_move, double time){
	int i;
	if(time <= 1){
		for(i=0;i<sizeof(mouth.indexes)/sizeof(int);i++){
			scene.lugosi.texture_vertices[mouth.indexes[i]].v = mouth.inner_points[i].v + time * mouth_move;
		}
		for(i=0;i<sizeof(left_eyebrow.indexes)/sizeof(int);i++){
			scene.lugosi.texture_vertices[left_eyebrow.indexes[i]].v = mouth.inner_points[i].v + time * eyebrow_move;
		}
		for(i=0;i<sizeof(right_eyebrow.indexes)/sizeof(int);i++){
			scene.lugosi.texture_vertices[right_eyebrow.indexes[i]].v = mouth.inner_points[i].v + time * eyebrow_move;
		}
	}
}


			
	