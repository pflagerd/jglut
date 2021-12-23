package com.pflager;

public class glu extends gl {

	/* Extensions */
	public final static int GLU_EXT_object_space_tess = 1;
	public final static int GLU_EXT_nurbs_tessellator = 1;

	/* Boolean */
	public final static int GLU_FALSE = 0;
	public final static int GLU_TRUE = 1;

	/* Version */
	public final static int GLU_VERSION_1_1 = 1;
	public final static int GLU_VERSION_1_2 = 1;
	public final static int GLU_VERSION_1_3 = 1;

	/* StringName */
	public final static int GLU_VERSION = 100800;
	public final static int GLU_EXTENSIONS = 100801;

	/* ErrorCode */
	public final static int GLU_INVALID_ENUM = 100900;
	public final static int GLU_INVALID_VALUE = 100901;
	public final static int GLU_OUT_OF_MEMORY = 100902;
	public final static int GLU_INCOMPATIBLE_GL_VERSION = 100903;
	public final static int GLU_INVALID_OPERATION = 100904;

	/* NurbsDisplay */
	/* GLU_FILL */
	public final static int GLU_OUTLINE_POLYGON = 100240;
	public final static int GLU_OUTLINE_PATCH = 100241;

	/* NurbsCallback */
	public final static int GLU_NURBS_ERROR = 100103;
	public final static int GLU_ERROR = 100103;
	public final static int GLU_NURBS_BEGIN = 100164;
	public final static int GLU_NURBS_BEGIN_EXT = 100164;
	public final static int GLU_NURBS_VERTEX = 100165;
	public final static int GLU_NURBS_VERTEX_EXT = 100165;
	public final static int GLU_NURBS_NORMAL = 100166;
	public final static int GLU_NURBS_NORMAL_EXT = 100166;
	public final static int GLU_NURBS_COLOR = 100167;
	public final static int GLU_NURBS_COLOR_EXT = 100167;
	public final static int GLU_NURBS_TEXTURE_COORD = 100168;
	public final static int GLU_NURBS_TEX_COORD_EXT = 100168;
	public final static int GLU_NURBS_END = 100169;
	public final static int GLU_NURBS_END_EXT = 100169;
	public final static int GLU_NURBS_BEGIN_DATA = 100170;
	public final static int GLU_NURBS_BEGIN_DATA_EXT = 100170;
	public final static int GLU_NURBS_VERTEX_DATA = 100171;
	public final static int GLU_NURBS_VERTEX_DATA_EXT = 100171;
	public final static int GLU_NURBS_NORMAL_DATA = 100172;
	public final static int GLU_NURBS_NORMAL_DATA_EXT = 100172;
	public final static int GLU_NURBS_COLOR_DATA = 100173;
	public final static int GLU_NURBS_COLOR_DATA_EXT = 100173;
	public final static int GLU_NURBS_TEXTURE_COORD_DATA = 100174;
	public final static int GLU_NURBS_TEX_COORD_DATA_EXT = 100174;
	public final static int GLU_NURBS_END_DATA = 100175;
	public final static int GLU_NURBS_END_DATA_EXT = 100175;

