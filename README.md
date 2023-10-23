# PE Reader

Welcome to the "Portable Executable Reader" repository! This is an open-source project that aims to provide a tool for reading and analyzing Portable Executable (PE) files.

- [Introdution](#introduction)
- [Folder structure](#folder-structure)
- [References](#references)
- [Requirements](#requirements)
- [Coding style](#coding-style)

Introduction
----------------
The Portable Executable (PE) format is a commonly used file format in the Windows operating system. It includes executable files (.exe), dynamic-link libraries (.dll), and other system files. Understanding the content and structure of PE files is crucial for various purposes. The "PE Reader" repository offers a comprehensive solution for reading and dissecting PE files.

Folder structure
----------------
```
.
├── pe-reader.exe                                        
│   │
├── main.cpp
│   │
├── inlucde
│   │
│   └── pestructure
│   │   │ 
│   │   └── fileheader
│   │   │   └── dosheader.h
│   │   │   └── ntheader.h
│   │   │   └── cofffileheader.h
│   │   │   └── optionalheader.h
│   │   │ 
│   │   └── datadirectories
│   │   │   └── datadirectorytable.h
│   │   │   └── datadirectory.h
│   │   │ 
│   │   └── sectionheaders
│   │   │   └── sectiontable.h
│   │   │   └── sectionheader.h
│   │   │ 
│   │   └── importdirectory
│   │   │   └── importdirectorytable.h
│   │   │   └── importdirectoryentry.h
│   │   │   └── importlookuptable.h
│   │   │   └── importlookupentry.h
│   │   │   └── hintnametable.h
│   │   │   └── hintnameentry.h
│   │   │ 
│   │   └── exportdirectory
│   │   │   └── exportdirectorytable.h
│   │   │   └── exportaddressentry.h
│   │   │ 
│   │   └── rsrcsection
│   │   │   └── resourcedirectorytable.h
│   │   │   └── resourcedirectorynameentry.h
│   │   │   └── resourcedirectoryidentry.h
│   │   │   └── resourcedirectorynameentry.h
│   │   │   └── resourcedirectorystring.h
│   │   │ 
│   │   └── peconstants.h
│   │
│   └── ulti
│   │   └── everything.h
│   │
────────────	
```

References
----------------
[MSDN - PE Format](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format)

Requirements
---
* C++ 20
* Supported Operating Systems (64-bit)
  * Windows

Coding style
------------
[Google C++ Style](https://google.github.io/styleguide/cppguide.html)
