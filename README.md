# park-my-vehicle

Implements parking lot management system that allows users to add vehicles, track total number of vehicles, display parking arrangement and check availability of parking spots.

# Project Objective's 

- Implement a Parking Management System: The program simulates a parking lot for cars and scooters, managing parking space allocation by assigning row and column positions to vehicles. It keeps track of parking availability in a 2D array, differentiating parking spaces for cars and scooters.
- Efficiently Handle Vehicle Data: Using structures, the code stores the details of each vehicle, including type (car or scooter), parking location (row and column), and vehicle number. Dynamic memory allocation (malloc) is utilized to store vehicle records efficiently.
- Provide Real-time Parking Information: The system continuously updates and displays real-time information, such as the total number of vehicles, cars, and scooters parked, utilizing counters like vehcount, carcount, and scootercount.
- Search and Allocate Parking Slots: The system uses the getfreerowcol function to search for available parking slots in the designated areas for cars and scooters. It ensures vehicles are parked in the correct section and handles full parking conditions with error messages when no slots are available.

![interface](https://github.com/user-attachments/assets/7cda7dad-8986-459f-86a2-16bb7ea2e2f7)

![output](https://github.com/user-attachments/assets/237402ce-ca5a-40dd-a7c1-3994c534d321)
