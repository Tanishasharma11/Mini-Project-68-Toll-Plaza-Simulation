	#include <GL/gl.h>
	#include<stdio.h>
	#include<math.h>
	#include <GL/glut.h>
	

	char * c;
	#define PI 3.14159265358979323846
	

	GLfloat x, y, radius, twicePi; // for circle
	int triangleAmount;
	GLfloat position_s = 1.6 f; // for smoke
	GLfloat speed_s = 0.01 f;
	

	GLfloat position_r = -0.1 f; // for river
	GLfloat speed_r = 0.01 f;
	

	int cnt = 0; // for car1 update
	GLfloat position_c1 = 2.4 f; // for car 1
	GLfloat speed_c1 = 0.01 f;
	

	GLfloat position_c2 = 1.6 f; // for car 2
	GLfloat speed_c2 = 0.01 f;
	#define STOP_Y_POSITION - 0.9 f //rain
	

	int flag = 0;
	int car_stopped = 0;
	int car_stopped1 = 0;
	int rain_stopped = 0;
	GLfloat position_rain = 0.0 f; // for rain
	GLfloat speed_rain = 0.05 f;
	GLfloat position_rain2 = 2.0 f; // for rain
	GLfloat speed_rain2 = 0.05 f;
	

	void start() {
	  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (back)
	  glClearColor(0.5 f, 1.0 f, 0.0 f, 1.0 f); // Set background color to black and opaque
	

	  glBegin(GL_POLYGON);
	  glColor3ub(255, 255, 0);
	  glVertex2f(-2.0 f, 2.0 f);
	  glColor3ub(147, 112, 219);
	  glVertex2f(2.0 f, 2.0 f);
	  glColor3ub(30, 144, 255);
	  glVertex2f(2.0 f, -2.0 f);
	  glColor3ub(70, 130, 180);
	  glVertex2f(-2.0 f, -2.0 f);
	  glEnd();
	

	  glColor3ub(255, 255, 255);
	  char * c = "Highway Lens : TOLL PLAZA";
	  glRasterPos2f(-0.3, 0.7);
	  for (int i = 0; c[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
	

	  glColor3ub(0, 0, 0);
	  c = "Feature: \n-> Press 'R' = To collect tax. \n-> Press 'G' = To exempt vehicle.";
	  float x = 0.3 f;
	  glRasterPos2f(-1.5, 0.3);
	  for (int i = 0; c[i] != '\0'; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
	    if (c[i] == '\n')
	      glRasterPos2f(-1.5, x = x - 0.1);
	  }
	  glColor3ub(255, 0, 0);
	  c = "Press F to START the project";
	  glRasterPos2f(-0.3, -0.7);
	  for (int i = 0; c[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
	

	  glFlush();
	}
	

	void tree() {
	  // circle tree 1
	  glLineWidth(10.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(-1.5 f, 0.8 f);
	  glVertex2f(-1.5 f, 0.55 f);
	  glEnd();
	  x = -1.45 f;
	  y = 0.82 f;
	  radius = 0.08 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(0, 153, 51);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	  x = -1.5 f;
	  y = 0.85 f;
	  radius = 0.08 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(0, 153, 51);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	  x = -1.55 f;
	  y = 0.82 f;
	  radius = 0.08 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(0, 153, 51);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	

	  glPointSize(5.0);
	  glBegin(GL_POINTS); // fruits
	  glColor3f(1.0 f, 0.0 f, 0.0 f);
	  glVertex2f(-1.53 f, 0.85 f);
	  glVertex2f(-1.47 f, 0.8 f);
	  glEnd();
	

	  // circle tree 2
	  glLineWidth(10.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(-0.8 f, 0.8 f);
	  glVertex2f(-0.8 f, 0.57 f);
	  glEnd();
	  x = -0.85 f;
	  y = 0.82 f;
	  radius = 0.08 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(0, 153, 51);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	  x = -0.8 f;
	  y = 0.85 f;
	  radius = 0.08 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(0, 153, 51);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	  x = -0.75 f;
	  y = 0.82 f;
	  radius = 0.08 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(0, 153, 51);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	

	  // triangle tree 1
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(1.55 f, 0.65 f);
	  glVertex2f(1.55 f, 0.8 f);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glColor3ub(0, 153, 51);
	  glVertex2f(1.45 f, 0.7 f);
	  glVertex2f(1.55 f, 0.95 f);
	  glVertex2f(1.65 f, 0.7 f);
	  glEnd();
	

	  // triangle tree 2
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(-0.2 f, 0.65 f);
	  glVertex2f(-0.2 f, 0.8 f);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glColor3ub(0, 153, 51);
	  glVertex2f(-0.3 f, 0.7 f);
	  glVertex2f(-0.2 f, 0.95 f);
	  glVertex2f(-0.1 f, 0.7 f);
	  glEnd();
	

	  // triangle tree 4
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(1.75 f, 0.65 f);
	  glVertex2f(1.75 f, 0.8 f);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glColor3ub(0, 153, 51);
	  glVertex2f(1.65 f, 0.7 f);
	  glVertex2f(1.75 f, 0.95 f);
	  glVertex2f(1.85 f, 0.7 f);
	  glEnd();
	

	  // triangle tree 2
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(-0.2 f, 0.65 f);
	  glVertex2f(-0.2 f, 0.8 f);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glColor3ub(0, 153, 51);
	  glVertex2f(-0.3 f, 0.7 f);
	  glVertex2f(-0.2 f, 0.95 f);
	  glVertex2f(-0.1 f, 0.7 f);
	  glEnd();
	

	  // triangle tree 3
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(1.9 f, 0.7 f);
	  glVertex2f(1.9 f, 0.85 f);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glColor3ub(0, 153, 51);
	  glVertex2f(1.8 f, 0.75 f);
	  glVertex2f(1.9 f, 1.0 f);
	  glVertex2f(2.0 f, 0.75 f);
	  glEnd();
	}
	

	void new_trees() {
	  // triangle tree 1
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(-1.45 f, -0.9 f);
	  glVertex2f(-1.45 f, -0.75 f);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glColor3ub(0, 153, 51);
	  glVertex2f(-1.55 f, -0.8 f);
	  glVertex2f(-1.45 f, -0.55 f);
	  glVertex2f(-1.35 f, -0.8 f);
	  glEnd();
	

	  // triangle tree 2
	  glBegin(GL_LINES);
	  glColor3ub(153, 51, 51);
	  glVertex2f(-1.2 f, -0.9 f);
	  glVertex2f(-1.2 f, -0.75 f);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glColor3ub(0, 153, 51);
	  glVertex2f(-1.3 f, -0.8 f);
	  glVertex2f(-1.2 f, -0.55 f);
	  glVertex2f(-1.1 f, -0.8 f);
	  glEnd();
	

	}
	

	void update_smoke(int value) {
	  if (position_s > 2.1)
	    position_s = 1.6 f;
	

	  position_s += speed_s;
	

	  glutPostRedisplay();
	  glutTimerFunc(100, update_smoke, 0);
	}
	void update_rain(int value) {
	  // Update rain position only if rain should not stop and rain is active
	  if (!rain_stopped) {
	    // Update position of raindrops
	    if (position_rain < -0.1)
	      position_rain = 0.3 f;
	    position_rain -= speed_rain;
	    if (position_rain2 > 2.0)
	      position_rain2 = 1.8 f;
	    position_rain2 += speed_rain2;
	    glutPostRedisplay();
	    glutTimerFunc(100, update_rain, 0);
	  } else if (rain_stopped) {
	    // If rain should stop, set the flag and don't update or redisplay
	    rain_stopped = 0;
	  }
	}
	

	void drawCircle(float cx, float cy, float r, int num_segments) {
	  glBegin(GL_POLYGON);
	  for (int i = 0; i < num_segments; i++) {
	    float theta = 2.0 f * 3.1415926 f * float(i) / float(num_segments);
	    float x = r * cosf(theta);
	    float y = r * sinf(theta);
	    glVertex2f(x + cx, y + cy);
	  }
	  glEnd();
	}
	

	void shop() {
	  // right shop start
	  glBegin(GL_POLYGON); // body
	  glColor3ub(250, 20, 99);
	  glVertex2f(0.25 f, 0.5 f);
	  glVertex2f(0.25 f, 0.8 f);
	  glVertex2f(0.8 f, 0.8 f);
	  glVertex2f(0.8 f, 0.5 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // roof
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.25 f, 0.85 f);
	  glVertex2f(0.25 f, 0.8 f);
	  glVertex2f(0.8 f, 0.8 f);
	  glVertex2f(0.8 f, 0.85 f);
	  glEnd();
	  glBegin(GL_POLYGON); // roof
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.7 f, 0.85 f);
	  glVertex2f(0.65 f, 0.9 f);
	  glVertex2f(0.4 f, 0.9 f);
	  glVertex2f(0.34 f, 0.85 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // inside
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.27 f, 0.6 f);
	  glVertex2f(0.27 f, 0.75 f);
	  glVertex2f(0.78 f, 0.75 f);
	  glVertex2f(0.78 f, 0.6 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // product
	  glColor3ub(255, 0, 0);
	  glVertex2f(0.2 f, 0.6 f);
	  glVertex2f(0.2 f, 0.65 f);
	  glVertex2f(0.3 f, 0.65 f);
	  glVertex2f(0.3 f, 0.6 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // product
	  glColor3ub(0, 0, 0);
	  glVertex2f(0.5 f, 0.6 f);
	  glVertex2f(0.5 f, 0.65 f);
	  glVertex2f(0.65 f, 0.65 f);
	  glVertex2f(0.65 f, 0.6 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // table
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.27 f, 0.5 f);
	  glVertex2f(0.27 f, 0.6 f);
	  glVertex2f(0.78 f, 0.6 f);
	  glVertex2f(0.78 f, 0.5 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // shelter
	  glColor3ub(128, 128, 128);
	  glVertex2f(0.2 f, 0.7 f);
	  glVertex2f(0.85 f, 0.7 f);
	  glVertex2f(0.85 f, 0.75 f);
	  glVertex2f(0.8 f, 0.8 f);
	  glVertex2f(0.25 f, 0.8 f);
	  glVertex2f(0.2 f, 0.75 f);
	  glEnd();
	  //bottom line
	  glBegin(GL_LINES);
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.23 f, 0.5 f);
	  glVertex2f(0.83 f, 0.5 f);
	

	  glVertex2f(0.23 f, 0.504 f);
	  glVertex2f(0.83 f, 0.504 f);
	

	  glColor3ub(255, 153, 51);
	  glVertex2f(0.27 f, 0.6 f);
	  glVertex2f(0.78 f, 0.6 f);
	  glEnd();
	

	  //stick man 1
	  glBegin(GL_LINES); // Body
	  glColor3ub(0, 0, 0); // Black color
	  glVertex2f(0.5 f, 0.5 f); // Head
	  glVertex2f(0.5 f, 0.4 f); // Body
	  glEnd();
	

	  glBegin(GL_LINES); // Arms
	  glVertex2f(0.5 f, 0.45 f); // Left shoulder
	  glVertex2f(0.45 f, 0.42 f); // Left hand
	

	  glVertex2f(0.5 f, 0.45 f); // Right shoulder
	  glVertex2f(0.55 f, 0.42 f); // Right hand
	  glEnd();
	

	  glBegin(GL_LINES); // Legs
	  glVertex2f(0.5 f, 0.4 f); // Body
	  glVertex2f(0.48 f, 0.35 f); // Left leg
	

	  glVertex2f(0.5 f, 0.4 f); // Body
	  glVertex2f(0.52 f, 0.35 f); // Right leg
	

	  drawCircle(0.5 f, 0.55 f, 0.05 f, 50); // Head
	  int segments = 50;
	  int radius = 0.5;
	

	  glBegin(GL_LINE_LOOP);
	  for (int i = 0; i < segments; ++i) {
	    float theta = 2.0 f * M_PI * (float) i / (float) segments;
	    float x = radius * cosf(theta);
	    float y = radius * sinf(theta);
	    glVertex2f(x, y);
	  }
	  glEnd();
	  glColor3ub(0, 0, 0);
	  const char * c = "Toll plaza";
	  glRasterPos2f(0.4 f, 0.84 f);
	  for (int i = 0; c[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[i]);
	  // right shop end
	}
	

	void shop_d() {
	  // right shop start
	  glBegin(GL_POLYGON); // body
	  glColor3ub(250, 20, 99);
	  glVertex2f(0.25 f, -0.8 f);
	  glVertex2f(0.25 f, -0.5 f);
	  glVertex2f(0.8 f, -0.5 f);
	  glVertex2f(0.8 f, -0.8 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // roof
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.25 f, -0.45 f);
	  glVertex2f(0.25 f, -0.5 f);
	  glVertex2f(0.8 f, -0.5 f);
	  glVertex2f(0.8 f, -0.45 f);
	  glEnd();
	  glBegin(GL_POLYGON); // roof
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.7 f, -0.45 f);
	  glVertex2f(0.65 f, -0.4 f);
	  glVertex2f(0.4 f, -0.4 f);
	  glVertex2f(0.34 f, -0.45 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // inside
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.27 f, -0.7 f);
	  glVertex2f(0.27 f, -0.55 f);
	  glVertex2f(0.78 f, -0.55 f);
	  glVertex2f(0.78 f, -0.7 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // product
	  glColor3ub(255, 0, 0);
	  glVertex2f(0.2 f, -0.7 f);
	  glVertex2f(0.2 f, -0.65 f);
	  glVertex2f(0.3 f, -0.65 f);
	  glVertex2f(0.3 f, -0.7 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // product
	  glColor3ub(0, 0, 0);
	  glVertex2f(0.5 f, -0.7 f);
	  glVertex2f(0.5 f, -0.65 f);
	  glVertex2f(0.65 f, -0.65 f);
	  glVertex2f(0.65 f, -0.7 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // table
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.27 f, -0.8 f);
	  glVertex2f(0.27 f, -0.7 f);
	  glVertex2f(0.78 f, -0.7 f);
	  glVertex2f(0.78 f, -0.8 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // shelter
	  glColor3ub(128, 128, 128);
	  glVertex2f(0.2 f, -0.6 f);
	  glVertex2f(0.85 f, -0.6 f);
	  glVertex2f(0.85 f, -0.55 f);
	  glVertex2f(0.8 f, -0.5 f);
	  glVertex2f(0.25 f, -0.5 f);
	  glVertex2f(0.2 f, -0.55 f);
	  glEnd();
	  //bottom line
	  glBegin(GL_LINES);
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.23 f, -0.8 f);
	  glVertex2f(0.83 f, -0.8 f);
	  glVertex2f(0.23 f, -0.796 f);
	  glVertex2f(0.83 f, -0.796 f);
	  glColor3ub(255, 153, 51);
	  glVertex2f(0.27 f, -0.7 f);
	  glVertex2f(0.78 f, -0.7 f);
	  glEnd();
	  glColor3ub(0, 0, 0);
	  const char * c = "Toll plaza";
	  glRasterPos2f(0.4 f, -0.46 f);
	  for (int i = 0; c[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[i]);
	  // right shop end
	

	  // stick man 2
	  // Body
	  glBegin(GL_LINES);
	  glColor3ub(0, 0, 0); // Black color
	  glVertex2f(0.5 f, 0.5 f - 1.3 f); // Head
	  glVertex2f(0.5 f, 0.4 f - 1.3 f); // Body
	  glEnd();
	  // Arms
	  glBegin(GL_LINES);
	  glVertex2f(0.5 f, 0.45 f - 1.3 f); // Left shoulder
	  glVertex2f(0.45 f, 0.42 f - 1.3 f); // Left hand
	  glVertex2f(0.5 f, 0.45 f - 1.3 f); // Right shoulder
	  glVertex2f(0.55 f, 0.42 f - 1.3 f); // Right hand
	  glEnd();
	  // Legs
	  glBegin(GL_LINES);
	  glVertex2f(0.5 f, 0.4 f - 1.3 f); // Body
	  glVertex2f(0.48 f, 0.35 f - 1.3 f); // Left leg
	  glVertex2f(0.5 f, 0.4 f - 1.3 f); // Body
	  glVertex2f(0.52 f, 0.35 f - 1.3 f); // Right leg
	  glEnd();
	

	  drawCircle(0.5 f, 0.55 f - 1.3 f, 0.05 f, 50); // Head
	}
	

	void billboard() {
	
	  glBegin(GL_POLYGON);
	  glColor3ub(0, 128, 0);
	  glVertex2f(-0.35 f, -0.85 f);
	  glVertex2f(-0.35 f, -0.55 f);
	  glVertex2f(-1.0 f, -0.55 f);
	  glVertex2f(-1.0 f, -0.85 f);
	  glEnd();
	  glColor3ub(255, 255, 255);
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(-0.35 f, -0.85 f);
	  glVertex2f(-0.35 f, -0.55 f);
	  glVertex2f(-1.0 f, -0.55 f);
	  glVertex2f(-1.0 f, -0.85 f);
	  glEnd();
	  //table start
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(-0.595 f, -0.657 f);
	  glVertex2f(-0.595 f, -0.85 f);
	  glEnd();
	

	  glBegin(GL_LINE_LOOP);
	  glVertex2f(-0.755 f, -0.657 f);
	  glVertex2f(-0.755 f, -0.85 f);
	  glEnd();
	
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(-0.35 f, -0.657 f);
	  glVertex2f(-1.0 f, -0.657 f);
	  glEnd();
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(-0.35 f, -0.707 f);
	  glVertex2f(-1.0 f, -0.707 f);
	  glEnd();
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(-0.35 f, -0.757 f);
	  glVertex2f(-1.0 f, -0.757 f);
	  glEnd();
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(-0.35 f, -0.807 f);
	  glVertex2f(-1.0 f, -0.807 f);
	  glEnd();
	  //table end
	

	  glLineWidth(9.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(0, 0, 0);
	  glVertex2f(-0.67 f, -0.85 f);
	  glVertex2f(-0.67 f, -1.0 f);
	  glEnd();
	

	  const char * a = "NHAI (WEST BENGAL)";
	  glColor3ub(255, 255, 255);
	

	  glRasterPos2f(-0.9525 f, -0.65 f);
	  for (int i = 0; a[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, a[i]);
	

	  const char * c = "1    car       50";
	  glColor3ub(255, 255, 255);
	

	  glRasterPos2f(-0.8325 f, -0.70 f);
	  for (int i = 0; c[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
	

	  glRasterPos2f(-0.8325 f, -0.75 f);
	  const char * d = "2    bus     180";
	  for (int i = 0; d[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, d[i]);
	

	  glRasterPos2f(-0.8325 f, -0.80 f);
	  const char * f = "3    truck   200";
	  for (int i = 0; f[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, f[i]);
	

	  glRasterPos2f(-0.8325 f, -0.843 f);
	  const char * g = "4    auto    20";
	  for (int i = 0; g[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, g[i]);
	

	}
	

	void infoboard() {
	
	  glBegin(GL_POLYGON); // table
	  glColor3ub(100, 100, 240);
	  glVertex2f(0.9 f, 0.8 f);
	  glVertex2f(0.9 f, 0.65 f);
	  glVertex2f(1.4 f, 0.65 f);
	  glVertex2f(1.4 f, 0.8 f);
	  glEnd();
	

	  glLineWidth(9.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(0, 0, 0);
	  glVertex2f(1.10 f, 0.65 f);
	  glVertex2f(1.10 f, 0.5 f);
	  glEnd();
	

	  glColor3ub(255, 174, 66);
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(0.9 f, 0.8 f);
	  glVertex2f(0.9 f, 0.65 f);
	  glVertex2f(1.4 f, 0.65 f);
	  glVertex2f(1.4 f, 0.8 f);
	  glEnd();
	

	}
	void infoboard1() {
	  glBegin(GL_POLYGON); // table
	  glColor3ub(100, 100, 240);
	  glVertex2f(-0.25 f, -0.8 f); // Moved left and down
	  glVertex2f(-0.25 f, -0.65 f); // Moved left and down
	  glVertex2f(0.18 f, -0.65 f); // Moved left
	  glVertex2f(0.18 f, -0.8 f); // Moved left
	  glEnd();
	

	  glLineWidth(9.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(0, 0, 0);
	  glVertex2f(0.0 f, -0.8 f); // Moved left and down
	  glVertex2f(0.0 f, -1.0 f); // Moved left and down
	  glEnd();
	

	  glColor3ub(255, 174, 66);
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(-0.25 f, -0.8 f); // Moved left and down
	  glVertex2f(-0.25 f, -0.65 f); // Moved left and down
	  glVertex2f(0.18 f, -0.65 f); // Moved left
	  glVertex2f(0.18 f, -0.8 f); // Moved left
	  glEnd();
	}
	

	void billboard2() {
	

	  glBegin(GL_POLYGON); // table
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.90 f, -0.85 f);
	  glVertex2f(0.90 f, -0.75 f);
	  glVertex2f(1.345 f, -0.75 f);
	  glVertex2f(1.345 f, -0.85 f);
	  glEnd();
	

	  glLineWidth(9.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(0, 0, 0);
	  glVertex2f(1.15 f, -0.85 f);
	  glVertex2f(1.15 f, -1.0 f);
	  glEnd();
	

	  glColor3ub(100, 100, 100);
	  glBegin(GL_LINE_LOOP);
	  glVertex2f(0.90 f, -0.85 f);
	  glVertex2f(0.90 f, -0.75 f);
	  glVertex2f(1.345 f, -0.75 f);
	  glVertex2f(1.345 f, -0.85 f);
	  glEnd();
	

	  glColor3ub(0, 0, 0);
	  const char * c = "Kali Mata Mandir";
	  glRasterPos2f(0.9425 f, -0.82 f);
	  for (int i = 0; c[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
	

	}
	

	void update_car1(int value) {
	  if (cnt == 0) {
	    speed_c1 = 0.01 f;
	    if (position_c1 > 2.7)
	      position_c1 = -2.7 f;
	

	    position_c1 += speed_c1;
	

	  } else {
	

	    if (position_c1 > 0.0) {
	      speed_c1 = 0.0 f;
	      position_c1 = 0.0;
	    }
	    position_c1 += speed_c1;
	

	  }
	  if (speed_c1 == 0.0 f) {
	    car_stopped = 1;
	

	  } else {
	    car_stopped = 0;
	  }
	  glutPostRedisplay();
	  glutTimerFunc(10, update_car1, 0);
	}
	

	void update_car2(int value) {
	  if (cnt == 0) {
	    speed_c2 = 0.01 f;
	    if (position_c2 < -2.7)
	      position_c2 = 2.7 f;
	

	    position_c2 -= speed_c2;
	  } else {
	    if (position_c2 < 0.0) {
	      speed_c2 = 0.0 f;
	      position_c2 = 0.4 f; // Adjusted to stop at the same position as car1
	    }
	    position_c2 -= speed_c2;
	  }
	  if (speed_c2 == 0.0 f) {
	    car_stopped1 = 1;
	

	  } else {
	    car_stopped1 = 0;
	  }
	  glutPostRedisplay();
	  glutTimerFunc(10, update_car2, 0);
	}
	

	void fence() {
	  glBegin(GL_LINES);
	  glColor3ub(0, 0, 0);
	  glVertex2f(-2.0 f, 0.6 f); // left
	  glVertex2f(1.42 f, 0.6 f);
	

	  glVertex2f(-2.0 f, 0.53 f);
	  glVertex2f(1.42 f, 0.53 f);
	

	  glVertex2f(-1.98 f, 0.5 f);
	  glVertex2f(-1.98 f, 0.63 f);
	

	  glVertex2f(-1.5 f, 0.5 f);
	  glVertex2f(-1.5 f, 0.63 f);
	

	  glVertex2f(-1.45 f, 0.5 f);
	  glVertex2f(-1.45 f, 0.63 f);
	

	  glVertex2f(-0.4 f, 0.5 f);
	  glVertex2f(-0.4 f, 0.63 f);
	

	  glVertex2f(-0.85 f, 0.5 f);
	  glVertex2f(-0.85 f, 0.63 f);
	

	  glVertex2f(-0.8 f, 0.5 f);
	  glVertex2f(-0.8 f, 0.63 f);
	

	  glVertex2f(-0.17 f, 0.5 f);
	  glVertex2f(-0.17 f, 0.63 f);
	

	  glVertex2f(0.37 f, 0.5 f);
	  glVertex2f(0.37 f, 0.63 f);
	

	  glVertex2f(2.0 f, 0.6 f); // right
	  glVertex2f(1.42 f, 0.6 f);
	

	  glVertex2f(2.0 f, 0.53 f);
	  glVertex2f(1.42 f, 0.53 f);
	

	  glVertex2f(1.95 f, 0.5 f);
	  glVertex2f(1.95 f, 0.63 f);
	

	  glVertex2f(1.9 f, 0.5 f);
	  glVertex2f(1.9 f, 0.63 f);
	

	  glVertex2f(1.85 f, 0.5 f);
	  glVertex2f(1.85 f, 0.63 f);
	

	  glVertex2f(1.8 f, 0.5 f);
	  glVertex2f(1.8 f, 0.63 f);
	

	  glVertex2f(1.75 f, 0.5 f);
	  glVertex2f(1.75 f, 0.63 f);
	

	  glVertex2f(1.7 f, 0.5 f);
	  glVertex2f(1.7 f, 0.63 f);
	

	  glVertex2f(1.65 f, 0.5 f);
	  glVertex2f(1.65 f, 0.63 f);
	

	  glVertex2f(1.6 f, 0.5 f);
	  glVertex2f(1.6 f, 0.63 f);
	

	  glVertex2f(1.55 f, 0.5 f);
	  glVertex2f(1.55 f, 0.63 f);
	

	  glVertex2f(1.5 f, 0.5 f);
	  glVertex2f(1.5 f, 0.63 f);
	

	  glVertex2f(1.45 f, 0.5 f);
	  glVertex2f(1.45 f, 0.63 f);
	  glEnd();
	}
	

	void rain() {
	  glPushMatrix();
	  glTranslatef(position_rain2, position_rain, 0.0 f);
	  glLineWidth(2.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.0 f, 0.9 f);
	  glVertex2f(0.05 f, 0.85 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.0 f, 0.7 f);
	  glVertex2f(0.05 f, 0.65 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.0 f, 0.5 f);
	  glVertex2f(0.05 f, 0.45 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.0 f, 0.3 f);
	  glVertex2f(0.05 f, 0.25 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.0 f, 0.1 f);
	  glVertex2f(0.05 f, 0.05 f);
	  glEnd();
	

	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.05 f, -0.9 f);
	  glVertex2f(0.0 f, -0.85 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.05 f, -0.7 f);
	  glVertex2f(0.0 f, -0.65 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.05 f, -0.5 f);
	  glVertex2f(0.0 f, -0.45 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.05 f, -0.3 f);
	  glVertex2f(0.0 f, -0.25 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.05 f, -0.1 f);
	  glVertex2f(0.0 f, -0.05 f);
	  glEnd();
	

	  for (int i = 0; i < 100; i++) {
	    glTranslatef(-0.2, 0.0, 0.0 f);
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.9 f);
	    glVertex2f(0.05 f, 0.85 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.7 f);
	    glVertex2f(0.05 f, 0.65 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.5 f);
	    glVertex2f(0.05 f, 0.45 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.3 f);
	    glVertex2f(0.05 f, 0.25 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.1 f);
	    glVertex2f(0.05 f, 0.05 f);
	    glEnd();
	

	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.9 f);
	    glVertex2f(0.0 f, -0.85 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.7 f);
	    glVertex2f(0.0 f, -0.65 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.5 f);
	    glVertex2f(0.0 f, -0.45 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.3 f);
	    glVertex2f(0.0 f, -0.25 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.1 f);
	    glVertex2f(0.0 f, -0.05 f);
	    glEnd();
	  }
	

	  for (int i = 0; i < 100; i++) {
	    glTranslatef(0.2, 0.0, 0.0 f);
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.9 f);
	    glVertex2f(0.05 f, 0.85 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.7 f);
	    glVertex2f(0.05 f, 0.65 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.5 f);
	    glVertex2f(0.05 f, 0.45 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.3 f);
	    glVertex2f(0.05 f, 0.25 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.0 f, 0.1 f);
	    glVertex2f(0.05 f, 0.05 f);
	    glEnd();
	

	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.9 f);
	    glVertex2f(0.0 f, -0.85 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.7 f);
	    glVertex2f(0.0 f, -0.65 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.5 f);
	    glVertex2f(0.0 f, -0.45 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.3 f);
	    glVertex2f(0.0 f, -0.25 f);
	    glEnd();
	    glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(0.05 f, -0.1 f);
	    glVertex2f(0.0 f, -0.05 f);
	    glEnd();
	  }
	  glPopMatrix();
	}
	

	void road_light() {
	  glLineWidth(3.0 f);
	  // left-up
	  glBegin(GL_LINES);
	  glColor3ub(128, 128, 128);
	  glVertex2f(-1.9 f, 0.4 f);
	  glVertex2f(-1.8 f, 0.4 f);
	

	  glVertex2f(-1.8 f, 0.4 f);
	  glVertex2f(-1.8 f, 0.1 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(191, 191, 191);
	  glVertex2f(-1.85 f, 0.25 f);
	  glVertex2f(-1.8 f, 0.25 f);
	  glVertex2f(-1.8 f, 0.1 f);
	  glVertex2f(-1.85 f, 0.1 f);
	  glEnd();
	  glPointSize(10.0); //
	  glBegin(GL_POINTS);
	  glColor3ub(89, 89, 89);
	  glVertex2f(-1.9 f, 0.4 f);
	  glEnd();
	

	  for (int i = 0; i < 3; i++) {
	    glTranslated(0.6, 0.0, 0.0);
	    glBegin(GL_LINES);
	    glColor3ub(128, 128, 128);
	    glVertex2f(-1.9 f, 0.4 f);
	    glVertex2f(-1.8 f, 0.4 f);
	

	    glVertex2f(-1.8 f, 0.4 f);
	    glVertex2f(-1.8 f, 0.1 f);
	    glEnd();
	    glBegin(GL_POLYGON);
	    glColor3ub(191, 191, 191);
	    glVertex2f(-1.85 f, 0.25 f);
	    glVertex2f(-1.8 f, 0.25 f);
	    glVertex2f(-1.8 f, 0.1 f);
	    glVertex2f(-1.85 f, 0.1 f);
	    glEnd();
	    glBegin(GL_POINTS);
	    glColor3ub(89, 89, 89);
	    glVertex2f(-1.9 f, 0.4 f);
	    glEnd();
	  }
	

	  // left-down
	  glBegin(GL_LINES);
	  glColor3ub(128, 128, 128);
	  glVertex2f(-1.6 f, -0.4 f);
	  glVertex2f(-1.5 f, -0.4 f);
	

	  glVertex2f(-1.5 f, -0.4 f);
	  glVertex2f(-1.5 f, -0.1 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(191, 191, 191);
	  glVertex2f(-1.5 f, -0.1 f);
	  glVertex2f(-1.55 f, -0.1 f);
	  glVertex2f(-1.55 f, -0.25 f);
	  glVertex2f(-1.5 f, -0.25 f);
	  glEnd();
	  glBegin(GL_POINTS);
	  glColor3ub(89, 89, 89);
	  glVertex2f(-1.6 f, -0.4 f);
	  glEnd();
	

	  for (int i = 0; i < 3; i++) {
	    glTranslated(-0.6, 0.0, 0.0);
	    glBegin(GL_LINES);
	    glColor3ub(128, 128, 128);
	    glVertex2f(-1.6 f, -0.4 f);
	    glVertex2f(-1.5 f, -0.4 f);
	

	    glVertex2f(-1.5 f, -0.4 f);
	    glVertex2f(-1.5 f, -0.1 f);
	    glEnd();
	    glBegin(GL_POLYGON);
	    glColor3ub(191, 191, 191);
	    glVertex2f(-1.5 f, -0.1 f);
	    glVertex2f(-1.55 f, -0.1 f);
	    glVertex2f(-1.55 f, -0.25 f);
	    glVertex2f(-1.5 f, -0.25 f);
	    glEnd();
	    glBegin(GL_POINTS);
	    glColor3ub(89, 89, 89);
	    glVertex2f(-1.6 f, -0.4 f);
	    glEnd();
	  }
	

	  // right-up
	  glBegin(GL_LINES);
	  glColor3ub(128, 128, 128);
	  glVertex2f(1.4 f, 0.4 f);
	  glVertex2f(1.5 f, 0.4 f);
	

	  glVertex2f(1.5 f, 0.4 f);
	  glVertex2f(1.5 f, 0.1 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(191, 191, 191);
	  glVertex2f(1.5 f, 0.1 f);
	  glVertex2f(1.45 f, 0.1 f);
	  glVertex2f(1.45 f, 0.25 f);
	  glVertex2f(1.5 f, 0.25 f);
	  glEnd();
	  glBegin(GL_POINTS);
	  glColor3ub(89, 89, 89);
	  glVertex2f(1.4 f, 0.4 f);
	  glEnd();
	

	  // right-down
	  glBegin(GL_LINES);
	  glColor3ub(128, 128, 128);
	  glVertex2f(1.7 f, -0.4 f);
	  glVertex2f(1.8 f, -0.4 f);
	

	  glVertex2f(1.8 f, -0.4 f);
	  glVertex2f(1.8 f, -0.1 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(191, 191, 191);
	  glVertex2f(1.8 f, -0.1 f);
	  glVertex2f(1.75 f, -0.1 f);
	  glVertex2f(1.75 f, -0.25 f);
	  glVertex2f(1.8 f, -0.25 f);
	  glEnd();
	  glBegin(GL_POINTS);
	  glColor3ub(89, 89, 89);
	  glVertex2f(1.7 f, -0.4 f);
	  glEnd();
	

	}
	

	void car1() {
	  glPushMatrix();
	  glTranslatef(position_c1, 0.0 f, 0.0 f);
	  glBegin(GL_POLYGON); // body
	  glColor3ub(230, 0, 0);
	  glVertex2f(-0.2 f, 0.25 f);
	  glVertex2f(0.07 f, 0.25 f);
	  glVertex2f(0.15 f, 0.23 f);
	  glVertex2f(0.17 f, 0.2 f);
	  glVertex2f(0.17 f, 0.1 f);
	  glVertex2f(0.15 f, 0.07 f);
	  glVertex2f(0.07 f, 0.05 f);
	  glVertex2f(-0.2 f, 0.05 f);
	  glVertex2f(-0.22 f, 0.07 f);
	  glVertex2f(-0.22 f, 0.23 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // window
	  glColor3ub(0, 0, 0);
	  glVertex2f(0.07 f, 0.24 f);
	  glVertex2f(0.07 f, 0.06 f);
	  glVertex2f(-0.18 f, 0.06 f);
	  glVertex2f(-0.18 f, 0.24 f);
	  glEnd();
	  glBegin(GL_POLYGON); // roof
	  glColor3ub(230, 0, 0);
	  glVertex2f(0.03 f, 0.09 f);
	  glVertex2f(0.03 f, 0.21 f);
	  glVertex2f(-0.15 f, 0.21 f);
	  glVertex2f(-0.15 f, 0.09 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // light
	  glColor3ub(242, 242, 242);
	  glVertex2f(0.15 f, 0.23 f);
	  glVertex2f(0.17 f, 0.2 f);
	  glVertex2f(0.14 f, 0.2 f);
	  glVertex2f(0.14 f, 0.23 f);
	  glEnd();
	  glBegin(GL_POLYGON); // light
	  glColor3ub(242, 242, 242);
	  glVertex2f(0.15 f, 0.07 f);
	  glVertex2f(0.17 f, 0.1 f);
	  glVertex2f(0.14 f, 0.1 f);
	  glVertex2f(0.14 f, 0.07 f);
	  glEnd();
	

	  if (flag != 0) {
	    glBegin(GL_POLYGON); // head-light
	    glColor3ub(255, 255, 204);
	    glVertex2f(0.17 f, 0.2 f);
	    glVertex2f(0.14 f, 0.23 f);
	    glVertex2f(0.45 f, 0.3 f);
	    glVertex2f(0.45 f, 0.1 f);
	    glEnd();
	    glBegin(GL_POLYGON); // head-light
	    glColor3ub(255, 255, 204);
	    glVertex2f(0.17 f, 0.1 f);
	    glVertex2f(0.14 f, 0.07 f);
	    glVertex2f(0.45 f, 0.0 f);
	    glVertex2f(0.45 f, 0.2 f);
	    glEnd();
	  }
	

	  glBegin(GL_LINES);
	  glColor3ub(230, 0, 0);
	  glVertex2f(0.07 f, 0.24 f);
	  glVertex2f(0.03 f, 0.21 f);
	

	  glVertex2f(0.03 f, 0.09 f);
	  glVertex2f(0.07 f, 0.06 f);
	

	  glVertex2f(-0.18 f, 0.06 f);
	  glVertex2f(-0.15 f, 0.09 f);
	

	  glVertex2f(-0.15 f, 0.21 f);
	  glVertex2f(-0.18 f, 0.24 f);
	

	  glVertex2f(-0.06 f, 0.24 f);
	  glVertex2f(-0.06 f, 0.21 f);
	

	  glVertex2f(-0.06 f, 0.09 f);
	  glVertex2f(-0.06 f, 0.06 f);
	  glEnd();
	

	  glPopMatrix();
	}
	

	void car2() {
	  glPushMatrix();
	  glTranslatef(position_c2, 0.0 f, 0.0 f);
	  //glRotatef(180, 0.0f, 0.0f, 0.0f);
	  glBegin(GL_POLYGON); // body
	  glColor3ub(255, 204, 0);
	  glVertex2f(0.04 f, -0.25 f);
	  glVertex2f(-0.07 f, -0.25 f);
	  glVertex2f(-0.15 f, -0.23 f);
	  glVertex2f(-0.17 f, -0.2 f);
	  glVertex2f(-0.17 f, -0.1 f);
	  glVertex2f(-0.15 f, -0.07 f);
	  glVertex2f(-0.07 f, -0.05 f);
	  glVertex2f(0.04 f, -0.05 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // window
	  glColor3ub(0, 0, 0);
	  glVertex2f(-0.07 f, -0.24 f);
	  glVertex2f(-0.07 f, -0.06 f);
	  glVertex2f(0.03 f, -0.06 f);
	  glVertex2f(0.03 f, -0.24 f);
	  glEnd();
	  glBegin(GL_POLYGON); // roof
	  glColor3ub(255, 204, 0);
	  glVertex2f(-0.03 f, -0.09 f);
	  glVertex2f(-0.03 f, -0.21 f);
	  glVertex2f(0.07 f, -0.21 f);
	  glVertex2f(0.07 f, -0.09 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // light
	  glColor3ub(242, 242, 242);
	  glVertex2f(-0.15 f, -0.23 f);
	  glVertex2f(-0.17 f, -0.2 f);
	  glVertex2f(-0.14 f, -0.2 f);
	  glVertex2f(-0.14 f, -0.23 f);
	  glEnd();
	  glBegin(GL_POLYGON); // light
	  glColor3ub(242, 242, 242);
	  glVertex2f(-0.15 f, -0.07 f);
	  glVertex2f(-0.17 f, -0.1 f);
	  glVertex2f(-0.14 f, -0.1 f);
	  glVertex2f(-0.14 f, -0.07 f);
	  glEnd();
	

	  if (flag != 0) {
	    glBegin(GL_POLYGON); // head-light
	    glColor3ub(255, 255, 204);
	    glVertex2f(-0.17 f, -0.2 f);
	    glVertex2f(-0.14 f, -0.23 f);
	    glVertex2f(-0.45 f, -0.3 f);
	    glVertex2f(-0.45 f, -0.1 f);
	    glEnd();
	    glBegin(GL_POLYGON); // head-light
	    glColor3ub(255, 255, 204);
	    glVertex2f(-0.17 f, -0.1 f);
	    glVertex2f(-0.14 f, -0.07 f);
	    glVertex2f(-0.45 f, -0.0 f);
	    glVertex2f(-0.45 f, -0.2 f);
	    glEnd();
	  }
	

	  glBegin(GL_POLYGON); // lorry
	  glColor3ub(242, 242, 242);
	  glVertex2f(0.06 f, -0.25 f);
	  glVertex2f(0.06 f, -0.05 f);
	  glVertex2f(0.5 f, -0.05 f);
	  glVertex2f(0.5 f, -0.25 f);
	  glEnd();
	

	  glBegin(GL_LINES);
	  glColor3ub(255, 204, 0);
	  glVertex2f(-0.07 f, -0.24 f);
	  glVertex2f(-0.03 f, -0.21 f);
	

	  glVertex2f(-0.03 f, -0.09 f);
	  glVertex2f(-0.07 f, -0.06 f);
	

	  glVertex2f(0.03 f, -0.24 f);
	  glVertex2f(0.03 f, -0.21 f);
	

	  glVertex2f(0.03 f, -0.09 f);
	  glVertex2f(0.03 f, -0.06 f);
	

	  glColor3ub(217, 217, 217);
	  glVertex2f(0.06 f, -0.25 f);
	  glVertex2f(0.06 f, -0.05 f);
	

	  glVertex2f(0.06 f, -0.05 f);
	  glVertex2f(0.5 f, -0.05 f);
	

	  glVertex2f(0.5 f, -0.05 f);
	  glVertex2f(0.5 f, -0.25 f);
	

	  glVertex2f(0.5 f, -0.25 f);
	  glVertex2f(0.06 f, -0.25 f);
	  glEnd();
	

	  glPopMatrix();
	}
	

	void house1() {
	  // left shop start
	  glBegin(GL_POLYGON); // body
	  glColor3ub(255, 255, 255);
	  glVertex2f(-1.95 f, -1.0 f);
	  glVertex2f(-1.95 f, -0.75 f);
	  glVertex2f(-1.55 f, -0.75 f);
	  glVertex2f(-1.55 f, -1.0 f);
	  glEnd();
	  glBegin(GL_POLYGON); // roof
	  glColor3ub(128, 0, 0);
	  glVertex2f(-1.95 f, -0.75 f);
	  glVertex2f(-1.95 f, -0.65 f);
	  glVertex2f(-1.55 f, -0.65 f);
	  glVertex2f(-1.55 f, -0.75 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // shelter
	  glColor3ub(255, 0, 0);
	  glVertex2f(-2.0 f, -0.85 f);
	  glVertex2f(-1.5 f, -0.85 f);
	  glVertex2f(-1.5 f, -0.8 f);
	  glVertex2f(-1.55 f, -0.75 f);
	  glVertex2f(-1.95 f, -0.75 f);
	  glVertex2f(-2.0 f, -0.8 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // door
	  glColor3ub(0, 230, 230);
	  glVertex2f(-1.9 f, -1.0 f);
	  glVertex2f(-1.9 f, -0.88 f);
	  glColor3ub(0, 153, 153);
	  glVertex2f(-1.82 f, -0.88 f);
	  glVertex2f(-1.82 f, -1.0 f);
	  glEnd();
	

	  glBegin(GL_LINES);
	  glColor3ub(128, 0, 0);
	  glVertex2f(-1.52 f, -1.0 f);
	  glVertex2f(-1.98 f, -1.0 f);
	

	  glVertex2f(-1.524 f, -0.996 f);
	  glVertex2f(-1.98 f, -0.996 f);
	

	  glColor3ub(255, 153, 51);
	  glVertex2f(-1.9 f, -1.0 f); // door
	  glVertex2f(-1.9 f, -0.88 f);
	

	  glVertex2f(-1.9 f, -0.88 f);
	  glVertex2f(-1.82 f, -0.88 f);
	

	  glVertex2f(-1.82 f, -0.88 f);
	  glVertex2f(-1.82 f, -1.0 f);
	

	  glVertex2f(-1.82 f, -1.0 f);
	  glVertex2f(-1.9 f, -1.0 f);
	

	  glVertex2f(-1.82 f, -0.95 f);
	  glVertex2f(-1.9 f, -0.95 f);
	

	  glEnd();
	

	  glColor3f(1.0, 1.0, 1.0);
	  c = "Toilet";
	  glRasterPos2f(-1.8, -0.72);
	  for (int i = 0; c[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
	  // left shop end
	

	}
	

	void factory() {
	  // funnel
	  glBegin(GL_POLYGON);
	  glColor3ub(163, 136, 151);
	  glVertex2f(1.5 f, -0.8 f);
	  glVertex2f(1.55 f, -0.4 f);
	  glVertex2f(1.65 f, -0.4 f);
	  glVertex2f(1.7 f, -0.8 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(231, 222, 225);
	  glVertex2f(1.54 f, -0.5 f);
	  glVertex2f(1.55 f, -0.45 f);
	  glVertex2f(1.65 f, -0.45 f);
	  glVertex2f(1.66 f, -0.5 f);
	  glEnd();
	  glBegin(GL_LINES);
	  glColor3ub(128, 0, 0);
	  glVertex2f(1.5 f, -0.8 f);
	  glVertex2f(1.55 f, -0.4 f);
	

	  glVertex2f(1.55 f, -0.4 f);
	  glVertex2f(1.65 f, -0.4 f);
	

	  glVertex2f(1.65 f, -0.4 f);
	  glVertex2f(1.7 f, -0.8 f);
	

	  glVertex2f(1.7 f, -0.8 f);
	  glVertex2f(1.5 f, -0.8 f);
	  glEnd();
	

	  // smoke
	  glPushMatrix();
	  glTranslatef(position_s, -0.05 f, 0.0 f);
	

	  x = 0.0 f;
	  y = -0.21 f;
	  radius = .05 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(217, 217, 217);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	  x = 0.07 f;
	  y = -0.25 f;
	  radius = .05 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(217, 217, 217);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	  x = 0.0 f;
	  y = -0.28 f;
	  radius = .05 f;
	  triangleAmount = 50;
	  twicePi = 2.0 f * PI;
	  glColor3ub(217, 217, 217);
	  glBegin(GL_TRIANGLE_FAN);
	  glVertex2f(x, y);
	  for (int i = 0; i <= triangleAmount; i++) {
	    glVertex2f(
	      x + (radius * cos(i * twicePi / triangleAmount)),
	      y + (radius * sin(i * twicePi / triangleAmount))
	    );
	  }
	  glEnd();
	

	  glPopMatrix();
	

	  // body start
	  glBegin(GL_POLYGON);
	  glColor3ub(220, 170, 159);
	  glVertex2f(1.45 f, -2.0 f);
	  glVertex2f(1.45 f, -0.7 f);
	  glVertex2f(1.65 f, -0.55 f);
	  glVertex2f(1.65 f, -2.0 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(220, 170, 159);
	  glVertex2f(1.65 f, -2.0 f);
	  glVertex2f(1.65 f, -0.7 f);
	  glVertex2f(1.85 f, -0.55 f);
	  glVertex2f(1.85 f, -2.0 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(220, 170, 159);
	  glVertex2f(1.85 f, -2.0 f);
	  glVertex2f(1.85 f, -0.7 f);
	  glVertex2f(2.05 f, -0.55 f);
	  glVertex2f(2.05 f, -2.0 f);
	  glEnd();
	  // body end
	

	  // roof
	  glBegin(GL_POLYGON);
	  glColor3ub(192, 117, 124);
	  glVertex2f(1.45 f, -0.7 f);
	  glVertex2f(1.45 f, -0.66 f);
	  glVertex2f(1.6 f, -0.55 f);
	  glVertex2f(1.65 f, -0.55 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(192, 117, 124);
	  glVertex2f(1.65 f, -0.7 f);
	  glVertex2f(1.65 f, -0.66 f);
	  glVertex2f(1.8 f, -0.55 f);
	  glVertex2f(1.85 f, -0.55 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(192, 117, 124);
	  glVertex2f(1.85 f, -0.7 f);
	  glVertex2f(1.85 f, -0.66 f);
	  glVertex2f(2.0 f, -0.55 f);
	  glVertex2f(2.05 f, -0.55 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // window 1
	  glColor3ub(96, 82, 118);
	  glVertex2f(1.5 f, -0.78 f);
	  glVertex2f(1.5 f, -0.7 f);
	  glVertex2f(1.6 f, -0.7 f);
	  glVertex2f(1.6 f, -0.78 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // window 2
	  glColor3ub(96, 82, 118);
	  glVertex2f(1.7 f, -0.78 f);
	  glVertex2f(1.7 f, -0.7 f);
	  glVertex2f(1.8 f, -0.7 f);
	  glVertex2f(1.8 f, -0.78 f);
	  glEnd();
	

	  glBegin(GL_POLYGON); // window 3
	  glColor3ub(96, 82, 118);
	  glVertex2f(1.9 f, -0.78 f);
	  glVertex2f(1.9 f, -0.7 f);
	  glVertex2f(1.99 f, -0.7 f);
	  glVertex2f(1.99 f, -0.78 f);
	  glEnd();
	

	  glBegin(GL_LINES);
	  glColor3ub(128, 0, 0);
	  glVertex2f(1.45 f, -2.0 f); // body
	  glVertex2f(1.45 f, -0.7 f);
	

	  glVertex2f(1.45 f, -0.7 f);
	  glVertex2f(1.65 f, -0.55 f);
	

	  glVertex2f(1.65 f, -0.55 f);
	  glVertex2f(1.65 f, -0.7 f);
	

	  glVertex2f(1.65 f, -0.7 f);
	  glVertex2f(1.85 f, -0.55 f);
	

	  glVertex2f(1.85 f, -0.55 f);
	  glVertex2f(1.85 f, -0.7 f);
	

	  glVertex2f(1.85 f, -0.7 f);
	  glVertex2f(2.05 f, -0.55 f);
	

	  glVertex2f(2.05 f, -0.55 f);
	  glVertex2f(2.05 f, -0.7 f);
	

	  glVertex2f(1.45 f, -0.7 f); // roof
	  glVertex2f(1.45 f, -0.66 f);
	

	  glVertex2f(1.45 f, -0.66 f);
	  glVertex2f(1.6 f, -0.55 f);
	

	  glVertex2f(1.6 f, -0.55 f);
	  glVertex2f(1.65 f, -0.55 f);
	

	  glVertex2f(1.65 f, -0.55 f);
	  glVertex2f(1.45 f, -0.7 f);
	

	  glVertex2f(1.65 f, -0.7 f);
	  glVertex2f(1.65 f, -0.66 f);
	

	  glVertex2f(1.65 f, -0.66 f);
	  glVertex2f(1.8 f, -0.55 f);
	

	  glVertex2f(1.8 f, -0.55 f);
	  glVertex2f(1.85 f, -0.55 f);
	

	  glVertex2f(1.85 f, -0.55 f);
	  glVertex2f(1.65 f, -0.7 f);
	

	  glVertex2f(1.85 f, -0.7 f);
	  glVertex2f(1.85 f, -0.66 f);
	

	  glVertex2f(1.85 f, -0.66 f);
	  glVertex2f(2.0 f, -0.55 f);
	

	  glVertex2f(2.0 f, -0.55 f);
	  glVertex2f(2.05 f, -0.55 f);
	

	  glVertex2f(2.05 f, -0.55 f);
	  glVertex2f(1.85 f, -0.7 f);
	

	  glColor3ub(217, 217, 217);
	  glVertex2f(1.5 f, -0.78 f); // window 1
	  glVertex2f(1.5 f, -0.7 f);
	

	  glVertex2f(1.5 f, -0.7 f);
	  glVertex2f(1.6 f, -0.7 f);
	

	  glVertex2f(1.6 f, -0.7 f);
	  glVertex2f(1.6 f, -0.78 f);
	

	  glVertex2f(1.6 f, -0.78 f);
	  glVertex2f(1.5 f, -0.78 f);
	

	  glVertex2f(1.6 f, -0.74 f);
	  glVertex2f(1.5 f, -0.74 f);
	

	  glVertex2f(1.55 f, -0.7 f);
	  glVertex2f(1.55 f, -0.78 f);
	

	  glVertex2f(1.7 f, -0.78 f); // window 2
	  glVertex2f(1.7 f, -0.7 f);
	

	  glVertex2f(1.7 f, -0.7 f);
	  glVertex2f(1.8 f, -0.7 f);
	

	  glVertex2f(1.8 f, -0.7 f);
	  glVertex2f(1.8 f, -0.78 f);
	

	  glVertex2f(1.8 f, -0.78 f);
	  glVertex2f(1.7 f, -0.78 f);
	

	  glVertex2f(1.8 f, -0.74 f);
	  glVertex2f(1.7 f, -0.74 f);
	

	  glVertex2f(1.75 f, -0.7 f);
	  glVertex2f(1.75 f, -0.78 f);
	

	  glVertex2f(1.9 f, -0.78 f); // window 3
	  glVertex2f(1.9 f, -0.7 f);
	

	  glVertex2f(1.9 f, -0.7 f);
	  glVertex2f(1.99 f, -0.7 f);
	

	  glVertex2f(1.99 f, -0.7 f);
	  glVertex2f(1.99 f, -0.78 f);
	

	  glVertex2f(1.99 f, -0.78 f);
	  glVertex2f(1.9 f, -0.78 f);
	

	  glVertex2f(1.99 f, -0.74 f);
	  glVertex2f(1.9 f, -0.74 f);
	

	  glVertex2f(1.95 f, -0.7 f);
	  glVertex2f(1.95 f, -0.78 f);
	  glEnd();
	

	  glColor3ub(255, 217, 179);
	  char * P = "M e t a l  w o r k s";
	  glRasterPos2f(1.55 f, -0.9);
	  for (int i = 0; P[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, P[i]);
	}
	

	void display(void) {
	  glClear(GL_COLOR_BUFFER_BIT);
	  tree();
	  // road
	  glBegin(GL_POLYGON);
	  glColor3ub(95, 96, 91);
	  glVertex2f(-2.0 f, 0.5 f);
	  glVertex2f(2.0 f, 0.5 f);
	  glVertex2f(2.0 f, -0.5 f);
	  glVertex2f(-2.0 f, -0.5 f);
	  glEnd();
	

	  // footpath
	  glBegin(GL_POLYGON);
	  glColor3ub(176, 191, 189);
	  glVertex2f(-2.0 f, 0.5 f);
	  glVertex2f(-2.0 f, 0.3 f);
	  glVertex2f(2.0 f, 0.3 f);
	  glVertex2f(2.0 f, 0.5 f);
	  glEnd();
	  glBegin(GL_POLYGON);
	  glColor3ub(176, 191, 189);
	  glVertex2f(-2.0 f, -0.5 f);
	  glVertex2f(-2.0 f, -0.3 f);
	  glVertex2f(2.0 f, -0.3 f);
	  glVertex2f(2.0 f, -0.5 f);
	  glEnd();
	

	  // zebra-crossing start
	  glLineWidth(5.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  glVertex2f(0.2 f, 0.3 f);
	  glVertex2f(0.2 f, -0.3 f);
	

	  glVertex2f(0.4 f, -0.3 f);
	  glVertex2f(0.4 f, 0.3 f);
	

	  glVertex2f(1.4 f, 0.3 f);
	  glVertex2f(1.4 f, -0.3 f);
	

	  glVertex2f(1.6 f, 0.3 f);
	  glVertex2f(1.6 f, -0.3 f);
	

	  glEnd();
	

	  glLineWidth(10.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(255, 255, 255);
	  // left cross
	  glVertex2f(0.2 f, 0.2 f);
	  glVertex2f(0.4 f, 0.2 f);
	

	  glVertex2f(0.2 f, 0.1 f);
	  glVertex2f(0.4 f, 0.1 f);
	

	  glVertex2f(0.2 f, 0.0 f);
	  glVertex2f(0.4 f, 0.0 f);
	

	  glVertex2f(0.2 f, -0.1 f);
	  glVertex2f(0.4 f, -0.1 f);
	

	  glVertex2f(0.2 f, -0.2 f);
	  glVertex2f(0.4 f, -0.2 f);
	

	  // right cross
	  glVertex2f(1.4 f, 0.2 f);
	  glVertex2f(1.6 f, 0.2 f);
	

	  glVertex2f(1.4 f, 0.1 f);
	  glVertex2f(1.6 f, 0.1 f);
	

	  glVertex2f(1.4 f, 0.0 f);
	  glVertex2f(1.6 f, 0.0 f);
	

	  glVertex2f(1.4 f, -0.1 f);
	  glVertex2f(1.6 f, -0.1 f);
	

	  glVertex2f(1.4 f, -0.2 f);
	  glVertex2f(1.6 f, -0.2 f);
	

	  glEnd();
	  // zebra-crossing end
	

	  //center line
	  glLineWidth(10.0 f);
	  glBegin(GL_LINES);
	  glColor3ub(176, 191, 189);
	  // left cross
	  glVertex2f(-2.0 f, 0.0 f);
	  glVertex2f(2.0 f, 0.0 f);
	

	  glEnd();
	

	  new_trees();
	  glEnd();
	

	  shop();
	  factory();
	  infoboard();
	  infoboard1();
	  car1();
	  car2();
	  if (car_stopped) {
	    glLineWidth(80.0 f);
	    glBegin(GL_LINES);
	    glColor3ub(0, 0, 0);
	    glVertex2f(0.23 f, 0.65 f);
	    glVertex2f(0.23 f, 0.0 f);
	    glEnd();
	

	    glColor3ub(255, 255, 255);
	    const char * c = "Please Pay 50";
	    glRasterPos2f(1.0 f, 0.73 f);
	    for (int i = 0; c[i] != '\0'; i++)
	      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
	    glColor3ub(255, 255, 255);
	    const char * d = "Rupees";
	    glRasterPos2f(1.0 f, 0.68 f);
	    for (int i = 0; d[i] != '\0'; i++)
	      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, d[i]);
	

	  } else {
	    const char * c = "Thank You";
	    glRasterPos2f(1.0 f, 0.73 f);
	    for (int i = 0; c[i] != '\0'; i++)
	      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
	    glBegin(GL_LINES);
	    glColor3ub(0, 0, 0);
	    glVertex2f(0.23 f, 0.65 f);
	    glVertex2f(0.23 f, 0.95 f);
	    glEnd();
	  }
	

	  if (car_stopped1) {
	    glLineWidth(80.0 f);
	    glBegin(GL_LINES);
	    glColor3ub(0, 0, 0);
	    glVertex2f(0.23 f, -0.65 f);
	    glVertex2f(0.23 f, -0.09 f);
	    glEnd();
	    glColor3ub(255, 255, 255);
	    const char * c = "Please Pay 200";
	    glRasterPos2f(-0.20 f, -0.70 f);
	    for (int i = 0; c[i] != '\0'; i++)
	      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
	    glColor3ub(255, 255, 255);
	    const char * d = "Rupees";
	    glRasterPos2f(-0.20 f, -0.75 f);
	    for (int i = 0; d[i] != '\0'; i++)
	      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, d[i]);
	

	  } else {
	

	    glBegin(GL_LINES);
	    glColor3ub(0, 0, 0);
	    glVertex2f(0.23 f, 0.65 f);
	    glVertex2f(0.23 f, 0.95 f);
	    glEnd();
	    const char * c = "Thank You";
	    glColor3ub(255, 255, 255);
	    glRasterPos2f(-0.20 f, -0.70 f);
	    for (int i = 0; c[i] != '\0'; i++)
	      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
	    glBegin(GL_LINES);
	    glColor3ub(0, 0, 0);
	    glVertex2f(0.23 f, -0.65 f);
	    glVertex2f(0.23 f, -0.95 f);
	    glEnd();
	  }
	

	  house1();
	  road_light();
	  rain();
	  fence();
	  billboard();
	  billboard2();
	  shop_d();
	

	  glEnd();
	  glutPostRedisplay();
	  glFlush();
	  glutSwapBuffers();
	}
	

	void button(unsigned char key, int x, int y) {
	  glColor3ub(0, 0, 0);
	  const char * c = "Thank You";
	  glRasterPos2f(1.0 f, 0.73 f);
	  for (int i = 0; c[i] != '\0'; i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
	

	  switch (key) {
	  case 'f':
	    glutDisplayFunc(display);
	    break;
	

	  case 'r':
	    cnt++;
	    break;
	

	  case 'g':
	    cnt = 0;
	    break;
	
	  }
	}
	void init(void) {
	  //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	  glClearColor(0.5 f, 1.0 f, 0.0 f, 1.0 f);
	  glMatrixMode(GL_PROJECTION);
	  gluOrtho2D(-2, 2, -1, 1);
	  // window size
	}
	

	int main(int argc, char ** argv) {
	  glutInit( & argc, argv);
	  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	  glutInitWindowSize(1430, 800);
	  glutInitWindowPosition(0, 0);
	  glutCreateWindow("TOLL GATE SCENARIO");
	  init();
	  glutDisplayFunc(start);
	  glutTimerFunc(10, update_car1, 0);
	  glutTimerFunc(10, update_car2, 0);
	  glutTimerFunc(100, update_rain, 0);
	  glutTimerFunc(100, update_smoke, 0);
	  glutKeyboardFunc(button);
	  printf("Project Title:Highway Lens : Toll Plaza\n\n");
	  printf("Group Member: Tanisha Sharma  \n");
	  printf("Group Member: Divya Arora     \n");
	  printf("Submitted to: Dr. Kuntal Chowdhary\n\n");
	  glutMainLoop();
	  return 0;
	}
