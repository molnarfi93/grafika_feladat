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
	mouth->control_points[0] = get_texture_coords(-0.95, -1.29, 1.08);
	mouth->control_points[1] = get_texture_coords(0.95, -1.29, 1.08);
	mouth->control_points[2] = get_texture_coords(-0.48, -2.82, 0);
	mouth->control_points[3] = get_texture_coords(0.88, -2.53, -0.12);
	
	//* init inner_points
	int num_points = 0;
	int i;
	for(i=1;i<scene.lugosi.n_texture_vertices;i++){
		int u_ok = FALSE;
		int v_ok = FALSE;
		int j;
		for(j=1;j<4;j++){
			if((scene.lugosi.texture_vertices[i].u <= mouth->control_points[0].u) && (scene.lugosi.texture_vertices[i].u >= mouth->control_points[j].u)){
				u_ok = TRUE;
				break;
			}
			else if((scene.lugosi.texture_vertices[i].u >= mouth->control_points[0].u) && (scene.lugosi.texture_vertices[i].u <= mouth->control_points[j].u)){
				u_ok = TRUE;
				break;
			}
		}
		if(u_ok == TRUE){
			for(j=1;j<4;j++){
				if((scene.lugosi.texture_vertices[i].v <= mouth->control_points[0].v) && (scene.lugosi.texture_vertices[i].v >= mouth->control_points[j].v)){
					v_ok = TRUE;
					break;
				}
				else if((scene.lugosi.texture_vertices[i].v >= mouth->control_points[0].v) && (scene.lugosi.texture_vertices[i].v <= mouth->control_points[j].v)){
					v_ok = TRUE;
					break;
				}
			}
			if(v_ok == TRUE){
				mouth->inner_points = (TextureVertex*)malloc((num_points + 1) * sizeof(TextureVertex));
				mouth->inner_points[num_points].u = scene.lugosi.texture_vertices[i].u;
				mouth->inner_points[num_points].v = scene.lugosi.texture_vertices[i].v;
				mouth->indexes = (int*)malloc((num_points + 1) * sizeof(int));
				mouth->indexes[num_points] = i;
				num_points += 1;
			}
		}
	}
}

void init_left_eyebrow(){
	
	//* init control_points
	left_eyebrow->control_points[0] = get_texture_coords(0.39, -1.97, 2.98);
	left_eyebrow->control_points[1] = get_texture_coords(1.57, -1.24, 3.34);
	left_eyebrow->control_points[2] = get_texture_coords(0.58, -1.74, 2.56);
	left_eyebrow->control_points[3] = get_texture_coords(1.36, -1.76, 2.81);
	left_eyebrow->control_points[4] = get_texture_coords(1.38, -1.37, 2.65);
	
	//* init inner_points
	int num_points = 0;
	int i;
	for(i=1;i<scene.lugosi.n_texture_vertices;i++){
		int u_ok = FALSE;
		int v_ok = FALSE;
		int j;
		for(j=1;j<5;j++){
			if((scene.lugosi.texture_vertices[i].u <= left_eyebrow->control_points[0].u) && (scene.lugosi.texture_vertices[i].u >= left_eyebrow->control_points[j].u)){
				u_ok = TRUE;
				break;
			}
			else if((scene.lugosi.texture_vertices[i].u >= left_eyebrow->control_points[0].u) && (scene.lugosi.texture_vertices[i].u <= left_eyebrow->control_points[j].u)){
				u_ok = TRUE;
				break;
			}
		}
		if(u_ok == TRUE){
			for(j=1;j<5;j++){
				if((scene.lugosi.texture_vertices[i].v <= left_eyebrow->control_points[0].v) && (scene.lugosi.texture_vertices[i].v >= left_eyebrow->control_points[j].v)){
					v_ok = TRUE;
					break;
				}
				else if((scene.lugosi.texture_vertices[i].v >= left_eyebrow->control_points[0].v) && (scene.lugosi.texture_vertices[i].v <= left_eyebrow->control_points[j].v)){
					v_ok = TRUE;
					break;
				}
			}
			if(v_ok == TRUE){
				left_eyebrow->inner_points = (TextureVertex*)malloc((num_points + 1) * sizeof(TextureVertex));
				left_eyebrow->inner_points[num_points].u = scene.lugosi.texture_vertices[i].u;
				left_eyebrow->inner_points[num_points].v = scene.lugosi.texture_vertices[i].v;
				left_eyebrow->indexes = (int*)malloc((num_points + 1) * sizeof(int));
				left_eyebrow->indexes[num_points] = i;
				num_points += 1;
			}
		}
	}
}

