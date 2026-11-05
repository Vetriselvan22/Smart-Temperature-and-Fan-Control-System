# SMART TEMPERATURE AND FAN CONTROL SYSTEM

**PROJECT OVERVIEW**

A console-based C application that automatically adjusts fan speed based on temperature. It monitors temperature, detects overheating, and stores temperature details in a CSV file.

**FEATURES**
- Automatic Temperature Monitoring
- Automatic Fan Speed Control
- System Status Display
- Temperature History
- Maximum, Minimum and Average Temperature
- Overheating Detection and Alarm
- System Reset
- CSV File Handling

**FAN SPEED CONTROL**

| Temperature | Fan Speed |
|---|---:|
| Below 25°C | 0% |
| 25°C – 34°C | 30% |
| 35°C – 44°C | 60% |
| 45°C – 54°C | 80% |
| 55°C and above | 100% |

**TECHNOLOGIES USED**
- Language: C
- Compiler: GCC
- Concepts: Structures, Pointers, Arrays and Functions
- File Handling: CSV Operations

**PROJECT STRUCTURE**

```text
Smart-Temperature-and-Fan-Control-System/
├── main.c
├── smartTemp_Fan.c
├── smartTemp_Fan.h
├── database.csv
└── README.md
```

**LEARNING OUTCOMES**
- Developed automatic fan control logic.
- Practiced structures, pointers and arrays.
- Improved modular programming skills.
- Implemented temperature history management.
- Learned CSV file handling in C.
