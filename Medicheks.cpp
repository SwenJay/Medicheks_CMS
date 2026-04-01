#include <iostream>
#include <windows.h> // Include for system-specific functions like Sleep
#include <fstream> // File operations
#include <stdlib.h>
#include <sstream> // String stream for parsing
#include <string>
#include <vector> // Dynamic array
#include <conio.h> // Console Input/Output (for _getch())
#include <algorithm> // For find_if
#include <regex> // for validate time


using namespace std;


// Hash function
unsigned int Hash(const string& data){
    unsigned int result = 0;
    //hashing the password
    for (unsigned int ch : data)
        result = ch + (result << 4) + (result << 10) - result;
    //return hashed password
    return result;
}
//function of password not show in console
string getPassword(){
    string password;
    char ch;

    cout << "\tEnter password: ";

    while (true)
    {
        ch = _getch();//read password without typing

        if (ch == 13) // Enter key
        {
            cout << endl;
            break;
        }
        else if (ch == 8) // Backspace key
        {
            if (!password.empty())
            {   //delete last letter
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            //show * instead of password characters
            cout << '*';
            password.push_back(ch);//add characters one by one into password string
        }
    }
    //return the password
    return password;
}
//delay function
void sleepDelay(){
    cout << "\033[32m";
    cout << "Wait ";
    for(int i = 0; i < 3; i++){
        cout << "-";
        Sleep(500);
    }
    cout << "\033[0m";
}


//data validation functions
bool isValidDate(const string& date) {
    //checking weather input date is formatted or not
    regex datePattern("(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/(19|20)\\d\\d");
    return regex_match(date, datePattern);
}
bool isValidTime(const string& time) {
    //checking weather input date is formatted or not
    regex timePattern("([01]?[0-9]|2[0-3]):[0-5][0-9]");
    return regex_match(time, timePattern);
}
bool isValidContactNumber(const string& contactNumber) {
    //checking weather input contact number is valid or not
    regex contactNumberPattern("^0\\d{9}$");
    return regex_match(contactNumber, contactNumberPattern);
}
bool isValidEmailAddress(const string& emailAddress) {
    //checking weather input contact number is valid or not
    return emailAddress.find('@') != string::npos;
}



// change color of specific messages
void displayErrorMessage(const string& message) {
    cout << "\033[31m";
    cout << message;
    cout << "\033[0m";   // Reset text color to default
}
void displayFactMessage(const string& message) {
    cout << "\033[32m";
    cout << message;
    cout << "\033[0m";   // Reset text color to default
}



//structures
struct Patient{
    string patientName;
    string patientUserName;
    unsigned int patientHashedPassword;
    string patientContactNumber;
    string patientEmailAddress;

};
struct Appointment{
    string appointmentDoctor;
    string appointmentDate;
    string appointmentTime;
    string appointmentPatient;
    string appointmentPatientContact;
    string appointmentStatus;
    string appointmentNumber;

};
struct Doctor{
    string doctorName;
    string doctorUserName;
    unsigned int doctorHashedPassword;
};
struct Record{
    string recordPatientName;
    string diagnosisReport;
    string medicationsReport;
    string recommendationsReport;
};


//menu functions
void clinicManagementSystemHome(){
    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "\t\t\tClinic Management System - HOME\n" << endl;
    cout << "\t\t1.Patient" << endl;
    cout << "\t\t2.Doctor" << endl;
    cout << "\t\t3.Exit\n" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "   Enter the number you want to access (1/2/3) : ";

}
void patientMenu(){
    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "\t\t\t\tPatient Login\n" <<endl;
    cout << "\t\t1.Sign up" << endl;
    cout << "\t\t2.Sign in" << endl;
    cout << "\t\t3.Exit" << endl;
    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "   Enter the number you chose (1/2/3) : ";
}
void doctorMenu(){
    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "\t\t\tDoctor Login\n" <<endl;
    cout << "\t\t1.Sign up" << endl;
    cout << "\t\t2.Sign in" << endl;
    cout << "\t\t3.Exit" << endl;
    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "   Enter the number you chose (1/2/3) : ";
}
void patientServicesMenu(){
    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "\t\t\tAvailable Services for Patients \n" <<endl;
    cout << "\t\t1.View Medical Records" << endl;
    cout << "\t\t2.Schedule Appointments" << endl;
    cout << "\t\t3.Cancel Appointments" << endl;
    cout << "\t\t4.Update Personal Information" << endl;
    cout << "\t\t5.Exit" << endl;
    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "   Enter the option you chose (1-5) : ";
}
void doctorServicesMenu(){

    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "\t\t\tAvailable Services for Doctors\n" <<endl;
    cout << "\t\t1.View Schedule" << endl;
    cout << "\t\t2.Access Patient Records" << endl;
    cout << "\t\t3.Update Patient Records" << endl;
    cout << "\t\t4.Mark Appointment as Complete" << endl;
    cout << "\t\t5.Exit" << endl;
    cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
    cout << "   Enter the option you chose (1-5) : ";
}


//saving data into relevant files
void writePatientFile(vector<Patient>& patients){
    ofstream patientFile("patient data.txt", ios::app);

    if (patientFile.is_open())//checking the relevant file object is open or not
    {
        for (Patient& patient : patients)
        {   //save the data s into the file
            patientFile << patient.patientName
                        << ";" << patient.patientUserName
                        << " " << patient.patientContactNumber
                        << " " << patient.patientEmailAddress
                        << " " << patient.patientHashedPassword
                        << endl;
        }
        patientFile.close();//close the file object
    }
    else
    {   //error message if file not open
        displayErrorMessage("\n\tError opening file for save data.\n");
    }
}
void writeDoctorFile(vector<Doctor>& doctors){
    ofstream doctorFile("doctor data.txt", ios::app);

    if (doctorFile.is_open())//checking the relevant file object is open or not
    {
        for ( Doctor& doctor : doctors)
        {   //save the data s into the file
            doctorFile << doctor.doctorName
                        << ";" << doctor.doctorUserName
                        << " " << doctor.doctorHashedPassword
                        << endl;
        }

        doctorFile.close();//close the file object
    }
    else
    {   //error message if file not open
        displayErrorMessage("\n\tError opening file for save data.\n");
    }
}
void writeAppointmentFile(vector<Appointment>& appointments){
    ofstream appointmentFile("appointment data.txt");

    if (appointmentFile.is_open())//checking the relevant file object is open or not
    {
        for ( Appointment& appointment : appointments)
        {   //save the data s into the file
            appointmentFile << appointment.appointmentNumber << ";"
                        << appointment.appointmentDoctor << ";"
                        << appointment.appointmentPatient << ";"
                        << appointment.appointmentPatientContact << ";"
                        << appointment.appointmentDate << ";"
                        << appointment.appointmentTime << ";"
                        << appointment.appointmentStatus
                        << endl;
        }

        appointmentFile.close();//close the file object
    }
    else
    {   //error message if file not open
        displayErrorMessage("\n\tError opening file for save data.\n");
    }
}
void writeRecordFile(vector<Record>& records){
    ofstream recordFile("patient record data.txt");

    if (recordFile.is_open())//checking the relevant file object is open or not
    {
        for ( Record& record : records)
        {   //save the data s into the file
            recordFile << record.recordPatientName
                        << ";" << record.diagnosisReport
                        << ";" << record.medicationsReport
                        << ";" << record.recommendationsReport
                        << ";" << endl;
        }

        recordFile.close();//close the file object
    }
    else
    {   //error message if file not open
        displayErrorMessage("\n\tError opening file for save data.\n");
    }
}


//reading data from relevant files and return the vector
vector<Doctor> readDoctorFile() {

    vector<Doctor> doctors;//vector declaration
    ifstream DocFlie("doctor data.txt");

    if (!DocFlie.is_open()) {
        displayErrorMessage("\n\tError opening the file\n");//error message if file not open
        return doctors;
    }

    string line;
    //read line by line until all the data found
    while (getline(DocFlie, line)) {
        Doctor doctor;  // Create a new Doctor object
        istringstream iss(line);

        getline(iss, doctor.doctorName, ';');
        iss >> doctor.doctorUserName
                >> doctor.doctorHashedPassword;

        doctors.push_back(doctor);  // Add the new doctor to the vector
    }

    DocFlie.close();

    return doctors; //return doctor vector
}
vector<Patient> readPatientFile() {

    vector<Patient> patients;//vector declaration
    ifstream PatFile("patient data.txt");

    if (!PatFile.is_open()) {
        displayErrorMessage("\n\tError opening the file");//error message if file not open
        return patients;
    }

    string line;
    //read line by line until all the data found
    while (getline(PatFile, line)) {
        Patient patient;  // Create a new Patient object
        istringstream iss(line);

        getline(iss, patient.patientName, ';');
        iss >> patient.patientUserName
            >> patient.patientContactNumber
            >> patient.patientEmailAddress
            >> patient.patientHashedPassword;

        patients.push_back(patient);  // Add the new patient to the vector
    }

    PatFile.close();

    return patients; // return patient vector
}
vector<Appointment> readAppointmentFile() {

    vector<Appointment> appointments;//vector declaration
    ifstream AppFile("appointment data.txt");

    if (!AppFile.is_open()) {
        displayErrorMessage("\n\tError opening the file");//error message if file not open
        return appointments;
    }

    string line;
    //read line by line until all the data found
    while (getline(AppFile, line)) {
        Appointment appointment;  // Create a new Appointment object
        istringstream iss(line);

        getline(iss, appointment.appointmentNumber, ';');
        getline(iss, appointment.appointmentDoctor, ';');
        getline(iss, appointment.appointmentPatient, ';');
        getline(iss, appointment.appointmentPatientContact, ';');
        getline(iss, appointment.appointmentDate, ';');
        getline(iss, appointment.appointmentTime, ';');
        getline(iss, appointment.appointmentStatus, ' ');

        appointments.push_back(appointment);  // Add the new appointment to the vector
    }

    AppFile.close();

    return appointments; //return appointment vector
}
vector<Record> readRecordFile(){

    vector<Record> records;//vector declaration
    ifstream RecFile("patient record data.txt");

    if (!RecFile.is_open()) {
        displayErrorMessage("\n\tError opening the file");//error message if file not open
        return records;
    }


    string line;
    //read line by line until all the data found
    while (getline(RecFile, line)) {
        Record record;  // Create a new record object
        istringstream iss(line);

        getline(iss, record.recordPatientName, ';');
        getline(iss, record.diagnosisReport, ';');
        getline(iss, record.medicationsReport, ';');
        getline(iss, record.recommendationsReport, ';');

        records.push_back(record);  // Add the new medical record to the vector
    }

    RecFile.close();

    return records; // return records vector
}


// functions to avoid overlap patient and doctors
bool patientExists(string& name, string& username) {
    vector<Patient> patients = readPatientFile();

    for (Patient& patient : patients) {
        if (patient.patientUserName == username || patient.patientName == name) {
            displayErrorMessage("\n\tSign up failed. Patient already exist ! \n\n");
            Sleep(1000);
            system("cls");
            return true; // Patient already exists
        }
    }
    return false; // No patient found with the given username
}
bool doctorExists(string& name, string& username) {
    vector<Doctor> doctors = readDoctorFile();

    for (Doctor& doctor : doctors) {
        if (doctor.doctorUserName == username || doctor.doctorName == name) {
            displayErrorMessage("\n\tSign up failed. Doctor already exist ! \n\n");
            Sleep(1000);
            system("cls");
            return true; // doctor already exists
        }
    }
    return false; // No doctor found with the given username
}


//patient and doctor signup functions
void patientSignUp() {
    vector<Patient> patients;
    string username, name, password, contactNumber, emailAdd;

    cout << "\n\tEnter Your name: ";
    cin.ignore(); // Clear the buffer
    getline(cin, name);

    // Contact number validation
    do {
        cout << "\tEnter Your Contact number: ";
        getline(cin, contactNumber);
        if (!isValidContactNumber(contactNumber)) {
            displayErrorMessage("\n\tInvalid contact number. Please enter a 10-digit number starting with 0.\n\n");
        }
    } while (!isValidContactNumber(contactNumber));

    // Email address validation
    do {
        cout << "\tEnter Your Email Address: ";
        getline(cin, emailAdd);
        if (!isValidEmailAddress(emailAdd)) {
            displayErrorMessage("\n\tInvalid email address. Please include an '@' in the email address.\n\n");
        }
    } while (!isValidEmailAddress(emailAdd));

    cout << "\n\tEnter username: ";
    cin >> username;

    cout << "\tEnter password: ";
    cin >> password;

    if(!patientExists(name, username)){

        Patient newPatient; // Create a new patient object

        newPatient.patientName = name;
        newPatient.patientUserName = username;
        newPatient.patientContactNumber = contactNumber; // Assign valid contact number
        newPatient.patientEmailAddress = emailAdd; // Assign valid email address
        newPatient.patientHashedPassword = Hash(password); // Hash the password

        patients.push_back(newPatient); // Add new patient to the vector

        cout << "\n\t\t    ";
        sleepDelay(); // Delay function
        displayFactMessage("-> Patient signed up successfully!\n");
        writePatientFile(patients); // Write the data into the file
        Sleep(1000);
        system("cls");
    }
}
void doctorSignUp(){
    vector<Doctor> doctors;
    string name, username, password;

    cout << "\n\tEnter your name : ";
    cin.ignore(); // clear the buffer
    getline(cin,name);

    cout << "\n\tEnter username: ";
    cin >> username;

    cout << "\tEnter password: ";
    cin >> password;

    if (!doctorExists(name, username)){
        Doctor newDoctor; // create a new patient object

        newDoctor.doctorName = name;
        newDoctor.doctorUserName = username;
        newDoctor.doctorHashedPassword = Hash(password); // hashed the password which doctor input

        doctors.push_back(newDoctor); // add new doctor to a vector
        cout << "\n\t\t    ";

        sleepDelay(); // delay function
        displayFactMessage("-> Doctor signed up successfully !\n");
        Sleep(1000);
        writeDoctorFile(doctors);
        //write the data into the file
        system("cls"); // clear the console
    }
}


//patient's functions
void availableDoctors(){
    //read the data from files and save into the vectors
    vector<Doctor> doctors = readDoctorFile();
    vector<Appointment> appointments = readAppointmentFile();

    bool appointmentFound = false;
    bool doctorFound = false;

    cout << "\n=================================================================================\n" << endl;
    cout << "\tAvailable Doctors : \n\n";
    for(Doctor& doctor : doctors) // checking doctors one by one
    {
        doctorFound = true; // display available doctors
        cout << "\t\t\t" << doctor.doctorName << "\t\t" << doctor.doctorUserName << endl;
    }

    if(!doctorFound){
        //error message to if no doctors in there
        displayErrorMessage("\t\t\tThere are no available doctors !\n");
    }
    cout << "\n=================================================================================\n" << endl;
    cout << "\tTheir Appointments : \n" << endl;

        cout << "---------------------------------------------------------------------------------" << endl;
        for(Appointment& appointment : appointments){
            if (appointment.appointmentStatus == "PENDING"){
                appointmentFound = true;
                //upcoming appointments of all the doctors
                cout << " " << appointment.appointmentNumber
                        << " Doctor " << appointment.appointmentDoctor << "\'s Appointment"
                        << "     Date : " << appointment.appointmentDate
                        << "     Time : " << appointment.appointmentTime << endl;
                cout << "---------------------------------------------------------------------------------" << endl;
            }
          }
    if (!appointmentFound){
        //message for if their is no appointments
        displayErrorMessage("\t\t\t  There are no appointments...\n");
        cout << "---------------------------------------------------------------------------------" << endl;
    }
    cout << "\n=================================================================================" << endl;
}
void scheduleAppointment(string& userName, Patient& patient) {
    //read the data from files and save into the vectors
    vector<Doctor> doctors = readDoctorFile();
    vector<Appointment> appointments = readAppointmentFile();

    string time, date, docName;
    bool doctorFound = false;
    bool overlappingDoctor = false;
    bool overlappingPatient = false;

    //input date and time from patient
    cout << "\tEnter Appointment Time (HH:MM): ";
    cin >> time;
    while (!isValidTime(time)) {
        displayErrorMessage("\n\tInvalid time format. Please enter time in HH:MM format\n");
        cin >> time;
    }

    cout << "\tEnter Appointment Date (DD/MM/YYYY): ";
    cin >> date;
    while (!isValidDate(date)) {
        displayErrorMessage("\n\tInvalid date format. Please enter date in DD/MM/YYYY format\n");
        cin >> date;
    }


    for (Doctor& doctor : doctors) {
            //checking weather doctor's name valid or not
        if (userName == doctor.doctorUserName) {
            docName = doctor.doctorName;
            doctorFound = true;
            break;
        }
    }

    if (!doctorFound) {
            //if its invalid showing this message
        displayErrorMessage("\n\t\t\t  Invalid Doctor user name !\n");
        cout << "\n=================================================================================\n" << endl;
        return;
    }

    for (Appointment& appointment : appointments) {
        if (docName == appointment.appointmentDoctor && date == appointment.appointmentDate && time == appointment.appointmentTime) {
            //check this doctor has same appointment date and time
            overlappingDoctor = true;
            break;
        }
        if (patient.patientName == appointment.appointmentPatient && date == appointment.appointmentDate && time == appointment.appointmentTime) {
            //check this patient has another appointment with other doctor
            overlappingPatient = true;
            break;
        }
    }

    if (overlappingDoctor) {
            //message of if doctor has appointment
        cout << "\n\t\t  Doctor already has an appointment at this time" << endl;
        cout << "\n=================================================================================\n" << endl;
        return;
    }

    if (overlappingPatient) {
            //message of if patient has another doctor appointment
        cout << "\n\tYou already has an appointment at this time with another doctor !" << endl;
        cout << "\n=================================================================================\n" << endl;
        return;
    }

    if (!overlappingDoctor && !overlappingPatient){
            //if appointments are not overlapping save the appointment into the file
        Appointment newAppointment;
        newAppointment.appointmentNumber = to_string(appointments.size() + 1);
        newAppointment.appointmentDoctor = docName;
        newAppointment.appointmentPatient = patient.patientName;
        newAppointment.appointmentPatientContact = patient.patientContactNumber;
        newAppointment.appointmentDate = date;
        newAppointment.appointmentTime = time;
        newAppointment.appointmentStatus = "PENDING";

        Sleep(1000);
        //appointment summery
        cout << "\n---------------------------------------------------------------------------------\n" << endl;
        cout << "\t\t\t   Appointment Summary: " << endl;
        cout << "\n\t\t   Patient Name: " << newAppointment.appointmentPatient
             << "\n\t\t   Doctor's Name: " << newAppointment.appointmentDoctor
             << "\n\t\t   Appointment Time: " << newAppointment.appointmentTime
             << "\n\t\t   Appointment Date: " << newAppointment.appointmentDate << endl;
        cout << "\n---------------------------------------------------------------------------------\n" << endl;

        appointments.push_back(newAppointment); // add new appointment into the appointments vector
        writeAppointmentFile(appointments); // save this vector to the file
        displayFactMessage("\t\t The doctor has been successfully appointed !\n");
        cout << "\n=================================================================================\n" << endl;
    }
}
void viewMedicalRecord(Patient& patient) {
    //read the data from files and save into the vectors
    vector<Appointment> appointments = readAppointmentFile();
    vector<Patient> updatePatients = readPatientFile();

    bool hasUpcomingAppointments = false;
    bool hasPreviousAppointments = false;

    for(Patient& updatePatient : updatePatients){
        if(patient.patientName == updatePatient.patientName){
            //show the logged patient information
            cout << "\n=================================================================================\n" << endl;
            cout << "\t\t\tPatient's informations" << endl;
            cout << "\n\t\tName :\t\t\t" << patient.patientName << endl;
            cout << "\t\tContact number :\t" << updatePatient.patientContactNumber << endl;
            cout << "\t\tEmail address :\t\t" << updatePatient.patientEmailAddress << endl;
            cout << "\n=================================================================================\n" << endl;

        }
    }
    // check weather Upcoming Appointments has or not
    for (Appointment& appointment : appointments) {
        if (patient.patientName == appointment.appointmentPatient && appointment.appointmentStatus != "OK") {
            hasUpcomingAppointments = true;
        }
    }
    if (hasUpcomingAppointments){
            //if has upcoming appointments show appointments
        cout << "\tUpcoming appointments\n" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        for (Appointment& appointment : appointments) {
            if (patient.patientName == appointment.appointmentPatient && appointment.appointmentStatus != "OK") {
                cout << "  Doctor " << appointment.appointmentDoctor << "\'s Appointment"
                     << "     Date : " << appointment.appointmentDate
                     << "     Time : " << appointment.appointmentTime << endl;
                cout << "---------------------------------------------------------------------------------" << endl;
            }
        }
    }

    if (!hasUpcomingAppointments) {
            //if not has upcoming appointments show this message
        cout << "---------------------------------------------------------------------------------" << endl;
        displayErrorMessage("\t\tYou have no upcoming appointments !\n");
        cout << "---------------------------------------------------------------------------------" << endl;
    }
    cout << "\n=================================================================================\n" << endl;


    for (Appointment& appointment : appointments) {
            // check weather Previous Appointments has or not
        if (patient.patientName == appointment.appointmentPatient && appointment.appointmentStatus == "OK") {
            hasPreviousAppointments = true;
        }
    }
    if (hasPreviousAppointments){
            //if has previous appointments, show appointments
        cout << "\tPrevious appointments\n" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        for (Appointment& appointment : appointments) {
            if (patient.patientName == appointment.appointmentPatient && appointment.appointmentStatus == "OK") {
                cout << "  Doctor " << appointment.appointmentDoctor << "\'s Appointment"
                     << "     Date : " << appointment.appointmentDate
                     << "     Time : " << appointment.appointmentTime << endl;
                cout << "---------------------------------------------------------------------------------" << endl;
            }
        }
    }

    if (!hasPreviousAppointments) {
            //if has previous appointments show appointments
        cout << "---------------------------------------------------------------------------------" << endl;
        displayErrorMessage("\t\tYou have no previous appointments !\n");
        cout << "---------------------------------------------------------------------------------" << endl;
    }
    cout << "\n=================================================================================\n" << endl;
}
void updatePatientData(Patient& patientUpdate) {
    //read the data from files and save into the vectors
    vector<Patient> patients = readPatientFile();
    vector<Appointment> appointments = readAppointmentFile();

    bool patientFound = false;
    string newContactNumber;
    string newEmailAddress;

    for (Patient& patient : patients) {
            //check weather patient's name who login to the system and saved patient's name equal or not
        if (patientUpdate.patientName == patient.patientName) {
            patientFound = true;
                    //contact number validation
                    cin.ignore(); // clear the buffer
                    do {
                        cout << "\tEnter Your Contact number: ";
                        getline(cin, newContactNumber);
                        if (!isValidContactNumber(newContactNumber)) {
                            displayErrorMessage("\n\tInvalid contact number. Please enter a 10-digit number starting with 0.\n\n");
                        }
                    } while (!isValidContactNumber(newContactNumber));
                    // Email address validation
                    do {
                        cout << "\tEnter Your Email Address: ";
                        getline(cin, newEmailAddress);
                        if (!isValidEmailAddress(newEmailAddress)) {
                            displayErrorMessage("\n\tInvalid email address. Please include an '@' in the email address.\n\n");
                        }
                    } while (!isValidEmailAddress(newEmailAddress));
                    patient.patientContactNumber = newContactNumber; // Assign valid contact number
                    patient.patientEmailAddress = newEmailAddress; // Assign valid contact number

                    ofstream patientFile("patient data.txt");
                    //update patient's contact details in patient's detail file
                    if (patientFile.is_open()) {
                        for (const Patient& updatedPatient : patients) {
                            patientFile << updatedPatient.patientName
                                        << ";" << updatedPatient.patientUserName
                                        << " " << updatedPatient.patientContactNumber
                                        << " " << updatedPatient.patientEmailAddress
                                        << " " << updatedPatient.patientHashedPassword
                                        << endl;
                        }
                        patientFile.close();
                        cout << "\n\t\t";
                        sleepDelay();
                        displayFactMessage("-> Successfully saved your data\n");
                    }
                    else {
                            //error message if not opening the relevant file
                        displayErrorMessage("\n\tError opening file for saving data.\n");
                    }

                    for (Appointment& appointment : appointments){
                        if (appointment.appointmentPatient == patient.patientName){
                            appointment.appointmentPatientContact = newContactNumber;
                            //update patient's contact details in appointment detail file
                            ofstream appointmentFile("appointment data.txt");

                            if (appointmentFile.is_open()) {
                                for (const Appointment& updatedAppointment : appointments) {
                                    appointmentFile << updatedAppointment.appointmentNumber << ";"
                                                    << updatedAppointment.appointmentDoctor << ";"
                                                    << updatedAppointment.appointmentPatient << ";"
                                                    << updatedAppointment.appointmentPatientContact << ";"
                                                    << updatedAppointment.appointmentDate << ";"
                                                    << updatedAppointment.appointmentTime << ";"
                                                    << updatedAppointment.appointmentStatus
                                                    << endl;
                                }
                                appointmentFile.close();
                            }
                            else {
                                    //error message if not opening the relevant file
                                displayErrorMessage("\n\tError opening file for saving data.\n");
                            }
                        }
                    }
            }
    }

    if (!patientFound) {
            //error message if not available patients
        displayErrorMessage("\n\t\t\tPatient not found.\n");
    }
}
void cancelAppointment(Patient& patient) {
    string decision;
    string confirm;
    bool hasUpcomingAppointments = false;

    //read the data from files and save into the vectors
    vector<Appointment> appointments = readAppointmentFile();


    cout << "\n=================================================================================\n" << endl;
    cout << "\tUpcoming appointments\n" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    for (Appointment& appointment : appointments) {
        if (patient.patientName == appointment.appointmentPatient && appointment.appointmentStatus != "OK") {
            //checking and showing upcoming appointments
            hasUpcomingAppointments = true;
            cout << "  " << appointment.appointmentNumber
                 << "  Doctor " << appointment.appointmentDoctor << "\'s Appointment"
                 << "     Date : " << appointment.appointmentDate
                 << "     Time : " << appointment.appointmentTime << endl;
            cout << "---------------------------------------------------------------------------------" << endl;
        }
    }
    if (!hasUpcomingAppointments) {
            //if their is no upcoming appointment, show this message
        displayErrorMessage("\t\tYou have no upcoming appointments !\n");
        cout << "---------------------------------------------------------------------------------" << endl;
    }

    if (hasUpcomingAppointments){
            //if has upcoming appointments
        cout << "   Enter appointment number to cancel the appointment : ";
        cin >> decision;

        // Find the selected appointment and save it to selected
        auto selected = find_if(appointments.begin(), appointments.end(),
                      [&decision](Appointment& a) {
                          return a.appointmentNumber == decision && a.appointmentStatus == "PENDING";
                      });


        if (selected != appointments.end()) {
            cout << "   Enter '1' to confirm your decision or Enter any number to abort: ";
            cin >> confirm;

            if (confirm == "1") {
                appointments.erase(selected); // Erase the appointment if confirmed
                displayFactMessage("\n\t\tAppointment canceled successfully !\n");
                // Save the updated appointments to file
                vector<Appointment> updateAppointments;
                for (Appointment& appointment : appointments){

                Appointment newAppointment;
                newAppointment.appointmentNumber = to_string(updateAppointments.size() + 1);
                newAppointment.appointmentDoctor = appointment.appointmentDoctor;
                newAppointment.appointmentPatient = appointment.appointmentPatient;
                newAppointment.appointmentPatientContact = appointment.appointmentPatientContact;
                newAppointment.appointmentDate = appointment.appointmentDate;
                newAppointment.appointmentTime = appointment.appointmentTime;

                //when we rewrite appointment file we should update separately weather it's status "pending" or "ok"
                 if (appointment.appointmentStatus == "PENDING"){
                    newAppointment.appointmentStatus = "PENDING";
                }
                else{
                    newAppointment.appointmentStatus = "OK";
                }

                //new appointment add to the update appointment vector
                updateAppointments.push_back(newAppointment);
                }
                //write updated appointment into the file
                writeAppointmentFile(updateAppointments);

            } else {
                //if patient want to exit from cancel appointment show this message
                displayErrorMessage("\n\t\tTask aborted successfully.\n");
            }
        } else {
            //if appointment number is not matched show this message
            displayErrorMessage("\n\tInvalid appointment number of the appointment is not pending.\n");
        }

    }

    cout << "\n=================================================================================\n" << endl;
}


//doctor's functions
void viewSchedule(Doctor& doctor) {
    //read the data from files and save into the vectors
    vector<Appointment> appointments = readAppointmentFile();
    bool hasAppointments = false;

    cout << "\n=================================================================================\n" << endl;
    cout << "\tUpcoming Appointments\n" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    for (Appointment& appointment : appointments) {
        if (appointment.appointmentDoctor == doctor.doctorName && appointment.appointmentStatus != "OK") {
            hasAppointments = true;
            //display upcoming appointments if available
            cout << "\tPatient " << appointment.appointmentPatient << "\'s Appointment\n"
                    << "\tContact Number: " << appointment.appointmentPatientContact
                    << "   Date: " << appointment.appointmentDate
                    << "   Time: " << appointment.appointmentTime << endl;
            cout << "---------------------------------------------------------------------------------" << endl;
        }
    }

    if (!hasAppointments) {
            //if has not upcoming appointments display this message
        displayErrorMessage("\t\t\tNo upcoming appointments !\n");
        cout << "---------------------------------------------------------------------------------" << endl;
    }
    cout << "\n=================================================================================\n" << endl;
}
void accessPatientRecord(Doctor& doctor){
    //read the data from files and save into the vectors
    vector<Record> records = readRecordFile();
    vector<Appointment> appointments = readAppointmentFile();
    vector<Patient> patients = readPatientFile();

    string name;
    bool appointmentFound = false;
    bool hasAppointment = false;

    cout << "\n=================================================================================\n" << endl;
    cout << "\tAvailable Patients :\n\n";
    for (Appointment& appointment : appointments){
        for (Record& record : records){
            if (doctor.doctorName == appointment.appointmentDoctor){
                //check weather the appointment's doctor name equal to doctor's name who has login the system or not
                hasAppointment = true;
            }
        }
    }
    if(!hasAppointment){
            //if their is no medical history, display this message
        displayErrorMessage("\t\tThere are no Patient's medical history !\n");
    }

    if(hasAppointment){
        for (Appointment& appointment : appointments){
            for (Record& record : records){
                if (doctor.doctorName == appointment.appointmentDoctor
                    && appointment.appointmentPatient == record.recordPatientName){
                        //display medical record patient's which are related to relevant doctor
                    cout << "\t\t\t" << record.recordPatientName << endl;
                }
            }
        }
    }

    if (hasAppointment){
            //showing patient's medical records
        cout << "\n=================================================================================\n" << endl;
        cout << "   Enter patient's name : ";
        cin.ignore();
        getline(cin,name);

        cout << "\n---------------------------------------------------------------------------------" << endl;

        for (Record& record : records)
        {
            if (name == record.recordPatientName)
            {
                appointmentFound = true;
                cout << "\t " << record.recordPatientName << "\'s Medical History\n" << endl;
                cout << "\t\tDiagnosis : " << record.diagnosisReport << endl;
                cout << "\t\tPrescibed Medications : " << record.medicationsReport << endl;
                cout << "\t\tAdditional Recommendations : " << record.recommendationsReport << endl;
                cout << "---------------------------------------------------------------------------------" << endl;
            }
        }
        if (!appointmentFound){
                //error message of patient's name didn't exist
            displayErrorMessage("\t\t\tInvalid Patient's name !\n");
            cout << "---------------------------------------------------------------------------------" << endl;
        }

    }
    cout << "\n=================================================================================\n" << endl;
}
void updatePatientRecord(Doctor& doctor) {
    //read the data from files and save into the vectors
    vector<Appointment> appointments = readAppointmentFile();
    vector<Record> records = readRecordFile();
    string name, diagnosis, medication, recommendation;
    bool appointmentFound = false;
    bool recordUpdated = false;
    bool hasAppointment = false;

    cout << "\n=================================================================================\n" << endl;
    cout << "\tAvailable Patients :\n\n";
    for (Appointment& appointment : appointments) {
        if (doctor.doctorName == appointment.appointmentDoctor && appointment.appointmentStatus == "OK") {
            hasAppointment = true;
            //display patients of completed appointments by doctor
            cout << "\t\t\t" << appointment.appointmentPatient << endl;
        }
    }
    if (!hasAppointment){
            //display message for their is no available medical history
        displayErrorMessage("\t\t  There are no Patient's medical history \n");
        displayErrorMessage("\n   Note *If the appointment is over, Update the Appointment as complete !\n");
    }

    if (hasAppointment){
            //taking patient name for update their medical record
        cout << "\n=================================================================================\n" << endl;
        cout << "   Enter patient's name for update their medical history: ";
        cin.ignore();
        getline(cin, name);
        //update their data
        cout << "\n\tEnter patient's Diagnosis: ";
        getline(cin, diagnosis);
        cout << "\tEnter patient's Prescribed Medications: ";
        getline(cin, medication);
        cout << "\tEnter patient's Additional Recommendations: ";
        getline(cin, recommendation);

        for (Appointment& appointment : appointments) {
            if (appointment.appointmentPatient == name && appointment.appointmentDoctor == doctor.doctorName) {
                appointmentFound = true;

                for (Record& record : records) {
                    if (name == record.recordPatientName) {
                            //checking weather input name equal to record's patient name or not
                        record.diagnosisReport = diagnosis;
                        record.medicationsReport = medication;
                        record.recommendationsReport = recommendation;
                        recordUpdated = true;
                        break;
                    }
                }

                if (!recordUpdated) {
                    // if not equal to the medical records. then create new record
                    Record newRecord;
                    newRecord.recordPatientName = name;
                    newRecord.diagnosisReport = diagnosis;
                    newRecord.medicationsReport = medication;
                    newRecord.recommendationsReport = recommendation;
                    records.push_back(newRecord); // add new record into
                }
                break;
            }
        }

        if (!appointmentFound) {
                //display the message if not found the appointment with the doctor
            displayErrorMessage("\n\t   No appointment found for this patient with the doctor !\n");
        } else {
            // Write the updated records back to the file
            writeRecordFile(records);
            cout << "\n\t\t";
            sleepDelay();
            displayFactMessage("-> Patient record updated successfully !\n");
        }
    }

    cout << "\n=================================================================================\n" << endl;
}
void markAppointment(Doctor& doctor) {
    //read the data from files and save into the vectors
    vector<Appointment> appointments = readAppointmentFile();
    string appNumber;
    bool appointmentFound = false;
    bool pendingAppointment = false;

    cout << "\n=================================================================================\n" << endl;
    cout << "\tPending Appointments\n" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    for (Appointment& appointment : appointments) {
        if (doctor.doctorName == appointment.appointmentDoctor && appointment.appointmentStatus == "PENDING") {
            pendingAppointment = true;
            cout << "   " << appointment.appointmentNumber
                << "   Patient " << appointment.appointmentPatient << "\'s Appointment\n"
                << "\tContact Number: " << appointment.appointmentPatientContact
                << "   Date: " << appointment.appointmentDate
                << "   Time: " << appointment.appointmentTime << endl;
            cout << "---------------------------------------------------------------------------------" << endl;
        }
    }

    if (!pendingAppointment){
        cout << "\t\tYou haven't any pending Appointments !" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
    }

    if (pendingAppointment){
        cout << "\n=================================================================================\n" << endl;
        cout << "   Enter the appointment number to mark as complete: ";
        cin >> appNumber;

        for (Appointment& appointment : appointments) {
            if (appNumber == appointment.appointmentNumber && appointment.appointmentStatus == "PENDING") {
                appointment.appointmentStatus = "OK";
                cout << "\n\t\t";
                sleepDelay();
                displayFactMessage("-> Appointment marked as complete !\n");
                appointmentFound = true;
                break;
            }
        }

        if (!appointmentFound) {
            cout << "\n=================================================================================\n" << endl;
            displayErrorMessage("\t\tAppointment number not found or not pending !\n");
        } else {
            writeAppointmentFile(appointments);
        }

    }
    cout << "\n=================================================================================\n" << endl;
}


//services functions
void patientServices(Patient& patient){

    string decision;
    string appDocName;

    while(true)
    {
        //patient services menu
        patientServicesMenu();
        cin >> decision;

        if (decision == "1"){
            system("cls");
            //view medical records function
            viewMedicalRecord(patient);
            cout << "\n\n(Press Enter)";
            getch(); // taking any number
            system("cls");
        }
        else if (decision == "2"){
            system("cls");
            // show available doctors and their appointments functions
            availableDoctors();
            cout << "\n\tEnter username of doctor : ";
            cin >> appDocName;
            scheduleAppointment(appDocName, patient);
            cout << "\n\n(Press Enter)";
            getch(); // taking any number
            system("cls");
        }
        else if (decision == "3"){
            system("cls");
            //cancel appointment function
            cancelAppointment(patient);
            cout << "\n\n(Press Enter)";
            getch();
            system("cls");
        }
        else if (decision == "4"){
                //update patient data function
            updatePatientData(patient);
            cout << "\n\n(Press Enter)";
            getch(); // taking any number
            system("cls");
        }
        else if (decision == "5"){
                //exit option
            cout << "\n\t\t\t\t";
            sleepDelay();
            displayFactMessage("-> Exiting\n");
            Sleep(1000);
            system("cls");
            return;
        }
        else{
            //display error message when user entered wrong input
            displayErrorMessage("\n\t\tInvalid choice. Please try again.\n");
            Sleep(1500);
            system("cls");
        }
    }

}
void doctorServices(Doctor& doctor){
    string decision;

    while(true)
    {
        //display doctor's services menu
        doctorServicesMenu();
        cin >> decision;

        if (decision == "1"){
            system("cls");
            //view schedule function
            viewSchedule(doctor);
            cout << "\n\n(Press Enter)";
            getch();
            system("cls");
        }
        else if(decision == "2"){
            system("cls");
            //access patient record function
            accessPatientRecord(doctor);
            cout << "\n\n(Press Enter)";
            getch();
            system("cls");
        }
        else if (decision == "3"){
            system("cls");
            //update patient record function
            updatePatientRecord(doctor);
            cout << "\n\n(Press Enter)";
            getch();
            system("cls");
        }
        else if (decision == "4"){
            system("cls");
            //function of mark appointment as completed
            markAppointment(doctor);
            cout << "\n\n(Press Enter)";
            getch();
            system("cls");
        }
        else if (decision == "5"){
            cout << "\n\t\t\t\t";
            sleepDelay();
            //exit function
            displayFactMessage("-> Exiting\n");
            Sleep(1000);
            system("cls");
            return;
        }
        else {
                //display error message when user entered wrong input
            displayErrorMessage("\n\t\tInvalid choice. Please try again.\n");
            Sleep(1500);
            system("cls");
        }
    }
}


//login functions
bool patientLogIn(){
    //read the data from files and save into the vectors
    vector<Patient> patients = readPatientFile();
    string username;

    cout << "\n\tEnter username: ";
    cin >> username;

    //taking password using getPassword function
    string password = getPassword();

    //hash the password which input from user
    unsigned int hashedPassword = Hash(password);

    //check password and userName equal to the stored userName and password
    for (Patient& patient : patients)
    {
        if (patient.patientUserName == username && patient.patientHashedPassword == hashedPassword)
        {
            cout << "\n\t\t\t";
            sleepDelay();
            displayFactMessage("-> Login successful !\n");
            Sleep(1000);
            system("cls");
            //if successfully login go to the patient services function
            patientServices(patient);
            return true;
        }
    }
    //if user credentials are invalid show this message
    displayErrorMessage("\n\t\tLogin failed !!! Invalid username or password !\n");
    Sleep(1500);
    system("cls");
    return false;
}
bool doctorLogIn(){
    //read the data from files and save into the vectors
    vector<Doctor> doctors = readDoctorFile();
    string username;

    cout << "\n\tEnter username: ";
    cin >> username;

    //taking password using getPassword function
    string password = getPassword();

    //hash the password which input from user
    unsigned int hashedPassword = Hash(password);

    //check password and userName equal to the stored userName and password
    for ( Doctor& doctor : doctors)
    {
        if (doctor.doctorUserName == username && doctor.doctorHashedPassword == hashedPassword)
        {
            cout << "\n\t\t\t";
            sleepDelay();
            displayFactMessage("-> Login successful !\n");
            Sleep(1000);
            system("cls");
            //if successfully login go to the doctor services function
            doctorServices(doctor);
            return true;
        }
    }

    //if user credentials are invalid show this message
    displayErrorMessage("\n\t\tLogin failed. Invalid username or password !\n");
    Sleep(1500);
    system("cls");
    return false;
}


//home functions
void patientHome(){

    while(true)
    {

        string decision;
        //display patients menu
        patientMenu();
        cin >> decision;

        if (decision == "1"){
                //patient sign up function
            patientSignUp();
        }
        else if (decision == "2"){
                //patient log in function
            patientLogIn();
        }
        else if (decision == "3"){
            cout << "\n\t\t\t\t";
            sleepDelay();
                //exit from home
            displayFactMessage("-> Exiting\n");
            Sleep(1500);
            system("cls");
            return;
        }
        else {
                //display error message when decision is not valid
            displayErrorMessage("\n\n\t\tInvalid choice. Please try again !\n");
            Sleep(1500);
            system("cls");
        }
    }
}
void doctorHome(){

    while(true)
    {
        string decision;
        doctorMenu();
        cin >> decision;

        if (decision == "1"){
                //doctor sign up function
            doctorSignUp();
        }
        else if (decision == "2"){
                //doctor log in function
            doctorLogIn();
        }
        else if (decision == "3"){
            cout << "\n\t\t\t\t";
            sleepDelay();
                //exit function
            displayFactMessage("-> Exiting\n");
            Sleep(1500);
            system("cls");
            return;
        }
        else{
                //display error message when decision is not valid
            displayErrorMessage("\n\t\tInvalid choice. Please try again !\n");
            Sleep(1500);
            system("cls");
        }

    }
}


//main function
int main(){
    while (true)
    {
        //show clinic management home menu
        clinicManagementSystemHome();
        string decision;
        cin >> decision;

        if (decision == "1"){
            system("cls");
            //patient home function
            patientHome();
        }
        else if (decision == "2"){
            system("cls");
            //doctor home function
            doctorHome();
        }
        else if (decision == "3"){
            cout << "\n\t\t\t";
            sleepDelay();
            //exit from the system
            displayFactMessage("-> Exiting Programm\n");
            cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" <<endl;
            Sleep(2000);
            return 0;
        }
        else{
                //display error message when decision is not valid
            displayErrorMessage("\n\t\tInvalid choice. Please try again !");
            Sleep(1500);
            system("cls");
        }
    }

    return 0;
}
