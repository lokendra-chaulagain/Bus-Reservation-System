#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_SEATS 50

struct Bus
{
    int busNumber;
    int totalSeats;
    int availableSeats;
    int bookedSeats[MAX_SEATS];
};

struct Bus buses[MAX_BUSES];
int numBuses = 0;

// Define user structure
struct User
{
    char username[100];
    char password[100];
};

struct User users[MAX_BUSES]; // Store user data
int numUsers = 0;

// Function to authenticate the admin
int authenticateAdmin()
{
    char username[100];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Check admin credentials from file
    FILE *adminFile = fopen("admins.txt", "r");
    if (adminFile)
    {
        char fileUsername[100];
        char filePassword[100];

        while (fscanf(adminFile, "%s %s", fileUsername, filePassword) != EOF)
        {
            if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0)
            {
                fclose(adminFile);
                return 1; // Authentication successful
            }
        }

        fclose(adminFile);
    }

    return 0; // Authentication failed
}

// Function to register a new user
void registerUser()
{
    char username[100];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // // Check if the username already exists in memory (in the 'users' array)
    // for (int i = 0; i < numUsers; i++)
    // {
    //     if (strcmp(username, users[i].username) == 0)
    //     {
    //         printf("______________________________________________\n Status : Failed \n Message : Username already exists. Please choose a different username.\n______________________________________________\n");
    //         return;
    //     }
    // }

    // Check if the username already exists in the "users.txt" file
    FILE *file = fopen("users.txt", "r");
    if (file)
    {
        char fileUsername[100];
        char filePassword[100];

        while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF)
        {
            if (strcmp(username, fileUsername) == 0)
            {
                printf("______________________________________________\n Status:Failed \n Message : Username already exists in the file. Please choose a different username.\n______________________________________________\n");
                fclose(file);
                return;
            }
        }

        fclose(file);
    }

    // // Save user credentials to the array
    // strcpy(users[numUsers].username, username);
    // strcpy(users[numUsers].password, password);
    // numUsers++;

    printf("______________________________________________\n Status:Success \n Message : User registered successfully.\n______________________________________________\n");

    // Save user data to a text file
    file = fopen("users.txt", "a"); // Open the file for appending
    if (file)
    {
        fprintf(file, "%s %s\n", username, password);
        fclose(file);
    }
    else
    {
        printf("Message opening the file for saving user data.\n");
    }
}

// Function to authenticate a user
int authenticateUser()
{
    char username[100];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Check if the username and password match
    FILE *file = fopen("users.txt", "r"); // Open the file for reading
    if (file)
    {
        char fileUsername[100];
        char filePassword[100];

        while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF)
        {
            if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0)
            {
                fclose(file);
                return 1; // Authentication successful
            }
        }

        fclose(file);
    }

    return 0; // Authentication failed
}

void addBus(int busNumber, int totalSeats)
{
    if (numBuses < MAX_BUSES)
    {
        buses[numBuses].busNumber = busNumber;
        buses[numBuses].totalSeats = totalSeats;
        buses[numBuses].availableSeats = totalSeats;
        numBuses++;

        // Save bus data to a text file
        FILE *busFile = fopen("buses.txt", "a"); // Open the file for appending
        if (busFile)
        {
            fprintf(busFile, "%d %d\n", busNumber, totalSeats);
            fclose(busFile);

            printf("______________________________________________\n Status : Success \n Message : Bus added successfully.\n______________________________________________\n");
        }
        else
        {
            printf("Message opening the file for saving bus data.\n");
        }
    }
    else
    {
        printf("Maximum bus limit reached.\n");
    }
}

int findBusIndex(int busNumber)
{
    for (int i = 0; i < numBuses; i++)
    {
        if (buses[i].busNumber == busNumber)
        {
            return i;
        }
    }
    return -1;
}

void deleteBus(int busNumber)
{
    int busIndex = findBusIndex(busNumber);
    if (busIndex != -1)
    {
        // Shift buses to remove the one being deleted
        for (int i = busIndex; i < numBuses - 1; i++)
        {
            buses[i] = buses[i + 1];
        }
        numBuses--;
        printf("Bus %d deleted successfully.\n", busNumber);
    }
    else
    {
        printf("Bus not found.\n");
    }
}

// ... (rest of your functions remain the same)
void checkBusStatus(int busNumber)
{
    int busIndex = findBusIndex(busNumber);
    if (busIndex != -1)
    {
        printf("Bus %d - Total Seats: %d, Available Seats: %d\n",
               buses[busIndex].busNumber, buses[busIndex].totalSeats, buses[busIndex].availableSeats);
    }
    else
    {
        printf("Bus not found.\n");
    }
}

