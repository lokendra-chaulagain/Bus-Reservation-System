// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_BUSES 10
// #define MAX_SEATS 50

// struct Bus
// {
//     int busNumber;
//     int totalSeats;
//     int availableSeats;
//     int bookedSeats[MAX_SEATS];
// };

// struct Bus buses[MAX_BUSES];
// int numBuses = 0;

// void addBus(int busNumber, int totalSeats)
// {
//     if (numBuses < MAX_BUSES)
//     {
//         buses[numBuses].busNumber = busNumber;
//         buses[numBuses].totalSeats = totalSeats;
//         buses[numBuses].availableSeats = totalSeats;
//         numBuses++;
//     }
//     else
//     {
//         printf("Maximum bus limit reached.\n");
//     }
// }

// void displayBusList()
// {
//     printf("Bus List:\n");
//     for (int i = 0; i < numBuses; i++)
//     {
//         printf("Bus %d - Total Seats: %d, Available Seats: %d\n",
//                buses[i].busNumber, buses[i].totalSeats, buses[i].availableSeats);
//     }
// }

// int findBusIndex(int busNumber)
// {
//     for (int i = 0; i < numBuses; i++)
//     {
//         if (buses[i].busNumber == busNumber)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// void bookTicket(int busNumber)
// {
//     int busIndex = findBusIndex(busNumber);
//     if (busIndex != -1)
//     {
//         if (buses[busIndex].availableSeats > 0)
//         {
//             int seatNumber = buses[busIndex].totalSeats - buses[busIndex].availableSeats + 1;
//             buses[busIndex].bookedSeats[seatNumber - 1] = 1;
//             buses[busIndex].availableSeats--;
//             printf("Ticket booked for Bus %d, Seat Number: %d\n", busNumber, seatNumber);
//         }
//         else
//         {
//             printf("No available seats for Bus %d.\n", busNumber);
//         }
//     }
//     else
//     {
//         printf("Bus not found.\n");
//     }
// }

// void cancelBooking(int busNumber, int seatNumber)
// {
//     int busIndex = findBusIndex(busNumber);
//     if (busIndex != -1 && seatNumber >= 1 && seatNumber <= buses[busIndex].totalSeats)
//     {
//         if (buses[busIndex].bookedSeats[seatNumber - 1] == 1)
//         {
//             buses[busIndex].bookedSeats[seatNumber - 1] = 0;
//             buses[busIndex].availableSeats++;
//             printf("Booking canceled for Bus %d, Seat Number: %d\n", busNumber, seatNumber);
//         }
//         else
//         {
//             printf("Seat is not booked.\n");
//         }
//     }
//     else
//     {
//         printf("Invalid bus number or seat number.\n");
//     }
// }

// void checkBusStatus(int busNumber)
// {
//     int busIndex = findBusIndex(busNumber);
//     if (busIndex != -1)
//     {
//         printf("Bus %d - Total Seats: %d, Available Seats: %d\n",
//                buses[busIndex].busNumber, buses[busIndex].totalSeats, buses[busIndex].availableSeats);
//     }
//     else
//     {
//         printf("Bus not found.\n");
//     }
// }

// int main()
// {
//     int choice, busNumber, totalSeats, seatNumber;

//     do
//     {
//         printf("\nBus Ticket Booking System\n");
//         printf("1. Add Bus\n");
//         printf("2. Display Bus List\n");
//         printf("3. Book Ticket\n");
//         printf("4. Cancel Booking\n");
//         printf("5. Check Bus Status\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter Bus Number: ");
//             scanf("%d", &busNumber);
//             printf("Enter Total Seats: ");
//             scanf("%d", &totalSeats);
//             addBus(busNumber, totalSeats);
//             break;
//         case 2:
//             displayBusList();
//             break;
//         case 3:
//             printf("Enter Bus Number: ");
//             scanf("%d", &busNumber);
//             bookTicket(busNumber);
//             break;
//         case 4:
//             printf("Enter Bus Number: ");
//             scanf("%d", &busNumber);
//             printf("Enter Seat Number: ");
//             scanf("%d", &seatNumber);
//             cancelBooking(busNumber, seatNumber);
//             break;
//         case 5:
//             printf("Enter Bus Number: ");
//             scanf("%d", &busNumber);
//             checkBusStatus(busNumber);
//             break;
//         case 6:
//             printf("Exiting program.\n");
//             break;
//         default:
//             printf("Invalid choice. Please enter a valid option.\n");
//         }

//     } while (choice != 6);

//     return 0;
// }

//=========Admin Authorization===============================================================================================>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> // Added for string comparison

// #define MAX_BUSES 10
// #define MAX_SEATS 50

// // Define admin credentials
// #define ADMIN_USERNAME "admin"
// #define ADMIN_PASSWORD "password"

// struct Bus
// {
//     int busNumber;
//     int totalSeats;
//     int availableSeats;
//     int bookedSeats[MAX_SEATS];
// };

// struct Bus buses[MAX_BUSES];
// int numBuses = 0;

// // Function to authenticate the admin
// int authenticateAdmin()
// {
//     char username[100];
//     char password[100];

//     printf("Enter username: ");
//     scanf("%s", username);

//     printf("Enter password: ");
//     scanf("%s", password);

//     if (strcmp(username, ADMIN_USERNAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0)
//     {
//         return 1; // Authentication successful
//     }
//     else
//     {
//         return 0; // Authentication failed
//     }
// }

