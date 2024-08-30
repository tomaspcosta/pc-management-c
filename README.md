# Console PC Management Application

This project is a console-based PC management application written in C. It allows users to manage a list of PCs, including adding, editing, searching, deleting, and storing data in a binary file. It also supports categorizing and sorting PCs by purchase date.

## Project Structure

The repository contains the following file:

- **`console_app.c`**: The main source code of the application.

## Features

- **Add PC**: Input details for a PC, including brand, model, GPU, CPU, serial number, purchase date, RAM, disk space, and price. The PC type is categorized as Desktop, Portable, or Server.
- **Display PCs**: View all entered PCs with detailed information.
- **Display by Category**: List PCs by category (Desktop, Portable, or Server).
- **Remove PC**: Delete a PC record by its registration number.
- **Save PCs**: Save the list of PCs to a binary file (`pc.bin`).
- **Read and Show PCs**: Read and display the PCs stored in the binary file.
- **Sort PCs**: Sort PCs by purchase date in ascending or descending order, save the sorted list to a binary file, and display it.
- **Calculate Total Value**: Calculate and display the total value of all registered PCs.
