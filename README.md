# 🏥 MediChecks CMS

> A **C++ CLI-based Clinic Management System** that handles patient registration, appointment scheduling, doctor dashboards, and medical record management — all from the terminal.

---

## 📋 Project Description

MediChecks CMS is a terminal-based application written in C++ that streamlines clinic operations. Patients can register, log in, book and cancel appointments with doctors, and view their medical history. Doctors can log in to manage their schedule, access and update patient medical records, and mark appointments as complete.

All data is persisted using text file storage, and passwords are protected using a custom hash function. Built as a learning project to explore structured C++ programming, file I/O, and role-based CLI application design.

---

## ✨ Features

### 👤 Patient
- Register a new account or log in to an existing one
- View upcoming and previous appointments
- Book an appointment by selecting a doctor and entering a date & time
- Automatic conflict detection — prevents double-booking for both patients and doctors
- Cancel a pending appointment
- Update contact number and email address

### 🩺 Doctor
- Register a new account or log in
- View upcoming patient appointments with contact details
- Access patient medical records
- Update patient records with diagnosis, prescribed medications, and recommendations
- Mark appointments as complete

### 🔐 General
- Hidden password input (displays `*` while typing)
- Custom password hashing for secure credential storage
- Input validation for dates (`DD/MM/YYYY`), times (`HH:MM`), contact numbers, and email addresses
- Colour-coded terminal output for errors and success messages
- Text file-based persistent storage

---

## 🛠️ Tech Stack

| Component | Details |
|---|---|
| **Language** | C++ |
| **Standard** | C++11 |
| **IDE Support** | DevC++, CodeBlocks |
| **Compiler** | TDM-GCC 4.9.2 64-bit |
| **Storage** | Text file I/O (`.txt`) |
| **Key Libraries** | `<fstream>`, `<regex>`, `<vector>`, `<sstream>`, `<conio.h>` |
| **Platform** | Windows |

---

## 📂 Project Structure

```
MediChecksCMS/
│
├── Final_project.cpp        # Full source code
├── patient data.txt         # Stores patient account details
├── doctor data.txt          # Stores doctor account details
├── appointment data.txt     # Stores all appointment records
└── patient record data.txt  # Stores patient medical records
```

---

## ⚙️ Setup Instructions

### 1️⃣ Clone the Repository

```bash
https://github.com/SwenJay/Medicheks_CMS_C-
```

### 2️⃣ Open the Project

Open **DevC++** or **CodeBlocks**, then go to `File > Open` and select `Final_project.cpp`.

### 3️⃣ Configure the Compiler *(DevC++ only)*

1. Click **Tools** in the header bar
2. Set the compiler to `TDM-GCC 4.9.2 64-bit Debug`
3. Find the field **"Add the following commands when calling the linker"** and replace the default value with:

```
-std=c++11
```

### 4️⃣ Compile & Run

- **DevC++** → `Execute > Compile and Run`
- **CodeBlocks** → `Build > Build and Run`

---

## 🗂️ How It Works

```
Start
 ├── 1. Patient
 │     ├── Sign Up / Sign In
 │     ├── View Medical Records
 │     ├── Schedule Appointment
 │     ├── Cancel Appointment
 │     └── Update Personal Information
 │
 ├── 2. Doctor
 │     ├── Sign Up / Sign In
 │     ├── View Schedule
 │     ├── Access Patient Records
 │     ├── Update Patient Records
 │     └── Mark Appointment as Complete
 │
 └── 3. Exit
```

---

## 🚧 Work In Progress

- [ ] Stronger password hashing algorithm
- [ ] Admin role with full system access
- [ ] Appointment search and filtering
- [ ] Appointment history and reporting

---

## 🎯 What This Project Demonstrates

- Role-based CLI application design in C++
- File I/O for persistent data storage across sessions
- Custom password hashing for authentication
- Input validation using `<regex>` for dates, times, contacts, and emails
- Conflict detection logic for appointment scheduling
- Use of `struct`, `vector`, and modular function design

---

## 👨‍💻 Author

**Ruwina Jayathunga**  
Aspiring Software Developer — Focused on C++ and backend systems

---

> ⭐ This project is part of an ongoing learning journey in software engineering and application development.
