# File Structure Management System

## Project Description
The **File Structure Management System** is designed to manage and organize various records, such as camper information, staff details, activities, and associated fees. This system is implemented in C++ and features a menu-driven interface that allows for easy addition, updating, deletion, listing, and searching of records. The project demonstrates a structured approach to file handling and basic CRUD operations using C++.

## Features
- **Camper Management**: Add, update, delete, list, and search camper records.
- **Staff Management**: Manage staff details, including qualifications and pay.
- **Activity Management**: Maintain records of activities, including descriptions and duration.
- **Fee Management**: Manage fees associated with each activity.
- **Menu-Driven Interface**: Simple and user-friendly interface for interacting with the system.

## Project Structure
FileStructure/
├── src/
│   ├── main.cpp                # Main program file with code
│   ├── camper.cpp              # Camper-related operations
│   ├── staff.cpp               # Staff-related operations
│   ├── activity.cpp            # Activity-related operations
│   └── fee.cpp                 # Fee structure-related operations
│
├── include/
│   ├── camper.h                # Header file for camper operations
│   ├── staff.h                 # Header file for staff operations
│   ├── activity.h              # Header file for activity operations
│   └── fee.h                   # Header file for fee operations
│
├── assets/                     # Folder for images or other assets
│   ├── Insertion_of_a_record.png
│   ├── Menu.png
│   ├── Modified_data.png
│   ├── Process_of_Record_modification.png
│   ├── Record_Deletion.png
│   ├── Record_Display.png
│   └── Record_searching.png
│
└── README.md                   # Project description

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/FileStructure.git
   cd FileStructure
2. Compile the program (assuming all source files are in the `src` folder):
   ```bash
   g++ src/*.cpp -o file_structure_management
## Usage
1. Run the program:
   ```bash
   ./file_structure_management
2. Follow the on-screen menu to manage camper, staff, activity, and fee records.

## Example Screenshots
### Main Menu
![Main Menu](https://github.com/VarshaVenky/file-structure-project/blob/master/assets/images/Menu.png)

### Record Insertion
![Record Insertion](assets/Insertion_of_a_record.png)

## Requirements
- C++ compiler (e.g., `g++`)

## Contributors

- **Varsha V.** - [varshavenkatesh3798@gmail.com](mailto:varshavenkatesh3798@gmail.com)

## License
This project is licensed under the MIT License. See the `LICENSE`![LICENSE](https://github.com/VarshaVenky/file-structure-project/blob/master/LICENSE.txt) file for more details.
