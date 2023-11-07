import sqlite3
import csv
import random

conn = sqlite3.connect('/Users/lisahisamura/Downloads/CPSC408/StudentDB.db')
mycursor = conn.cursor()

student_advisors = ["Eric Chimenti", "Claudine Jaenichen", "Andrew Shalat", "Kathleen Kaiser", "Adriana Falcon"]

mycursor.execute("DELETE FROM Student")
conn.commit()

# a. Import the students.csv file
def generate_csv():
    with (open('/Users/lisahisamura/Downloads/CPSC408/students.csv', 'r') as file):
        csvreader = csv.DictReader(file)

        for row in csvreader:
          sql = "INSERT INTO Student(FirstName, LastName, Address, City, State, ZipCode, MobilePhoneNumber, Major, GPA, FacultyAdvisor, isDeleted) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
          val = (
                row['FirstName'],
                row['LastName'],
                row['Address'],
                row['City'],
                row['State'],
                row['ZipCode'],
                row['MobilePhoneNumber'],
                row['Major'],
                row['GPA'],
                random.choice(student_advisors),
                0
          )

          mycursor.execute(sql, val)

        conn.commit()

    print('data import complete')


# b. Display All Students and all of their attributes
def display_students():
    mycursor.execute("SELECT FirstName, LastName, GPA, Major, FacultyAdvisor, Address, City, State, ZipCode, MobilePhoneNumber FROM Student WHERE isDeleted = 0")
    rows = mycursor.fetchall()
    for row in rows:
        print(row)
    # mycursor.close()

# c. Add New Students
# All attributes are required when creating a new student.
# Please make sure to validate user input appropriately.


