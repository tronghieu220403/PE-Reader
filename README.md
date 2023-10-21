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
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── datadirectories
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── sectionheaders
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── importdirectory
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── exportdirectory
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── rsrcsection
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── peconstants
│   │
│   └── ulti
│   │   └── everything.h
│   │
────────────	
```

References
----------------
### [MSDN - PE Format](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format)

Requirements
---
* C++ 20
* Supported Operating Systems (64-bit)
  * Windows

Coding style
------------
[Google C++ Style](https://google.github.io/styleguide/cppguide.html)