void init_right_eyebrow(){
	
	//* init control_points
	right_eyebrow->control_points[0] = get_texture_coords(-1.48, -1.34, 3.23);
	right_eyebrow->control_points[1] = get_texture_coords(-0.39, -2.56, 3.14);
	right_eyebrow->control_points[2] = get_texture_coords(-1.11, -1.41, 2.75);
	right_eyebrow->control_points[3] = get_texture_coords(-0.95, -1.51, 2.54);
	right_eyebrow->control_points[4] = get_texture_coords(-0.32, -1.58, 2.54);
	
	//* init inner_points
	int num_points = 0;
	int i;
	for(i=1;i<scene.lugosi.n_texture_vertices;i++){
		int u_ok = FALSE;
		int v_ok = FALSE;
		int j;
		for(j=1;j<5;j++){
			if((scene.lugosi.texture_vertices[i].u <= right_eyebrow->control_points[0].u) && (scene.lugosi.texture_vertices[i].u >= right_eyebrow->control_points[j].u)){
				u_ok = TRUE;
				break;
			}
			else if((scene.lugosi.texture_vertices[i].u >= right_eyebrow->control_points[0].u) && (scene.lugosi.texture_vertices[i].u <= right_eyebrow->control_points[j].u)){
				u_ok = TRUE;
				break;
			}
		}
		if(u_ok == TRUE){
			for(j=1;j<5;j++){
				if((scene.lugosi.texture_vertices[i].v <= right_eyebrow->control_points[0].v) && (scene.lugosi.texture_vertices[i].v >= right_eyebrow->control_points[j].v)){
					v_ok = TRUE;
					break;
				}
				else if((scene.lugosi.texture_vertices[i].v >= right_eyebrow->control_points[0].v) && (scene.lugosi.texture_vertices[i].v <= right_eyebrow->control_points[j].v)){
					v_ok = TRUE;
					break;
				}
			}
			if(v_ok == TRUE){
				right_eyebrow->inner_points = (TextureVertex*)malloc((num_points + 1) * sizeof(TextureVertex));
				right_eyebrow->inner_points[num_points].u = scene.lugosi.texture_vertices[i].u;
				right_eyebrow->inner_points[num_points].v = scene.lugosi.texture_vertices[i].v;
				right_eyebrow->indexes = (int*)malloc((num_points + 1) * sizeof(int));
				right_eyebrow->indexes[num_points] = i;
				num_points += 1;
			}
		}
	}
}

TextureVertex get_texture_coords(double x, double y, double z){
	int i = find_vertex(x, y, z);
	int texture_index = find_triangle(i);
	return scene.lugosi.texture_vertices[texture_index];	
}

int find_vertex(double wanted_x, double wanted_y, double wanted_z){
	int i;
	for(i=1;i<scene.lugosi.n_vertices;i++){
		int x_tol = is_tolerated(scene.lugosi.vertices[i].x, wanted_x);
		int y_tol = is_tolerated(scene.lugosi.vertices[i].y, wanted_y);
		int z_tol = is_tolerated(scene.lugosi.vertices[i].z, wanted_z);
		if(x_tol == TRUE && y_tol == TRUE && z_tol == TRUE){
			printf("itt");
			return i + 3;
		}
	}
}

int is_tolerated(double coord, double wanted){
	if (abs(coord - wanted) < 0.1){
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

void update_mimic(char *mimic){
	switch (mimic) {
		case "cloudy":
			animate(0, -0.1);
			break;
		case "nervous":
			animate(0.1, -0.1);
			break;
		case "peeved":
			animate(0.1, 0);
			break;
		case "surprised":
			animate(0, 0.1);
			break;
		case "normal":
			animate(0, 0);
			break;
	}
}

void animate(double mouth_move, double eyebrow_move){
	int i;
	for(i=0;i<sizeof(mouth.indexes)/sizeof(int);i++){
		&(scene.lugosi.texture_vertices[mouth.indexes[i]].v) = mouth.inner_points[i].v + mouth_move;
	for(i=0;i<sizeof(left_eyebrow.indexes)/sizeof(int);i++){
		&(scene.lugosi.texture_vertices[left_eyebrow.indexes[i]].v) = mouth.inner_points[i].v + eyebrow_move;
	for(i=0;i<sizeof(right_eyebrow.indexes)/sizeof(int);i++){
		&(scene.lugosi.texture_vertices[right_eyebrow.indexes[i]].v) = mouth.inner_points[i].v + eyebrow_move;
}


			
	