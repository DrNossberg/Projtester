**projTester**
===

Hello, and welcome here in this ProjTeser README! :D
===

This is the ProjTester, a tool that will help you to execute multiple test on the output of your program throught it's developpement

It allow you to easely create test for your whole programme

Test should all be contained in the smae directory. A test is a single .tdf file, formatted as following:
ARGS:_write here the arguments_
RES:_write here the expected output_

The projTester performe a comparaison between the output of your programme with the gived arguments (ARGS)
and the RES expected output.

_./projTester -h :_
USAGE:
	./projTester TRD [BFT] [outputFile]/[option]

DESCRIPTION :
	TRD		root directory of all the tests
	BFT		binary file to be tested
	outputFile	file in witch the ressult is printed
	Option :	
		-s	silence; don't print passed tests		
		-l	debugging; display the name of all failed tests
		-v	optimisation; execute valgrind on all testIN BUILDING
		-f	failed; print details of failed tests
		-d	details; print details of all tests

Example
`./projTester TestDirectory/`
-----rootDirectory1/
----------no_valide_res.tdf
----------option1/
---------------client/
--------------------test1.tdf
---------------killerTest.tdf
---------------server/
--------------------test1.tdf
--------------------test2.tdf
----------option2/
---------------bigTest.tdf
---------------smallTest.tdf
----------rigor/
---------------noArg.tdf
---------------tooManyArgs.tdf

`./projTester TestDirectory echo `
[rootDirectory1] no_valide_res:KO^
[rootDirectory1] [option1] [client] test1: OK!
[rootDirectory1] [option1] killerTest: OK!
[rootDirectory1] [option1] [server] test1: OK!
[rootDirectory1] [option1] [server] test2: OK!
[rootDirectory1] [option2] bigTest: OK!
[rootDirectory1] [option2] smallTest: OK!
[rootDirectory1] [rigor] noArg: OK!
[rootDirectory1] [rigor] tooManyArgs: OK!

Summary:
Passed test : 8/9 - 1 fails


If you detect any bug or wants to submit an idea/feedback/improvement feel free to submit it at antoine.orion@epitech.eu

One last thing, this code has been made in accordance with the 2022 EPITECH promotion's coding rule, witch follows the standard C one.

Enjoy!