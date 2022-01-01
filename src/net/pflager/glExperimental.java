package net.pflager;

public interface glExperimental {
	final JNI jni = new JNI();
	
	public default void glClear(int mask) {
		System.out.println("Got here");
		jni.glClear(mask);
	}
	
	class JNI {
		public native void glClear(int mask);
	}	
}
