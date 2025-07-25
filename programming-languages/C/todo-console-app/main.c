#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESCRIPTION_LENGTH 256
#define INITAL_CAPACITY 2

typedef struct {
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    bool completed;
} TodoItem;

TodoItem* todo_list = NULL;
int todo_count = 0;
int todo_capacity = 0;
int next_id = 1;

void initialize_todo_list(){
    todo_capacity = INITAL_CAPACITY;
    todo_list = (TodoItem*)malloc(sizeof(TodoItem)* todo_capacity);
    if(todo_list == NULL) {
        printf("Error failed to allocate memory! bad!");
        exit(EXIT_FAILURE);
    }

    todo_count = 0;
    next_id = 1;
}

void free_todo_list(){
    if(todo_list != NULL){
        free(todo_list);
        todo_list = NULL;
    }
    todo_count = 0;
    todo_capacity = 0;
    next_id = 1;
}

void ensure_capacity(){
    if(todo_count >= todo_capacity){
        todo_capacity *= 2;
        TodoItem* temp = (TodoItem*)realloc(todo_list, sizeof(TodoItem) * todo_capacity);
        if(temp == NULL){
            printf("Erro: failed to reallocate memory!");
            exit(EXIT_FAILURE);
        }

        todo_list = temp;
        printf("Info: resized todo list to capacity of %d.\n", todo_capacity);
    }


}

void add_todo(const char* description){
    if(strlen(description) == 0){
        printf("Error: description cannot be empty.\n");
        return;
    }

    ensure_capacity();

    todo_list[todo_count].id = next_id++;
    strcpy(todo_list[todo_count].description, description);
    todo_list[todo_count].completed = false;
    todo_count++;

    printf("Success: TodoItem added: ID %d - \"%s\"\n", todo_list[todo_count - 1].id, todo_list[todo_count - 1].description);
}

void list_todos(){
    if(todo_count == 0){
        printf("The todo list is empty.\n");
        return;
    }

    printf("\n*** Current Todo Items (%d items) ***\n", todo_count);
    for(int i = 0; i < todo_count; i++){
        printf("Id: %-4d | Status: %-8s | Description: %s\n", todo_list[i].id, todo_list[i].completed ? "COMPLETE" : "PENDING", todo_list[i].description);
    }
    printf("----------------------\n");



}

void complete_todo(int id){
    for(int i = 0; i < todo_count; i++){
        if(todo_list[i].id == id){
            if(todo_list[i].completed){
                printf("Info: Todo ID %d is already complete.\n", id);
            }else {
                todo_list[i].completed = true;
                printf("Success: Todo ID %d marked as COMPLETE.\n",id);
            }
            return;
        }
    }
    printf("Error: Todo with ID %d not found.\n", id);
}

void delete_todo(int id){
    int found_index = -1;
    //Find the index of the todo item with the given ID
    for(int i =0; i < todo_count; i++){
        if(todo_list[i].id == id){
            found_index =i;
            break;
        }

    }

    if(found_index != -1){
        //Shift elements to the left to fill the gap created by deletion
        for(int i = found_index; i < todo_count -1; i++){
            todo_list[i] = todo_list[i + 1];
        }
        todo_count--; //Decrement the count of todos
        printf("Success: Todo with ID %d deleted.\n", id);
    }else {
        printf("Error: Todo with ID %d not found. \n", id);
    }
}

void save_todo_to_file(const char* filename){
    FILE* file = fopen(filename, "w"); //Open file in write mode, overwriting if exists
    if(file == NULL){
        perror("Error: Could not open file for writing");
        return;
    }

    for(int i = 0; i < todo_count; i++) {
        //Write each todo item's data to the file
        fprintf(file, "%d;%d;%s\n", todo_list[i].id, todo_list[i].completed ? 1 : 0, todo_list[i].description);
    }

    fclose(file); //Close the file
}

