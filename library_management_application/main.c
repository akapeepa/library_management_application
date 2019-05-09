#include <stdio.h>
#include <stdlib.h>

struct Book
{
  int code;    char title[15];    char author[15] ; char isbn[15]; float price;
};

//module 01:
void add_books(struct Book book_array[]  , int MAX);
//Module 02
void print_books(struct Book book_array[]  , int MAX);
//Module 03-b
void search_book(struct Book book_array[] , int MAX, int key);


int main() //begin control module
{
  int max;
  printf("\nEnter the maximum number of books: ");
  scanf("%d", &max);
  struct Book book_array[max];
  int option, number; int key;

  int book_array_empty = 1 ; //I starting with an empty array it's true (1 meoption true)
  //printf("\n  1- Is array full? \n);
  do{
    system("cls");
    printf("\n=============== MAIN MENU ===============\n");
    printf("\n   1 - Is array full? \n    2 - ADD \n    3 - PRINT \n    4 - SEARCH \n 5 - SORT \n   6 - EXIT \n");
    // printf("\n   1 - Is array full? \n    2 - ADD \n    3 - PRINT \n    4 - SEARCH \n    5 - SORT \n    6 - EXIT \n\n \t\t   ([Type -1 to exit]");
    printf("\n\nPlease enter your choice: ");
    scanf("%d", &option);
    if( option == 1 )
    {
      if(book_array_empty == 1)
      {
        printf( "\n Array EMPTY..... ADD books.........: ");
        system("pause");
      }
      else
      {
        printf("\n Array FULL......DO NOT ADD MORE.........: ");
        system("pause");
      }
    }
    else if(option == 2 &&  book_array_empty == 1 )
    {
      add_books(book_array , max) ;
      book_array_empty  = 0 ;
      system("pause");
    }
    else if(option == 3)
    {
      system("cls");
      print_books(book_array, max);
      system("pause");
    }
    else if(option == 4)
    {
      // search_data(book_array, max);
      system("pause");

      /***** --- 2d way -----**/
      struct Book found_book;
      system("cls");
      printf("\nPlease enter the book code to search: ");
      scanf("%d", &key);
      search_book(book_array, max, key);  system("pause");
      /*******************/

    }
    else if(option == 5)
    {
      system("cls");
      sort_books(book_array, max);
      printf("\n  <<<<<<<<ARRAY SORTED>>>>>>>>>>> ");
      system("pause");
      print_books(book_array, max);
      system("pause");
    }
    else if(option == 6)
    {
      printf("\nEnd of the Menu...\n");
      break;
    }

  } while(option != 5) ;

  printf("\n\n\n End of the Control Module\n");

  return 0;

}//end control module


// ----------------------end of main control module------------------------------

//module 1
void add_books(struct Book book_array[] ,int MAX ){
  printf("\n Hi.. we are adding books from Keyboard to book_array array in RAM\n");
  for( int i = 0 ; i < MAX ; i++)
  {
    printf("\n Please Enter Book id ? :");
    scanf("%d" , &book_array[i].code);

    fflush(stdin);

    printf("\n Please Enter Book Title ? :");
    scanf("%s" , &book_array[i].title  ) ;
    fgets(book_array[i].title , 15 ,stdin );

    printf("\n Please Enter Book author ? :");
    scanf("%s" , &book_array[i].author  ) ;
    fgets(book_array[i].author , 15 ,stdin );

    printf("\n Please Enter Book isbn ? :");
    scanf("%s" , &book_array[i].isbn  ) ;
    fgets(book_array[i].isbn , 15 ,stdin );

    printf("\n Please Enter Book Price ? :");
    scanf("%d" , &book_array[i].price  ) ;
    //fgets(book_array[i].price  ,stdin );
  }
}

//module 2
void print_books(struct Book book_array[] ,const int MAX ){
  printf("\n Hi.. we are printing books from book_array array to SCREEN\n");

  for( int i = 0 ; i < MAX ; i++)
  {
    printf("\ncode: %d \n" , book_array[i].code);
    printf("title: %s " , book_array[i].title);
    printf("author: %s " , book_array[i].author);
    printf("isbn: %s " , book_array[i].isbn);
    printf("price: %d " , book_array[i].price);
  }
}

//module 3
void search_book(struct Book book_array[] ,const int MAX , int key){

  int position = -1;

  system("cls");
  printf("\nPlease enter the book code  to search: ");
  scanf("%d", &key);

  for(int index = 0 ; index < MAX ; index++)
  {
    if(book_array[index].code == key)
    {
      position = index ;    break;
    }
  }
  if(position == -1)
  {
    printf("Book %d not found: ", key);
  }
  else{
    printf("Book code: %d \n", book_array[position].code );
    printf("Book title: %s \n", book_array[position].title );
    printf("Book author: %s \n", book_array[position].author );
    printf("Book isbn: %s \n", book_array[position].isbn );
    printf("Book price: %d \n", book_array[position].price );
  }
}

void sort_books(struct Customer book_array[], int max)
{
  for(int i = 0; i < max ; i++)
  {
    for(int j = i+1; j < max ; j++)
    {
      if(book_array[i].id > book_array[j].id)
      {
        //process the interchanging(known as swapping)
        struct Book   temp;
        temp = book_array[i];
        book_array[i] = book_array[j];
        book_array[j] = temp;

        /**** 2 way : call the function interchange()
        // interchange(&book_array[i], &book_array[j]);
        ****************/
      }
    }
  }
}
