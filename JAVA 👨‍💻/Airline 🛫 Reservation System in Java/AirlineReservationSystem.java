package Airline;

import java.util.Scanner;

public class AirlineReservationSystem {
    private static boolean[] seats = new boolean[10];
    private static int[] modificationCounts = new int[10];  // To track modification counts for each seat
    private static final int MAX_CHANGES = 3;  // Maximum allowed changes per reservation

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            System.out.println("Airline Reservation System in Java");
            System.out.println();
            System.out.println("Designed & Developed by Hemant");
            System.out.println();
            System.out.println("1. Reserve a seat");
            System.out.println("2. View all seats");
            System.out.println("3. Cancel a reservation");
            System.out.println("4. Modify a reservation");
            System.out.println("5. View reservation list");
            System.out.println("6. EXIT");
            System.out.println();

            int choice = input.nextInt();
            if (choice == 1) {
                reserveSeat(input);
            } else if (choice == 2) {
                viewSeats();
            } else if (choice == 3) {
                cancelReservation(input);
            } else if (choice == 4) {
                modifyReservation(input);
            } else if (choice == 5) {
                viewReservationList();
            } else if (choice == 6) {
                break;
            } else {
                System.out.println("INVALID CHOICE");
            }
        }
        input.close();
    }

    private static void viewSeats() {
        for (int i = 0; i < seats.length; i++) {
            System.out.print("Seat " + (i + 1) + ": ");
            if (seats[i]) {
                System.out.println("Seat is reserved");
            } else {
                System.out.println("Seat is available");
            }
        }
    }

    private static void reserveSeat(Scanner input) {
        boolean allSeatsReserved = true;
        for (boolean seat : seats) {
            if (!seat) {
                allSeatsReserved = false;
                break;
            }
        }

        if (allSeatsReserved) {
            System.out.println("All seats are reserved.");
            return;
        }

        System.out.println("Enter seat number (1-10): ");
        int seatNum = input.nextInt();
        if (seatNum < 1 || seatNum > 10) {
            System.out.println("Invalid seat number. Please enter a number between 1 and 10.");
        } else if (!seats[seatNum - 1]) {
            seats[seatNum - 1] = true;
            modificationCounts[seatNum - 1] = 0;  // Initialize modification count for the seat
            System.out.println("Seat " + seatNum + " is reserved.");
        } else {
            System.out.println("SORRY, this seat is already reserved.");
        }
    }

    private static void cancelReservation(Scanner input) {
        System.out.println("Enter seat number to cancel (1-10): ");
        int seatNum = input.nextInt();
        if (seatNum < 1 || seatNum > 10) {
            System.out.println("Invalid seat number. Please enter a number between 1 and 10.");
        } else if (seats[seatNum - 1]) {
            seats[seatNum - 1] = false;
            modificationCounts[seatNum - 1] = 0;  // Reset modification count when reservation is canceled
            System.out.println("Reservation for seat " + seatNum + " is canceled.");
        } else {
            System.out.println("Seat " + seatNum + " is already available.");
        }
    }

    private static void modifyReservation(Scanner input) {
        System.out.println("Enter your current seat number (1-10): ");
        int currentSeatNum = input.nextInt();
        if (currentSeatNum < 1 || currentSeatNum > 10) {
            System.out.println("Invalid seat number. Please enter a number between 1 and 10.");
            return;
        }

        if (!seats[currentSeatNum - 1]) {
            System.out.println("No reservation found for seat " + currentSeatNum);
            return;
        }

        if (modificationCounts[currentSeatNum - 1] >= MAX_CHANGES) {
            System.out.println("You have reached the maximum number of changes for seat " + currentSeatNum);
            return;
        }

        System.out.println("Enter the new seat number you want (1-10): ");
        int newSeatNum = input.nextInt();
        if (newSeatNum < 1 || newSeatNum > 10) {
            System.out.println("Invalid seat number. Please enter a number between 1 and 10.");
        } else if (!seats[newSeatNum - 1]) {
            seats[currentSeatNum - 1] = false;  // Free up the current seat
            seats[newSeatNum - 1] = true;  // Reserve the new seat
            modificationCounts[currentSeatNum - 1]++;  // Increment the modification count for the original seat
            modificationCounts[newSeatNum - 1] = 0;  // Reset modification count for the new seat
            System.out.println("Reservation has been changed from seat " + currentSeatNum + " to seat " + newSeatNum);
        } else {
            System.out.println("SORRY, the new seat " + newSeatNum + " is already reserved.");
        }
    }

    private static void viewReservationList() {
        System.out.println("Reserved Seats:");
        boolean anyReservations = false;
        for (int i = 0; i < seats.length; i++) {
            if (seats[i]) {
                System.out.println("Seat " + (i + 1));
                anyReservations = true;
            }
        }
        if (!anyReservations) {
            System.out.println("No seats are currently reserved.");
        }
    }
}