	/* NurbsError */
	public final static int GLU_NURBS_ERROR1 = 100251;
	public final static int GLU_NURBS_ERROR2 = 100252;
	public final static int GLU_NURBS_ERROR3 = 100253;
	public final static int GLU_NURBS_ERROR4 = 100254;
	public final static int GLU_NURBS_ERROR5 = 100255;
	public final static int GLU_NURBS_ERROR6 = 100256;
	public final static int GLU_NURBS_ERROR7 = 100257;
	public final static int GLU_NURBS_ERROR8 = 100258;
	public final static int GLU_NURBS_ERROR9 = 100259;
	public final static int GLU_NURBS_ERROR10 = 100260;
	public final static int GLU_NURBS_ERROR11 = 100261;
	public final static int GLU_NURBS_ERROR12 = 100262;
	public final static int GLU_NURBS_ERROR13 = 100263;
	public final static int GLU_NURBS_ERROR14 = 100264;
	public final static int GLU_NURBS_ERROR15 = 100265;
	public final static int GLU_NURBS_ERROR16 = 100266;
	public final static int GLU_NURBS_ERROR17 = 100267;
	public final static int GLU_NURBS_ERROR18 = 100268;
	public final static int GLU_NURBS_ERROR19 = 100269;
	public final static int GLU_NURBS_ERROR20 = 100270;
	public final static int GLU_NURBS_ERROR21 = 100271;
	public final static int GLU_NURBS_ERROR22 = 100272;
	public final static int GLU_NURBS_ERROR23 = 100273;
	public final static int GLU_NURBS_ERROR24 = 100274;
	public final static int GLU_NURBS_ERROR25 = 100275;
	public final static int GLU_NURBS_ERROR26 = 100276;
	public final static int GLU_NURBS_ERROR27 = 100277;
	public final static int GLU_NURBS_ERROR28 = 100278;
	public final static int GLU_NURBS_ERROR29 = 100279;
	public final static int GLU_NURBS_ERROR30 = 100280;
	public final static int GLU_NURBS_ERROR31 = 100281;
	public final static int GLU_NURBS_ERROR32 = 100282;
	public final static int GLU_NURBS_ERROR33 = 100283;
	public final static int GLU_NURBS_ERROR34 = 100284;
	public final static int GLU_NURBS_ERROR35 = 100285;
	public final static int GLU_NURBS_ERROR36 = 100286;
	public final static int GLU_NURBS_ERROR37 = 100287;

	/* NurbsProperty */
	public final static int GLU_AUTO_LOAD_MATRIX = 100200;
	public final static int GLU_CULLING = 100201;
	public final static int GLU_SAMPLING_TOLERANCE = 100203;
	public final static int GLU_DISPLAY_MODE = 100204;
	public final static int GLU_PARAMETRIC_TOLERANCE = 100202;
	public final static int GLU_SAMPLING_METHOD = 100205;
	public final static int GLU_U_STEP = 100206;
	public final static int GLU_V_STEP = 100207;
	public final static int GLU_NURBS_MODE = 100160;
	public final static int GLU_NURBS_MODE_EXT = 100160;
	public final static int GLU_NURBS_TESSELLATOR = 100161;
	public final static int GLU_NURBS_TESSELLATOR_EXT = 100161;
	public final static int GLU_NURBS_RENDERER = 100162;
	public final static int GLU_NURBS_RENDERER_EXT = 100162;

	/* NurbsSampling */
	public final static int GLU_OBJECT_PARAMETRIC_ERROR = 100208;
	public final static int GLU_OBJECT_PARAMETRIC_ERROR_EXT = 100208;
	public final static int GLU_OBJECT_PATH_LENGTH = 100209;
	public final static int GLU_OBJECT_PATH_LENGTH_EXT = 100209;
	public final static int GLU_PATH_LENGTH = 100215;
	public final static int GLU_PARAMETRIC_ERROR = 100216;
	public final static int GLU_DOMAIN_DISTANCE = 100217;

	/* NurbsTrim */
	public final static int GLU_MAP1_TRIM_2 = 100210;
	public final static int GLU_MAP1_TRIM_3 = 100211;

	/* QuadricDrawStyle */
	public final static int GLU_POINT = 100010;
	public final static int GLU_LINE = 100011;
	public final static int GLU_FILL = 100012;
	public final static int GLU_SILHOUETTE = 100013;

	/* QuadricCallback */
	/* GLU_ERROR */

	/* QuadricNormal */
	public final static int GLU_SMOOTH = 100000;
	public final static int GLU_FLAT = 100001;
	public final static int GLU_NONE = 100002;

	/* QuadricOrientation */
	public final static int GLU_OUTSIDE = 100020;
	public final static int GLU_INSIDE = 100021;

