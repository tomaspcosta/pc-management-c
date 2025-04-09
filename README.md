#   Console PC Management Application

##   Table of Contents

1.  [Project Description](#project-description)
2.  [Technologies Used](#technologies-used)
3.  [Features](#features)

##   1. Project Description

A console-based application written in C for managing a list of personal computers (PCs). It allows users to register, edit, display, delete, and store PC records in a binary file. Additional features include category filtering, sorting by purchase date, and calculating the total value of all PCs. This project demonstrates basic data structures, file handling, and user interaction via a command-line interface.

##   2. Technologies Used

* C (Standard C Library)
* Binary file handling (`fopen`, `fread`, `fwrite`)
* Struct-based data modeling
* Console I/O (`scanf`, `printf`)

##   3. Features

* **Add PC**  
  Register a new PC with details including brand, model, GPU, CPU, serial number, purchase date, RAM, disk space, and price. Categorize the PC as Desktop, Portable, or Server.

* **Display All PCs**  
  Show all registered PCs with full details.

* **Display PCs by Category**  
  View PCs filtered by category: Desktop, Portable, or Server.

* **Remove PC**  
  Delete a PC using its registration number.

* **Save PCs to File**  
  Store the current list of PCs into a binary file (`pc.bin`).

* **Read and Display from File**  
  Load and display PCs saved in the binary file.

* **Sort PCs by Purchase Date**  
  Sort PCs by their purchase date in ascending or descending order. The sorted list can be saved and displayed.

* **Calculate Total Value**  
  Calculate and display the total combined value of all registered PCs.
