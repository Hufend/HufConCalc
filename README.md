# HufConCalc
English | [简体中文](https://github.com/Hufend/HufConCalc/blob/main/README_ZH-CN.md)

Introduction
--------------
Simple Console Calculator  
Simple Source Code  
Simple Program  
Simple Project  
  
It's so simple

Simple Calculator
--------------
Really simple calculator  
Only four operations are supported  
But parentheses are supported

# Usage

Due to the author's low programming level, spaces must be added after the operation symbols  
For example:

	8* 2+ ( 9- 3) / 2+ 1=
	20.000000

For aesthetics, it is generally written in the following form

	8 * 2 + ( 9 - 3 ) / 2 + 1 =
	20.000000

Of course, there are several **SPECIAL** ways of writing  

'Cause I am ~~LAN~~lazy  
The formula in the program can be infinitely wrapped before the equal sign, and large, medium and small parentheses are used indiscriminately  
For example:

	8
	*
	2 + (
	9 -
	3 ) /
	2
	+ 1 =
	20.000000

	9 * ( 8 + { 6 * { 7 * 9 - 2 ) + [ 6 + 3 * 3 ) - 81 ] - 306 } =
	18.000000

This way of writing is also possible  
~~Whatever floats your boat~~


The TRUE Calculator
--------------
Not yet developed  
~~Maybe~~ coming soon

Compile Command
--------------
### GCC

	gcc ./Simple-Calculator.c -fexec-charset=GBK -o ./Simple-Calculator.exe

The value of `-fexec-charset` can be changed according to the encoding of your own terminal