	/* TessCallback */
	public final static int GLU_TESS_BEGIN = 100100;
	public final static int GLU_BEGIN = 100100;
	public final static int GLU_TESS_VERTEX = 100101;
	public final static int GLU_VERTEX = 100101;
	public final static int GLU_TESS_END = 100102;
	public final static int GLU_END = 100102;
	public final static int GLU_TESS_ERROR = 100103;
	public final static int GLU_TESS_EDGE_FLAG = 100104;
	public final static int GLU_EDGE_FLAG = 100104;
	public final static int GLU_TESS_COMBINE = 100105;
	public final static int GLU_TESS_BEGIN_DATA = 100106;
	public final static int GLU_TESS_VERTEX_DATA = 100107;
	public final static int GLU_TESS_END_DATA = 100108;
	public final static int GLU_TESS_ERROR_DATA = 100109;
	public final static int GLU_TESS_EDGE_FLAG_DATA = 100110;
	public final static int GLU_TESS_COMBINE_DATA = 100111;

	/* TessContour */
	public final static int GLU_CW = 100120;
	public final static int GLU_CCW = 100121;
	public final static int GLU_INTERIOR = 100122;
	public final static int GLU_EXTERIOR = 100123;
	public final static int GLU_UNKNOWN = 100124;

	/* TessProperty */
	public final static int GLU_TESS_WINDING_RULE = 100140;
	public final static int GLU_TESS_BOUNDARY_ONLY = 100141;
	public final static int GLU_TESS_TOLERANCE = 100142;

	/* TessError */
	public final static int GLU_TESS_ERROR1 = 100151;
	public final static int GLU_TESS_ERROR2 = 100152;
	public final static int GLU_TESS_ERROR3 = 100153;
	public final static int GLU_TESS_ERROR4 = 100154;
	public final static int GLU_TESS_ERROR5 = 100155;
	public final static int GLU_TESS_ERROR6 = 100156;
	public final static int GLU_TESS_ERROR7 = 100157;
	public final static int GLU_TESS_ERROR8 = 100158;
	public final static int GLU_TESS_MISSING_BEGIN_POLYGON = 100151;
	public final static int GLU_TESS_MISSING_BEGIN_CONTOUR = 100152;
	public final static int GLU_TESS_MISSING_END_POLYGON = 100153;
	public final static int GLU_TESS_MISSING_END_CONTOUR = 100154;
	public final static int GLU_TESS_COORD_TOO_LARGE = 100155;
	public final static int GLU_TESS_NEED_COMBINE_CALLBACK = 100156;

	/* TessWinding */
	public final static int GLU_TESS_WINDING_ODD = 100130;
	public final static int GLU_TESS_WINDING_NONZERO = 100131;
	public final static int GLU_TESS_WINDING_POSITIVE = 100132;
	public final static int GLU_TESS_WINDING_NEGATIVE = 100133;
	public final static int GLU_TESS_WINDING_ABS_GEQ_TWO = 100134;

	public final static double GLU_TESS_MAX_COORD = 1.0e150;

	public static class GLUnurbs {
		@SuppressWarnings("unused")
		private long address;
	};

	public static class GLUquadric {
		@SuppressWarnings("unused")
		private long address;
	};

	public static class GLUtesselator {
		@SuppressWarnings("unused")
		private long address; 					// contains the GLUtesselator pointer returned by gluNewTess() in C.
		@SuppressWarnings("unused")
		private long com_pflager_glu_jni_impl; // contains a pointer to the com_pflager_glu_jni_impl struct associated with this tesselator object.
	};

	/* Internal convenience typedefs */
//	typedef void (GLAPIENTRYP _GLUfuncptr)(void);
//
	public native void gluBeginCurve(GLUnurbs nurb);

	public native void gluBeginPolygon(GLUtesselator tess);

	public native void gluBeginSurface(GLUnurbs nurb);

	public native void gluBeginTrim(GLUnurbs nurb);

//	GLAPI GLint GLAPIENTRY gluBuild1DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
//	GLAPI GLint GLAPIENTRY gluBuild1DMipmaps (GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, const void *data);
//	GLAPI GLint GLAPIENTRY gluBuild2DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
//	GLAPI GLint GLAPIENTRY gluBuild2DMipmaps (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *data);
//	GLAPI GLint GLAPIENTRY gluBuild3DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
//	GLAPI GLint GLAPIENTRY gluBuild3DMipmaps (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
//	GLAPI GLboolean GLAPIENTRY gluCheckExtension (const GLubyte *extName, const GLubyte *extString);
	public native void gluCylinder(GLUquadric quad, double base, double top, double height, int slices, int stacks);

