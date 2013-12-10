#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "glm.hpp"

#include <sys/time.h>

#ifdef OSX
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#endif

#include <stdexcept>
#include <time.h>
#include <math.h>

/** Particle class definition. Defines a particle with a mass, position, and velocity attributes. */
class Particle
{
public:
	//Particle constructor:
	Particle();
	Particle(glm::vec3 _pos);
	void evalForce();
  void changePos(glm::vec3 p);


	bool canMove;
	float mass;
	glm::vec3  pos, oldPos, vel, accel;
	
};

/** Particle system, sets up system of particle linking. */
//cloth

class ParticleSystem
{
public:
	ParticleSystem();
	void initializeConstraints();
	int sysPartCount;
};


class Sphere
{
	Sphere();
};



class Constraint
{
public:
	Particle part1, part2;
	Constraint();
	Constraint(Particle _part1, Particle _part2);
	//void setConstraint(Particle part1, Particle part2);
	void evalConstraint();	

	
private:
	float structDistance; //the default resting distance between two particles
	
};



//Functions
ParticleSystem initializeVerticalCloth();
ParticleSystem initializeHorizCloth();
glm::vec3 getTriangleNormal(Particle part1, Particle part2, Particle part3);
void createConstraint(Particle part1, Particle part2);
