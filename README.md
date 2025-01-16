# Restaurant Guest List Manager

This C program serves as a digital guestbook for restaurants, making it easy to manage guest information. It allows restaurant personnel to add new guests, retrieve a list of all current guests, and clear the list at the end of the day. The program uses the guest's phone number as a unique identifier to avoid duplicate entries.

## Features
- **Add Guests**: Allows you to add guests to the list with their phone number, first name, last name, and party size.
- **Retrieve Guest List**: Displays all registered guests with their details.
- **Clear Guest List**: Clears the entire list of guests to prepare for the next day.
- **Phone Number as Unique Identifier**: Ensures no duplicate entries by checking phone numbers.

## How to Compile and Run
1. Save the program as `restaurant_guest_list.c`.
2. Compile the program:
   ```bash
   gcc restaurant_guest_list.c -o restaurant_guest_list