	public native void gluDeleteNurbsRenderer(GLUnurbs nurb);

	public native void gluDeleteQuadric(GLUquadric quad);

	public native void gluDeleteTess(GLUtesselator tess);

	public native void gluDisk(GLUquadric quad, double inner, double outer, int slices, int loops);

	public native void gluEndCurve(GLUnurbs nurb);

	public native void gluEndPolygon(GLUtesselator tess);

	public native void gluEndSurface(GLUnurbs nurb);

	public native void gluEndTrim(GLUnurbs nurb);

	public native String gluErrorString(int error);

//	GLAPI void GLAPIENTRY gluGetNurbsProperty (GLUnurbs* nurb, GLenum property, GLfloat* data);
//	GLAPI const GLubyte * GLAPIENTRY gluGetString (GLenum name);
//	GLAPI void GLAPIENTRY gluGetTessProperty (GLUtesselator* tess, GLenum which, GLdouble* data);
//	GLAPI void GLAPIENTRY gluLoadSamplingMatrices (GLUnurbs* nurb, const GLfloat *model, const GLfloat *perspective, const GLint *view);
	public native void gluLookAt(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX, double upY, double upZ);

	public native GLUnurbs gluNewNurbsRenderer();

	public native GLUquadric gluNewQuadric();

	public native GLUtesselator gluNewTess();
//	GLAPI void GLAPIENTRY gluNextContour (GLUtesselator* tess, GLenum type);

	public interface NurbsError {
		public void error(int errno);
	}

	public native void gluNurbsCallback(GLUnurbs nurb, int which, NurbsError nurbsError);

//	GLAPI void GLAPIENTRY gluNurbsCallbackData (GLUnurbs* nurb, GLvoid* userData);
//	GLAPI void GLAPIENTRY gluNurbsCallbackDataEXT (GLUnurbs* nurb, GLvoid* userData);
	public native void gluNurbsCurve(GLUnurbs nurb, int knotCount, double[] knots, int stride, double[] control, int order, int type);

	public native void gluNurbsProperty(GLUnurbs nurb, int property, double value);

	public native void gluNurbsSurface(GLUnurbs nurb, int sKnotCount, double[] sKnots, int tKnotCount, double[] tKnots, int sStride, int tStride, double[] control, int sOrder, int tOrder, int type);

	// public native void gluNurbsSurface(GLUnurbs nurb, int sKnotCount, float[] sKnots, int tKnotCount, float[] tKnots, int sStride, int tStride, float[] control, int sOrder, int tOrder, int type);
	public native void gluOrtho2D(double left, double right, double bottom, double top);

	public native void gluPartialDisk(GLUquadric quad, double inner, double outer, int slices, int loops, double start, double sweep);

	public native void gluPerspective(double fovy, double aspect, double zNear, double zFar);

//	GLAPI void GLAPIENTRY gluPickMatrix (GLdouble x, GLdouble y, GLdouble delX, GLdouble delY, GLint *viewport);
//	GLAPI GLint GLAPIENTRY gluProject (GLdouble objX, GLdouble objY, GLdouble objZ, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble* winX, GLdouble* winY, GLdouble* winZ);
	public native void gluPwlCurve(GLUnurbs nurb, int count, double[] data, int stride, int type);

	public native void gluQuadricCallback(GLUquadric quad, int which, ErrorFunc errorFunc);

	public native void gluQuadricDrawStyle(GLUquadric quad, int draw);

