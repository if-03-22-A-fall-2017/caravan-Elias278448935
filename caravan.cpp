/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "stdlib.h"
#include "caravan.h"
#include "pack_animal.h"
#include "general.h"
#include "string.h"
#include "stdio.h"

struct Node
{
  PackAnimal data;
  struct Node* next;
};

struct CaravanImplementation
{
	struct Node* head;
  struct Node* tail;
  int length;
  int load;
  int speed;
};




Caravan new_caravan()
{
  Caravan new_caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  new_caravan->length = 0;
  new_caravan->head = 0;
  new_caravan->tail = 0;
  new_caravan->speed = 0;
  new_caravan->load = 0;
  return new_caravan;

}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
 struct Node* current = caravan->head;
 while (current != 0)
 {
   struct Node* to_delete = current;
   current = current->next;
   sfree(to_delete);
 }
 sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  
 if(animal == 0 || get_caravan(animal) == caravan)return;
  Node* newNode = (struct Node*)malloc(sizeof(struct Node*));

  newNode->data = animal;
  newNode->next = 0;
  if(caravan->head == 0)
  {
    caravan->head = newNode;
    caravan->tail = newNode;
  }
  else
  {
    caravan->tail->next = newNode;
    caravan->tail = caravan->tail->next;
  }



  add_to_caravan(animal, caravan);

  caravan->load += get_load(animal);

  caravan->length++;






void remove_pack_animal(Caravan caravan, PackAnimal animal)
{

  if(caravan->head == 0 || animal == 0 || caravan == 0) return;


  if(caravan->head->data == animal)
  {


    struct Node* current = caravan->head;
    caravan->head = caravan->head->next;
    remove_from_caravan(animal, 0);

      caravan->load -= get_load(current->data);
    sfree(current);

    caravan->length--;
    return;
  }
  struct Node* current = caravan->head;
    struct Node* to_delete = 0;
  while(current != 0)
  {
    if(current->next!=0 && current->next->data == animal)
    {

      to_delete=current->next;
      if(current->next->next!=0)
      {
          current->next = current->next->next;
          caravan->load -= get_load(to_delete->data);
          caravan->length--;
          remove_from_caravan(animal, 0);
          sfree(to_delete);

      }
      else
      {
        caravan->load -= get_load(to_delete->data);
        sfree(to_delete);
        caravan->length--;
      }


      return;
    }
  current = current->next;
  }


}

int get_caravan_load(Caravan caravan)
{
   return caravan->load;
}

void unload(Caravan caravan)
{
  struct Node* current = caravan->head;
  for (int i = 0; i < caravan->length; i++) {
    unload(current->data);
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  int speed = 0;
    struct Node* current = caravan->head;
    for (int i = 0; i < caravan->length; ++i) {
        speed = get_actual_speed(current->data)<speed ? get_actual_speed(current->data): speed;
    current = current->next;
    }
    return speed;
}
void optimize_load(Caravan caravan)
{
  return;
}
