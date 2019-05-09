#include <stdio.h>
#include <stdlib.h>

struct Book
{
  int code;    char title[15];    char author[15] ; char isbn[15]; float price;
};
//---------------- START OF MAIN-----------------------------------

//module 1
void add_books(struct Book library[] ,const int max ){
  printf("\n Hi.. we are adding books from Keyboard to library array in RAM\n");
  for( int i = 0 ; i < MAX ; i++)
  {
    printf("\n Please Enter Book id ? :");
    scanf("%d" , &library[i].code);

    fflush(stdin);

    printf("\n Please Enter Book Title ? :");
    scanf("%s" , &library[i].title  ) ;
    fgets(library[i].title , 15 ,stdin );

    printf("\n Please Enter Book author ? :");
    scanf("%s" , &library[i].author  ) ;
    fgets(library[i].author , 15 ,stdin );

    printf("\n Please Enter Book isbn ? :");
    scanf("%s" , &library[i].isbn  ) ;
    fgets(library[i].isbn , 15 ,stdin );

    printf("\n Please Enter Book Price ? :");
    scanf("%d" , &library[i].price  ) ;
    fgets(library[i].price  ,stdin );
  }
}

//module 2
void print_books((struct Book library[] ,const int max ){
  printf("\n Hi.. we are printing books from library array to SCREEN\n");

  for( int i = 0 ; i < MAX ; i++)
  {
    printf("\ncode: %d \n" , library[i].code);
    printf("title: %s " , library[i].title);
    printf("author: %s " , library[i].author);
    printf("isbn: %s " , library[i].isbn);
    printf("price: %d " , library[i].price);
  }
}

//module 3
void search_book(struct Book library[] ,const int max , int key){
  int key;
  int position = -1;

  system("cls");
  printf("\nPlease enter the book code  to search: ");
  scanf("%d", &key);

  for(int index = 0 ; index < MAX ; index++)
  {
    if(library[index].code == key)
    {
      position = index ;    break;
    }
  }
  if(position == -1)
  {
    printf("Book %d not found: ", key);
  }
  else{
    printf("Book code: %d \n", library[position].code );
    printf("Book title: %s \n", library[position].title );
    printf("Book author: %s \n", library[position].author );
    printf("Book isbn: %s \n", library[position].isbn );
    printf("Book price: %d \n", library[position].price );
  }
}

// ------------------ main contral module--------------------------------------
int main()
{
  int max;
  printf("\nEnter the maximum number of Books: ");
  scanf("%d", &max);
  struct Book book_array[max];
  int option, number; int key;

  int vech_array_empty = 1 ;

  do{
    system("cls");
    printf("\n=============== MAIN MENU ===============\n");
    printf("\n\n    1 - Is array full \n    2 - ADD \n    3 - PRINT \n    4 - SEARCH \n       5 - EXIT \n");

    printf("\n\nPlease enter your choice: ");
    scanf("%d", &option);
    if( option == 1 )
    {
      if(book_array_empty == 1)
      {
        printf( "\n  Array EMPTY..... ADD Books.........: ");
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

      system("pause");

      struct Book found_Book;
      system("cls");
      printf("\nPlease enter the Book code number to search: ");
      scanf("%d", &key);
      search_book(book_array, max, key);  system("pause");

    }


    else if(option == 5)
    {
      printf("\nEnd of the Menu...\n");
      break;
    }

  } while(option != 5) ;

  printf("\n\n\n End of the Control Module\n");

  return 0;

}

// ----------------------end of main control module------------------------------