	public native void gluQuadricNormals(GLUquadric quad, int normal);

//	GLAPI void GLAPIENTRY gluQuadricOrientation (GLUquadric* quad, GLenum orientation);
//	GLAPI void GLAPIENTRY gluQuadricTexture (GLUquadric* quad, GLboolean texture);
//	GLAPI GLint GLAPIENTRY gluScaleImage (GLenum format, GLsizei wIn, GLsizei hIn, GLenum typeIn, const void *dataIn, GLsizei wOut, GLsizei hOut, GLenum typeOut, GLvoid* dataOut);
	public native void gluSphere(GLUquadric quad, double radius, int slices, int stacks);

	public native void gluTessBeginContour(GLUtesselator tess);

	public native void gluTessBeginPolygon(GLUtesselator tess, Object data);

	private native void gluTessCallbackNative(GLUtesselator tess, int which, Object callback);

	public interface BeginFunc {
		public void begin(int type);
	}

	public void gluTessCallback(GLUtesselator tess, int which, BeginFunc beginFunc) {
		gluTessCallbackNative(tess, which, beginFunc);
	}

	public void gluTessCallback(GLUtesselator tess, BeginFunc beginFunc) {
		gluTessCallbackNative(tess, GLU_TESS_BEGIN, beginFunc);
	}

	public interface BeginDataFunc {
		public void beginData(int type, Object polygon_data);
	}

	public void gluTessCallback(GLUtesselator tess, int which, BeginDataFunc beginDataFunc) {
		gluTessCallbackNative(tess, which, beginDataFunc);
	}

	public void gluTessCallback(GLUtesselator tess, BeginDataFunc beginDataFunc) {
		gluTessCallbackNative(tess, GLU_TESS_BEGIN_DATA, beginDataFunc);
	}

	public interface EdgeFlagFunc {
		public void edgFlag(boolean flag);
	}

	public void gluTessCallback(GLUtesselator tess, int which, EdgeFlagFunc edgeFlagFunc) {
		gluTessCallbackNative(tess, which, edgeFlagFunc);
	}

	public void gluTessCallback(GLUtesselator tess, EdgeFlagFunc edgeFlagFunc) {
		gluTessCallbackNative(tess, GLU_TESS_EDGE_FLAG, edgeFlagFunc);
	}

	public interface EdgeFlagDataFunc {
		public void edgeFlagData(boolean type, Object polygon_data);
	}

	public void gluTessCallback(GLUtesselator tess, int which, EdgeFlagDataFunc edgeFlagDataFunc) {
		gluTessCallbackNative(tess, which, edgeFlagDataFunc);
	}

	public void gluTessCallback(GLUtesselator tess, EdgeFlagDataFunc edgeFlagDataFunc) {
		gluTessCallbackNative(tess, GLU_TESS_EDGE_FLAG_DATA, edgeFlagDataFunc);
	}

	public interface VertexFunc {
		public void vertex(Object vertex_data);
	}

	public void gluTessCallback(GLUtesselator tess, int which, VertexFunc vertexFunc) {
		gluTessCallbackNative(tess, which, vertexFunc);
	}

	public void gluTessCallback(GLUtesselator tess, VertexFunc vertexFunc) {
		gluTessCallbackNative(tess, GLU_TESS_VERTEX, vertexFunc);
	}

	public interface VertexFunc2 {
		public void vertex(Object vertex_data, Object polygon_data);
	}

	public void gluTessCallback(GLUtesselator tess, int which, VertexFunc2 vertexFunc) {
		gluTessCallbackNative(tess, which, vertexFunc);
	}

	public void gluTessCallback(GLUtesselator tess, VertexFunc2 vertexFunc) {
		gluTessCallbackNative(tess, GLU_TESS_VERTEX, vertexFunc);
	}

	public interface VertexDataFunc {
		public void vertexData(double[] vertex_data, Object polygon_data);
	}

	public void gluTessCallback(GLUtesselator tess, int which, VertexDataFunc vertexDataFunc) {
		gluTessCallbackNative(tess, which, vertexDataFunc);
	}

	public void gluTessCallback(GLUtesselator tess, VertexDataFunc vertexDataFunc) {
		gluTessCallbackNative(tess, GLU_TESS_VERTEX_DATA, vertexDataFunc);
	}

	public interface EndFunc {
		public void end();
	}

