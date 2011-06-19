#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import subprocess
from test_helpers import runtest

def build(debug=False):
	errll = []
	apath = os.path.abspath(os.path.dirname(__file__))
	curdir = apath+"/st_test"
	
	failed = False
	
	filename = 'binary_test'
	
	toremove = apath + filename
	if(os.path.exists(toremove)):
		os.remove(toremove)
	
	if debug:
		compilecommands = ['g++', '-Wall', '-ggdb3', '-L' +curdir, '-lsimtools', 'bs_test.cpp', '-o', filename]
	else:
		compilecommands = ['g++', '-Wall', '-O3', '-L' +curdir, '-lsimtools', 'bs_test.cpp', '-o', filename]
	
	pres = subprocess.Popen(compilecommands, stderr=subprocess.PIPE)
	pres.wait()
	
	for line in pres.stderr:
		errll.append(line)
		
	filename = 'growing_test'
	
	toremove = apath + filename
	if(os.path.exists(toremove)):
		os.remove(toremove)
		
	if debug:
		compilecommands = ['g++', '-Wall', '-ggdb3', '-L' +curdir, '-lsimtools', 'growing_test.cpp', '-o', filename]
	else:
		compilecommands = ['g++', '-Wall', '-O3', '-L' +curdir, '-lsimtools', 'growing_test.cpp', '-o', filename]
	
	pres2 = subprocess.Popen(compilecommands, stderr=subprocess.PIPE)
	pres2.wait()
	
	for line in pres2.stderr:
		errll.append(line)
		
	filename = 'heap_test'
	
	toremove = apath + filename
	if(os.path.exists(toremove)):
		os.remove(toremove)
		
	if debug:
		compilecommands = ['g++', '-Wall', '-ggdb3', '-L' +curdir, '-lsimtools', 'heap_test.cpp', '-o', filename]
	else:
		compilecommands = ['g++', '-Wall', '-O3', '-L' +curdir, '-lsimtools', 'heap_test.cpp', '-o', filename]
	
	pres3 = subprocess.Popen(compilecommands, stderr=subprocess.PIPE)
	pres3.wait()
	
	for line in pres3.stderr:
		errll.append(line)
	
	if len(errll) > 0:
		failed = True
	
	return [not failed, errll]

def growing_test():
	return runtest('./growing_test')

def binary_test():
	return runtest('./binary_test')

def heap_test():
	return runtest('./heap_test')