// void addBus(int busNumber, int totalSeats)
// {
//     if (numBuses < MAX_BUSES)
//     {
//         buses[numBuses].busNumber = busNumber;
//         buses[numBuses].totalSeats = totalSeats;
//         buses[numBuses].availableSeats = totalSeats;
//         numBuses++;
//     }
//     else
//     {
//         printf("Maximum bus limit reached.\n");
//     }
// }

// int findBusIndex(int busNumber)
// {
//     for (int i = 0; i < numBuses; i++)
//     {
//         if (buses[i].busNumber == busNumber)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// void deleteBus(int busNumber)
// {
//     int busIndex = findBusIndex(busNumber);
//     if (busIndex != -1)
//     {
//         // Shift buses to remove the one being deleted
//         for (int i = busIndex; i < numBuses - 1; i++)
//         {
//             buses[i] = buses[i + 1];
//         }
//         numBuses--;
//         printf("Bus %d deleted successfully.\n", busNumber);
//     }
//     else
//     {
//         printf("Bus not found.\n");
//     }
// }

// // ... (rest of your functions remain the same)
// void checkBusStatus(int busNumber)
// {
//     int busIndex = findBusIndex(busNumber);
//     if (busIndex != -1)
//     {
//         printf("Bus %d - Total Seats: %d, Available Seats: %d\n",
//                buses[busIndex].busNumber, buses[busIndex].totalSeats, buses[busIndex].availableSeats);
//     }
//     else
//     {
//         printf("Bus not found.\n");
//     }
// }

// void cancelBooking(int busNumber, int seatNumber)
// {
//     int busIndex = findBusIndex(busNumber);
//     if (busIndex != -1 && seatNumber >= 1 && seatNumber <= buses[busIndex].totalSeats)
//     {
//         if (buses[busIndex].bookedSeats[seatNumber - 1] == 1)
//         {
//             buses[busIndex].bookedSeats[seatNumber - 1] = 0;
//             buses[busIndex].availableSeats++;
//             printf("Booking canceled for Bus %d, Seat Number: %d\n", busNumber, seatNumber);
//         }
//         else
//         {
//             printf("Seat is not booked.\n");
//         }
//     }
//     else
//     {
//         printf("Invalid bus number or seat number.\n");
//     }
// }

// void bookTicket(int busNumber)
// {
//     int busIndex = findBusIndex(busNumber);
//     if (busIndex != -1)
//     {
//         if (buses[busIndex].availableSeats > 0)
//         {
//             int seatNumber = buses[busIndex].totalSeats - buses[busIndex].availableSeats + 1;
//             buses[busIndex].bookedSeats[seatNumber - 1] = 1;
//             buses[busIndex].availableSeats--;
//             printf("Ticket booked for Bus %d, Seat Number: %d\n", busNumber, seatNumber);
//         }
//         else
//         {
//             printf("No available seats for Bus %d.\n", busNumber);
//         }
//     }
//     else
//     {
//         printf("Bus not found.\n");
//     }
// }

// void displayBusList()
// {
//     printf("Bus List:\n");
//     for (int i = 0; i < numBuses; i++)
//     {
//         printf("Bus %d - Total Seats: %d, Available Seats: %d\n",
//                buses[i].busNumber, buses[i].totalSeats, buses[i].availableSeats);
//     }
// }

// int main()
// {
//     int choice, busNumber, totalSeats, seatNumber;

//     int isAdminAuthenticated = 0; // Flag to track admin authentication

//     do
//     {
//         printf("\nBus Ticket Booking System\n");
//         printf("1. Admin Login\n");
//         printf("2. Display Bus List\n");
//         printf("3. Book Ticket\n");
//         printf("4. Cancel Booking\n");
//         printf("5. Check Bus Status\n");
//         printf("6. Add Bus (Admin)\n");
//         printf("7. Delete Bus (Admin)\n");
//         printf("8. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             if (authenticateAdmin())
//             {
//                 isAdminAuthenticated = 1;
//                 printf("Admin login successful.\n");
//             }
//             else
//             {
//                 printf("Admin login failed.\n");
//             }
//             break;
//         case 2:
//             displayBusList();
//             break;
//         case 3:
//             printf("Enter Bus Number: ");
//             scanf("%d", &busNumber);
//             bookTicket(busNumber);
//             break;
//         case 4:
//             printf("Enter Bus Number: ");
//             scanf("%d", &busNumber);
//             printf("Enter Seat Number: ");
//             scanf("%d", &seatNumber);
//             cancelBooking(busNumber, seatNumber);
//             break;
//         case 5:
//             printf("Enter Bus Number: ");
//             scanf("%d", &busNumber);
//             checkBusStatus(busNumber);
//             break;
//         case 6:
//             if (isAdminAuthenticated)
//             {
//                 printf("Enter Bus Number: ");
//                 scanf("%d", &busNumber);
//                 printf("Enter Total Seats: ");
//                 scanf("%d", &totalSeats);
//                 addBus(busNumber, totalSeats);
//             }
//             else
//             {
//                 printf("Admin authentication required.\n");
//             }
//             break;
//         case 7:
//             if (isAdminAuthenticated)
//             {
//                 printf("Enter Bus Number to delete: ");
//                 scanf("%d", &busNumber);
//                 deleteBus(busNumber);
//             }
//             else
//             {
//                 printf("Admin authentication required.\n");
//             }
//             break;
//         case 8:
//             printf("Exiting program.\n");
//             break;
//         default:
//             printf("Invalid choice. Please enter a valid option.\n");
//         }

//     } while (choice != 8);

//     return 0;
// }