package org.pflager;

import org.junit.platform.suite.api.SelectClasses;
import org.junit.platform.suite.api.Suite;

@Suite
@SelectClasses({
	org.pflager.gl.AllTests.class,
})
public class AllTests {}