void    load_todos_from_file(const char* filename){
    FILE* file = fopen(filename, "r"); //Open file in read mode
    if(file == NULL){
        printf("Info: No existing '%s' file found, Starting with an empty list.\n", filename);
        return;
    }

    free_todo_list();
    initialize_todo_list();

    char line[MAX_DESCRIPTION_LENGTH + 50]; // Buffer for reading each line from the file
	int loaded_id, loaded_completed;
	char loaded_description[MAX_DESCRIPTION_LENGTH];
	int max_id_found = 0; // Track the highest ID found to ensure new IDs are unique

	while (fgets(line, sizeof(line), file) != NULL) {
		// Find the first semicolon to parse ID
		char* first_semi = strchr(line, ';');
		if (first_semi == NULL) {
			fprintf(stderr, "Warning: Skipping malformed line in file (missing first ';'): %s\n", line);
			continue;
		}
		*first_semi = '\0'; // Null-terminate the ID part
		loaded_id = atoi(line); // Convert ID string to integer "1" -> 1

		// Find the second semicolon to parse completion status
		char* second_semi = strchr(first_semi + 1, ';');
		if (second_semi == NULL) {
			fprintf(stderr, "Warning: Skipping malformed line in file (missing second ';'): %s\n", line);
			continue;
		}
		*second_semi = '\0'; // Null-terminate the completed status part
		loaded_completed = atoi(first_semi + 1); // Convert status string to integer

		// Get the description part and remove trailing newline
		strncpy(loaded_description, second_semi + 1, sizeof(loaded_description) - 1);
		loaded_description[sizeof(loaded_description) - 1] = '\0'; // Ensure null termination
		loaded_description[strcspn(loaded_description, "\n")] = 0; // Remove newline if present

		ensure_capacity(); // Ensure enough space for the new todo item

		// Populate the TodoItem struct
		todo_list[todo_count].id = loaded_id;
		strcpy(todo_list[todo_count].description, loaded_description);
		todo_list[todo_count].completed = (loaded_completed == 1); // Convert 0/1 to boolean
		todo_count++; // Increment count

		// Update the maximum ID found to ensure future new IDs are unique
		if (loaded_id >= max_id_found) {
			max_id_found = loaded_id;
		}
	}
	next_id = max_id_found + 1; // Set nextId to be one greater than the highest loaded ID

	fclose(file); // Close the file
	printf("Info: Loaded %d todos from '%s'.\n", todo_count, filename);

}

int main(void){

    initialize_todo_list();

    load_todos_from_file("todos.txt");

    int choice;
    int temp_description[MAX_DESCRIPTION_LENGTH];
    int temp_id;

    do{
       //Display the Menu
       printf("\n*** Todo List Application ***\n");
       printf("1. Add Todo\n");
       printf("2. List Todos\n");
       printf("3. Mark Todo as Complete\n");
       printf("4. Delete Todo\n");
       printf("5. Save Todos\n");
       printf("6. Exit\n");
       printf("Enter your choice: ");

       if(scanf("%d", &choice) != 1){
           printf("Invalid input, Please enter a number.\n");
           while(getchar() != '\n');
           continue; // skip to next iteration of loop
       }

       // consume left over newline character
       while(getchar() != '\n');

       switch(choice){
       case 1:
           printf("Enter the new todo description: ");
           fgets(temp_description, sizeof(temp_description), stdin);
           temp_description[strcspn("temp_description", "\n")];
           add_todo(temp_description);
           break;

       case 2:
           list_todos();
           break;

       case 3:
           printf("Enter the ID of todo to complete:");
           if (scanf("%d", &temp_id) != 1){
                printf("Invalid input. Please enter a number.\n");
                while(getchar() != '\n');
                continue;
           }

           while (getchar() != '\n'); //consume newline
           complete_todo(temp_id);
           break;
       case 4:
            printf("Enter the ID of todo to delete: ");
            if (scanf("%d", &temp_id) != 1){
                printf("Invalid input. Please enter a number.\n");
                while(getchar() != '\n');
                continue;
            }
            while (getchar() != '\n'); //consume newline
            delete_todo(temp_id);
            break;
       case 5:
            //Save todos
            save_todo_to_file("todos.txt");
            printf("Todos saved to todos.txt.\n");
            break;

       case 6: //exit
           printf("Exiting application. Have a great day!\n");
           break;
       default:
           printf("Invalid choice. Please try again.\n");

       }


    }while(choice != 6);

    free_todo_list();
    return 0;
}
