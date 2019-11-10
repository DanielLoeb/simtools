#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import subprocess

GREEN = '\033[92m'
RED = '\033[91m'
CEND = '\033[0m'


def resprint(sim_res):
	failed = False
	
	if not sim_res[0]:
		failed = True
		print(RED + "failed." + CEND)
		print()
		for entry in sim_res[1]:
			print('\t',entry)
		print()
	else:
		print(GREEN + "success!" + CEND)
	
	return failed

def runtest(exec_name):
	curdir = os.path.abspath(os.path.dirname(__file__))+"/st_test"
	failed = False
	env_mapping = os.environ
	if 'LD_LIBRARY_PATH' in env_mapping:
		env_mapping['LD_LIBRARY_PATH'] = curdir + ":" + env_mapping['LD_LIBRARY_PATH']
	else:
		env_mapping['LD_LIBRARY_PATH'] = curdir
	
	execcommand = exec_name.split('\t')
	pres = subprocess.Popen(execcommand, stderr=subprocess.PIPE, stdout=subprocess.PIPE, env=env_mapping)
	pres.wait()
	
	errll = []
	for line in pres.stderr:
		failed = True
		errll.append(line)
	
	for line in pres.stdout:
		failed = True
		errll.append(line)
	
	if pres.returncode != True:
		failed = True
	
	return [not failed, errll]
