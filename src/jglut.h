/*
 * jglut.h
 *
 *  Created on: Mar 2, 2019
 *      Author: oy753c
 */

#ifndef SRC_JGLUT_H_
#define SRC_JGLUT_H_

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#ifdef WIN32
#include <GL/glext.h>
#endif

#include <GL/glu.h>

#include "DPRINTF.h"

int array_length_from_pname(int pname);

#endif /* SRC_JGLUT_H_ */
