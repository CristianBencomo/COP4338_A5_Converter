# COP 4338 Converter
Assignment 5         
Cristian Bencomo
## Description
This program will take an input which will indicate 2 files, the first one must be an existing file and the second one will be the file created.           
This is the command format:
> xxxx.ext yyyy.ext       
> This will convert the file with name xxxx and extension ext into the extension of file yyyy and save it under that name

## Contents
* converter.c is the program source code
* pdfAssignment description pdf
* a.exe is a version compiled on a windows system (might create compatibility issues with some devices)

## Supported conversions table
| from/to | csv | tl5 | tr9 | tc9 |
|:-------:|:---:|:---:|:---:|:---:|
|   csv   |  NA |  Y  |  N  |  N  |
|   tl5   |  Y  |  NA |  N  |  N  |
|   tr9   |  N  |  N  |  NA |  N  |
|   tc9   |  N  |  N  |  N  |  NA |