def add_student():
    while True:
        try:
            first_name = str(input("Enter first name: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break

    while True:
        try:
            last_name = str(input("Enter last name: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break

    while True:
        try:
            gpa = float(input("Enter GPA: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break

    while True:
        try:
            major = str(input("Enter major: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break


    while True:
        try:
            address = str(input("Enter address: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break

    while True:
        try:
            city = str(input("Enter city: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break

    while True:
        try:
            state = str(input("Enter state: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break

    while True:
        try:
            zip_code = str(input("Enter zip code: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break

    while True:
        try:
            mobile_phone_number = str(input("Enter mobile phone number: "))
        except ValueError:
            print("Please try again.")
            continue
        else:
            break

    mycursor.execute("INSERT INTO Student('FirstName', 'LastName', 'GPA', 'Major', 'FacultyAdvisor', 'Address', 'City', 'State', 'ZipCode', 'MobilePhoneNumber', 'isDeleted') VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", (first_name, last_name, gpa, major, random.choice(student_advisors), address, city, state, zip_code, mobile_phone_number, 0))
    #
    conn.commit()
    print('Created new record in the Student table.')
#
# # d. Update Students (only Major, Advisor, MobilePhoneNumber can be updated)

def update_student():
    studentExists = False
    while studentExists == False:

        updating_first_name = input("Enter student's first name of student record you would like to update: ")
        updating_last_name = input("Enter student's last name of student record you would like to update: ")

        mycursor.execute("SELECT * FROM Student WHERE FirstName = ? AND LastName = ?", (updating_first_name, updating_last_name))
        existing_student = mycursor.fetchone()


        if existing_student:

            while True:
                try:
                    new_major = str(input("Enter new major: "))
                except ValueError:
                    print("Please try again.")
                    continue
                else:
                    break

            while True:
                try:
                    new_faculty_advisor = str(input("Enter new faculty advisor: "))
                except ValueError:
                    print("Please try again.")
                    continue
                else:
                    break

            while True:
                try:
                    new_mobile_phone_number = str(input("Enter new mobile phone number: "))
                except ValueError:
                    print("Please try again.")
                    continue
                else:
                    break

            mycursor.execute("UPDATE Student SET Major = ?, FacultyAdvisor = ?, MobilePhoneNumber = ? WHERE FirstName = ? AND LastName = ?", (new_major, new_faculty_advisor, new_mobile_phone_number, updating_first_name, updating_last_name,))


            conn.commit()
            print('record updated')
            studentExists = True
            break
        else:
            print('Student not found')
#
# # e. Delete students by StudentID (set isDeleted to true)
def delete_student():
    studentExists = False;
    while studentExists == False:
        delete_first_name = input("Enter first name of student record you would like to delete: ")
        delete_last_name = input("Enter last name of student record you would like to delete: ")
        mycursor.execute("SELECT * FROM Student WHERE FirstName = ? AND LastName = ?",(delete_first_name, delete_last_name))
        existing_student = mycursor.fetchone()

        if existing_student:
            mycursor.execute("UPDATE Student SET isDeleted = 1 WHERE FirstName = ? AND LastName = ?", (delete_first_name, delete_last_name))
            conn.commit()
            print('Record student record deleted')
            studentExists = True
            break
        else:
            print('Student not found')

# f. Search/Display students by Major, GPA, City, State and Advisor
def search_student():
    valid_choice = False;
    while valid_choice == False:

        search_choice = input("Would you like to search by Major, GPA, City, State or Advisor?: ")
        if search_choice == "major" or search_choice == "Major":
            search_major = input("What major would you like to search?: ")
            mycursor.execute("SELECT FirstName, LastName, GPA, Major, FacultyAdvisor, Address, City, State, ZipCode, MobilePhoneNumber FROM Student WHERE Major = ?", (search_major,))
            conn.commit()
            rows = mycursor.fetchall()
            for row in rows:
                print(row)
            break
        elif search_choice == "gpa" or search_choice == "GPA":
            search_gpa = input("What GPA would you like to search?: ")
            mycursor.execute("SELECT FirstName, LastName, GPA, Major, FacultyAdvisor, Address, City, State, ZipCode, MobilePhoneNumber FROM Student WHERE GPA = ?", (search_gpa,))
            conn.commit()
            rows = mycursor.fetchall()
            for row in rows:
                print(row)
            break
        elif search_choice == "city" or search_choice == "City":
            search_city = input("What city would you like to search?: ")
            mycursor.execute("SELECT FirstName, LastName, GPA, Major, FacultyAdvisor, Address, City, State, ZipCode, MobilePhoneNumber FROM Student WHERE City = ?", (search_city,))
            conn.commit()
            rows = mycursor.fetchall()
            for row in rows:
                print(row)
            break
        elif search_choice == "state" or search_choice == "State":
            search_city = input("What state would you like to search?: ")
            mycursor.execute("SELECT FirstName, LastName, GPA, Major, FacultyAdvisor, Address, City, State, ZipCode, MobilePhoneNumber FROM Student WHERE State = ?", (search_state,))
            conn.commit()
            rows = mycursor.fetchall()
            for row in rows:
                print(row)
            break
        elif search_choice == "advisor" or search_choice == "Advisor":
            search_city = input("What advisor would you like to search?: ")
            mycursor.execute("SELECT FirstName, LastName, GPA, Major, FacultyAdvisor, Address, City, State, ZipCode, MobilePhoneNumber FROM Student WHERE Advisor = ?", (search_advisor,))
            conn.commit()
            rows = mycursor.fetchall()
            for row in rows:
                print(row)
            break
        else:
            print("Please enter a valid attribute.")


end_loop = False
while end_loop == False:
    print("Welcome to the student database! Here are your options: \n")
    print("a. Import the students.csv file.\n")
    print("b. Display all Students and all of their attributes.\n")
    print("c. Add a new student.\n")
    print("d. Update Students (only Major, Advisor, MobilePhoneNumber can be updated).\n")
    print("e. Delete students by StudentID.\n")
    print("f. Search/Display students by Major, GPA, City, State and Advisor.\n")

    user_option = input("Choose an option from the menu above: ")

    if user_option == 'a' or user_option == 'A':
        generate_csv()
    elif user_option == 'b' or user_option == 'B':
        display_students()
    elif user_option == 'c' or user_option == 'C':
        add_student()
    elif user_option == 'd' or user_option == 'D':
        update_student()
    elif user_option == 'e' or user_option == 'E':
        delete_student()
    elif user_option == 'f' or user_option == 'F':
        search_student()
    else:
        print("Please select an option from the menu.")
        continue

    willContinue = input("Would you like to continue or exit the application? Enter continue or exit: ")
    if willContinue == "exit" or willContinue == "Exit":
        end_loop = True
        break
