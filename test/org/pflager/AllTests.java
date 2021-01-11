package org.pflager;

import org.junit.platform.suite.api.SuiteDisplayName;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteDisplayName("JGlut AllTests Suite")
@SuiteClasses({
	org.pflager.gl.AllTests.class,
})
public class AllTests {}