void cancelBooking(int busNumber, int seatNumber)
{
    int busIndex = findBusIndex(busNumber);
    if (busIndex != -1 && seatNumber >= 1 && seatNumber <= buses[busIndex].totalSeats)
    {
        if (buses[busIndex].bookedSeats[seatNumber - 1] == 1)
        {
            buses[busIndex].bookedSeats[seatNumber - 1] = 0;
            buses[busIndex].availableSeats++;
            printf("Booking canceled for Bus %d, Seat Number: %d\n", busNumber, seatNumber);
        }
        else
        {
            printf("Seat is not booked.\n");
        }
    }
    else
    {
        printf("Invalid bus number or seat number.\n");
    }
}

void bookTicket(int busNumber)
{
    int busIndex = findBusIndex(busNumber);
    if (busIndex != -1)
    {
        if (buses[busIndex].availableSeats > 0)
        {
            int seatNumber = buses[busIndex].totalSeats - buses[busIndex].availableSeats + 1;
            buses[busIndex].bookedSeats[seatNumber - 1] = 1;
            buses[busIndex].availableSeats--;
            printf("Ticket booked for Bus %d, Seat Number: %d\n", busNumber, seatNumber);
        }
        else
        {
            printf("No available seats for Bus %d.\n", busNumber);
        }
    }
    else
    {
        printf("Bus not found.\n");
    }
}

void displayBusList()
{
    printf("Bus List:\n");
    for (int i = 0; i < numBuses; i++)
    {
        printf("Bus %d - Total Seats: %d, Available Seats: %d\n",
               buses[i].busNumber, buses[i].totalSeats, buses[i].availableSeats);
    }
}

int main()
{
    int choice, busNumber, totalSeats, seatNumber;

    int isAdminAuthenticated = 0; // Flag to track admin authentication
    int isUserAuthenticated = 0;  // Flag to track user authentication

    do
    {
        printf("\nBus Ticket Booking System\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. User Registration\n");
        printf("4. Display Bus List\n");
        printf("5. Book Ticket\n");
        printf("6. Cancel Booking\n");
        printf("7. Check Bus Status\n");
        printf("8. Add Bus (Admin)\n");
        printf("9. Delete Bus (Admin)\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (authenticateAdmin())
            {
                isAdminAuthenticated = 1;
                printf("______________________________________________\n Status : Success \n Message : Admin login successful.\n______________________________________________\n");
            }
            else
            {

                printf("______________________________________________\n Status : Failed \n Message : Admin login failed.\n______________________________________________\n");
            }
            break;
        case 2:
            if (authenticateUser())
            {
                isUserAuthenticated = 1;

                printf("______________________________________________\n Status : Success \n Message : User login successful.\n______________________________________________\n");
            }
            else
            {

                printf("______________________________________________\n Status : Failed \n Message : User login failed.\n______________________________________________\n");
            }
            break;
        case 3:
            registerUser();
            break;
        case 4:
            displayBusList();
            break;
        case 5:
            if (isUserAuthenticated)
            {
                printf("Enter Bus Number: ");
                scanf("%d", &busNumber);
                bookTicket(busNumber);
            }
            else
            {
                printf("______________________________________________\n Status : Failed \n Message : User authentication required.\n______________________________________________\n");
            }
            break;

        case 6:
            if (isUserAuthenticated)
            {
                printf("Enter Bus Number: ");
                scanf("%d", &busNumber);
                printf("Enter Seat Number: ");
                scanf("%d", &seatNumber);
                cancelBooking(busNumber, seatNumber);
            }
            else
            {

                printf("______________________________________________\nMessage : User authentication required.\n______________________________________________\n");
            }
            break;

        case 7:
            printf("Enter Bus Number: ");
            scanf("%d", &busNumber);
            checkBusStatus(busNumber);
            break;
        case 8:
            if (isAdminAuthenticated)
            {
                printf("Enter Bus Number: ");
                scanf("%d", &busNumber);
                printf("Enter Total Seats: ");
                scanf("%d", &totalSeats);
                addBus(busNumber, totalSeats);
            }
            else
            {
                printf("______________________________________________\n Status : Failed \n Message : Admin authentication required..\n______________________________________________\n");
            }
            break;
        case 9:
            if (isAdminAuthenticated)
            {
                printf("Enter Bus Number to delete: ");
                scanf("%d", &busNumber);
                deleteBus(busNumber);
            }
            else
            {
                printf("______________________________________________\n Status : Failed \n Message : Admin authentication required.\n______________________________________________\n");
            }
            break;
        case 10:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 10);

    return 0;
}
