#include <stdio.h>
#include <stdlib.h>

#include "../src/com_pflager_glu.h"

int main(int argc, char** argv) {

	puts("Got here"); fflush(stdout);

	Java_com_pflager_glu_gluTessCallback__Lcom_pflager_glu_GLUtesselator_2ILcom_pflager_glu_BeginFunc_2(NULL, NULL, NULL, 3, NULL);

	Java_com_pflager_glu_gluTessCallback__Lcom_pflager_glu_GLUtesselator_2ILcom_pflager_glu_ErrorFunc_2(NULL, NULL, NULL, 3, NULL);

	Java_com_pflager_glu_gluTessCallback__Lcom_pflager_glu_GLUtesselator_2ILcom_pflager_glu_EndFunc_2(NULL, NULL, NULL, 2, NULL);

	puts("Got here too!"); fflush(stdout);

	return EXIT_SUCCESS;
}
