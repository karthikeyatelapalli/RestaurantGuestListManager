/*Description: The code is a useful tool for keeping track of restaurant patrons. It functions similarly to a digital guestbook, allowing you to 
keep things organized, add new guest, and see who's already on the list. It uses the guest's phone number as a unique identifier to 
detect attempts to add guests who are already registered. Through a command loop driven by menus, the user interface functions. Because 
of the simple layout, anyone managing a busy restaurant may easily add or retrieve guest information without any difficulty. Moreover, 
it can tidy the list at the end of the day so that it is ready for the throng the following day.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30
#define PHONE_LEN 20

// Here we define the structure which stores the guest information
// Here every guest have a phone number, party size, last name, and first name
// Here additionally, a pointer to the following guest is included, forming a linked list. 
struct guest{
	char phone[PHONE_LEN+1];
	char last[NAME_LEN+1];
	char first[NAME_LEN+1];
	int party_size;
	struct guest *next;
};


// These are the functions that we use in this program
struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct guest *new_list = NULL;  
  printf("Operation Code: a for adding to the list at the end, p for printing the list; q for quit.\n");
  // This is a loop for the interface. 
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   // skips to end of line
      ;
    switch (code) {
      case 'a': new_list = add_guest(new_list); // Here we add the guest to our list
                break;
      case 'p': print_list(new_list); // Here we print the current list of guests
                break;
      case 'q': clear_list(new_list); // Here we quit the running code after we clear the list
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}


// This function allows us to add new guests to the list
// It determines whether there is already a guest with the same phone number.
// If not, a new guest is created and added to the end of the list.
struct guest *add_guest(struct guest *list) {
    char phone[PHONE_LEN+1];
    printf("Enter phone number: ");
    read_line(phone, PHONE_LEN);

    // Here we check for if the guest already exists
    struct guest *p;
    for (p = list; p != NULL; p = p->next) {
        if (strcmp(phone, p->phone) == 0) {
            printf("guest already exists.");
            return list;
        }
    }

    // Here we get the guest details
    struct guest *new_guest = malloc(sizeof(struct guest));
    if (new_guest == NULL) {
        printf("Error: malloc failed.\n");
        return list;
    }
    strcpy(new_guest->phone, phone);
    printf("Enter guest's last name: ");
    read_line(new_guest->last, NAME_LEN);
    printf("Enter guest's first name: ");
    read_line(new_guest->first, NAME_LEN);
    printf("Enter party size: ");
    scanf("%d", &new_guest->party_size);
    new_guest->next = NULL;

    // Here we add guest to the end of the list
    if (list == NULL) {
        // Here the list is empty, now the new guest is on the list  
        return new_guest;
    } else {
        // Here we find the end of the ;ist and add our new guest 
        struct guest *cur = list;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_guest;
        return list;
    }
}
 


// This is a function to print the list of guests
void print_list(struct guest *list) {
    struct guest *p = list;
    while (p != NULL) {
        printf("%-15s%-20s%-20s%5d\n", p->phone, p->last, p->first, p->party_size);
        p = p->next;
    }
}


// This is a function to clears the list of guests
void clear_list(struct guest *list) {
    while (list != NULL) {
        struct guest *p = list;
        list = list->next;
        free(p);
    }
}

// This is an utility function to read a line of text
// It manages input better than a basic scanf.
int read_line(char str[], int n)
{
  int ch, i = 0;

  // Here we skip initiate whitespace
  while (isspace(ch = getchar()))
    ;
  // Here we start storing characters.
  str[i++] = ch;
  // Here we continue until the newline
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0'; // Terminate the string null.
   return i; // Here we return no of characters read.
}
