#include "scene.h"
#include "load.h"
#include "model.h"
#include <GL/glut.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->lugosi), "head.obj");
    scene->texture_id = load_texture("lugosi_grafika.png"); 

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 0.2;
    scene->material.ambient.green = 0.3;
    scene->material.ambient.blue = 0.4;

    scene->material.diffuse.red = 0.6;
    scene->material.diffuse.green = 0.6;
    scene->material.diffuse.blue = 0.5;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 100.0;
}

void set_lighting()
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void update_lighting(float x)
{
	float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	
	int i;
	for(i=0;i<4;i++){
		ambient_light[i] += x;
        diffuse_light[i] += x;
		specular_light[i] += x;
	}

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
}

void set_material(const Material* material)
{
    float ambient_material_color[3];
    ambient_material_color[0] = material->ambient.red;
    ambient_material_color[1] = material->ambient.green;
    ambient_material_color[2] = material->ambient.blue;

    float diffuse_material_color[3];
    diffuse_material_color[0] = material->diffuse.red;
    diffuse_material_color[1] = material->diffuse.green;
    diffuse_material_color[2] = material->diffuse.blue;

    float specular_material_color[3];
    specular_material_color[0] = material->specular.red;
    specular_material_color[1] = material->specular.green;
    specular_material_color[2] = material->specular.blue;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
	
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glScalef(0.1, 0.1, 0.1);
	draw_model(&(scene->lugosi));
	glPopMatrix();
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void draw_model(const Model* model)
{
	draw_triangles(model);
}

void draw_triangles(const Model* model)
{
    int i, k;
    int vertex_index, texture_index, normal_index;
    float x, y, z, u, v;

    glBegin(GL_TRIANGLES);

    for (i = 0; i < model->n_triangles; ++i) {
        for (k = 0; k < 3; ++k) {

            normal_index = model->triangles[i].points[k].normal_index;
            x = model->normals[normal_index].x;
            y = model->normals[normal_index].y;
            z = model->normals[normal_index].z;
            glNormal3f(x, y, z);

			texture_index = model->triangles[i].points[k].texture_index;
            u = model->texture_vertices[texture_index].u;
            v = model->texture_vertices[texture_index].v;
            glTexCoord2f(u, 1.0 - v);

            vertex_index = model->triangles[i].points[k].vertex_index;
            x = model->vertices[vertex_index].x;
            y = model->vertices[vertex_index].y;
            z = model->vertices[vertex_index].z;
            glVertex3f(x, y, z);
        }
    }

    glEnd();
}
