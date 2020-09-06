
# CPPFOLDER overview
[CPPFOLDER](https://github.com/tanghocle123/cppfolder) is the setup that I use when I'm starting a new project or just a small tinkering to do in C++.

## Index

- [About](#about)
- [Usage preview](#usage-preview)
  - [Installation](#installation)
  - [Examples](#examples)
    - [Start from the top directory - cppfolder/](#start-from-the-top-directory)
      - [Default make](#default-make)
      - [make with TARGET](#make-with-target)
    - [In subfolders](#in-subfolders)
- [Using cppfolder](#using-cppfolder)
  - [Pre-Requisites](#pre-requisites)
  - [File Structure](#file-structure)
  - [Build](#build) 
- [Community](#community)
  - [Contribution](#contribution)
- [Resources](#resources)
- [Gallery](#gallery)
- [Credit/Acknowledgment](#creditacknowledgment)
- [License](#license)

## About
Setting the same things up and typing them all over again can be quite terrifying.

I figure by having this template of a project like this, my workflow will be better and I don't have to bother setting up things again. I just have to follow the instructions in the folder

Linux supported and terminal based. 
Uses makefile for automation, g++ for compiling, googletest for testing (changable of course)
Doesn't involve any IDE

## Usage preview
Use it to speed up your C++ project setup.

###   Installation

```
// Clone this github to your folder

cd /Your/Path/To/Folder
git clone https://github.com/tanghocle123/cppfolder.git
```

###   Examples

#### Start from the top directory
Start from the top directory when you want to run everything without going into each subfolders.
##### Default make
```
make
```
Result:
```
make -C coding/ 
make[1]: Entering directory '/home/jack2510/Documents/code/project/standardcpp/coding'
// Do stuff in one folder 
make[1]: Leaving directory '/home/jack2510/Documents/code/project/standardcpp/coding'


make -C gtest_default/ 	
make[1]: Entering directory '/home/jack2510/Documents/code/project/standardcpp/gtest_default'
// Do stuff in another folder 
make[1]: Leaving directory '/home/jack2510/Documents/code/project/standardcpp/gtest_default'
```
##### make with TARGET

Available target names are in each of the makefiles in each subfolder
```
make TARGET=run
```

Result:


```
make -C coding/ run
make[1]: Entering directory '/home/jack2510/Documents/code/project/standardcpp/coding'
// Do stuff in one folder
make[1]: Leaving directory '/home/jack2510/Documents/code/project/standardcpp/coding'

make -C gtest_default/ run
make[1]: Entering directory '/home/jack2510/Documents/code/project/standardcpp/gtest_default'
// Do stuff in another folder
make[1]: Leaving directory '/home/jack2510/Documents/code/project/standardcpp/gtest_default'
```

#### In subfolders
Subfolder makefiles syntaxes are exactly like in the top folder, but without TARGET=...

For example
```
// Running the output file
make run
```
Result:


```
./final.o
Yes
```

##  Using cppfolder
Cppfolder is plug and play as long as you have the pre-requisites ready.

###  Pre-Requisites
- [Googletest](https://github.com/google/googletest) for testing
- [Valgrind](https://valgrind.org/) for checking memory leaks and profiling.
- A compiler that supports C++11 or newer for developing code
- Text editor or IDE.


###  File Structure
File structure aren't to be changed because makefile needs the structure to stay the same.
```
├── coding
│   ├── temp.cpp
│   ├── temp.h
│   └──main.cpp
└── gtest_default
    ├── include_test.h
    ├── main.cpp
    └── Test_folder
```
### Build
```
make
```

## Community

This is open-source, you can use this library how ever you wish to use it.

 ###  Contribution

 Your contributions are always welcome and appreciated. The following are the things you can do to contribute to this project.

 1. **Report a bug** <br>
 If you think you have encountered a bug, and I should know about it, feel free to create an issue in this Github repo and I will take care of it.

 2. **Request a feature** <br>
 You can also request for a feature with an issue, and if it is viable, it will be picked for development.  

 3. **Code contribution** <br>
 Hit me up with an issue for
 - More operations ...



##  Resources

### MAKEFILE


### Testing
[https://github.com/google/googletest/blob/master/googletest/docs/primer.md](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
### Utilities
[https://stackedit.io/](https://stackedit.io/) for online readme editing

[Mastering markdown](https://guides.github.com/features/mastering-markdown/)

[README template I use for most of my projects.](https://www.reddit.com/r/programming/comments/cfeu99/readme_template_i_use_for_most_of_my_projects/)


##  Gallery

## Credit/Acknowledgment

##  License
[MIT License](https://opensource.org/licenses/MIT) </b> </em>
