# **DATA STRUCTURES LIBRARY** <a name = "TOP"></a>

The purpose of this library is to provide basic data structures, as studied in ETCS 209 of the CSE curriculum of IPU, in a friendly and easy-to-use manner, abstracting the implementational details from the user. The library provides the data structures in a manner similar to the _Collections_ module of Java, with the user being able to instantiate objects of the data structures and use the various functions provided off the bat.

The data structures currently implemented are :

1. Arrays (non-resizable)
2. Linked lists
3. Stacks
4. Queues
5. Binary Search Trees

> Note : All the data structures have been implemented as templated class to allow usage of custom data types the user may have.

## **Setup**

It is recommended to compile the source code into a static library.

For this purpose the use of _**premake5**_ has been made for the convenience of the user.

The premake5 lua script currently only supports setting up projects for Visual Studio and generating makefiles for make/gmake.

### FOR VISUAL STUDIO USERS :

1. Download the repository from [Data Structures Library](https://github.com/KaranAhlawat/Data-Structures-Lib) or clone the repository from <https://github.com/KaranAhlawat/Data-Structures-Lib.git> using

```
git clone https://github.com/KaranAhlawat/Data-Structures-Lib.git
```

2. Navigate to the build folder inside the repository, and open a terminal in it.
3. Run the following command in the terminal

```
./premake5.exe vs2019
```

4. Now return to the root folder, where a `Data Structures.sln` has been added, alongside a Visual Studio project file inside the myDSlib project.
5. Open the solution, and compile the source code.
6. The compiled and archived library should be present in a folder named _binaries_.

### FOR GMAKE/MAKE USERS :

1. Download the repository from [Data Structures Library](https://github.com/KaranAhlawat/Data-Structures-Lib) or clone the repository from <https://github.com/KaranAhlawat/Data-Structures-Lib.git> using

```
git clone https://github.com/KaranAhlawat/Data-Structures-Lib.git
```

2. Navigate to the build folder inside the repository, and open a terminal in it.
3. Run the following command in the terminal

```
./premake5.exe gmake
```

4. Now return to the root folder, where a makefile has been added. Open a terminal in there, running the following

```
make
```

5. The compiled and archived library should be present in a folder named _binaries_.

## **USAGE**

1. To use the classes in the library, include "myDSlib.h" in your source code

```
#include "myDSlib.h"
```

2. Link the library with your source code by using a command similar to

```
g++ -L. -l myDSlib -o main.cpp
```

## **CONTRIBUTORS**

- Karan Ahlawat : For writing the source code of the library, publishing it on github.
- Emily : For setting up the project generation scripts and managing the premake scripts of the project.