	public void gluTessCallback(GLUtesselator tess, int which, EndFunc endFunc) {
		gluTessCallbackNative(tess, which, endFunc);
	}

	public void gluTessCallback(GLUtesselator tess, EndFunc endFunc) {
		gluTessCallbackNative(tess, GLU_TESS_END, endFunc);
	}

	public interface EndDataFunc {
		public void endData(Object polygon_data);
	}

	public void gluTessCallback(GLUtesselator tess, int which, EndDataFunc endDataFunc) {
		gluTessCallbackNative(tess, which, endDataFunc);
	}

	public void gluTessCallback(GLUtesselator tess, EndDataFunc endDataFunc) {
		gluTessCallbackNative(tess, GLU_TESS_END_DATA, endDataFunc);
	}

	public interface CombineFunc {
		public void combine(double[] coords, Object[] vertex_data, double[] weight, Object obj);
	}

	public void gluTessCallback(GLUtesselator tess, int which, CombineFunc combineFunc) {
		gluTessCallbackNative(tess, which, combineFunc);
	}

	public void gluTessCallback(GLUtesselator tess, CombineFunc combineFunc) {
		gluTessCallbackNative(tess, GLU_TESS_COMBINE, combineFunc);
	}

	public interface CombineDataFunc {
		public Object combine(double[] coords, Object[] vertex_data, double[] weight, Object polygon_Data);
	}

	public void gluTessCallback(GLUtesselator tess, int which, CombineDataFunc combineDataFunc) {
		gluTessCallbackNative(tess, which, combineDataFunc);
	}

	public void gluTessCallback(GLUtesselator tess, CombineDataFunc combineDataFunc) {
		gluTessCallbackNative(tess, GLU_TESS_COMBINE, combineDataFunc);
	}

	public interface ErrorFunc {
		public void error(int errno);
	}

	public void gluTessCallback(GLUtesselator tess, int which, ErrorFunc errorFunc) {
		gluTessCallbackNative(tess, which, errorFunc);
	}

	public void gluTessCallback(GLUtesselator tess, ErrorFunc errorFunc) {
		gluTessCallbackNative(tess, GLU_TESS_ERROR, errorFunc);
	}

	public interface ErrorDataFunc {
		public void errorData(int type, Object polygon_data);
	}

	public void gluTessCallback(GLUtesselator tess, int which, ErrorDataFunc errorDataFunc) {
		gluTessCallbackNative(tess, which, errorDataFunc);
	}

	public void gluTessCallback(GLUtesselator tess, ErrorDataFunc errorDataFunc) {
		gluTessCallbackNative(tess, GLU_TESS_ERROR_DATA, errorDataFunc);
	}

	public native void gluTessEndContour(GLUtesselator tess);

	public native void gluTessEndPolygon(GLUtesselator tess);

//	GLAPI void GLAPIENTRY gluTessNormal (GLUtesselator* tess, GLdouble valueX, GLdouble valueY, GLdouble valueZ);
	public native void gluTessProperty(GLUtesselator tess, int which, double data);
	public native void gluTessVertex (GLUtesselator tess, double[] location, Object data);
//	GLAPI GLint GLAPIENTRY gluUnProject (GLdouble winX, GLdouble winY, GLdouble winZ, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble* objX, GLdouble* objY, GLdouble* objZ);
	public native int gluUnProject(double winX, double winY, double winZ, double[] model, double[] proj, int[] view, double[] objXYZ);

	public native int gluUnProject(double[] winXYZ, double[] model, double[] proj, int[] view, double[] objXYZ);

	public native double[] gluUnProject(double winX, double winY, double winZ, double[] model, double[] proj, int[] view);

	public native double[] gluUnProject(double[] winXYZ, double[] model, double[] proj, int[] view);
//	GLAPI GLint GLAPIENTRY gluUnProject4 (GLdouble winX, GLdouble winY, GLdouble winZ, GLdouble clipW, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble nearVal, GLdouble farVal, GLdouble* objX, GLdouble* objY, GLdouble* objZ, GLdouble* objW);
}
