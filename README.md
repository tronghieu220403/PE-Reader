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
│   │
├── main.cpp                                             # main code
│   │
├── inlucde
│   │
│   └── pestructure
│   │   │ 
│   │   └── fileheader                                     # dependencies for pipeline (IPC)
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── datadirectories                                     # dependencies for pipeline (IPC)
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── sectionheaders                                     # dependencies for pipeline (IPC)
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── fileheader                                     # dependencies for pipeline (IPC)
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── importdirectory                                     # dependencies for pipeline (IPC)
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── exportdirectory                                     # dependencies for pipeline (IPC)
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── rsrcsection                                     # dependencies for pipeline (IPC)
│   │   │   └── client.h
│   │   │   └── server.h
│   │   │   └── pipe.h
│   │   │ 
│   │   └── peconstants                                     # dependencies for pipeline (IPC)
│   │
│   └── ulti                                             # dependencies for platform 
│   │   └── everything.h                                         # everything needed (libraries, syntaxs) for the code
│   │
────────────	
```

References
----------------
## [MSDN - PE Format](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format)

Requirements
---
* C++ 20
* Supported Operating Systems (64-bit)
  * Windows

Coding style
------------
[Google C++ Style](https://google.github.io/styleguide/cppguide.html)
