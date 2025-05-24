# 📱 Phonebook Management System (C++)

A simple command-line phonebook manager built in C++ using object-oriented programming principles.  
Allows users to add, edit, search, delete, and organize contacts with label support.

## 🎯 Features
- Add new contacts with duplication checks
- Edit, delete, and search contacts by name or phone number
- Sort contacts alphabetically
- Mark contacts as favorites
- Save and load contacts from `contacts_list.txt`
- User-friendly CLI interface

## 🛠 Tech Stack
- Language: **C++**
- IDE: Dev C++, Visual Studio Code
- OS: Windows

## 💡 Object-Oriented Design
The system uses two main classes:
- **Contact** – Holds name, number, favorite tag, and display methods
- **PhoneBook** – Manages contact list, including search, modify, delete functions

## 📂 Project Structure
├── main.cpp
├── Contact.h / Contact.cpp
├── PhoneBook.h / PhoneBook.cpp
├── contacts_list.txt
├── README.md
└── ...

## 🚀 How to Run
1. Clone the repo and open in Dev C++ or VS Code.
2. Compile and run `main.cpp`.
3. Follow the command-line instructions to manage your contacts.

## 📸 Screenshots (Optional)
_Add images or terminal outputs if available_

## 👤 Contributors
- Trần Nguyễn Khánh Hoàng – UI & Testing  
- Đỗ Lê Việt Hoàng – Add/Edit Functions  
- Lê Công Bắc – Search/Delete Functions  
- Nguyễn Việt Bình – Documentation & Testing

## 📌 Future Improvements
- Add login and data encryption  
- Enhance UI with a GUI framework  
- Store call history and blocklist  
- Backup contacts to cloud/local database

## 📄 License
This project is for educational use only.
